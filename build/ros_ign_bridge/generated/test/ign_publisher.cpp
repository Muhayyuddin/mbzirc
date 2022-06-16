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

// This file is generated from test/resource/ign_publisher.cpp.em

#include <ignition/msgs.hh>
#include <ignition/transport.hh>

#include <atomic>
#include <chrono>
#include <csignal>
#include <iostream>
#include <string>
#include <thread>

#include "utils/test_utils.hpp"
#include "utils/ign_test_msg.hpp"

/// \brief Flag used to break the publisher loop and terminate the program.
static std::atomic<bool> g_terminatePub(false);

//////////////////////////////////////////////////
/// \brief Function callback executed when a SIGINT or SIGTERM signals are
/// captured. This is used to break the infinite loop that publishes messages
/// and exit the program smoothly.
/// \param[in] _signal signal number (interrupt or terminate)
void signal_handler(int _signal)
{
  if (_signal == SIGINT || _signal == SIGTERM) {
    g_terminatePub = true;
  }
}

//////////////////////////////////////////////////
int main(int /*argc*/, char **/*argv*/)
{
  // Install a signal handler for SIGINT and SIGTERM.
  std::signal(SIGINT, signal_handler);
  std::signal(SIGTERM, signal_handler);

  // Create a transport node and advertise a topic.
  ignition::transport::Node node;

  // ignition.msgs.Vector3d.
  auto vector3d_point_pub = 
    node.Advertise<ignition::msgs::Vector3d>("vector3d_point");
  ignition::msgs::Vector3d vector3d_point_msg;
  ros_ign_bridge::testing::createTestMsg(vector3d_point_msg);

  // ignition.msgs.Pose.
  auto pose_pose_pub = 
    node.Advertise<ignition::msgs::Pose>("pose_pose");
  ignition::msgs::Pose pose_pose_msg;
  ros_ign_bridge::testing::createTestMsg(pose_pose_msg);

  // ignition.msgs.Pose.
  auto pose_posestamped_pub = 
    node.Advertise<ignition::msgs::Pose>("pose_posestamped");
  ignition::msgs::Pose pose_posestamped_msg;
  ros_ign_bridge::testing::createTestMsg(pose_posestamped_msg);

  // ignition.msgs.Quaternion.
  auto quaternion_quaternion_pub = 
    node.Advertise<ignition::msgs::Quaternion>("quaternion_quaternion");
  ignition::msgs::Quaternion quaternion_quaternion_msg;
  ros_ign_bridge::testing::createTestMsg(quaternion_quaternion_msg);

  // ignition.msgs.Pose.
  auto pose_transform_pub = 
    node.Advertise<ignition::msgs::Pose>("pose_transform");
  ignition::msgs::Pose pose_transform_msg;
  ros_ign_bridge::testing::createTestMsg(pose_transform_msg);

  // ignition.msgs.Pose.
  auto pose_transformstamped_pub = 
    node.Advertise<ignition::msgs::Pose>("pose_transformstamped");
  ignition::msgs::Pose pose_transformstamped_msg;
  ros_ign_bridge::testing::createTestMsg(pose_transformstamped_msg);

  // ignition.msgs.Twist.
  auto twist_twist_pub = 
    node.Advertise<ignition::msgs::Twist>("twist_twist");
  ignition::msgs::Twist twist_twist_msg;
  ros_ign_bridge::testing::createTestMsg(twist_twist_msg);

  // ignition.msgs.Vector3d.
  auto vector3d_vector3_pub = 
    node.Advertise<ignition::msgs::Vector3d>("vector3d_vector3");
  ignition::msgs::Vector3d vector3d_vector3_msg;
  ros_ign_bridge::testing::createTestMsg(vector3d_vector3_msg);

  // ignition.msgs.Wrench.
  auto wrench_wrench_pub = 
    node.Advertise<ignition::msgs::Wrench>("wrench_wrench");
  ignition::msgs::Wrench wrench_wrench_msg;
  ros_ign_bridge::testing::createTestMsg(wrench_wrench_msg);

  // ignition.msgs.Odometry.
  auto odometry_odometry_pub = 
    node.Advertise<ignition::msgs::Odometry>("odometry_odometry");
  ignition::msgs::Odometry odometry_odometry_msg;
  ros_ign_bridge::testing::createTestMsg(odometry_odometry_msg);

  // ignition.msgs.Contact.
  auto contact_contact_pub = 
    node.Advertise<ignition::msgs::Contact>("contact_contact");
  ignition::msgs::Contact contact_contact_msg;
  ros_ign_bridge::testing::createTestMsg(contact_contact_msg);

  // ignition.msgs.Contacts.
  auto contacts_contacts_pub = 
    node.Advertise<ignition::msgs::Contacts>("contacts_contacts");
  ignition::msgs::Contacts contacts_contacts_msg;
  ros_ign_bridge::testing::createTestMsg(contacts_contacts_msg);

  // ignition.msgs.Dataframe.
  auto dataframe_dataframe_pub = 
    node.Advertise<ignition::msgs::Dataframe>("dataframe_dataframe");
  ignition::msgs::Dataframe dataframe_dataframe_msg;
  ros_ign_bridge::testing::createTestMsg(dataframe_dataframe_msg);

  // ignition.msgs.Entity.
  auto entity_entity_pub = 
    node.Advertise<ignition::msgs::Entity>("entity_entity");
  ignition::msgs::Entity entity_entity_msg;
  ros_ign_bridge::testing::createTestMsg(entity_entity_msg);

  // ignition.msgs.GUICamera.
  auto guicamera_guicamera_pub = 
    node.Advertise<ignition::msgs::GUICamera>("guicamera_guicamera");
  ignition::msgs::GUICamera guicamera_guicamera_msg;
  ros_ign_bridge::testing::createTestMsg(guicamera_guicamera_msg);

  // ignition.msgs.JointWrench.
  auto jointwrench_jointwrench_pub = 
    node.Advertise<ignition::msgs::JointWrench>("jointwrench_jointwrench");
  ignition::msgs::JointWrench jointwrench_jointwrench_msg;
  ros_ign_bridge::testing::createTestMsg(jointwrench_jointwrench_msg);

  // ignition.msgs.Light.
  auto light_light_pub = 
    node.Advertise<ignition::msgs::Light>("light_light");
  ignition::msgs::Light light_light_msg;
  ros_ign_bridge::testing::createTestMsg(light_light_msg);

  // ignition.msgs.StringMsg_V.
  auto stringmsg_v_stringvec_pub = 
    node.Advertise<ignition::msgs::StringMsg_V>("stringmsg_v_stringvec");
  ignition::msgs::StringMsg_V stringmsg_v_stringvec_msg;
  ros_ign_bridge::testing::createTestMsg(stringmsg_v_stringvec_msg);

  // ignition.msgs.TrackVisual.
  auto trackvisual_trackvisual_pub = 
    node.Advertise<ignition::msgs::TrackVisual>("trackvisual_trackvisual");
  ignition::msgs::TrackVisual trackvisual_trackvisual_msg;
  ros_ign_bridge::testing::createTestMsg(trackvisual_trackvisual_msg);

  // ignition.msgs.VideoRecord.
  auto videorecord_videorecord_pub = 
    node.Advertise<ignition::msgs::VideoRecord>("videorecord_videorecord");
  ignition::msgs::VideoRecord videorecord_videorecord_msg;
  ros_ign_bridge::testing::createTestMsg(videorecord_videorecord_msg);

  // ignition.msgs.Clock.
  auto clock_clock_pub = 
    node.Advertise<ignition::msgs::Clock>("clock_clock");
  ignition::msgs::Clock clock_clock_msg;
  ros_ign_bridge::testing::createTestMsg(clock_clock_msg);

  // ignition.msgs.BatteryState.
  auto batterystate_batterystate_pub = 
    node.Advertise<ignition::msgs::BatteryState>("batterystate_batterystate");
  ignition::msgs::BatteryState batterystate_batterystate_msg;
  ros_ign_bridge::testing::createTestMsg(batterystate_batterystate_msg);

  // ignition.msgs.CameraInfo.
  auto camerainfo_camerainfo_pub = 
    node.Advertise<ignition::msgs::CameraInfo>("camerainfo_camerainfo");
  ignition::msgs::CameraInfo camerainfo_camerainfo_msg;
  ros_ign_bridge::testing::createTestMsg(camerainfo_camerainfo_msg);

  // ignition.msgs.FluidPressure.
  auto fluidpressure_fluidpressure_pub = 
    node.Advertise<ignition::msgs::FluidPressure>("fluidpressure_fluidpressure");
  ignition::msgs::FluidPressure fluidpressure_fluidpressure_msg;
  ros_ign_bridge::testing::createTestMsg(fluidpressure_fluidpressure_msg);

  // ignition.msgs.Image.
  auto image_image_pub = 
    node.Advertise<ignition::msgs::Image>("image_image");
  ignition::msgs::Image image_image_msg;
  ros_ign_bridge::testing::createTestMsg(image_image_msg);

  // ignition.msgs.IMU.
  auto imu_imu_pub = 
    node.Advertise<ignition::msgs::IMU>("imu_imu");
  ignition::msgs::IMU imu_imu_msg;
  ros_ign_bridge::testing::createTestMsg(imu_imu_msg);

  // ignition.msgs.Model.
  auto model_jointstate_pub = 
    node.Advertise<ignition::msgs::Model>("model_jointstate");
  ignition::msgs::Model model_jointstate_msg;
  ros_ign_bridge::testing::createTestMsg(model_jointstate_msg);

  // ignition.msgs.LaserScan.
  auto laserscan_laserscan_pub = 
    node.Advertise<ignition::msgs::LaserScan>("laserscan_laserscan");
  ignition::msgs::LaserScan laserscan_laserscan_msg;
  ros_ign_bridge::testing::createTestMsg(laserscan_laserscan_msg);

  // ignition.msgs.Magnetometer.
  auto magnetometer_magneticfield_pub = 
    node.Advertise<ignition::msgs::Magnetometer>("magnetometer_magneticfield");
  ignition::msgs::Magnetometer magnetometer_magneticfield_msg;
  ros_ign_bridge::testing::createTestMsg(magnetometer_magneticfield_msg);

  // ignition.msgs.PointCloudPacked.
  auto pointcloudpacked_pointcloud2_pub = 
    node.Advertise<ignition::msgs::PointCloudPacked>("pointcloudpacked_pointcloud2");
  ignition::msgs::PointCloudPacked pointcloudpacked_pointcloud2_msg;
  ros_ign_bridge::testing::createTestMsg(pointcloudpacked_pointcloud2_msg);

  // ignition.msgs.Boolean.
  auto boolean_bool_pub = 
    node.Advertise<ignition::msgs::Boolean>("boolean_bool");
  ignition::msgs::Boolean boolean_bool_msg;
  ros_ign_bridge::testing::createTestMsg(boolean_bool_msg);

  // ignition.msgs.Color.
  auto color_colorrgba_pub = 
    node.Advertise<ignition::msgs::Color>("color_colorrgba");
  ignition::msgs::Color color_colorrgba_msg;
  ros_ign_bridge::testing::createTestMsg(color_colorrgba_msg);

  // ignition.msgs.Empty.
  auto empty_empty_pub = 
    node.Advertise<ignition::msgs::Empty>("empty_empty");
  ignition::msgs::Empty empty_empty_msg;
  ros_ign_bridge::testing::createTestMsg(empty_empty_msg);

  // ignition.msgs.Float.
  auto float_float32_pub = 
    node.Advertise<ignition::msgs::Float>("float_float32");
  ignition::msgs::Float float_float32_msg;
  ros_ign_bridge::testing::createTestMsg(float_float32_msg);

  // ignition.msgs.Double.
  auto double_float64_pub = 
    node.Advertise<ignition::msgs::Double>("double_float64");
  ignition::msgs::Double double_float64_msg;
  ros_ign_bridge::testing::createTestMsg(double_float64_msg);

  // ignition.msgs.Header.
  auto header_header_pub = 
    node.Advertise<ignition::msgs::Header>("header_header");
  ignition::msgs::Header header_header_msg;
  ros_ign_bridge::testing::createTestMsg(header_header_msg);

  // ignition.msgs.Int32.
  auto int32_int32_pub = 
    node.Advertise<ignition::msgs::Int32>("int32_int32");
  ignition::msgs::Int32 int32_int32_msg;
  ros_ign_bridge::testing::createTestMsg(int32_int32_msg);

  // ignition.msgs.StringMsg.
  auto stringmsg_string_pub = 
    node.Advertise<ignition::msgs::StringMsg>("stringmsg_string");
  ignition::msgs::StringMsg stringmsg_string_msg;
  ros_ign_bridge::testing::createTestMsg(stringmsg_string_msg);

  // ignition.msgs.UInt32.
  auto uint32_uint32_pub = 
    node.Advertise<ignition::msgs::UInt32>("uint32_uint32");
  ignition::msgs::UInt32 uint32_uint32_msg;
  ros_ign_bridge::testing::createTestMsg(uint32_uint32_msg);

  // ignition.msgs.Pose_V.
  auto pose_v_tfmessage_pub = 
    node.Advertise<ignition::msgs::Pose_V>("pose_v_tfmessage");
  ignition::msgs::Pose_V pose_v_tfmessage_msg;
  ros_ign_bridge::testing::createTestMsg(pose_v_tfmessage_msg);

  // ignition.msgs.JointTrajectory.
  auto jointtrajectory_jointtrajectory_pub = 
    node.Advertise<ignition::msgs::JointTrajectory>("jointtrajectory_jointtrajectory");
  ignition::msgs::JointTrajectory jointtrajectory_jointtrajectory_msg;
  ros_ign_bridge::testing::createTestMsg(jointtrajectory_jointtrajectory_msg);


  // Publish messages at 1Hz.
  while (!g_terminatePub) {
    vector3d_point_pub.Publish(vector3d_point_msg);
    pose_pose_pub.Publish(pose_pose_msg);
    pose_posestamped_pub.Publish(pose_posestamped_msg);
    quaternion_quaternion_pub.Publish(quaternion_quaternion_msg);
    pose_transform_pub.Publish(pose_transform_msg);
    pose_transformstamped_pub.Publish(pose_transformstamped_msg);
    twist_twist_pub.Publish(twist_twist_msg);
    vector3d_vector3_pub.Publish(vector3d_vector3_msg);
    wrench_wrench_pub.Publish(wrench_wrench_msg);
    odometry_odometry_pub.Publish(odometry_odometry_msg);
    contact_contact_pub.Publish(contact_contact_msg);
    contacts_contacts_pub.Publish(contacts_contacts_msg);
    dataframe_dataframe_pub.Publish(dataframe_dataframe_msg);
    entity_entity_pub.Publish(entity_entity_msg);
    guicamera_guicamera_pub.Publish(guicamera_guicamera_msg);
    jointwrench_jointwrench_pub.Publish(jointwrench_jointwrench_msg);
    light_light_pub.Publish(light_light_msg);
    stringmsg_v_stringvec_pub.Publish(stringmsg_v_stringvec_msg);
    trackvisual_trackvisual_pub.Publish(trackvisual_trackvisual_msg);
    videorecord_videorecord_pub.Publish(videorecord_videorecord_msg);
    clock_clock_pub.Publish(clock_clock_msg);
    batterystate_batterystate_pub.Publish(batterystate_batterystate_msg);
    camerainfo_camerainfo_pub.Publish(camerainfo_camerainfo_msg);
    fluidpressure_fluidpressure_pub.Publish(fluidpressure_fluidpressure_msg);
    image_image_pub.Publish(image_image_msg);
    imu_imu_pub.Publish(imu_imu_msg);
    model_jointstate_pub.Publish(model_jointstate_msg);
    laserscan_laserscan_pub.Publish(laserscan_laserscan_msg);
    magnetometer_magneticfield_pub.Publish(magnetometer_magneticfield_msg);
    pointcloudpacked_pointcloud2_pub.Publish(pointcloudpacked_pointcloud2_msg);
    boolean_bool_pub.Publish(boolean_bool_msg);
    color_colorrgba_pub.Publish(color_colorrgba_msg);
    empty_empty_pub.Publish(empty_empty_msg);
    float_float32_pub.Publish(float_float32_msg);
    double_float64_pub.Publish(double_float64_msg);
    header_header_pub.Publish(header_header_msg);
    int32_int32_pub.Publish(int32_int32_msg);
    stringmsg_string_pub.Publish(stringmsg_string_msg);
    uint32_uint32_pub.Publish(uint32_uint32_msg);
    pose_v_tfmessage_pub.Publish(pose_v_tfmessage_msg);
    jointtrajectory_jointtrajectory_pub.Publish(jointtrajectory_jointtrajectory_msg);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
