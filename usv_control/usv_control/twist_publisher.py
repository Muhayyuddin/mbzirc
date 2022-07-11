#!/usr/bin/env python3
# license removed for brevity
import rclpy
import sys
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Float64

class TwistPublisher(Node):

    def __init__(self):
        super().__init__('twistpublisher')
        self.timer_period = 0.1  # seconds
        self.timer = self.create_timer(self.timer_period, self.callback)
        self.twist_publisher = self.create_publisher(Twist,'cmd_vel',10)
        self.declare_parameter('my_parameter', 0.0)
        self.twist = Twist()
        self.twist.angular.z = 0.0
        #self.twist.linear.x = 0.0

    def callback(self):
        my_param = self.get_parameter('my_parameter').get_parameter_value().double_value
        self.twist.angular.z=float(my_param)
        self.get_logger().info('Hello %f!' % my_param)

   
        my_param = self.get_parameter('my_parameter').get_parameter_value().double_value

        self.twist.angular.z=float(my_param)
        self.get_logger().info('Publishing %f!' % self.twist.angular.z)
        self.twist_publisher.publish(self.twist)

def main(args=None):

    rclpy.init(args=args)

    twist_publisher = TwistPublisher()
    rclpy.spin(twist_publisher)

      # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    twist_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':

    main()
