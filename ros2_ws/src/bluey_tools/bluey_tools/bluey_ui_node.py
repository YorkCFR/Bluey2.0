import sys
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
import math
import time
from rclpy import qos
from std_msgs.msg import String, Float32
from geometry_msgs.msg import Twist
from ament_index_python.packages import get_package_share_directory
import cv2
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
from std_msgs.msg import Bool
from std_msgs.msg import String
from bluey_interface.srv import Lights, Arm, Motion, Commands

import tkinter as tk
from tkinter import Frame, Button, Label, PhotoImage
import PIL.Image
import PIL.ImageTk


# used in debugging, now not needed
#class Color(QWidget):
#    def __init__(self, color):
#        super().__init__()
#        self.setAutoFillBackground(True)
#        palette = self.palette()
#        palette.setColor(QPalette.Window, QColor(color))
#        self.setPalette(palette)
#
#class RobotControlGUI(QMainWindow):
#    def __init__(self):
#        super().__init__()
#        self._node = rclpy.create_node('blue_ui_node')
#
#        home = get_package_share_directory('bluey_tools')
#        self._node.get_logger().info(f'{self._node.get_name()} You are loading from {home}/')
#        self._stop_icon = QPixmap(f"{home}/stop-96.png").scaled(96, 96)
#        self._up_icon = QIcon(QPixmap(f"{home}/up-100.png"))
#        self._down_icon = QIcon(QPixmap(f"{home}/down-100.png"))
#        self._left_icon = QIcon(QPixmap(f"{home}/left-100.png"))   
#        self._right_icon = QIcon(QPixmap(f"{home}/right-100.png"))
#        self._diag_up_left_icon = QIcon(QPixmap(f"{home}/up-left-100.png")
#        self._diag_up_right_icon = QIcon(QPixmap(f"{home}/up-right-100.png"))
#
#        self._node.declare_parameter('image', "/mycamera/image_raw")
#        self._image_topic = self._node.get_parameter('image').get_parameter_value().string_value
#        self._node.create_subscription(Image, self._image_topic, self._image_callback, 1)
#
#        client = self._node.create_client(Lights, f'/set_lights')
#        while not client.wait_for_service(timeout_sec=1.0):
#            self._node.get_logger().info(f'{self._node.get_name()} Waiting for /set_lights')
#            break
#        self._set_lights_cli = client
#
#        client = self._node.create_client(Arm, f'/arm')
#        while not client.wait_for_service(timeout_sec=1.0):
#            self._node.get_logger().info(f'{self._node.get_name()} Waiting for /arm')
#            break
#        self._arm_cli = client
#
#        client = self._node.create_client(Motion, f'/motion')
#        while not client.wait_for_service(timeout_sec=1.0):
#            self._node.get_logger().info(f'{self._node.get_name()} Waiting for /motion')
#            break
#        self._motion_cli = client
#
#        self.init_ui()
#
#        self._timer = QTimer(self)
#        self._timer.timeout.connect(self._timerCallback)
#        self._timer.start(100)
#
#        self._recording = False
#        self._videoout = None
#
#    def _timerCallback(self):
#        try:
#            rclpy.spin_once(self._node, timeout_sec=10)  # deal with subscription callbacks
#            print("spun")
#        except Exception as e:
#            print(f'rclpy spin_once fails (likely rclpy closed down) Exception {e}') 
#            sys.exit()
#
#    def _image_callback(self, msg):
#        print("image callback called")
#        image = self._bridge.imgmsg_to_cv2(msg, "bgr8")
#
#        if self._recording:
#            if self._videoout is None:
#                shape = image.shape
#                self._videoout = cv2.VideoWriter(f'{round(time.time()*1000)}.avi', cv2.VideoWriter_fourcc(*'MJPG'), 30, (shape[1], shape[0]))
#            self._videoout.write(image)
#
#        x = cv2.resize(image, (0,0), fx=0.25, fy=0.25)
#        if self._recording:
#            cv2.circle(x, (20, 20), 5, (0, 0, 255), -1)
#        cv2.imshow('image', image)
#        cv2.waitKey(3)
#
#
#        layout.addWidget(QLabel(""), alignment=Qt.AlignmentFlag.AlignHCenter)
#        layout.addWidget(QLabel("Recording"), alignment=Qt.AlignmentFlag.AlignHCenter)
#
#        rec = QHBoxLayout()
#        recordingOnButton = QPushButton("On")
#        rec.addWidget(recordingOnButton, alignment=Qt.AlignmentFlag.AlignHCenter)
#        lightsOnButton.clicked.connect(self._requestRecordingOn)
#
#        recordingOffButton = QPushButton("Off")
#        rec.addWidget(recordingOffButton, alignment=Qt.AlignmentFlag.AlignHCenter)
#        recordingOffButton.clicked.connect(self._requestRecordingOff)
#        layout.addLayout(rec)
#
#        layout.addWidget(QLabel(""), alignment=Qt.AlignmentFlag.AlignHCenter)
#        layout.addWidget(QLabel("Horizontal Control"), alignment=Qt.AlignmentFlag.AlignHCenter)
#
#        joystick = QGridLayout()
#        up_button = QPushButton(self)
#        up_button.setIcon(self._up_icon)
#        up_button.setIcon(QIcon(self._up_icon))
#        down_button = QPushButton(self)
#        down_button.setIcon(QIcon(self._down_icon))
#        left_button = QPushButton(self)
#        left_button.setIcon(QIcon(self._left_icon))
#        right_button = QPushButton(self)
#        right_button.setIcon(QIcon(self._right_icon))
#        diag_up_left_button = QPushButton(self)
#        diag_up_left_button.setIcon(QIcon(self._diag_up_left_icon))
#        diag_up_right_button = QPushButton(self)
#        diag_up_right_button.setIcon(QIcon(self._diag_up_right_icon))
#        stop_button = QPushButton(self)
#        stop_button.setIcon(QIcon(self._stop_icon))
#        joystick.addWidget(diag_up_left_button, 0, 0, alignment=Qt.AlignmentFlag.AlignHCenter)
#        joystick.addWidget(up_button, 0, 1, alignment=Qt.AlignmentFlag.AlignHCenter)
#        joystick.addWidget(diag_up_right_button, 0, 2, alignment=Qt.AlignmentFlag.AlignHCenter)
#        joystick.addWidget(left_button, 1, 0, alignment=Qt.AlignmentFlag.AlignHCenter)
#        joystick.addWidget(stop_button, 1, 1, alignment=Qt.AlignmentFlag.AlignHCenter)
#        joystick.addWidget(right_button, 1, 2, alignment=Qt.AlignmentFlag.AlignHCenter)
#        joystick.addWidget(down_button, 2, 1, alignment=Qt.AlignmentFlag.AlignHCenter)
#        button_size = 40
#        for button in [up_button, down_button, left_button, right_button,
#                       diag_up_left_button, diag_up_right_button, stop_button]:
#            button.setIconSize(QSize(button_size, button_size))
#            button.setFixedSize(button_size, button_size)
#
#        up_button.clicked.connect(lambda: self._move_robot('forward'))
#        down_button.clicked.connect(lambda: self._move_robot('reverse'))
#        left_button.clicked.connect(lambda: self._move_robot('swayLeft'))
#        right_button.clicked.connect(lambda: self._move_robot('swayRight'))
#        diag_up_left_button.clicked.connect(lambda: self._move_robot('yawLeft'))
#        diag_up_right_button.clicked.connect(lambda: self._move_robot('yawRight'))
#        stop_button.clicked.connect(lambda: self._move_robot('stop'))
#
#        layout.addLayout(joystick)
#        
#        layout.addWidget(QLabel(""), alignment=Qt.AlignmentFlag.AlignHCenter)
#        layout.addWidget(QLabel("Vertical Control"), alignment=Qt.AlignmentFlag.AlignHCenter)
#        up = QPushButton("Up")
#        layout.addWidget(up, alignment=Qt.AlignmentFlag.AlignHCenter)
#        up.clicked.connect(lambda: self._move_robot('up'))
#        stop = QPushButton("Stop")
#        layout.addWidget(stop, alignment=Qt.AlignmentFlag.AlignHCenter)
#        stop.clicked.connect(lambda: self._move_robot('stop'))
#        down = QPushButton("Down")
#        layout.addWidget(down, alignment=Qt.AlignmentFlag.AlignHCenter)
#        down.clicked.connect(lambda: self._move_robot('down'))
#
#        widget = QWidget()
#        widget.setLayout(layout)
#        self.setCentralWidget(widget)
#
##        self.setFixedSize(self.size())
#
#
#    def _requestRecordingOn(self):
#        self._recording = True
#
#    def _requestRecordingOff(self):
#        self._recording = False
#        if self._videoout is not None:
#            self._videoout.release()
#            self._videoout = None
#

