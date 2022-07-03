#!/usr/bin/env python3


import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from tf2_msgs.msg import TFMessage
from geometry_msgs.msg import Transform
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster
import math

import sys
from math import pi

from geometry_msgs.msg import Vector3
from geometry_msgs.msg import Twist
from std_msgs.msg import Float64
from std_msgs.msg import Float32
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu

# From this package
from usv_pid.pypid import Pid


class PositionControl(Node):

  def __init__(self):
    """
    Class constructor to set up the node
    """
    super().__init__('position_control')
   
    # Setup Velocity Pid
    self.vpid = Pid(0.0, 0.0, 0.0)
    self.vpid.set_setpoint(0.0)
    self.vpid.set_maxIout(1.0)
    # self.pid.set_inputisangle(True,pi)
    self.vpid.set_derivfeedback(True)  # D term in feedback look
    fc = 20;  # cutoff freq in hz
    wc = fc*(2.0*pi)  # cutoff freq. in rad/s
    self.vpid.set_derivfilter(1, wc)

    # Initialize some bits as none - for now
    self.drivemsg = None
    self.publisher = None
    self.lasttime = None
    # For diagnosing/tuning PID
    self.vpubdebug = None
    self.ypubdebug = None

    # Setup outbound messages
    self.left_cmd = Float64()
    self.right_cmd = Float64()
    
    # Setup publisher
    self.left_publisher = self.create_publisher(Float64, '/usv/left/thrust/cmd_thrust', 10)
    self.right_publisher = self.create_publisher(Float64,'/usv/right/thrust/cmd_thrust', 10)
    
    # node.ypubdebug = rospy.Publisher("yaw_pid_debug",PidDiagnose,queue_size=10)
    # node.vpubdebug = rospy.Publisher("vel_pid_debug",PidDiagnose,queue_size=10)
    # node.ydebugmsg = PidDiagnose()
    # node.vdebugmsg = PidDiagnose()

    # Setup subscribers
    self.s1 = self.create_subscription(Odometry,'/usv/odom',self.odom_callback,10)
    #self.s2 = self.create_subscription(Twist,"cmd_vel",self.twist_callback,10)
    self.create_subscription(Float64,"set_position",self.set_setpoint,10)

    print('all set')


  def set_setpoint(self, msg):
    self.vpid.set_setpoint(msg.data)

  def odom_callback(self,msg):
    # Yaw Control
    now = self.get_clock().now()
    if self.lasttime is None:
      self.lasttime = now
      return
    dt = now.to_msg().sec-self.lasttime.to_msg().sec
    self.lasttime = now
    # print("dt: %.6f"%dt)
    if dt < 1.0e-6:
      self.get_logger().info('USV Control dt too small "%f"'%dt)
      return

    # Velocity control
    dx = msg.pose.pose.position.x
    vout = self.vpid.execute(dt,dx)
    thrust = vout[0]

    # I believe drive messages are scaled to -1.0 to 1.0
    # Scale so that no one output saturates
    '''
    mag = abs(torque)+abs(thrust)
    if mag > 1.0:

    torque = torque/mag
    thrust = thrust/mag
    '''

    # rospy.loginfo('Torque: %.3f, Thrust: %.3f'%(torque,thrust))
    '''
    self.drivemsg.left=-1*torque + thrust
    self.drivemsg.right=torque + thrust
    self.publisher.publish(self.drivemsg)
    '''
    self.left_cmd.data = (thrust)
    self.right_cmd.data = (thrust)
    print(self.left_cmd.data )
    print(self.right_cmd.data )
    self.left_publisher.publish(self.left_cmd)
    self.right_publisher.publish(self.right_cmd)

    if not (self.vpubdebug is None):
        self.vdebugmsg.PID = vout[0]
        self.vdebugmsg.P = vout[1]
        self.vdebugmsg.I = vout[2]
        self.vdebugmsg.D = vout[3]
        self.vdebugmsg.Error = vout[4]
        self.vdebugmsg.Setpoint = vout[5]
        self.vdebugmsg.Derivative= vout[6]
        self.vdebugmsg.Integral = vout[7]
        self.vpubdebug.publish(self.vdebugmsg)

  # def dynamic_callback(self,config,level):
  #     # rospy.loginfo("""Reconfigure Request: {int_param}, {double_param},\ 
  #     #  {str_param}, {bool_param}, {size}""".format(**config))
  #     rospy.loginfo("Reconfigure request...")
  #     # print config.keys()
  #     # print config['yawKp']
  #     self.ypid.Kp = config['yawKp']
  #     # self.ypid.Ki = config['yawKi']
  #     # Use method to zero the integrator
  #     Ki = config['yawKi']
  #     tol = 1e-6
  #     if abs(abs(Ki)-abs(self.ypid.Ki)) > tol:
  #         rospy.loginfo("Setting yaw Ki to %.3f"%Ki)
  #         self.ypid.set_Ki(Ki)
  #     self.ypid.Kd = config['yawKd']

  #     self.vpid.Kp = config['velKp']
  #     # self.vpid.Ki = config['velKi']
  #     Ki = config['velKi']
  #     if abs(abs(Ki)-abs(self.vpid.Ki)) > tol:
  #         rospy.loginfo("Setting vel Ki to %.3f"%Ki)
  #         self.vpid.set_Ki(Ki)
  #     self.vpid.Kd = config['velKd']
  #     return config 
 
def main(args=None):
  
  # Initialize the rclpy library
  rclpy.init(args=args)
  # ROS Parameters
  # yawKp = rospy.get_param('~yawKp',0.0)
  # yawKd = rospy.get_param('~yawKd',0.0)
  # yawKi = rospy.get_param('~yawKi',0.0)

  # velKp = rospy.get_param('~velKp',0.0)
  # velKd = rospy.get_param('~velKd',0.0)
  # velKi = rospy.get_param('~velKi',0.0)
  
#   yawKp = 40.0
#   yawKd = 50.0
#   yawKi = 10.0

  velKp = 5.0
  velKd = 2.0
  velKi = 0.1
  # Create the node
  pid_position_control = PositionControl()
  # Set initial gains from parameters
#   pid_position_control.ypid.Kp = yawKp
#   pid_position_control.ypid.Kd = yawKd
#   pid_position_control.ypid.Ki = yawKi
  pid_position_control.vpid.Kp = velKp
  pid_position_control.vpid.Kd = velKd
  pid_position_control.vpid.Ki = velKi


  try:
    rclpy.spin(pid_position_control)
  except KeyboardInterrupt:
    pass
  
  # Shutdown the ROS client library for Python
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()

    
 