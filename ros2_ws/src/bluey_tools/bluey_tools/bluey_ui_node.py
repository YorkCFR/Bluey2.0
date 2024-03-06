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
from tkinter import Frame, Button, Label, PhotoImage, RAISED, IntVar, Checkbutton, LEFT
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
        self._mode = IntVar()
        self._arm = IntVar()
        self._speed = IntVar()
        self._video = IntVar()
        self._lights = IntVar()

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

        # create client for commands
        client = self.create_client(Commands, f'/commands')
        while not client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info(f'{self.get_name()} Waiting for /commands')
            break
        self._commands_cli = client

        # deal with video
        self.declare_parameter('image', "/mycamera/image_raw")
        self._image_topic = self.get_parameter('image').get_parameter_value().string_value
        self.create_subscription(Image, self._image_topic, self._image_callback, 1)

        self._create_gui()
        self._root.after(33, self._tk_timer)
        self.get_logger().info(f"Node created")

    def _create_gui(self):
        self._root.title("Bluey V1.1")
        self._root.maxsize(900, 800)
        self._root.config(bg="skyblue")

        left_frame = Frame(self._root, width=300, height=800, bg='red')
        left_frame.grid(row=0, column=0, padx=10, pady=10)

        centre_frame = Frame(self._root, width=200, height=400, bg='black')
        centre_frame.grid(row=0, column=1, padx=10, pady=10)

        right_frame=Frame(self._root, width=200, height=400, bg='white')
        right_frame.grid(row=0, column=2, padx=10, pady=10)

        up_down_frame =  Frame(self._root, width=200, height=400, bg='black')
        up_down_frame.grid(row=0, column=3, padx=10, pady=10)

        light_frame = Frame(left_frame, width=200,height=50, bg="black")
        light_frame.grid(row=0, column=0, padx=5, pady=5)
        Label(light_frame, text="Light", relief=RAISED).pack(side=LEFT, padx=5)
        Checkbutton(light_frame, text ="On", variable=self._lights, onvalue=0, command=self._requestLights).pack(side=LEFT, padx=5)
        Checkbutton(light_frame, text="Off", variable=self._lights, onvalue=1, command=self._requestLights).pack(side=LEFT, padx=5)
        self._lights.set(1)
        self._requestLights() # turns lights off

        arm_frame = Frame(left_frame, width=200,height=50, bg="black")
        arm_frame.grid(row=1, column=0, padx=5, pady=5)
        Label(arm_frame, text="Robot").pack(side=LEFT, padx=5)
        Checkbutton(arm_frame, text="Arm", variable=self._arm, onvalue=0, command=self._requestArm).pack(side=LEFT, padx=5)
        Checkbutton(arm_frame, text="Disarm", variable=self._arm, onvalue=1, command=self._requestArm).pack(side=LEFT, padx=5)
        self._arm.set(1)
        self._requestArm() # unarms robot

        video_frame = Frame(left_frame, width=200,height=50, bg="black")
        video_frame.grid(row=2, column=0, padx=5, pady=5)
        Label(video_frame, text="Video").pack(side=LEFT, padx=5)
        Checkbutton(video_frame, text ="Rec", onvalue=1, variable=self._video, command=self._requestRecording).pack(side=LEFT, padx=5)
        Checkbutton(video_frame, text="Off", onvalue=2, variable=self._video, command=self._requestRecording).pack(side=LEFT, padx=5)
        self._video.set(2)
        self._requestRecording() # not recording

        tilt_frame = Frame(left_frame, width=200,height=50, bg="black")
        tilt_frame.grid(row=3, column=0, padx=5, pady=5)
        Label(tilt_frame, text="Camera Tilt").pack(side=LEFT, padx=5)
        Button(tilt_frame, text ="Up", command=(lambda: self._move_robot("tiltUp"))).pack(side=LEFT, padx=5)
        Button(tilt_frame, text="Stop", command=(lambda: self._move_robot("tiltCenter"))).pack(side=LEFT, padx=5)
        Button(tilt_frame, text="Down", command=(lambda: self._move_robot("tiltDown"))).pack(side=LEFT, padx=5)

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

        mode_frame = Frame(left_frame, width=200,height=50, bg="black")
        mode_frame.grid(row=4, column=0, padx=5, pady=5)
        Checkbutton(mode_frame, text="MAN", variable=self._mode, onvalue=0, command=self._requestMode).pack(side=LEFT, padx=5)
        Checkbutton(mode_frame, text="STB", variable=self._mode, onvalue=1, command=self._requestMode).pack(side=LEFT, padx=5)
        Checkbutton(mode_frame, text="ALT", variable=self._mode, onvalue=2, command=self._requestMode).pack(side=LEFT, padx=5)
        self._mode.set(0)
        self._requestMode()

        speed_frame = Frame(left_frame, width=200,height=50, bg="black")
        speed_frame.grid(row=5, column=0, padx=5, pady=5)
        Label(speed_frame, text="Speed").pack(side=LEFT, padx=5)
        Checkbutton(speed_frame, text="SLOW", variable=self._speed, onvalue=0, command=self._requestSpeed).pack(side=LEFT, padx=5)
        Checkbutton(speed_frame, text="MED", variable=self._speed, onvalue=1, command=self._requestSpeed).pack(side=LEFT, padx=5)
        Checkbutton(speed_frame, text="FAST", variable=self._speed, onvalue=2, command=self._requestSpeed).pack(side=LEFT, padx=5)
        self._speed.set(0)
        self._requestSpeed()


    def _requestSpeed(self):
        """change the robot mode as requested"""
        self.get_logger().info(f'{self.get_name()} requesting speed {self._speed.get()}')
        speeds = [30, 40, 50]
        commands_req = Commands.Request()
        commands_req.command = 'setSpeed'
        commands_req.arg = str(speeds[self._speed.get()])
        future = self._commands_cli.call_async(commands_req) # ignoring the future
        print(f"Mode set to {commands_req.arg} {self._mode.get()}")

    def _requestMode(self):
        """change the robot mode as requested"""
        modes = ["MANUAL", "STABILIZE", "ALT_HOLD"]
        commands_req = Commands.Request()
        commands_req.command = 'setMode'
        commands_req.arg = modes[self._mode.get()]
        future = self._commands_cli.call_async(commands_req) # ignoring the future
        print(f"Mode set to {commands_req.arg} {self._mode.get()}")

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

    def _requestLights(self):
        if self._lights.get() == 0:
            self._requestLightsOn()
        else:
            self._requestLightsOff()

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
        self.get_logger().info(f'{self.get_name()} requesting to arm {self._arm.get()}')
        
        arm_req = Arm.Request()
        if self._arm.get() == 0: # arm
            arm_req.arm = True
        else:
            arm_req.arm = False
        future = self._arm_cli.call_async(arm_req) # ignoring the future


    def _move_robot(self, direction):
        self.get_logger().info(f'{self.get_name()} direction is {direction}')
        self._motion_req = Motion.Request()
        self._motion_req.command = direction
        self._future = self._motion_cli.call_async(self._motion_req) # ignoring the future

    def _requestRecording(self):
        if self._video.get() == 1:
            self._requestRecordingOn()
        else:
            self._requestRecordingOff()

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
