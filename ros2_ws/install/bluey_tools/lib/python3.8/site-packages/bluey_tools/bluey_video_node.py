import sys
import cv2
import rclpy
from .video import Video
from rclpy.node import Node
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image

class BlueyCamera(Node):

    def __init__(self, rostopic='/mycamera/image_raw'):
        super().__init__('opencv_camera')

        try:
            self._video =  Video()
        except Exception as e:
            self.get_logger().error(f'Unable to open bluey camera {e}')
            sys.exit(1)

        self._bridge = CvBridge()
        self._publisher = self.create_publisher(Image, rostopic, 1)

    def stream(self, debug=False):
        try:
            while True:
                if not self._video.frame_available():
                    continue

                frame = self._video.frame()
                if debug:
                    cv2.imshow('frame', frame)
                    if cv2.waitKey(1) & 0xFF == ord('q'):
                        break

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
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()

if __name__ == '__main__':
    main()
