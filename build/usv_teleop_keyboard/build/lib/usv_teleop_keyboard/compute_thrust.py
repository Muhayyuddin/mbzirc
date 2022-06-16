#!/usr/bin/env python3
# license removed for brevity
import rclpy
import sys
from rcl_interfaces.msg import SetParametersResult
from rclpy.parameter import Parameter
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Float64

class twist2thrust(Node):

    def __init__(self):
        super().__init__('twist2thrust')
        self.linear_scaling = 0.3
        self.angular_scaling =  0.2
        self.keyboard = '--keyboard' in sys.argv
        self.get_logger().info("Linear scaling=%f, Angular scaling=%f"%(self.linear_scaling,self.angular_scaling))
        self.left_pub = self.create_publisher(Float64,'/usv/left/thrust/cmd_thrust', 10)
        self.right_pub = self.create_publisher(Float64,'/usv/right/thrust/cmd_thrust', 10)
        self.left_msg =Float64()
        self.right_msg =Float64() 

    def callback(self,data):
        #self.get_logger().debug("RX: Twist "+self.get_caller_id())
        self.get_logger().info("\tlinear:")
        self.get_logger().info("\t\tx:%f,y:%f,z:%f"%(data.linear.x,
                                            data.linear.y,
                                            data.linear.z))
        self.get_logger().info("\tangular:")
        self.get_logger().info("\t\tx:%f,y:%f,z:%f"%(data.angular.x,
                                            data.angular.y,
                                            data.angular.z))
        # scaling factors
        
        linfac = self.linear_scaling
        angfac = self.angular_scaling

        if self.keyboard:
            self.left_msg.data = linfac*data.linear.x
            self.right_msg.data = linfac*data.linear.x
            self.left_msg.data += -angfac*data.angular.z
            self.right_msg.data += angfac*data.angular.z
        else:
            self.left_msg.data = data.linear.x
            self.right_msg.data = data.angular.z

        self.get_logger().info("TX ")
        self.get_logger().info("\tleft:%f, right:%f"%(self.left_msg.data,
                                              self.right_msg.data))
        self.left_pub.publish(self.left_msg)
        self.right_pub.publish(self.right_msg)

def main(args=None):

    rclpy.init(args=args)

    twist_to_thrust = twist2thrust()
    subscriber_vel = twist_to_thrust.create_subscription(Twist,"cmd_vel",twist_to_thrust.callback,10)
    rclpy.spin(twist_to_thrust)

      # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    twist_to_thrust.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':

    main()
