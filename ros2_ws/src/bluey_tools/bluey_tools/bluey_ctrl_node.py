import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
from std_msgs.msg import String
from bluey_interface.srv import Lights, Arm, Motion, Commands


from pymavlink import mavutil
import json

#
# This is a wrapper to access the BlueROV with the PixHawk controller
# It is based on various libraries that were scoured from the web. 
# It's not very clever. Just something to get the job done
#
# This basically uses the mavlilnk library to talk to the PixHawk
# Documentation on the navlink software can be found at
# https://mavlink.io But essentially you communicate with the device
# by setting PWM values for n servos.  'servo_n' is the AUX port to set 
# (assumes port is configured as a servo).  Valid values are 1-3 in a normal 
# BlueROV2 setup, but can go up to 8 depending on Pixhawk type and firmware.
# 'microseconds' is the PWM pulse-width to set the output to. Commonly
# between 1100 and 1900 microseconds.
#
# For the BLueROV
#    RC Inputs:
#    1 -> Pitch
#    2 -> Roll
#    3 -> Throttle
#    4 -> Yaw
#    5 -> Forward
#    6 -> Lateral (strafe?)
#    7 -> reserved
#    8 -> camera tilt
#    9 -> lights 1 level
#    10 -> lights 2 level
#
# Note that these are all based on Pitch=0 in the software. Use the defined
# constants to query/manipulate parameters
#
# Where values are
#    1100 = full dir1, 1900 = full dir2, 1500 = stop
# These constants are defined in the class below
#
# For the camera tilt, 1500 is neutral, 1100 and 1900 are the limits
#    not what seems to be true works like the other motors????
#
# The BlueROV operates in one of three modes
#    Manual mode - all up to the operator
#    Stabilized mode - maintain roll to level and maintain heading
#    Depth mode - maintain depth
# 


