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

import rclpy
from rclpy.node import Node

from std_msgs.msg import String, Float64
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

from numpy import sqrt, pi, arccos, radians
# to move the Propeller
#ros2 topic pub --once /usv/left/thrust/cmd_thrust std_msgs/msg/Float64 'data: 15'
#ros2 topic pub --once /usv/right/thrust/cmd_thrust std_msgs/msg/Float64 'data: 15'

#to move the thrushter
#ros2 topic pub --once /usv/left/thrust/joint/cmd_pos std_msgs/msg/Float64 'data: -1'
#ros2 topic pub --once /usv/right/thrust/joint/cmd_pos std_msgs/msg/Float64 'data: 1'


#commands
#ros2 launch mbzirc_ros competition_local.launch.py ign_args:="-v 4 -r simple_demo.sdf
#ros2 run py_pubsub talker

# coordinates
# Vessel-A: 25 25 0.3 0 0.0 -1.0
# Vessel-B: -20 20 0.3 0 0.0 -1.0
# Vessel-C: 10 -25 0.3 0 0.0 -1.0
# Vessel-D: -35 15 0.3 0 0.0 -1.0
# Vessel-E: 20 -50 0.3 0 0.0 -1.0
# Vessel-F: -45 10 0.3 0 0.0 -1.0
# Vessel-G: -28 -10 0.3 0 0.0 -1.0

