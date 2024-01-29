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
from tkinter import Frame, Button, Label, PhotoImage, RAISED
import PIL.Image
import PIL.ImageTk



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
        self._root.maxsize(900, 600)
        self._root.config(bg="skyblue")

        left_frame = Frame(self._root, width=300, height=600, bg='black')
        left_frame.grid(row=0, column=0, padx=10, pady=10)

        centre_frame = Frame(self._root, width=200, height=400, bg='black')
        centre_frame.grid(row=0, column=1, padx=10, pady=10)

        right_frame=Frame(self._root, width=200, height=400, bg='white')
        right_frame.grid(row=0, column=2, padx=10, pady=10)

        up_down_frame =  Frame(self._root, width=200, height=400, bg='black')
        up_down_frame.grid(row=0, column=3, padx=10, pady=10)

        light_frame = Frame(left_frame, width=200,height=50, bg="grey")
        light_frame.grid(row=0, column=0, padx=5, pady=5)
        Label(light_frame, text="Light", relief=RAISED).grid(row=0, column=0)
        Button(light_frame, text ="On", command=self._requestLightsOn).grid(row=0, column=1)
        Button(light_frame, text="Off", command=self._requestLightsOff).grid(row=0, column=2)

        arm_frame = Frame(left_frame, width=200,height=50, bg="grey")
        arm_frame.grid(row=1, column=0, padx=5, pady=5)
        Label(arm_frame, text="Robot").grid(row=1, column=0)
        Button(arm_frame, text ="Arm", command=self._requestArm).grid(row=1, column=1)
        Button(arm_frame, text="Disarm", command=self._requestDisarm).grid(row=1, column=2)

        video_frame = Frame(left_frame, width=200,height=50, bg="grey")
        video_frame.grid(row=2, column=0, padx=5, pady=5)
        Label(video_frame, text="Video").grid(row=2, column=0)
        Button(video_frame, text ="Record", command=self._requestRecordingOn).grid(row=2, column=1)
        Button(video_frame, text="Off", command=self._requestRecordingOff).grid(row=2, column=2)

        tilt_frame = Frame(left_frame, width=200,height=50, bg="grey")
        tilt_frame.grid(row=3, column=0, padx=5, pady=5)
        Label(tilt_frame, text="Camera Tilt").grid(row=2, column=0)
        Button(tilt_frame, text ="Up", command=(lambda: self._move_robot("tiltUp"))).grid(row=2, column=1)
        Button(tilt_frame, text="Horizontal", command=(lambda: self._move_robot("tiltCenter"))).grid(row=2, column=2)
        Button(tilt_frame, text="Down", command=(lambda: self._move_robot("tiltDown"))).grid(row=2, column=3)

        self._keep = PIL.ImageTk.PhotoImage(PIL.Image.new('RGB', (320, 180), 'black'))
        self._label_image = Label(right_frame, image=self._keep)
        self._label_image.grid(row=0,column=0)
        self._image = None

        home = get_package_share_directory('bluey_tools')
        self.get_logger().info(f'{self.get_name()} You are loading from {home}/')
        self._stop_icon = PhotoImage(file=f"{home}/stop-96.png").subsample(2, 2)
        self._up_icon = PhotoImage(file=f"{home}/up-100.png").subsample(2, 2)
 
        self._down_icon = PhotoImage(file=f"{home}/down-100.png").subsample(2, 2)
        self._left_icon = PhotoImage(file=f"{home}/left-100.png").subsample(2, 2)
        self._right_icon = PhotoImage(file=f"{home}/right-100.png").subsample(2, 2)
        self._diag_up_left_icon = PhotoImage(file=f"{home}/up-left-100.png").subsample(2, 2)
        self._diag_up_right_icon = PhotoImage(file=f"{home}/up-right-100.png").subsample(2, 2)

        plane_frame = Frame(centre_frame, width=300, height=300)
        plane_frame.grid(row=0,column=0,padx=5,pady=5)
        Button(plane_frame, image=self._diag_up_left_icon, command=(lambda: self._move_robot('yawLeft'))).grid(row=0, column=0)
        Button(plane_frame, image=self._up_icon, command=(lambda: self._move_robot('forward'))).grid(row=0, column=1)
        Button(plane_frame, image=self._diag_up_right_icon, command=(lambda: self._move_robot('yawRight'))).grid(row=0, column=2)
        Button(plane_frame, image=self._left_icon, command=(lambda: self._move_robot('swayLeft'))).grid(row=1, column=0)
        Button(plane_frame, image=self._stop_icon, command=(lambda: self._move_robot('stop'))).grid(row=1, column=1)
        Button(plane_frame, image=self._right_icon, command=(lambda: self._move_robot('swayRight'))).grid(row=1, column=2)
        Button(plane_frame, image=self._down_icon, command=(lambda: self._move_robot('reverse'))).grid(row=2, column=1)

        arrow_frame = Frame(up_down_frame, width=100, height=300)
        arrow_frame.grid(row=0,column=0,padx=5,pady=5)
        Button(arrow_frame, image=self._up_icon, command=(lambda: self._move_robot('up'))).grid(row=0, column=0)
        Button(arrow_frame, image=self._stop_icon, command=(lambda: self._move_robot('stop'))).grid(row=1, column=0)
        Button(arrow_frame, image=self._down_icon, command=(lambda: self._move_robot('down'))).grid(row=2, column=0)


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
