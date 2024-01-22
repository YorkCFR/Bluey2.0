import sys
import rclpy
import math
from rclpy import qos
from std_msgs.msg import String, Float32
from geometry_msgs.msg import Twist
from ament_index_python.packages import get_package_share_directory
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QVBoxLayout, QHBoxLayout, QWidget, QTextEdit, QLineEdit, QLabel, QGridLayout, QStyle
from PyQt5.QtGui import QPixmap, QPalette, QColor, QIcon
from PyQt5.QtCore import Qt, QTimer, QSize
import cv2
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
from std_msgs.msg import Bool
from std_msgs.msg import String
from bluey_interface.srv import Lights, Arm, Motion, Commands


# used in debugging, now not needed
class Color(QWidget):
    def __init__(self, color):
        super().__init__()
        self.setAutoFillBackground(True)
        palette = self.palette()
        palette.setColor(QPalette.Window, QColor(color))
        self.setPalette(palette)

class RobotControlGUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self._node = rclpy.create_node('blue_ui_node')

        home = get_package_share_directory('bluey_tools')
        self._node.get_logger().info(f'{self._node.get_name()} You are loading from {home}/')
        self._stop_icon = QPixmap(f"{home}/stop-96.png").scaled(96, 96)
        self._up_icon = QIcon(QPixmap(f"{home}/up-100.png"))
        self._down_icon = QIcon(QPixmap(f"{home}/down-100.png"))
        self._left_icon = QIcon(QPixmap(f"{home}/left-100.png"))   
        self._right_icon = QIcon(QPixmap(f"{home}/right-100.png"))
        self._diag_up_left_icon = QIcon(QPixmap(f"{home}/up-left-100.png"))
        self._diag_up_right_icon = QIcon(QPixmap(f"{home}/up-right-100.png"))

        self._node.declare_parameter('image', "/mycamera/image_raw")
        self._image_topic = self._node.get_parameter('image').get_parameter_value().string_value
        self._node.create_subscription(Image, self._image_topic, self._image_callback, 1)

        client = self._node.create_client(Lights, f'/set_lights')
        while not client.wait_for_service(timeout_sec=1.0):
            self._node.get_logger().info(f'{self._node.get_name()} Waiting for /set_lights')
            break
        self._set_lights_cli = client

        client = self._node.create_client(Arm, f'/arm')
        while not client.wait_for_service(timeout_sec=1.0):
            self._node.get_logger().info(f'{self._node.get_name()} Waiting for /arm')
            break
        self._arm_cli = client

        client = self._node.create_client(Motion, f'/motion')
        while not client.wait_for_service(timeout_sec=1.0):
            self._node.get_logger().info(f'{self._node.get_name()} Waiting for /motion')
            break
        self._motion_cli = client

        self.init_ui()

        self._timer = QTimer(self)
        self._timer.timeout.connect(self._timerCallback)
        self._timer.start(100)

        self._recording = False
        self._videoout = None

    def _timerCallback(self):
        try:
            rclpy.spin_once(self._node, timeout_sec=0)  # deal with subscription callbacks
            print("spun")
        except Exception as e:
            print(f'rclpy spin_once fails (likely rclpy closed down) Exception {e}') 
            sys.exit()

    def _image_callback(self, msg):
        print("image callback called")
        image = self._bridge.imgmsg_to_cv2(msg, "bgr8")

        if self._recording:
            if self._videoout is None:
                shape = image.shape
                self._videoout = cv2.VideoWriter(f'{round(time.time()*1000)}.avi', cv2.VideoWriter_fourcc(*'MJPG'), 30, (shape[1], shape[0]))
            self._videoout.write(image)

        x = cv2.resize(image, (0,0), fx=0.25, fy=0.25)
        if self._recording:
            cv2.circle(x, (20, 20), 5, (0, 0, 255), -1)
        cv2.imshow('image', image)
        cv2.waitKey(3)

    def init_ui(self):
        self.setWindowTitle(f'blue_ui')
        self.setStyleSheet("background-color: white;")
        layout = QVBoxLayout()

        layout.addWidget(QLabel("Arm/Disarm"), alignment=Qt.AlignmentFlag.AlignHCenter)

        ad = QHBoxLayout()
        armButton = QPushButton("Arm")
        ad.addWidget(armButton, alignment=Qt.AlignmentFlag.AlignHCenter)
        armButton.clicked.connect(self._requestArm)

        disarmButton = QPushButton("Disarm")
        ad.addWidget(disarmButton, alignment=Qt.AlignmentFlag.AlignHCenter)
        disarmButton.clicked.connect(self._requestDisarm)
        layout.addLayout(ad)

        layout.addWidget(QLabel(""), alignment=Qt.AlignmentFlag.AlignHCenter)
        layout.addWidget(QLabel("Lights"), alignment=Qt.AlignmentFlag.AlignHCenter)

        lt = QHBoxLayout()
        lightsOnButton = QPushButton("On")
        lt.addWidget(lightsOnButton, alignment=Qt.AlignmentFlag.AlignHCenter)
        lightsOnButton.clicked.connect(self._requestLightsOn)

        lightsOffButton = QPushButton("Off")
        lt.addWidget(lightsOffButton, alignment=Qt.AlignmentFlag.AlignHCenter)
        lightsOffButton.clicked.connect(self._requestLightsOff)
        layout.addLayout(lt)

        layout.addWidget(QLabel(""), alignment=Qt.AlignmentFlag.AlignHCenter)
        layout.addWidget(QLabel("Recording"), alignment=Qt.AlignmentFlag.AlignHCenter)

        rec = QHBoxLayout()
        recordingOnButton = QPushButton("On")
        rec.addWidget(recordingOnButton, alignment=Qt.AlignmentFlag.AlignHCenter)
        lightsOnButton.clicked.connect(self._requestRecordingOn)

        recordingOffButton = QPushButton("Off")
        rec.addWidget(recordingOffButton, alignment=Qt.AlignmentFlag.AlignHCenter)
        recordingOffButton.clicked.connect(self._requestRecordingOff)
        layout.addLayout(rec)

        layout.addWidget(QLabel(""), alignment=Qt.AlignmentFlag.AlignHCenter)
        layout.addWidget(QLabel("Horizontal Control"), alignment=Qt.AlignmentFlag.AlignHCenter)

        joystick = QGridLayout()
        up_button = QPushButton(self)
        up_button.setIcon(self._up_icon)
        up_button.setIcon(QIcon(self._up_icon))
        down_button = QPushButton(self)
        down_button.setIcon(QIcon(self._down_icon))
        left_button = QPushButton(self)
        left_button.setIcon(QIcon(self._left_icon))
        right_button = QPushButton(self)
        right_button.setIcon(QIcon(self._right_icon))
        diag_up_left_button = QPushButton(self)
        diag_up_left_button.setIcon(QIcon(self._diag_up_left_icon))
        diag_up_right_button = QPushButton(self)
        diag_up_right_button.setIcon(QIcon(self._diag_up_right_icon))
        stop_button = QPushButton(self)
        stop_button.setIcon(QIcon(self._stop_icon))
        joystick.addWidget(diag_up_left_button, 0, 0, alignment=Qt.AlignmentFlag.AlignHCenter)
        joystick.addWidget(up_button, 0, 1, alignment=Qt.AlignmentFlag.AlignHCenter)
        joystick.addWidget(diag_up_right_button, 0, 2, alignment=Qt.AlignmentFlag.AlignHCenter)
        joystick.addWidget(left_button, 1, 0, alignment=Qt.AlignmentFlag.AlignHCenter)
        joystick.addWidget(stop_button, 1, 1, alignment=Qt.AlignmentFlag.AlignHCenter)
        joystick.addWidget(right_button, 1, 2, alignment=Qt.AlignmentFlag.AlignHCenter)
        joystick.addWidget(down_button, 2, 1, alignment=Qt.AlignmentFlag.AlignHCenter)
        button_size = 40
        for button in [up_button, down_button, left_button, right_button,
                       diag_up_left_button, diag_up_right_button, stop_button]:
            button.setIconSize(QSize(button_size, button_size))
            button.setFixedSize(button_size, button_size)

        up_button.clicked.connect(lambda: self._move_robot('forward'))
        down_button.clicked.connect(lambda: self._move_robot('reverse'))
        left_button.clicked.connect(lambda: self._move_robot('swayLeft'))
        right_button.clicked.connect(lambda: self._move_robot('swayRight'))
        diag_up_left_button.clicked.connect(lambda: self._move_robot('yawLeft'))
        diag_up_right_button.clicked.connect(lambda: self._move_robot('yawRight'))
        stop_button.clicked.connect(lambda: self._move_robot('stop'))

        layout.addLayout(joystick)
        
        layout.addWidget(QLabel(""), alignment=Qt.AlignmentFlag.AlignHCenter)
        layout.addWidget(QLabel("Vertical Control"), alignment=Qt.AlignmentFlag.AlignHCenter)
        up = QPushButton("Up")
        layout.addWidget(up, alignment=Qt.AlignmentFlag.AlignHCenter)
        up.clicked.connect(lambda: self._move_robot('up'))
        stop = QPushButton("Stop")
        layout.addWidget(stop, alignment=Qt.AlignmentFlag.AlignHCenter)
        stop.clicked.connect(lambda: self._move_robot('stop'))
        down = QPushButton("Down")
        layout.addWidget(down, alignment=Qt.AlignmentFlag.AlignHCenter)
        down.clicked.connect(lambda: self._move_robot('down'))

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