class BlueyCtrlNode(Node):
    _LIGHT_SERVO = 1  # + 8
    _SWAY_SERVO = 6
    _FORWARD_SERVO = 5
    _YAW_SERVO = 4
    _HEAVE_SERVO = 3
    _CAMERA_TILT = 8
    _FULL_DIR1 = 1100
    _FULL_DIR2 = 1900
    _STOP = 1500
    _NCHANNELS = 18
    _LIGHT_ON_VALUE = 1500
    _LIGHT_OFF_VALUE = 1100
    _MAX_SPEED = 50
    _MIN_SPEED = 10
    _MODES = {'MANUAL' : -1, 'STABILIZE': -1, 'ALT_HOLD': -1}


    def __init__(self, debug=False):
        super().__init__('bluey_ctrl_node')
        self._debug = debug
        self.get_logger().info(f"{self.get_name()} created with debugging {self._debug}")
        self._data = {}

        self.declare_parameter('uri', 'udpin:0.0.0.0:14550')
        uri = self.get_parameter('uri').get_parameter_value().string_value

        #Connect to blueROV2 over MAVlink
        self._master = mavutil.mavlink_connection(uri)
        self._master.wait_heartbeat()
        self.get_logger().info(f"{self.get_name()} connected to robot")

        self._hearbeat_timer = self.create_timer(0.9, self._heartbeat)

        self._light_on = False
        self.create_service(Lights, f"/set_lights", self._handle_lights)

        # not armed
        self._armed = False
        self.disarm()
        self.create_service(Arm, f"/arm", self._handle_arm)

        self._speed = BlueyCtrlNode._MIN_SPEED  # default speed

        self.create_service(Motion, f"/motion", self._handle_motion)

        self.create_service(Commands, f"/commands", self._handle_commands)

        # find the mode numbers for the available modes and set mode to manual
        for k in BlueyCtrlNode._MODES.keys():
            BlueyCtrlNode._MODES[k] = self._master.mode_mapping()[k]
        self.setMode(mode='MANUAL')

    def _get_mode_name(self, mode_id):
        """associate name with mode_id""" 
        for k in BlueyCtrlNode._MODES:
            if BlueyCtrlNode._MODES[k] == mode_id:
                return k
        self.get_logger().info(f'{self.get_name()} invalid mode_id {mode_id}')
        return "UNKNOWN"

    def _handle_commands(self, request, response):
        """Deal with non motion commands"""
        self.get_logger().info(f'{self.get_name()} got a non-motion  {request.command}')
        response.result = ''
        response.status = True

        if request.command == 'getModes':
            response.result = json.dumps(list(BlueyCtrlNode._MODES.keys()))
        elif request.command == 'getMode':
            if 'HEARTBEAT' in self._data:
                custom_mode = self._data['HEARTBEAT']['custom_mode']
                response.result = self._get_mode_name(custom_mode)
            else:
                self.get_logger().info(f'{self.get_name()} No Heartbeat message (yet?)')
        elif request.command == 'setMode':
            self.setMode(mode=request.arg)
        elif request.command == 'getSpeed':
            response.result = str(self._speed)
        elif request.command == 'setSpeed':
            self.get_logger().info(f'{self.get_name()} set speed argument {request.arg}')
            speed = int(request.arg)
            if (speed <  BlueyCtrlNode._MIN_SPEED) or (speed > BlueyCtrlNode._MAX_SPEED):
                self.get_logger().info(f'{self.get_name()} set speed argument {request.arg} invalid, using min speed')
                speed = BlueyCtrlNode._MIN_SPEED
            self._speed = speed
        elif request == 'armed':
            response.result = self._armed
        else:
            self.get_logger().info(f'{self.get_name()} got an invalid  non-motion  {request.command}')
            response.status = True
        return response

    def _handle_motion(self, request, response):
        self.get_logger().info(f'{self.get_name()} got a motion command {request.command}')

        response.result = True
        if request.command == 'stop':
            self.clearMotion()
        elif request.command ==  'forward':
            self.forward(speed=self._speed)
        elif request.command ==  'reverse':
            self.reverse(speed=self._speed)
        elif request.command ==  'yawLeft':
            self.yawLeft(speed=self._speed)
        elif request.command ==  'yawRight':
            self.yawRight(speed=self._speed)
        elif request.command ==  'up':
            self.up(speed=self._speed)
        elif request.command ==  'down':
            self.down(speed=self._speed)
        elif request.command ==  'swayLeft':
            self.swayLeft(speed=self._speed)
        elif request.command ==  'swayRight':
            self.swayRight(speed=self._speed)
        elif request.command ==  'tiltUp':
            self.tiltCamera(100)
        elif request.command ==  'tiltDown':
            self.tiltCamera(-100)
        elif request.command ==  'tiltCenter':
            self.tiltCamera(0)
        else:
            self.get_logger().info(f'{self.get_name()} got a bad request {request.command} stopping')
            self.clearMotion()
            response.result = False

        return response

    def _handle_arm(self, request, response):
        self.get_logger().info(f'{self.get_name()} got a arm {request.arm}')

        if request.arm:
            if not self._armed:
                self.arm()
        else:
            if self._armed:
                self.disarm()
        self._armed = request.arm
        return response

    def _handle_lights(self, request, response):
        """Request to set or reset estop"""
        self.get_logger().info(f'{self.get_name()} got a lights message {request.turn_on}')

        if request.turn_on:
            if not self._light_on:
                self.lightOn()
        else:
            if self._light_on:
                self.lightOff()
        self._light_on = request.turn_on
        return response

    def _heartbeat(self):
        """Send a heartbeat wakeup to Bluey. Using ROS to schedule"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} hearbeat beating")
        self._master.mav.heartbeat_send(
            6, #MAVTYPE = MAV_TYPE_GCS
            8, #MAVAUTOPILOT = MAV_AUTOPILOT_INVALID
            128, # MAV_MODE = MAV_MODE_FLAG_SAFETY_ARMED, have also tried 0 here
            0,0)
        while True:
            msg = self._master.recv_match()
            if msg != None:
                key = msg.get_type()
                val = msg.to_dict()
                self._data[key] = val
            else:
                break


    def _set_servo_pwm(self, servo_n, microseconds):
        """ Sets AUX 'servo_n' output PWM pulse-width.

            Uses https://mavlink.io/en/messages/common.html#MAV_CMD_DO_SET_SERVO

            'servo_n' is the AUX port to set (assumes port is configured as a servo).
            Valid values are 1-3 in a normal BlueROV2 setup, but can go up to 8
            depending on Pixhawk type and firmware.
            'microseconds' is the PWM pulse-width to set the output to. Commonly
            between 1100 and 1900 microseconds.
            """
        if self._debug:
            self.get_logger().info(f"{self.get_name()} _set_servo_pwm {servo_n}")
        # master.set_servo(servo_n+8, microseconds) or:
        self._master.mav.command_long_send(
            self._master.target_system, self._master.target_component,
            mavutil.mavlink.MAV_CMD_DO_SET_SERVO,
            0,            # first transmission of this command
            servo_n + 8,  # servo instance, offset by 8 MAIN outputs
            microseconds, # PWM pulse-width
            0,0,0,0,0     # unused parameters
        )

    def _set_rc_channel_pwm(self, channel_id, pwm=None):
        """ Set RC channel pwm value
            Args:
                channel_id (TYPE): Channel ID
                pwm (int, optional): Channel pwm value 1100-1900 
        """
        if pwm is None:
            pwm = BlueyCtrlNode._STOP
        if self._debug:
            self.get_logger().info(f"{self.get_name()} _set_servo_pwm {servo_n}")
        
        if (channel_id < 0) or (channel_id >= BlueyCtrlNode._NCHANNELS):
            self.get_logger().info(f"{self.get_name()} _set_rc_channel {channel_id} does not exist")
            return

        # Mavlink 2 supports up to 18 channels:
        # https://mavlink.io/en/messages/common.html#RC_CHANNELS_OVERRIDE
        rc_channel_values = [65535 for _ in range(BlueyCtrlNode._NCHANNELS)]
        rc_channel_values[channel_id - 1] = pwm
        self._master.mav.rc_channels_override_send(
            self._master.target_system,                # target_system
            self._master.target_component,             # target_component
            *rc_channel_values)                  # RC channel list, in microseconds.


    def getAvailableModes(self):
        """Return available control modes"""
        return self._master.mode_mapping().keys()

    def setMode(self, mode='MANUAL'):
        """Set robot operating mode"""

        if mode not in self._master.mode_mapping():
            self.get_logger().info(f"{self.get_name()} setMode {mode} invalid")
        else:
            mode_id = self._master.mode_mapping()[mode]
            self._master.set_mode(mode_id)

    def clearMotion(self):
        """Disable all motion"""
        rc_channel_values = [65535 for _ in range(BlueyCtrlNode._NCHANNELS)]
        rc_channel_values[0] = BlueyCtrlNode._STOP  # pitch
        rc_channel_values[1] = BlueyCtrlNode._STOP  # roll
        rc_channel_values[2] = BlueyCtrlNode._STOP  # throttle
        rc_channel_values[3] = BlueyCtrlNode._STOP  # yaw
        rc_channel_values[4] = BlueyCtrlNode._STOP  # forward
        rc_channel_values[5] = BlueyCtrlNode._STOP  # lateral
        rc_channel_values[7] = BlueyCtrlNode._STOP  # Camera Tilt
        self._master.mav.rc_channels_override_send(
            self._master.target_system,                # target_system
            self._master.target_component,             # target_component
            *rc_channel_values)                  # RC channel list, in microseconds.

    def lightOn(self):
        """Turn the lights on"""
        self._set_servo_pwm(BlueyCtrlNode._LIGHT_SERVO, BlueyCtrlNode._LIGHT_ON_VALUE)
        self.get_logger().info(f"{self.get_name()} lights on")

    def lightOff(self):
        """Turn the lights off"""
        self._set_servo_pwm(BlueyCtrlNode._LIGHT_SERVO, BlueyCtrlNode._LIGHT_OFF_VALUE)
        self.get_logger().info(f"{self.get_name()} lights off")

    def arm(self):
        """Arm the robot (stay away from the spinning blades)"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} arming the robot")
        self.clearMotion()
        self._master.mav.command_long_send(
            self._master.target_system,
            self._master.target_component,
            mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
            0,
            1, 21196, 0, 0, 0, 0, 0)
        self._master.motors_armed_wait()
        
    def disarm(self):
        """Disarm the robot"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} disarming the robot")
        self.clearMotion()
        self._master.mav.command_long_send(
            self._master.target_system,
            self._master.target_component,
            mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
            0,
            0, 21196, 0, 0, 0, 0, 0)
        self._master.motors_disarmed_wait()
    
    def stop(self):
        """Stop moving"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} stopping the robot")
        self.clearMotion()
    
    def forward(self, speed=50):
        """Move forward at a sensible speed"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} moving the robot forward {speed}")
        self._set_rc_channel_pwm(BlueyCtrlNode._FORWARD_SERVO, BlueyCtrlNode._STOP + speed) 

    def reverse(self, speed=50):
        """Move in reverse at a sensible speed"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} moving the robot in reverse {speed}")
        self._set_rc_channel_pwm(BlueyCtrlNode._FORWARD_SERVO, BlueyCtrlNode._STOP - speed) 

    def yawLeft(self, speed=50):
        """Yaw left at a sensible speed"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} yaw to the left {speed}")
        self._set_rc_channel_pwm(BlueyCtrlNode._YAW_SERVO, BlueyCtrlNode._STOP - speed) 

    def yawRight(self, speed=50):
        """Yaw right at a sensible speed"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} yaw to the right {speed}")
        self._set_rc_channel_pwm(BlueyCtrlNode._YAW_SERVO, BlueyCtrlNode._STOP + speed) 

    def up(self, speed=50):
        """Move up at a sensible speed"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} moving the robot up {speed}")
        self._set_rc_channel_pwm(BlueyCtrlNode._HEAVE_SERVO, BlueyCtrlNode._STOP + speed) 

    def down(self, speed=50):
        """Move down at a sensible speed"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} moving the robot down {speed}")
        self._set_rc_channel_pwm(BlueyCtrlNode._HEAVE_SERVO, BlueyCtrlNode._STOP - speed) 

    def swayLeft(self, speed=50):
        """Move to the left at a sensible speed"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} moving the robot to the left {speed}")
        self._set_rc_channel_pwm(BlueyCtrlNode._SWAY_SERVO, BlueyCtrlNode._STOP - speed) 

    def swayRight(self, speed=50):
        """Move to the right at a sensible speed"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} moving the robot to the right {speed}")
        self._set_rc_channel_pwm(BlueyCtrlNode._SWAY_SERVO, BlueyCtrlNode._STOP + speed)

    def tiltCamera(self, tilt):
        """Tilt a bit (-400..+400 by the manual)"""
        if self._debug:
            self.get_logger().info(f"{self.get_name()} tilting camera by {tilt}")
        if (tilt < -200) or (tilt > 200):
            self.get_logger().info(f"{self.get_name()} tilt too large")
        else:
            self._set_rc_channel_pwm(BlueyCtrlNode._CAMERA_TILT, BlueyCtrlNode._STOP + tilt)

