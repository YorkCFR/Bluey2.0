import sys
import time
import cv2
import rclpy
from .video import Video
from rclpy.node import Node
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image

class BlueyCamera(Node):

    def __init__(self, rostopic='/mycamera/image_raw'):
        super().__init__('bluey_camera')
        self._recording = False
        self._out = None

        try:
            self._video =  Video()
        except Exception as e:
            self.get_logger().error(f'Unable to open bluey camera {e}')
            sys.exit(1)

        self._bridge = CvBridge()
        self._publisher = self.create_publisher(Image, rostopic, 1)

    def stream(self, debug=True):
        try:
            while True:
                if not self._video.frame_available():
                    continue

                frame = self._video.frame()
                key = chr(cv2.waitKey(1) & 0xFF)
                if self._out is not None:
                    self._out.write(frame)
                if key == 'r':
                    print("recording started")
                    if self._out is None:
                        shape = frame.shape
                        self._out  = cv2.VideoWriter(f'{round(time.time()*1000)}.avi', cv2.VideoWriter_fourcc(*'MJPG'), 30, (shape[1], shape[0]))
                elif key == 's':
                    print("recording stopped")
                    if self._out is not None:
                        self._out.release()
                        self._out = None
                x = cv2.resize(frame, (0,0), fx=0.50, fy=0.50)
                if self._recording:
                    cv2.circle(x, (100, 100), 20, (255, 255, 255), -1)
                cv2.imshow("image", x)


                image_message = self._bridge.cv2_to_imgmsg(frame, "bgr8")
                self._publisher.publish(image_message)
                rclpy.spin_once(self, timeout_sec=0)
        except Exception as e:
            self.get_logger().error(f'CameraStreamNode capture error {e}')

def main(args=None):
    rclpy.init(args=args)
    node = BlueyCamera()
    try:
        node.stream()
        rclpy.shutdown()
    except KeyboardInterrupt:
        pass

if __name__ == '__main__':
    main()
