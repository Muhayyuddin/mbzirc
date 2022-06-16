// Copyright 2022 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <rclcpp/rclcpp.hpp>
#include "utils/test_utils.hpp"
#include "utils/ros_test_msg.hpp"

//////////////////////////////////////////////////
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("ros_string_publisher");
  rclcpp::Rate loop_rate(1);

  // geometry_msgs/msg/Point.
  auto vector3d_point_pub = 
    node->create_publisher<geometry_msgs::msg::Point>("vector3d_point", 1000);
  geometry_msgs::msg::Point vector3d_point_msg;
  ros_ign_bridge::testing::createTestMsg(vector3d_point_msg);

  // geometry_msgs/msg/Pose.
  auto pose_pose_pub = 
    node->create_publisher<geometry_msgs::msg::Pose>("pose_pose", 1000);
  geometry_msgs::msg::Pose pose_pose_msg;
  ros_ign_bridge::testing::createTestMsg(pose_pose_msg);

  // geometry_msgs/msg/PoseStamped.
  auto pose_posestamped_pub = 
    node->create_publisher<geometry_msgs::msg::PoseStamped>("pose_posestamped", 1000);
  geometry_msgs::msg::PoseStamped pose_posestamped_msg;
  ros_ign_bridge::testing::createTestMsg(pose_posestamped_msg);

  // geometry_msgs/msg/Quaternion.
  auto quaternion_quaternion_pub = 
    node->create_publisher<geometry_msgs::msg::Quaternion>("quaternion_quaternion", 1000);
  geometry_msgs::msg::Quaternion quaternion_quaternion_msg;
  ros_ign_bridge::testing::createTestMsg(quaternion_quaternion_msg);

  // geometry_msgs/msg/Transform.
  auto pose_transform_pub = 
    node->create_publisher<geometry_msgs::msg::Transform>("pose_transform", 1000);
  geometry_msgs::msg::Transform pose_transform_msg;
  ros_ign_bridge::testing::createTestMsg(pose_transform_msg);

  // geometry_msgs/msg/TransformStamped.
  auto pose_transformstamped_pub = 
    node->create_publisher<geometry_msgs::msg::TransformStamped>("pose_transformstamped", 1000);
  geometry_msgs::msg::TransformStamped pose_transformstamped_msg;
  ros_ign_bridge::testing::createTestMsg(pose_transformstamped_msg);

  // geometry_msgs/msg/Twist.
  auto twist_twist_pub = 
    node->create_publisher<geometry_msgs::msg::Twist>("twist_twist", 1000);
  geometry_msgs::msg::Twist twist_twist_msg;
  ros_ign_bridge::testing::createTestMsg(twist_twist_msg);

  // geometry_msgs/msg/Vector3.
  auto vector3d_vector3_pub = 
    node->create_publisher<geometry_msgs::msg::Vector3>("vector3d_vector3", 1000);
  geometry_msgs::msg::Vector3 vector3d_vector3_msg;
  ros_ign_bridge::testing::createTestMsg(vector3d_vector3_msg);

  // geometry_msgs/msg/Wrench.
  auto wrench_wrench_pub = 
    node->create_publisher<geometry_msgs::msg::Wrench>("wrench_wrench", 1000);
  geometry_msgs::msg::Wrench wrench_wrench_msg;
  ros_ign_bridge::testing::createTestMsg(wrench_wrench_msg);

  // nav_msgs/msg/Odometry.
  auto odometry_odometry_pub = 
    node->create_publisher<nav_msgs::msg::Odometry>("odometry_odometry", 1000);
  nav_msgs::msg::Odometry odometry_odometry_msg;
  ros_ign_bridge::testing::createTestMsg(odometry_odometry_msg);

  // ros_ign_interfaces/msg/Contact.
  auto contact_contact_pub = 
    node->create_publisher<ros_ign_interfaces::msg::Contact>("contact_contact", 1000);
  ros_ign_interfaces::msg::Contact contact_contact_msg;
  ros_ign_bridge::testing::createTestMsg(contact_contact_msg);

  // ros_ign_interfaces/msg/Contacts.
  auto contacts_contacts_pub = 
    node->create_publisher<ros_ign_interfaces::msg::Contacts>("contacts_contacts", 1000);
  ros_ign_interfaces::msg::Contacts contacts_contacts_msg;
  ros_ign_bridge::testing::createTestMsg(contacts_contacts_msg);

  // ros_ign_interfaces/msg/Dataframe.
  auto dataframe_dataframe_pub = 
    node->create_publisher<ros_ign_interfaces::msg::Dataframe>("dataframe_dataframe", 1000);
  ros_ign_interfaces::msg::Dataframe dataframe_dataframe_msg;
  ros_ign_bridge::testing::createTestMsg(dataframe_dataframe_msg);

  // ros_ign_interfaces/msg/Entity.
  auto entity_entity_pub = 
    node->create_publisher<ros_ign_interfaces::msg::Entity>("entity_entity", 1000);
  ros_ign_interfaces::msg::Entity entity_entity_msg;
  ros_ign_bridge::testing::createTestMsg(entity_entity_msg);

  // ros_ign_interfaces/msg/GuiCamera.
  auto guicamera_guicamera_pub = 
    node->create_publisher<ros_ign_interfaces::msg::GuiCamera>("guicamera_guicamera", 1000);
  ros_ign_interfaces::msg::GuiCamera guicamera_guicamera_msg;
  ros_ign_bridge::testing::createTestMsg(guicamera_guicamera_msg);

  // ros_ign_interfaces/msg/JointWrench.
  auto jointwrench_jointwrench_pub = 
    node->create_publisher<ros_ign_interfaces::msg::JointWrench>("jointwrench_jointwrench", 1000);
  ros_ign_interfaces::msg::JointWrench jointwrench_jointwrench_msg;
  ros_ign_bridge::testing::createTestMsg(jointwrench_jointwrench_msg);

  // ros_ign_interfaces/msg/Light.
  auto light_light_pub = 
    node->create_publisher<ros_ign_interfaces::msg::Light>("light_light", 1000);
  ros_ign_interfaces::msg::Light light_light_msg;
  ros_ign_bridge::testing::createTestMsg(light_light_msg);

  // ros_ign_interfaces/msg/StringVec.
  auto stringmsg_v_stringvec_pub = 
    node->create_publisher<ros_ign_interfaces::msg::StringVec>("stringmsg_v_stringvec", 1000);
  ros_ign_interfaces::msg::StringVec stringmsg_v_stringvec_msg;
  ros_ign_bridge::testing::createTestMsg(stringmsg_v_stringvec_msg);

  // ros_ign_interfaces/msg/TrackVisual.
  auto trackvisual_trackvisual_pub = 
    node->create_publisher<ros_ign_interfaces::msg::TrackVisual>("trackvisual_trackvisual", 1000);
  ros_ign_interfaces::msg::TrackVisual trackvisual_trackvisual_msg;
  ros_ign_bridge::testing::createTestMsg(trackvisual_trackvisual_msg);

  // ros_ign_interfaces/msg/VideoRecord.
  auto videorecord_videorecord_pub = 
    node->create_publisher<ros_ign_interfaces::msg::VideoRecord>("videorecord_videorecord", 1000);
  ros_ign_interfaces::msg::VideoRecord videorecord_videorecord_msg;
  ros_ign_bridge::testing::createTestMsg(videorecord_videorecord_msg);

  // rosgraph_msgs/msg/Clock.
  auto clock_clock_pub = 
    node->create_publisher<rosgraph_msgs::msg::Clock>("clock_clock", 1000);
  rosgraph_msgs::msg::Clock clock_clock_msg;
  ros_ign_bridge::testing::createTestMsg(clock_clock_msg);

  // sensor_msgs/msg/BatteryState.
  auto batterystate_batterystate_pub = 
    node->create_publisher<sensor_msgs::msg::BatteryState>("batterystate_batterystate", 1000);
  sensor_msgs::msg::BatteryState batterystate_batterystate_msg;
  ros_ign_bridge::testing::createTestMsg(batterystate_batterystate_msg);

  // sensor_msgs/msg/CameraInfo.
  auto camerainfo_camerainfo_pub = 
    node->create_publisher<sensor_msgs::msg::CameraInfo>("camerainfo_camerainfo", 1000);
  sensor_msgs::msg::CameraInfo camerainfo_camerainfo_msg;
  ros_ign_bridge::testing::createTestMsg(camerainfo_camerainfo_msg);

  // sensor_msgs/msg/FluidPressure.
  auto fluidpressure_fluidpressure_pub = 
    node->create_publisher<sensor_msgs::msg::FluidPressure>("fluidpressure_fluidpressure", 1000);
  sensor_msgs::msg::FluidPressure fluidpressure_fluidpressure_msg;
  ros_ign_bridge::testing::createTestMsg(fluidpressure_fluidpressure_msg);

  // sensor_msgs/msg/Image.
  auto image_image_pub = 
    node->create_publisher<sensor_msgs::msg::Image>("image_image", 1000);
  sensor_msgs::msg::Image image_image_msg;
  ros_ign_bridge::testing::createTestMsg(image_image_msg);

  // sensor_msgs/msg/Imu.
  auto imu_imu_pub = 
    node->create_publisher<sensor_msgs::msg::Imu>("imu_imu", 1000);
  sensor_msgs::msg::Imu imu_imu_msg;
  ros_ign_bridge::testing::createTestMsg(imu_imu_msg);

  // sensor_msgs/msg/JointState.
  auto model_jointstate_pub = 
    node->create_publisher<sensor_msgs::msg::JointState>("model_jointstate", 1000);
  sensor_msgs::msg::JointState model_jointstate_msg;
  ros_ign_bridge::testing::createTestMsg(model_jointstate_msg);

  // sensor_msgs/msg/LaserScan.
  auto laserscan_laserscan_pub = 
    node->create_publisher<sensor_msgs::msg::LaserScan>("laserscan_laserscan", 1000);
  sensor_msgs::msg::LaserScan laserscan_laserscan_msg;
  ros_ign_bridge::testing::createTestMsg(laserscan_laserscan_msg);

  // sensor_msgs/msg/MagneticField.
  auto magnetometer_magneticfield_pub = 
    node->create_publisher<sensor_msgs::msg::MagneticField>("magnetometer_magneticfield", 1000);
  sensor_msgs::msg::MagneticField magnetometer_magneticfield_msg;
  ros_ign_bridge::testing::createTestMsg(magnetometer_magneticfield_msg);

  // sensor_msgs/msg/PointCloud2.
  auto pointcloudpacked_pointcloud2_pub = 
    node->create_publisher<sensor_msgs::msg::PointCloud2>("pointcloudpacked_pointcloud2", 1000);
  sensor_msgs::msg::PointCloud2 pointcloudpacked_pointcloud2_msg;
  ros_ign_bridge::testing::createTestMsg(pointcloudpacked_pointcloud2_msg);

  // std_msgs/msg/Bool.
  auto boolean_bool_pub = 
    node->create_publisher<std_msgs::msg::Bool>("boolean_bool", 1000);
  std_msgs::msg::Bool boolean_bool_msg;
  ros_ign_bridge::testing::createTestMsg(boolean_bool_msg);

  // std_msgs/msg/ColorRGBA.
  auto color_colorrgba_pub = 
    node->create_publisher<std_msgs::msg::ColorRGBA>("color_colorrgba", 1000);
  std_msgs::msg::ColorRGBA color_colorrgba_msg;
  ros_ign_bridge::testing::createTestMsg(color_colorrgba_msg);

  // std_msgs/msg/Empty.
  auto empty_empty_pub = 
    node->create_publisher<std_msgs::msg::Empty>("empty_empty", 1000);
  std_msgs::msg::Empty empty_empty_msg;
  ros_ign_bridge::testing::createTestMsg(empty_empty_msg);

  // std_msgs/msg/Float32.
  auto float_float32_pub = 
    node->create_publisher<std_msgs::msg::Float32>("float_float32", 1000);
  std_msgs::msg::Float32 float_float32_msg;
  ros_ign_bridge::testing::createTestMsg(float_float32_msg);

  // std_msgs/msg/Float64.
  auto double_float64_pub = 
    node->create_publisher<std_msgs::msg::Float64>("double_float64", 1000);
  std_msgs::msg::Float64 double_float64_msg;
  ros_ign_bridge::testing::createTestMsg(double_float64_msg);

  // std_msgs/msg/Header.
  auto header_header_pub = 
    node->create_publisher<std_msgs::msg::Header>("header_header", 1000);
  std_msgs::msg::Header header_header_msg;
  ros_ign_bridge::testing::createTestMsg(header_header_msg);

  // std_msgs/msg/Int32.
  auto int32_int32_pub = 
    node->create_publisher<std_msgs::msg::Int32>("int32_int32", 1000);
  std_msgs::msg::Int32 int32_int32_msg;
  ros_ign_bridge::testing::createTestMsg(int32_int32_msg);

  // std_msgs/msg/String.
  auto stringmsg_string_pub = 
    node->create_publisher<std_msgs::msg::String>("stringmsg_string", 1000);
  std_msgs::msg::String stringmsg_string_msg;
  ros_ign_bridge::testing::createTestMsg(stringmsg_string_msg);

  // std_msgs/msg/UInt32.
  auto uint32_uint32_pub = 
    node->create_publisher<std_msgs::msg::UInt32>("uint32_uint32", 1000);
  std_msgs::msg::UInt32 uint32_uint32_msg;
  ros_ign_bridge::testing::createTestMsg(uint32_uint32_msg);

  // tf2_msgs/msg/TFMessage.
  auto pose_v_tfmessage_pub = 
    node->create_publisher<tf2_msgs::msg::TFMessage>("pose_v_tfmessage", 1000);
  tf2_msgs::msg::TFMessage pose_v_tfmessage_msg;
  ros_ign_bridge::testing::createTestMsg(pose_v_tfmessage_msg);

  // trajectory_msgs/msg/JointTrajectory.
  auto jointtrajectory_jointtrajectory_pub = 
    node->create_publisher<trajectory_msgs::msg::JointTrajectory>("jointtrajectory_jointtrajectory", 1000);
  trajectory_msgs::msg::JointTrajectory jointtrajectory_jointtrajectory_msg;
  ros_ign_bridge::testing::createTestMsg(jointtrajectory_jointtrajectory_msg);


  while (rclcpp::ok()) {
    // Publish all messages.
    vector3d_point_pub->publish(vector3d_point_msg);
    pose_pose_pub->publish(pose_pose_msg);
    pose_posestamped_pub->publish(pose_posestamped_msg);
    quaternion_quaternion_pub->publish(quaternion_quaternion_msg);
    pose_transform_pub->publish(pose_transform_msg);
    pose_transformstamped_pub->publish(pose_transformstamped_msg);
    twist_twist_pub->publish(twist_twist_msg);
    vector3d_vector3_pub->publish(vector3d_vector3_msg);
    wrench_wrench_pub->publish(wrench_wrench_msg);
    odometry_odometry_pub->publish(odometry_odometry_msg);
    contact_contact_pub->publish(contact_contact_msg);
    contacts_contacts_pub->publish(contacts_contacts_msg);
    dataframe_dataframe_pub->publish(dataframe_dataframe_msg);
    entity_entity_pub->publish(entity_entity_msg);
    guicamera_guicamera_pub->publish(guicamera_guicamera_msg);
    jointwrench_jointwrench_pub->publish(jointwrench_jointwrench_msg);
    light_light_pub->publish(light_light_msg);
    stringmsg_v_stringvec_pub->publish(stringmsg_v_stringvec_msg);
    trackvisual_trackvisual_pub->publish(trackvisual_trackvisual_msg);
    videorecord_videorecord_pub->publish(videorecord_videorecord_msg);
    clock_clock_pub->publish(clock_clock_msg);
    batterystate_batterystate_pub->publish(batterystate_batterystate_msg);
    camerainfo_camerainfo_pub->publish(camerainfo_camerainfo_msg);
    fluidpressure_fluidpressure_pub->publish(fluidpressure_fluidpressure_msg);
    image_image_pub->publish(image_image_msg);
    imu_imu_pub->publish(imu_imu_msg);
    model_jointstate_pub->publish(model_jointstate_msg);
    laserscan_laserscan_pub->publish(laserscan_laserscan_msg);
    magnetometer_magneticfield_pub->publish(magnetometer_magneticfield_msg);
    pointcloudpacked_pointcloud2_pub->publish(pointcloudpacked_pointcloud2_msg);
    boolean_bool_pub->publish(boolean_bool_msg);
    color_colorrgba_pub->publish(color_colorrgba_msg);
    empty_empty_pub->publish(empty_empty_msg);
    float_float32_pub->publish(float_float32_msg);
    double_float64_pub->publish(double_float64_msg);
    header_header_pub->publish(header_header_msg);
    int32_int32_pub->publish(int32_int32_msg);
    stringmsg_string_pub->publish(stringmsg_string_msg);
    uint32_uint32_pub->publish(uint32_uint32_msg);
    pose_v_tfmessage_pub->publish(pose_v_tfmessage_msg);
    jointtrajectory_jointtrajectory_pub->publish(jointtrajectory_jointtrajectory_msg);

    rclcpp::spin_some(node);
    loop_rate.sleep();
  }

  return 0;
}