class GuiNode(Node):
    def __init__(self, root):
        super().__init__("debug_node")
        self._root = root
        self._recording = False
        self._videoout = None
        self._image = None
        self._bridge = CvBridge()

        # create client for lights
        client = self.create_client(Lights, f'/set_lights')
        while not client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info(f'{self.get_name()} Waiting for /set_lights')
            break
        self._set_lights_cli = client

        # create client for arm
        client = self.create_client(Arm, f'/arm')
        while not client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info(f'{self.get_name()} Waiting for /arm')
            break
        self._arm_cli = client

        # create client for motion
        client = self.create_client(Motion, f'/motion')
        while not client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info(f'{self.get_name()} Waiting for /motion')
            break
        self._motion_cli = client

        # deal with video
        self.declare_parameter('image', "/mycamera/image_raw")
        self._image_topic = self.get_parameter('image').get_parameter_value().string_value
        self.create_subscription(Image, self._image_topic, self._image_callback, 1)

        self._create_gui()
        self._root.after(33, self._tk_timer)
        self.get_logger().info(f"Node created")


    def _create_gui(self):
        self._root.title("Bluey V1.0")
        self._root.maxsize(600, 600)
        self._root.config(bg="skyblue")

      
        button_frame = Frame(self._root, width=100,height=50, bg="grey").grid(row=0, column=0, padx=5, pady=5)
        Label(button_frame, text="Light").grid(row=0, column=0)
        Button(button_frame, text ="On", command=self._requestLightsOn).grid(row=0, column=1)
        Button(button_frame, text="Off", command=self._requestLightsOff).grid(row=0, column=2)

        arm_frame = Frame(self._root, width=100,height=50, bg="grey").grid(row=1, column=0, padx=5, pady=5)
        Label(arm_frame, text="Robot").grid(row=1, column=0)
        Button(arm_frame, text ="Arm", command=self._requestArm).grid(row=1, column=1)
        Button(arm_frame, text="Disarm", command=self._requestDisarm).grid(row=1, column=2)

        video_frame = Frame(self._root, width=100,height=50, bg="grey").grid(row=2, column=0, padx=5, pady=5)
        Label(video_frame, text="Video").grid(row=2, column=0)
        Button(video_frame, text ="Record", command=self._requestRecordingOn).grid(row=2, column=1)
        Button(video_frame, text="Off", command=self._requestRecordingOff).grid(row=2, column=2)

        self._keep = PIL.ImageTk.PhotoImage(PIL.Image.new('RGB', (320, 180), 'black'))
        self._label_image = Label(image=self._keep)
        self._label_image.grid(row=3,column=0)
        self._image = None

        home = get_package_share_directory('bluey_tools')
        self.get_logger().info(f'{self.get_name()} You are loading from {home}/')
        self._stop_icon = PhotoImage(file=f"{home}/stop-96.png")
        self._up_icon = PhotoImage(file=f"{home}/up-100.png")
        self._down_icon = PhotoImage(file=f"{home}/down-100.png")
        self._left_icon = PhotoImage(file=f"{home}/left-100.png")
        self._right_icon = PhotoImage(file=f"{home}/right-100.png")
        self._diag_up_left_icon = PhotoImage(file=f"{home}/up-left-100.png")
        self._diag_up_right_icon = PhotoImage(file=f"{home}/up-right-100.png")

    def _photo_image(self, image):
        height, width = image.shape[:2]
        ppm_header = f'P6 {width} {height} 255 '.encode()
        data = ppm_header + cv2.cvtColor(image, cv2.COLOR_BGR2RGB).tobytes()
        return tk.PhotoImage(width=width, height=height, data=data, format= 'PPM')

    def _tk_timer(self):
        try:
            rclpy.spin_once(self, timeout_sec=0)  # deal with subscription callbacks
        except Exception as e:
            print(e)
        if self._image is not None:
            self._keep = self._photo_image(self._image)
            self._label_image.configure(image=self._keep)

        self._root.after(33, self._tk_timer)

    def _requestLightsOn(self):
        self.get_logger().info(f'{self.get_name()} requesting to turn lights on ')
        lights_req = Lights.Request()
        lights_req.turn_on = True
        future = self._set_lights_cli.call_async(lights_req) # ignoring the future

    def _requestLightsOff(self):
        self.get_logger().info(f'{self.get_name()} requesting to turn lights off')
        lights_req = Lights.Request()
        lights_req.turn_on = False
        future = self._set_lights_cli.call_async(lights_req) # ignoring the future

    def _requestArm(self):
        self.get_logger().info(f'{self.get_name()} requesting to arm ')
        arm_req = Arm.Request()
        arm_req.arm = True
        future = self._arm_cli.call_async(arm_req) # ignoring the future

    def _requestDisarm(self):
        self.get_logger().info(f'{self.get_name()} requesting to disarm')
        arm_req = Arm.Request()
        arm_req.arm = False
        future = self._arm_cli.call_async(arm_req) # ignoring the future

    def _move_robot(self, direction):
        self.get_logger().info(f'{self.get_name()} direction is {direction}')
        self._motion_req = Motion.Request()
        self._motion_req.command = direction
        self._future = self._motion_cli.call_async(self._motion_req) # ignoring the future

    def _requestRecordingOn(self):
        self.get_logger().info(f'{self.get_name()} Recording on')
        self._recording = True

    def _requestRecordingOff(self):
        self.get_logger().info(f'{self.get_name()} Recording off')
        self._recording = False
        if self._videoout is not None:
            self._videoout.release()
            self._videoout = None

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
        self._image = x


def main():
    rclpy.init(args=None)

    root = tk.Tk()
    node = GuiNode(root)
    root.mainloop()

if __name__ == '__main__':
    main()