#        self.setFixedSize(self.size())

    def _requestArm(self):
        self._node.get_logger().info(f'{self._node.get_name()} requesting to arm ')
        arm_req = Arm.Request()
        arm_req.arm = True
        future = self._arm_cli.call_async(arm_req) # ignoring the future

    def _requestDisarm(self):
        self._node.get_logger().info(f'{self._node.get_name()} requesting to disarm')
        arm_req = Arm.Request()
        arm_req.arm = False
        future = self._arm_cli.call_async(arm_req) # ignoring the future

    def _requestLightsOn(self):
        self._node.get_logger().info(f'{self._node.get_name()} requesting to turn lights on ')
        lights_req = Lights.Request()
        lights_req.turn_on = True
        future = self._set_lights_cli.call_async(lights_req) # ignoring the future

    def _requestLightsOff(self):
        self._node.get_logger().info(f'{self._node.get_name()} requesting to turn lights off')
        lights_req = Lights.Request()
        lights_req.turn_on = False
        future = self._set_lights_cli.call_async(lights_req) # ignoring the future

    def _requestRecordingOn(self):
        self._recording = True

    def _requestRecordingOff(self):
        self._recording = False
        if self._videoout is not None:
            self._videoout.release()
            self._videoout = None

    def _move_robot(self, direction):
        self._node.get_logger().info(f'{self._node.get_name()} direction is {direction}')
        self._motion_req = Motion.Request()
        self._motion_req.command = direction
        self._future = self._motion_cli.call_async(self._motion_req) # ignoring the future

def main():
    rclpy.init()
    app = QApplication(sys.argv)
    gui = RobotControlGUI()
    gui.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
