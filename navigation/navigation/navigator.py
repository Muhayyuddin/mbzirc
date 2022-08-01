# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from math import atan2
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu

from std_msgs.msg import String, Float64
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist, Pose2D, Transform
from nav_msgs.msg import Odometry
import math
from numpy import sqrt, pi, arccos, arctan, radians
import numpy as np
from tf2_ros import TransformBroadcaster
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
np.set_printoptions(precision=3, suppress=True)  # neat printing
from transforms3d.euler import euler2mat, mat2euler
from transforms3d.affines import compose, decompose
import sys
from transforms3d.axangles import axangle2mat

from geometry_msgs.msg import TransformStamped

import rclpy
from rclpy.node import Node

from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster

import tf_transformations



class USVNavigation(Node):

    def __init__(self):
        super().__init__('usv_navigation')
 
        self.target_vessel_pose = [10.0, 20.0, -1.0]
        self.usv_current_pose = [-40.0, 0.0, 0.0] #for simple env
        # self.usv_current_pose = [-1450.0, -16.6, 0.3]
        # self.target_vessel_pose = [0.0, -100.0, 0.3]
        self.target_vessel = TransformStamped()
        self.goal_pose = TransformStamped()
        self._tf_publisher = StaticTransformBroadcaster(self)
        self._tf_publisher2 = StaticTransformBroadcaster(self)
        self.goal_broadcaster = TransformBroadcaster(self)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        #self.make_transforms()
        self.compute_goalpose()
        self.twist = Twist()
        self.twist.angular.z = 0.0
        self.twist.linear.x = 0.0
        self.publish_twist = self.create_publisher(Twist,"cmd_vel",  10)
        
        self.create_subscription(Imu,'/usv/imu/data',self.imu_callback,50)
        self.create_subscription(Pose2D,'/target_vessel_pose',self.target_pose_callback,50)
        #self.create_subscription(LaserScan,'/usv/slot0/scan',self.laser_callback,50)
        self.create_subscription(Odometry, '/usv/odom', self.odom_callback,50)
        timer_period = 1.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.yaw = 0.0
        self.target_yaw = 0.0
        self.heading = False
        self.surge = False
        self.dist_threshold = 10.0 # meters
        self.yaw_threshold = 0.2 # radian
        self.angle = 0.0
        self.dacceleration_distance = 20

    def target_pose_callback (self,msg):
        self.target_vessel_pose[0]=msg.x
        self.target_vessel_pose[1]=msg.y
        self.target_vessel_pose[2]=msg.theta
        #self.make_transforms()
        self.compute_goalpose()
        print('not working yet')
    

    def imu_callback(self,msg):
        # Get quaternion from Imu message
        euler = self.euler_from_quaternion(msg.orientation.x,
                                           msg.orientation.y,
                                           msg.orientation.z,
                                           msg.orientation.w)
        self.yaw = euler[2]

    def odom_callback(self, msg):
        self.usv_current_pose[0] = msg.pose.pose.position.x
        self.usv_current_pose[1] = msg.pose.pose.position.y
        #print(msg)

    def timer_callback(self):

        self.dist_to_goal = sqrt((self.target_vessel_pose[0] - self.usv_current_pose[0])**2 + 
                                 (self.target_vessel_pose[1] - self.usv_current_pose[1])**2)

        if self.dist_to_goal < self.dist_threshold :
            print('USV is already near to the target, enable visual servoing ')
            #self.twist.angular.z = 0.0
            self.twist.linear.x = 0.0
            self.publish_twist.publish(self.twist)
            return
        else:
            self.angle = self.get_target_yaw()
            print('yaw: ', self.yaw)
            print('position: ', self.usv_current_pose)

            self.twist.angular.z = self.angle
            self.twist.linear.x = 0.0

            if(abs(abs(self.yaw)-abs(self.angle))<0.1):
                self.heading = True
                #print('heading is set start moving')
            else:
                self.heading = False

            if self.heading :
                if self.dist_to_goal <= self.dacceleration_distance:
                    self.twist.linear.x = min(((self.dist_to_goal/20.0)*2),2)
                    print('approaching goal distance and velocity are ', self.dist_to_goal, self.twist.linear.x)
                else:    
                    self.twist.linear.x = 2.0

            self.publish_twist.publish(self.twist)

    def get_target_yaw(self):

        self.Y =  self.usv_current_pose[1] - self.target_vessel_pose[1] 
        self.X =  self.usv_current_pose[0] - self.target_vessel_pose[0] 
        self.target_yaw =atan2(self.Y,self.X)
        angle = 0.0
        
        if self.target_yaw < 0 :
            angle = math.pi + self.target_yaw
        else:
            angle = self.target_yaw - math.pi
  
        return angle 

    


    def laser_callback(self, msg):
        #print(len(msg.ranges))

         print('Front: ',msg.ranges[0])
         print('Front: ', msg.ranges[5])
         print('Front: ', msg.ranges[10])
         print('Back: ', msg.ranges[180])
        #self.get_logger().info('I heard: "%s"' % msg.data)
    def compute_goalpose (self):
        target_position = [self.target_vessel_pose[0], self.target_vessel_pose[1], 0.0] # translations
        target_rotation = axangle2mat([0.0, 0.0, 1.0], self.target_vessel_pose[2])
        Z = [1.0, 1.0, 1.0] # zooms
        T1 = compose(target_position, target_rotation, Z)

        goal_offset_position = [0.0, 6.0, 0.0]
        goal_offset_rotation = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
        T2 = compose(goal_offset_position, goal_offset_rotation, Z)
        goal_pose = np.matmul(T1,T2)
        print(goal_pose)

    def make_transforms(self):
        self.target_vessel.header.stamp = self.get_clock().now().to_msg()
        self.target_vessel.header.frame_id = 'map'
        self.target_vessel.child_frame_id = 'target_vessel'
        self.target_vessel.transform.translation.x = self.target_vessel_pose[0]
        self.target_vessel.transform.translation.y = self.target_vessel_pose[1]
        self.target_vessel.transform.translation.z = 0.0
        quat = tf_transformations.quaternion_from_euler(0.0, 0.0, self.target_vessel_pose[2])
        self.target_vessel.transform.rotation.x = quat[0]
        self.target_vessel.transform.rotation.y = quat[1]
        self.target_vessel.transform.rotation.z = quat[2]
        self.target_vessel.transform.rotation.w = quat[3]
        self._tf_publisher.sendTransform(self.target_vessel)


        # self.target_vessel.header.stamp = self.get_clock().now().to_msg()
        # self.target_vessel.header.frame_id = 'odom'
        # self.target_vessel.child_frame_id = 'target_vessel'
        # self.target_vessel.transform.translation.x = 0.0
        # self.target_vessel.transform.translation.y = 6.0
        # self.target_vessel.transform.translation.z = 0.0
        # quat = tf_transformations.quaternion_from_euler(0.0, 0.0, 0.0)
        # self.target_vessel.transform.rotation.x = quat[0]
        # self.target_vessel.transform.rotation.y = quat[1]
        # self.target_vessel.transform.rotation.z = quat[2]
        # self.target_vessel.transform.rotation.w = quat[3]
        # self._tf_publisher.sendTransform(self.target_vessel)

        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'target_vessel'
        t.child_frame_id = 'usv_goal_pose'
        t.transform.translation.x = 0.0
        t.transform.translation.y = 6.0
        t.transform.translation.z = 0.0
        quat = tf_transformations.quaternion_from_euler(0.0, 0.0, 0.0)

        t.transform.rotation.x = quat[0]
        t.transform.rotation.y = quat[1]
        t.transform.rotation.z = quat[2]
        t.transform.rotation.w = quat[3]
        self.goal_broadcaster.sendTransform(t)
        print("computed goal position is ", self.goal_pose.transform.translation.x, self.goal_pose.transform.translation.y )




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
        
        return roll_x, pitch_y, yaw_z 

    def get_quaternion_from_euler(self, roll, pitch, yaw):
        """
        Convert an Euler angle to a quaternion.
        
        Input
            :param roll: The roll (rotation around x-axis) angle in radians.
            :param pitch: The pitch (rotation around y-axis) angle in radians.
            :param yaw: The yaw (rotation around z-axis) angle in radians.
        
        Output
            :return qx, qy, qz, qw: The orientation in quaternion [x,y,z,w] format
        """
        qx = np.sin(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) - np.cos(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
        qy = np.cos(roll/2) * np.sin(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.cos(pitch/2) * np.sin(yaw/2)
        qz = np.cos(roll/2) * np.cos(pitch/2) * np.sin(yaw/2) - np.sin(roll/2) * np.sin(pitch/2) * np.cos(yaw/2)
        qw = np.cos(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
        
        return [qx, qy, qz, qw]

def main(args=None):
    rclpy.init(args=args)

    usv_navigation = USVNavigation()

    rclpy.spin(usv_navigation)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    usv_navigation.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
