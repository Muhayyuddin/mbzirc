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


#include <gtest/gtest.h>
#include <ignition/transport.hh>

#include <chrono>
#include <memory>
#include <string>

#include "utils/test_utils.hpp"
#include "utils/ign_test_msg.hpp"

//////////////////////////////////////////////////
/// \brief A class for testing Ignition Transport topic subscription.
template<typename IGN_T>
class MyTestClass
{
/// \brief Class constructor.
/// \param[in] _topic Topic to subscribe.
public: explicit MyTestClass(const std::string & _topic)
{
  EXPECT_TRUE(this->node.Subscribe(_topic, &MyTestClass::Cb, this));
}

/// \brief Member function called each time a topic update is received.
/// \param[in] _msg Ignition message to be validated
public: void Cb(const IGN_T & _msg)
{
  ros_ign_bridge::testing::compareTestMsg(std::make_shared<IGN_T>(_msg));
  this->callbackExecuted = true;
}

/// \brief Member variables that flag when the actions are executed.
public: bool callbackExecuted = false;

/// \brief Transport node;
private: ignition::transport::Node node;
};

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, vector3d_point)
{
  MyTestClass<ignition::msgs::Vector3d> client("vector3d_point");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, pose_pose)
{
  MyTestClass<ignition::msgs::Pose> client("pose_pose");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, pose_posestamped)
{
  MyTestClass<ignition::msgs::Pose> client("pose_posestamped");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, quaternion_quaternion)
{
  MyTestClass<ignition::msgs::Quaternion> client("quaternion_quaternion");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, pose_transform)
{
  MyTestClass<ignition::msgs::Pose> client("pose_transform");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, pose_transformstamped)
{
  MyTestClass<ignition::msgs::Pose> client("pose_transformstamped");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, twist_twist)
{
  MyTestClass<ignition::msgs::Twist> client("twist_twist");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, vector3d_vector3)
{
  MyTestClass<ignition::msgs::Vector3d> client("vector3d_vector3");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, wrench_wrench)
{
  MyTestClass<ignition::msgs::Wrench> client("wrench_wrench");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, odometry_odometry)
{
  MyTestClass<ignition::msgs::Odometry> client("odometry_odometry");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, contact_contact)
{
  MyTestClass<ignition::msgs::Contact> client("contact_contact");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, contacts_contacts)
{
  MyTestClass<ignition::msgs::Contacts> client("contacts_contacts");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, dataframe_dataframe)
{
  MyTestClass<ignition::msgs::Dataframe> client("dataframe_dataframe");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, entity_entity)
{
  MyTestClass<ignition::msgs::Entity> client("entity_entity");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, guicamera_guicamera)
{
  MyTestClass<ignition::msgs::GUICamera> client("guicamera_guicamera");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, jointwrench_jointwrench)
{
  MyTestClass<ignition::msgs::JointWrench> client("jointwrench_jointwrench");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, light_light)
{
  MyTestClass<ignition::msgs::Light> client("light_light");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, stringmsg_v_stringvec)
{
  MyTestClass<ignition::msgs::StringMsg_V> client("stringmsg_v_stringvec");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, trackvisual_trackvisual)
{
  MyTestClass<ignition::msgs::TrackVisual> client("trackvisual_trackvisual");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, videorecord_videorecord)
{
  MyTestClass<ignition::msgs::VideoRecord> client("videorecord_videorecord");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, clock_clock)
{
  MyTestClass<ignition::msgs::Clock> client("clock_clock");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, batterystate_batterystate)
{
  MyTestClass<ignition::msgs::BatteryState> client("batterystate_batterystate");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, camerainfo_camerainfo)
{
  MyTestClass<ignition::msgs::CameraInfo> client("camerainfo_camerainfo");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, fluidpressure_fluidpressure)
{
  MyTestClass<ignition::msgs::FluidPressure> client("fluidpressure_fluidpressure");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, image_image)
{
  MyTestClass<ignition::msgs::Image> client("image_image");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, imu_imu)
{
  MyTestClass<ignition::msgs::IMU> client("imu_imu");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, model_jointstate)
{
  MyTestClass<ignition::msgs::Model> client("model_jointstate");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, laserscan_laserscan)
{
  MyTestClass<ignition::msgs::LaserScan> client("laserscan_laserscan");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, magnetometer_magneticfield)
{
  MyTestClass<ignition::msgs::Magnetometer> client("magnetometer_magneticfield");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, pointcloudpacked_pointcloud2)
{
  MyTestClass<ignition::msgs::PointCloudPacked> client("pointcloudpacked_pointcloud2");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, boolean_bool)
{
  MyTestClass<ignition::msgs::Boolean> client("boolean_bool");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, color_colorrgba)
{
  MyTestClass<ignition::msgs::Color> client("color_colorrgba");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, empty_empty)
{
  MyTestClass<ignition::msgs::Empty> client("empty_empty");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, float_float32)
{
  MyTestClass<ignition::msgs::Float> client("float_float32");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, double_float64)
{
  MyTestClass<ignition::msgs::Double> client("double_float64");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, header_header)
{
  MyTestClass<ignition::msgs::Header> client("header_header");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, int32_int32)
{
  MyTestClass<ignition::msgs::Int32> client("int32_int32");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, stringmsg_string)
{
  MyTestClass<ignition::msgs::StringMsg> client("stringmsg_string");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, uint32_uint32)
{
  MyTestClass<ignition::msgs::UInt32> client("uint32_uint32");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, pose_v_tfmessage)
{
  MyTestClass<ignition::msgs::Pose_V> client("pose_v_tfmessage");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
TEST(IgnSubscriberTest, jointtrajectory_jointtrajectory)
{
  MyTestClass<ignition::msgs::JointTrajectory> client("jointtrajectory_jointtrajectory");

  using namespace std::chrono_literals;
  ros_ign_bridge::testing::waitUntilBoolVar(
    client.callbackExecuted, 100ms, 200);

  EXPECT_TRUE(client.callbackExecuted);
}

/////////////////////////////////////////////////
int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
