#!/usr/bin/env python3 
 
"""
Description:
Publish the coordinate transformation between the map frame
and the base_link frame.
The output is [x,y,yaw]. yaw is -pi to pi
-------
Subscription Topics:
/tf - geometry_msgs/TransformStamped[]
-------
Publishing Topics:
/map_to_base_link_pose2d – std_msgs/Float64MultiArray
-------
Author: Addison Sears-Collins
Website: AutomaticAddison.com
Date: November 25, 2021
"""
 
# Import the ROS client library for Python 
import rclpy 
 
# Enables the use of rclpy's Node class
from rclpy.node import Node   
# Handle float64 arrays
from std_msgs.msg import Float64MultiArray 

from tf2_msgs.msg import TFMessage

from geometry_msgs.msg import Transform
from nav_msgs.msg import Odometry

from geometry_msgs.msg import TransformStamped

from tf2_ros import TransformBroadcaster
 
# Math library
import math 
 
 
class FrameListener(Node):
  """
  Subclass of the Node class.
  The class listens to coordinate transformations and 
  publishes the 2D pose at a specific time interval.
  """
  def __init__(self):
    """
    Class constructor to set up the node
    """
    
    # Initiate the Node class's constructor and give it a name
    super().__init__('usv2dpose')
 
    
 
    #self.tf_buffer = Buffer()
    #self.tf_listener = TransformListener(self.tf_buffer, self)
    # Create subscriber to receive usv pose in world frame
    self.usv_pose = self.create_subscription(TFMessage, '/usv/pose_static', self.odometry, 10)
    self.odom_pub = self.create_publisher(Odometry, '/usv/odom' ,10)

    # Create publisher(s)  
    self.br = TransformBroadcaster(self)
    self.odom = Odometry()
 
  def odometry(self, msg):
      t = TransformStamped()
      # Read message content and assign it to
      # corresponding tf variables
      t.header.stamp = msg.transforms[5].header.stamp
      t.header.frame_id = 'odom'
      t.child_frame_id = 'usv'

      # Turtle only exists in 2D, thus we get x and y translation
      # coordinates from the message and set the z coordinate to 0
      t.transform.translation.x = msg.transforms[5].transform.translation.x
      t.transform.translation.y = msg.transforms[5].transform.translation.y
      t.transform.translation.z = 0.0

      # For the same reason, turtle can only rotate around one axis
      # and this why we set rotation in x and y to 0 and obtain
      # rotation in z axis from the message
      t.transform.rotation.x = msg.transforms[5].transform.rotation.x
      t.transform.rotation.y = msg.transforms[5].transform.rotation.y
      t.transform.rotation.z = msg.transforms[5].transform.rotation.z
      t.transform.rotation.w = msg.transforms[5].transform.rotation.w

      # Send the transformation
      self.br.sendTransform(t)

      self.odom.header.stamp = msg.transforms[5].header.stamp
      self.odom.header.frame_id = "odom"

      # set the position
      self.odom.pose.pose.position.x = msg.transforms[5].transform.translation.x
      self.odom.pose.pose.position.y = msg.transforms[5].transform.translation.y
      self.odom.pose.pose.position.z = 0.0
      self.odom.pose.pose.orientation.x = msg.transforms[5].transform.rotation.x
      self.odom.pose.pose.orientation.y = msg.transforms[5].transform.rotation.y
      self.odom.pose.pose.orientation.z = msg.transforms[5].transform.rotation.z
      self.odom.pose.pose.orientation.w = msg.transforms[5].transform.rotation.w

      # todo
      # set the velocity
      # geometry_msgs/TwistWithCovariance twist

      self.odom.child_frame_id = "usv"

      # publish the message
      self.odom_pub.publish(self.odom)

      # Publish the 2D pose
      # self.current_x = msg.transforms[5].transform.translation.x
      # self.current_y = msg.transforms[5].transform.translation.y    
      # roll, pitch, yaw = self.euler_from_quaternion(
      # msg.transforms[5].transform.rotation.x,
      # msg.transforms[5].transform.rotation.y,
      # msg.transforms[5].transform.rotation.z,
      # msg.transforms[5].transform.rotation.w)      
      # self.current_yaw = yaw    
      # usv2dpose = Float64MultiArray()
      # usv2dpose.data = [self.current_x, self.current_y, self.current_yaw]   
      
      


  def euler_from_quaternion(self, x, y, z, w):
    """
    Convert a quaternion into euler angles (roll, pitch, yaw)
    roll is rotation around x in radians (counterclockwise)
    pitch is rotation around y in radians (counterclockwise)
    yaw is rotation around z in radians (counterclockwise)
    """
    t0 = +2.0 * (w * x + y * z)
    t1 = +1.0 - 2.0 * (x * x + y * y)
    roll_x = math.atan2(t0, t1)
      
    t2 = +2.0 * (w * y - z * x)
    t2 = +1.0 if t2 > +1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    pitch_y = math.asin(t2)
     
    t3 = +2.0 * (w * z + x * y)
    t4 = +1.0 - 2.0 * (y * y + z * z)
    yaw_z = math.atan2(t3, t4)
     
    return roll_x, pitch_y, yaw_z # in radians
 
def main(args=None):
  
  # Initialize the rclpy library
  rclpy.init(args=args)
  
  # Create the node
  frame_listener_node = FrameListener()
  
  # Spin the node so the callback function is called.
  # Publish any pending messages to the topics.
  try:
    rclpy.spin(frame_listener_node)
  except KeyboardInterrupt:
    pass
  
  # Shutdown the ROS client library for Python
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()