# USV:  -10, 28, 0.3, 0, 0, 0
class Navigator(Node):

    def __init__(self):
        super().__init__('navigator')
        #global circle
        #object1 = Twist()

        self.vesselA = [25.0, 25.0, 0.3]
        self.vesselB = [-20.0, 20.0, 0.3]
        self.vesselC = [10.0, -25.0, 0.3]
        self.vesselD = [-35.0, 15.0, 0.3]
        self.vesselE = [20.0, -50.0, 0.3]
        self.vesselF = [-45.0, 10.0, 0.3]
        self.vesselG = [-28.0, -10.0, 0.3]

        self.usv = [-30.0, 38.0, 0.3]

        self.right_pub = self.create_publisher(Float64, '/usv/right/thrust/cmd_thrust', 10)
        self.left_pub  = self.create_publisher(Float64,'/usv/left/thrust/cmd_thrust', 10)
        self.left_pub_angle = self.create_publisher(Float64, '/usv/left/thrust/joint/cmd_pos', 10)
        self.right_pub_angle = self.create_publisher(Float64, 'usv/right/thrust/joint/cmd_pos', 10)
        self.left_msg = Float64()
        self.right_msg = Float64()
        self.left_pub_angle_msg = Float64()
        self.right_pub_angle_msg = Float64()

        self.distA = sqrt((self.vesselA[0] - self.usv[0])**2 + (self.vesselA[1] - self.usv[1])**2 + (self.vesselA[2] - self.usv[2])**2)
        self.distB = sqrt((self.vesselB[0] - self.usv[0])**2 + (self.vesselB[1] - self.usv[1])**2 + (self.vesselB[2] - self.usv[2])**2)
        self.distC = sqrt((self.vesselC[0] - self.usv[0])**2 + (self.vesselC[1] - self.usv[1])**2 + (self.vesselC[2] - self.usv[2])**2)
        self.distD = sqrt((self.vesselD[0] - self.usv[0])**2 + (self.vesselD[1] - self.usv[1])**2 + (self.vesselD[2] - self.usv[2])**2)
        self.distE = sqrt((self.vesselE[0] - self.usv[0])**2 + (self.vesselE[1] - self.usv[1])**2 + (self.vesselE[2] - self.usv[2])**2)
        self.distF = sqrt((self.vesselF[0] - self.usv[0])**2 + (self.vesselF[1] - self.usv[1])**2 + (self.vesselF[2] - self.usv[2])**2)
        self.distG = sqrt((self.vesselG[0] - self.usv[0])**2 + (self.vesselG[1] - self.usv[1])**2 + (self.vesselG[2] - self.usv[2])**2)

        th = 5 # distance threshold

        self.m = 0
        if self.vesselA[0] - self.usv[0] != 0:
            self.m = (self.vesselA[1] - self.usv[1])/ (self.vesselA[0] - self.usv[0])
        else:
            self.m = (self.vesselA[1] - self.usv[1])

        print('Slope: ', self.m)

        #self.left_pub = self.create_publisher("/cmd_vel", Twist, 10)

        self.subscription = self.create_subscription(
            LaserScan,
            "/usv/slot0/scan",
            self.listener_callback,
            10)

        self.subscription = self.create_subscription(
            Odometry,
           "/usv/odom",
           self.odometry, 
           10)

        timer_period = 2.0  # seconds
        #self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.angleChanged = False
        self.finalThrust = False
        #self.subscription  # prevent unused variable warning

    def odometry(self, msg):
        print(msg.pose.pose)

    def timer_callback(self):
        msg = Float64()
        msg2 = Float64()
        msg3 = Float64()
        msg4 = Float64()
        print(self.usv)
        self.distA = sqrt((self.vesselA[0] - self.usv[0])**2 + (self.vesselA[1] - self.usv[1])**2 + (self.vesselA[2] - self.usv[2])**2)
        self.distB = sqrt((self.vesselB[0] - self.usv[0])**2 + (self.vesselB[1] - self.usv[1])**2 + (self.vesselB[2] - self.usv[2])**2)
        self.distC = sqrt((self.vesselC[0] - self.usv[0])**2 + (self.vesselC[1] - self.usv[1])**2 + (self.vesselC[2] - self.usv[2])**2)
        self.distD = sqrt((self.vesselD[0] - self.usv[0])**2 + (self.vesselD[1] - self.usv[1])**2 + (self.vesselD[2] - self.usv[2])**2)
        self.distE = sqrt((self.vesselE[0] - self.usv[0])**2 + (self.vesselE[1] - self.usv[1])**2 + (self.vesselE[2] - self.usv[2])**2)
        self.distF = sqrt((self.vesselF[0] - self.usv[0])**2 + (self.vesselF[1] - self.usv[1])**2 + (self.vesselF[2] - self.usv[2])**2)
        self.distG = sqrt((self.vesselG[0] - self.usv[0])**2 + (self.vesselG[1] - self.usv[1])**2 + (self.vesselG[2] - self.usv[2])**2)

        th = 5 # distance threshold

        #m = 0
        #if self.vesselA[0] - self.usv[0] != 0:
        #    m = (self.vesselA[1] - self.usv[1])/ (self.vesselA[0] - self.usv[0])
        #else:
        #    m = (self.vesselA[1] - self.usv[1])

        #print('Slope: ', m)

        if self.distA >= th and self.distB >= th and self.distC >= th and self.distD >= th and self.distE >= th and self.distF >= th and self.distG >= th:
            x = self.usv[0] + 1.75
            x0 = self.usv[0]
            y0 = self.usv[1]
            y = self.m*(x-x0) + y0

            self.usv = [x, y, 0.3]

            #print(self.i)

            y = y % 360.0
            y = (y + 360.0) % 360.0

            if y > 180.0:
                y = y - 360.0

            print('Rotation Angle: ', y)

            y = y * (pi/180)

            print('Radian Angle: ', y)
            print('Distance-A: ', self.distA)

            if y > 0:
                msg.data = 150.0# speed
                msg2.data = y # direction

                msg3.data = 150.0
                msg4.data = -1.0 * y

                if self.angleChanged == True:
                    self.right_pub.publish(msg3)
                    self.right_pub_angle.publish(msg4)
                    self.angleChanged = False
                else:
                    #msg2.data = y+radians(-1)
                    self.left_pub.publish(msg)
                    self.left_pub_angle.publish(msg2)

                    self.angleChanged = True
            else:
                msg.data = 0.0# speed
                msg2.data = 0.0 # direction

                msg3.data = 0.0
                msg4.data = 0.0

                self.left_pub.publish(msg)
                self.left_pub_angle.publish(msg2)
                self.right_pub.publish(msg3)
                self.right_pub_angle.publish(msg4)

        elif self.distA < th:
            print('Too close to A: ', self.distA)
            x1 = self.vesselA[0]
            y1 = self.vesselA[1]
            z1 = self.vesselA[2]

            x2 = self.usv[0]
            y2 = self.usv[1]
            z2 = self.usv[2]

            v1 = x2-x1
            v2 = y2-y1
            v3 = 0

            VP = [v1, v2, 0]
            V = [v1, v2, v3]

            magV = sqrt(V[0]*V[0]+V[1]*V[1]+V[2]*V[2])
            magVP = sqrt(VP[0]*VP[0]+VP[1]*VP[1]+VP[2]*VP[2])

            dot = V[0]*VP[0] + V[1] * VP[1] + V[2] * VP[2]

            yaw = arccos(radians(dot/(magV*magVP)))

            if self.finalThrust == False:
                msg.data = 150.0# speed
                msg2.data = -yaw # direction

                #msg3.data = 150.0
                #msg4.data = -yaw
                self.finalThrust = True
            else:
                msg.data = 0.0# speed
                msg2.data = -yaw # direction

                msg3.data = 0.0
                msg4.data = -yaw

            self.left_pub.publish(msg)
            self.left_pub_angle.publish(msg2)
            self.right_pub.publish(msg3)
            self.right_pub_angle.publish(msg4)


        #if self.i % 2 == 0:
        #    msg.data = 150.0#'Hello World: %d' % self.i
        #    msg2.data = -1.0
        #    self.left_pub.publish(msg)
        #    self.left_pub_angle.publish(msg2)
        #else:
        #    msg.data = 150.0#'Hello World: %d' % self.i
        #    msg2.data = 1.0
        #    self.right_pub.publish(msg)
        #    self.right_pub_angle.publish(msg2)

        #self.get_logger().info('Publishing: "%s"' % str(msg.data))
        self.i += 1

    def listener_callback(self, msg):
        print ('-------RECEIVING LIDAR SENSOR DATA-------')
        print ('Obstacle distance from Front: {}'.format(msg.ranges[360])) #lidar data for front side
        print ('Obstacle distance from Left:  {}'.format(msg.ranges[540])) #lidar data for left side
        print ('Obstacle distance from Right: {}'.format(msg.ranges[180])) #lidar data for right side
        #print ('Back: {}'.format(msg.ranges[180])) #lidar data for back side
        print("--------------------")
        #Obstacle Avoidance
        self.front_threshold = 15.0
        self.sides_threshold = 8.0
        if msg.ranges[360] > self.front_threshold and msg.ranges[365] > self.front_threshold and msg.ranges[355] > self.front_threshold: 
        #when no any obstacle near detected
            print("MOVING STREIGHT")
            self.left_msg.data = 15.0 # go (linear velocity)
            self.right_msg.data  = 15.0 
            # rotate (angular velocity)
            self.left_pub_angle_msg.data = 0.0
            self.right_pub_angle_msg.data = 0.0
            if msg.ranges[175] < self.sides_threshold and msg.ranges[180] < self.sides_threshold and msg.ranges[185] < self.sides_threshold:
                print("MOVING LEFT")
                self.left_pub_angle_msg.data = 1.57
                self.right_pub_angle_msg.data = 1.57  
            elif msg.ranges[535] < self.sides_threshold and msg.ranges[540] < self.sides_threshold and msg.ranges[545] < self.sides_threshold:
                self.left_pub_angle_msg.data = -1.57
                self.right_pub_angle_msg.data = -1.57 
        else: #when an obstacle near detected
            print("TURNING LEFT")

            self.left_msg.data = 0.0 # go (linear velocity)
            self.right_msg.data  = 12.0 
            # rotate (angular velocity)
            self.left_pub_angle_msg.data = 0.0#1.57
            self.right_pub_angle_msg.data = 0.0#1.57            
            # if msg.ranges[0] > self.distance and msg.ranges[15] > self.distance and msg.ranges[345] > self.distance and msg.ranges[45] > self.distance and msg.ranges[315] > self.distance:
            #     #when no any obstacle near detected after rotation
            #     self.left_msg.data = 15.0 # go (linear velocity)
            #     self.right_msg.data  = 15.0 
            #     # rotate (angular velocity)
            #     self.left_pub_angle_msg.data = 45.0
            #     self.right_pub_angle_msg.data = 45.0

        self.left_pub.publish(self.left_msg)
        self.right_pub.publish(self.right_msg)
        self.left_pub_angle.publish(self.left_pub_angle_msg)
        self.right_pub_angle.publish(self.right_pub_angle_msg)


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = Navigator()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
