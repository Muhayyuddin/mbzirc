#!/usr/bin/env python
'''
Using instances of the pypid Pid class to control yaw and velocity
'''
# Python

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
# ROS

#from dynamic_reconfigure.server import Server
#from kingfisher_control.cfg import YawDynamicConfig
#from kingfisher_control.cfg import TwistDynamicConfig

#from kingfisher_control.msg import PidDiagnose

from geometry_msgs.msg import Vector3
from geometry_msgs.msg import Twist
from std_msgs.msg import Float64
from nav_msgs.msg import Odometry
#from kingfisher_msgs.msg import Drive
#from kingfisher_msgs.msg import Course
from sensor_msgs.msg import Imu
#from std_srvs.srv import SetBool, SetBoolResponse, SetBoolRequest
#from std_srvs.srv import Empty, EmptyResponse

# BSB
from usv_pid.pypid import Pid

class PidControl(Node):
    #def __init__(self,engaged=False,yaw_cntrl=True,vel_cntrl=True):
    def __init__(self,engaged=False,yaw_cntrl=True,vel_cntrl=True):
        super().__init__('pid_control')
        # Setup Yaw Pid
        self.engaged = engaged
        self.yaw_cntrl = yaw_cntrl
        self.vel_cntrl = vel_cntrl
        self.Kp=15.0
        self.Ki=0.001
        self.Kd=20.0
        self.ypid = Pid(self.Kp,self.Ki,self.Kd)
        
        self.ypid.set_setpoint(0.0)
        self.ypid.set_inputisangle(True,pi)
        self.ypid.set_derivfeedback(True)  # D term in feedback look
        fc = 20;  # cutoff freq in hz
        wc = fc*(2.0*pi)  # cutoff freq. in rad/s
        self.ypid.set_derivfilter(1,wc)


        # self.ypid.set_setpoint(0.0)
        # #self.pid.set_inputisangle(True,pi)
        # self.ypid.set_derivfeedback(True)  # D term in feedback look
        # fc = 20;  # cutoff freq in hz
        # wc = fc*(2.0*pi)  # cutoff freq. in rad/s
        # self.ypid.set_derivfilter(1,wc)
        # self.ypid.set_maxIout(1.0)
        # Setup Velocity Pid
        self.vpid = Pid(30.0, 30.0, 0.01)
        self.vpid.set_setpoint(0.0)
        self.vpid.set_maxIout(1.0)
        #self.pid.set_inputisangle(True,pi)
        self.vpid.set_derivfeedback(True)  # D term in feedback look
        fc = 20;  # cutoff freq in hz
        wc = fc*(2.0*pi)  # cutoff freq. in rad/s
        self.vpid.set_derivfilter(1,wc)
        
        # Initialize some bits as none - for now
        self.drivemsg = None
        self.publisher = None
        self.lasttime = None
        # For diagnosing/tuning PID
        self.vpubdebug = None
        self.ypubdebug = None
        
        self.left_cmd = Float64()
        self.right_cmd = Float64()
        # Type of yaw control
        self.yaw_type = 'yaw'

                # Setup publisher
        self.left_publisher = self.create_publisher(Float64, '/usv/left/thrust/cmd_thrust', 10)
        self.right_publisher = self.create_publisher(Float64,'/usv/right/thrust/cmd_thrust', 10)
        self.timer_period = 0.1  # seconds
        #self.timer = self.create_timer(self.timer_period, self.callback)
        # node.ypubdebug = rospy.Publisher("yaw_pid_debug",PidDiagnose,queue_size=10)
        # node.vpubdebug = rospy.Publisher("vel_pid_debug",PidDiagnose,queue_size=10)
        # node.ydebugmsg = PidDiagnose()
        # node.vdebugmsg = PidDiagnose()

        # Setup subscribers
        self.s1 = self.create_subscription(Odometry,'/usv/odom',self.odom_callback,10)
        self.s2 = self.create_subscription(Twist,"/cmd_vel",self.twist_callback,10)
        # self.dt = 0.0
        # self.dyaw = 0.0
        # self.dx = 0.0
        self.create_subscription(Imu,'/usv/imu/data',self.imu_callback,50)
        self.yaw = 0.0

    def imu_callback(self,msg):
        # Get quaternion from Imu message
        # q = (msg.orientation.x,
        #      msg.orientation.y,
        #      msg.orientation.z,
        #      msg.orientation.w)
        euler = self.euler_from_quaternion(msg.orientation.x,msg.orientation.y,msg.orientation.z,msg.orientation.w)
        self.yaw = euler[2]

    def twist_callback(self,msg):
        print('Current twist is ', msg.angular.z)
        self.ypid.set_setpoint(msg.angular.z)
        self.vpid.set_setpoint(msg.linear.x)

    def course_callback(self,msg):
        self.ypid.set_setpoint(msg.yaw)
        self.vpid.set_setpoint(msg.speed)

    def odom_callback(self,msg):
        # Calculate time step
        now = self.get_clock().now()
        if self.lasttime is None:
            self.lasttime = now
            return
        dt = now.to_msg().sec-self.lasttime.to_msg().sec

        self.lasttime = now
        # Yaw Control
        if self.yaw_cntrl:
            #if self.yaw_type=='yaw_rate':
            yaw_fdbk = msg.twist.twist.angular.z # measured rate (process var.)
            #elif self.yaw_type=='yaw':
            #     euler = self.euler_from_quaternion(msg.orientation.x,
            #                                        msg.orientation.y,
            #                                        msg.orientation.z,
            #                                        msg.orientation.w)

            #     yaw_fdbk = euler[2]
            yout = self.ypid.execute(dt,self.yaw)
            torque = yout[0]
            print('received torque   ', torque)
        else:
            torque = 0.0


        # Velocity control
        if self.vel_cntrl:
            dx = msg.twist.twist.linear.x
            vout = self.vpid.execute(dt,dx)
            thrust = vout[0]
        else:
            thrust = 0.0

        # I believe drive messages are scaled to -1.0 to 1.0
        # Scale so that no one output saturates
        '''
        mag = abs(torque)+abs(thrust)
        if mag > 1.0:
            torque = torque/mag
            thrust = thrust/mag
        '''

        #rospy.loginfo('Torque: %.3f, Thrust: %.3f'%(torque,thrust))
        print('torque ', torque)
        print('thrust ',thrust)
        self.left_cmd.data = (-1.0*torque + thrust)
        self.right_cmd.data = (torque + thrust)
        # Only publish if engaged
        #if (self.engaged):
        self.left_publisher.publish(self.left_cmd)
        self.right_publisher.publish(self.right_cmd)

        if (not (self.ypubdebug is None)) and (self.yaw_cntrl):
            self.ydebugmsg.PID = yout[0]
            self.ydebugmsg.P = yout[1]
            self.ydebugmsg.I = yout[2]
            self.ydebugmsg.D = yout[3]
            self.ydebugmsg.Error = yout[4]
            self.ydebugmsg.Setpoint = yout[5]
            self.ydebugmsg.Derivative= yout[6]
            self.ydebugmsg.Integral = yout[7]
            self.ypubdebug.publish(self.ydebugmsg)
        if (not (self.vpubdebug is None)) and (self.vel_cntrl):
            self.vdebugmsg.PID = vout[0]
            self.vdebugmsg.P = vout[1]
            self.vdebugmsg.I = vout[2]
            self.vdebugmsg.D = vout[3]
            self.vdebugmsg.Error = vout[4]
            self.vdebugmsg.Setpoint = vout[5]
            self.vdebugmsg.Derivative= vout[6]
            self.vdebugmsg.Integral = vout[7]
            self.vpubdebug.publish(self.vdebugmsg)


    def dynamic_callback(self,config,level):
        #rospy.loginfo("""Reconfigure Request: {int_param}, {double_param},\ 
        #  {str_param}, {bool_param}, {size}""".format(**config))
        rospy.loginfo("Reconfigure request...")
        #print config.keys()
        #print config['yawKp']
        self.ypid.Kp = config['yawKp']
        #self.ypid.Ki = config['yawKi']
        # Use method to zero the integrator
        Ki = config['yawKi']
        tol = 1e-6
        if abs(abs(Ki)-abs(self.ypid.Ki)) > tol:
            rospy.loginfo("Setting yaw Ki to %.3f"%Ki)
            self.ypid.set_Ki(Ki)
        self.ypid.Kd = config['yawKd']

        self.vpid.Kp = config['velKp']
        #self.vpid.Ki = config['velKi']
        Ki = config['velKi']
        if abs(abs(Ki)-abs(self.vpid.Ki)) > tol:
            rospy.loginfo("Setting vel Ki to %.3f"%Ki)
            self.vpid.set_Ki(Ki)
        self.vpid.Kd = config['velKd']
        return config

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
  # ROS Parameters
  
  # yawKp = 40.0
  # yawKd = 40.0
  # yawKi = 0.5

  # velKp = 60.0
  # velKd = 0.0
  # velKi = 20.0

  yawKp = 2.0
  yawKd = 1.0
  yawKi = 0.0

  velKp = 0.7
  velKd = 0.0
  velKi = 0.30
  # Create the node
  pid_control = PidControl(True,True,True)
  # Set initial gains from parameters
#   pid_control.ypid.Kp = yawKp
#   pid_control.ypid.Kd = yawKd
#   pid_control.ypid.Ki = yawKi
#   pid_control.vpid.Kp = velKp
#   pid_control.vpid.Kd = velKd
#   pid_control.vpid.Ki = velKi


  try:
    rclpy.spin(pid_control)
  except KeyboardInterrupt:
    pass
  
  # Shutdown the ROS client library for Python
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()

    
     