#    elif event == 'Manual':
#        # Choose a mode
#        mode = 'MANUAL'     #DEPTH_HOLD
#
#        # Check if mode is available
#        if mode not in master.mode_mapping():
#            print(f'Unknown mode {mode}')
#            print('Try: {list(master.mode_mapping().keys())}')
#            sys.exit(1)
#
#        # Get mode ID
#        mode_id = master.mode_mapping()[mode]
#        print(f'I know that mode: {mode_id}')
#        # Set new mode
#        # master.mav.command_long_send(
#        #    master.target_system, master.target_component,
#        #    mavutil.mavlink.MAV_CMD_DO_SET_MODE, 0,
#        #    0, mode_id, 0, 0, 0, 0, 0) or:
#
#        master.set_mode(mode_id)
#        ##master.mav.set_mode_send(
#        #    master.target_system,
#        #    mavutil.mavlink.MAV_CMD_DO_SET_MODE,
#        #    mode_id)
#
#
#        print('Sent mode message')
#        while True:
#            # Wait for ACK command
#            # Would be good to add mechanism to avoid endlessly blocking
#            # if the autopilot sends a NACK or never receives the message
#            ack_msg = master.recv_match(type='COMMAND_ACK', blocking=True)
#            ack_msg = ack_msg.to_dict()
#
#            # Continue waiting if the acknowledged command is not `set_mode`
#            if ack_msg['command'] != mavutil.mavlink.MAV_CMD_DO_SET_MODE:
#                continue
#
#            # Print the ACK result !
#            print(mavutil.mavlink.enums['MAV_RESULT'][ack_msg['result']].description)
#            break
#
#        master.wait_heartbeat()
#        commandWindow['Stabilize'].update(disabled=False)
#        commandWindow['Manual'].update(disabled=True)

def main(args=None):
    rclpy.init(args=args)

    bluey = BlueyCtrlNode()
    try:
        rclpy.spin(bluey)
    except KeyboardInterrupt:
        bluey.get_logger().info(f"BLueyCtrlNode killed")
    finally:
        rclpy.shutdown()

