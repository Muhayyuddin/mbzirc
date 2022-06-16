// generated from ros_ign_bridge/resource/get_mappings.cpp.em

#include <map>
#include <string>

#include "get_mappings.hpp"

namespace ros_ign_bridge
{

bool
get_ign_to_ros_mapping(const std::string & ign_type_name, std::string & ros_type_name)
{

  if (ign_type_name == "ignition.msgs.Vector3d")
  {
    ros_type_name = "geometry_msgs/msg/Point";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Pose")
  {
    ros_type_name = "geometry_msgs/msg/Pose";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Pose")
  {
    ros_type_name = "geometry_msgs/msg/PoseStamped";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Quaternion")
  {
    ros_type_name = "geometry_msgs/msg/Quaternion";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Pose")
  {
    ros_type_name = "geometry_msgs/msg/Transform";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Pose")
  {
    ros_type_name = "geometry_msgs/msg/TransformStamped";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Twist")
  {
    ros_type_name = "geometry_msgs/msg/Twist";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Vector3d")
  {
    ros_type_name = "geometry_msgs/msg/Vector3";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Wrench")
  {
    ros_type_name = "geometry_msgs/msg/Wrench";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Odometry")
  {
    ros_type_name = "nav_msgs/msg/Odometry";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Contact")
  {
    ros_type_name = "ros_ign_interfaces/msg/Contact";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Contacts")
  {
    ros_type_name = "ros_ign_interfaces/msg/Contacts";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Dataframe")
  {
    ros_type_name = "ros_ign_interfaces/msg/Dataframe";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Entity")
  {
    ros_type_name = "ros_ign_interfaces/msg/Entity";
    return true;
  }
  if (ign_type_name == "ignition.msgs.GUICamera")
  {
    ros_type_name = "ros_ign_interfaces/msg/GuiCamera";
    return true;
  }
  if (ign_type_name == "ignition.msgs.JointWrench")
  {
    ros_type_name = "ros_ign_interfaces/msg/JointWrench";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Light")
  {
    ros_type_name = "ros_ign_interfaces/msg/Light";
    return true;
  }
  if (ign_type_name == "ignition.msgs.StringMsg_V")
  {
    ros_type_name = "ros_ign_interfaces/msg/StringVec";
    return true;
  }
  if (ign_type_name == "ignition.msgs.TrackVisual")
  {
    ros_type_name = "ros_ign_interfaces/msg/TrackVisual";
    return true;
  }
  if (ign_type_name == "ignition.msgs.VideoRecord")
  {
    ros_type_name = "ros_ign_interfaces/msg/VideoRecord";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Clock")
  {
    ros_type_name = "rosgraph_msgs/msg/Clock";
    return true;
  }
  if (ign_type_name == "ignition.msgs.BatteryState")
  {
    ros_type_name = "sensor_msgs/msg/BatteryState";
    return true;
  }
  if (ign_type_name == "ignition.msgs.CameraInfo")
  {
    ros_type_name = "sensor_msgs/msg/CameraInfo";
    return true;
  }
  if (ign_type_name == "ignition.msgs.FluidPressure")
  {
    ros_type_name = "sensor_msgs/msg/FluidPressure";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Image")
  {
    ros_type_name = "sensor_msgs/msg/Image";
    return true;
  }
  if (ign_type_name == "ignition.msgs.IMU")
  {
    ros_type_name = "sensor_msgs/msg/Imu";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Model")
  {
    ros_type_name = "sensor_msgs/msg/JointState";
    return true;
  }
  if (ign_type_name == "ignition.msgs.LaserScan")
  {
    ros_type_name = "sensor_msgs/msg/LaserScan";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Magnetometer")
  {
    ros_type_name = "sensor_msgs/msg/MagneticField";
    return true;
  }
  if (ign_type_name == "ignition.msgs.PointCloudPacked")
  {
    ros_type_name = "sensor_msgs/msg/PointCloud2";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Boolean")
  {
    ros_type_name = "std_msgs/msg/Bool";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Color")
  {
    ros_type_name = "std_msgs/msg/ColorRGBA";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Empty")
  {
    ros_type_name = "std_msgs/msg/Empty";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Float")
  {
    ros_type_name = "std_msgs/msg/Float32";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Double")
  {
    ros_type_name = "std_msgs/msg/Float64";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Header")
  {
    ros_type_name = "std_msgs/msg/Header";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Int32")
  {
    ros_type_name = "std_msgs/msg/Int32";
    return true;
  }
  if (ign_type_name == "ignition.msgs.StringMsg")
  {
    ros_type_name = "std_msgs/msg/String";
    return true;
  }
  if (ign_type_name == "ignition.msgs.UInt32")
  {
    ros_type_name = "std_msgs/msg/UInt32";
    return true;
  }
  if (ign_type_name == "ignition.msgs.Pose_V")
  {
    ros_type_name = "tf2_msgs/msg/TFMessage";
    return true;
  }
  if (ign_type_name == "ignition.msgs.JointTrajectory")
  {
    ros_type_name = "trajectory_msgs/msg/JointTrajectory";
    return true;
  }

  return false;
}

bool
get_ros_to_ign_mapping(const std::string & ros_type_name, std::string & ign_type_name)
{

  if (ros_type_name == "geometry_msgs/msg/Point")
  {
    ign_type_name = "ignition.msgs.Vector3d";
    return true;
  }
  if (ros_type_name == "geometry_msgs/msg/Pose")
  {
    ign_type_name = "ignition.msgs.Pose";
    return true;
  }
  if (ros_type_name == "geometry_msgs/msg/PoseStamped")
  {
    ign_type_name = "ignition.msgs.Pose";
    return true;
  }
  if (ros_type_name == "geometry_msgs/msg/Quaternion")
  {
    ign_type_name = "ignition.msgs.Quaternion";
    return true;
  }
  if (ros_type_name == "geometry_msgs/msg/Transform")
  {
    ign_type_name = "ignition.msgs.Pose";
    return true;
  }
  if (ros_type_name == "geometry_msgs/msg/TransformStamped")
  {
    ign_type_name = "ignition.msgs.Pose";
    return true;
  }
  if (ros_type_name == "geometry_msgs/msg/Twist")
  {
    ign_type_name = "ignition.msgs.Twist";
    return true;
  }
  if (ros_type_name == "geometry_msgs/msg/Vector3")
  {
    ign_type_name = "ignition.msgs.Vector3d";
    return true;
  }
  if (ros_type_name == "geometry_msgs/msg/Wrench")
  {
    ign_type_name = "ignition.msgs.Wrench";
    return true;
  }
  if (ros_type_name == "nav_msgs/msg/Odometry")
  {
    ign_type_name = "ignition.msgs.Odometry";
    return true;
  }
  if (ros_type_name == "ros_ign_interfaces/msg/Contact")
  {
    ign_type_name = "ignition.msgs.Contact";
    return true;
  }
  if (ros_type_name == "ros_ign_interfaces/msg/Contacts")
  {
    ign_type_name = "ignition.msgs.Contacts";
    return true;
  }
  if (ros_type_name == "ros_ign_interfaces/msg/Dataframe")
  {
    ign_type_name = "ignition.msgs.Dataframe";
    return true;
  }
  if (ros_type_name == "ros_ign_interfaces/msg/Entity")
  {
    ign_type_name = "ignition.msgs.Entity";
    return true;
  }
  if (ros_type_name == "ros_ign_interfaces/msg/GuiCamera")
  {
    ign_type_name = "ignition.msgs.GUICamera";
    return true;
  }
  if (ros_type_name == "ros_ign_interfaces/msg/JointWrench")
  {
    ign_type_name = "ignition.msgs.JointWrench";
    return true;
  }
  if (ros_type_name == "ros_ign_interfaces/msg/Light")
  {
    ign_type_name = "ignition.msgs.Light";
    return true;
  }
  if (ros_type_name == "ros_ign_interfaces/msg/StringVec")
  {
    ign_type_name = "ignition.msgs.StringMsg_V";
    return true;
  }
  if (ros_type_name == "ros_ign_interfaces/msg/TrackVisual")
  {
    ign_type_name = "ignition.msgs.TrackVisual";
    return true;
  }
  if (ros_type_name == "ros_ign_interfaces/msg/VideoRecord")
  {
    ign_type_name = "ignition.msgs.VideoRecord";
    return true;
  }
  if (ros_type_name == "rosgraph_msgs/msg/Clock")
  {
    ign_type_name = "ignition.msgs.Clock";
    return true;
  }
  if (ros_type_name == "sensor_msgs/msg/BatteryState")
  {
    ign_type_name = "ignition.msgs.BatteryState";
    return true;
  }
  if (ros_type_name == "sensor_msgs/msg/CameraInfo")
  {
    ign_type_name = "ignition.msgs.CameraInfo";
    return true;
  }
  if (ros_type_name == "sensor_msgs/msg/FluidPressure")
  {
    ign_type_name = "ignition.msgs.FluidPressure";
    return true;
  }
  if (ros_type_name == "sensor_msgs/msg/Image")
  {
    ign_type_name = "ignition.msgs.Image";
    return true;
  }
  if (ros_type_name == "sensor_msgs/msg/Imu")
  {
    ign_type_name = "ignition.msgs.IMU";
    return true;
  }
  if (ros_type_name == "sensor_msgs/msg/JointState")
  {
    ign_type_name = "ignition.msgs.Model";
    return true;
  }
  if (ros_type_name == "sensor_msgs/msg/LaserScan")
  {
    ign_type_name = "ignition.msgs.LaserScan";
    return true;
  }
  if (ros_type_name == "sensor_msgs/msg/MagneticField")
  {
    ign_type_name = "ignition.msgs.Magnetometer";
    return true;
  }
  if (ros_type_name == "sensor_msgs/msg/PointCloud2")
  {
    ign_type_name = "ignition.msgs.PointCloudPacked";
    return true;
  }
  if (ros_type_name == "std_msgs/msg/Bool")
  {
    ign_type_name = "ignition.msgs.Boolean";
    return true;
  }
  if (ros_type_name == "std_msgs/msg/ColorRGBA")
  {
    ign_type_name = "ignition.msgs.Color";
    return true;
  }
  if (ros_type_name == "std_msgs/msg/Empty")
  {
    ign_type_name = "ignition.msgs.Empty";
    return true;
  }
  if (ros_type_name == "std_msgs/msg/Float32")
  {
    ign_type_name = "ignition.msgs.Float";
    return true;
  }
  if (ros_type_name == "std_msgs/msg/Float64")
  {
    ign_type_name = "ignition.msgs.Double";
    return true;
  }
  if (ros_type_name == "std_msgs/msg/Header")
  {
    ign_type_name = "ignition.msgs.Header";
    return true;
  }
  if (ros_type_name == "std_msgs/msg/Int32")
  {
    ign_type_name = "ignition.msgs.Int32";
    return true;
  }
  if (ros_type_name == "std_msgs/msg/String")
  {
    ign_type_name = "ignition.msgs.StringMsg";
    return true;
  }
  if (ros_type_name == "std_msgs/msg/UInt32")
  {
    ign_type_name = "ignition.msgs.UInt32";
    return true;
  }
  if (ros_type_name == "tf2_msgs/msg/TFMessage")
  {
    ign_type_name = "ignition.msgs.Pose_V";
    return true;
  }
  if (ros_type_name == "trajectory_msgs/msg/JointTrajectory")
  {
    ign_type_name = "ignition.msgs.JointTrajectory";
    return true;
  }

  return false;
}

std::multimap<std::string, std::string>
get_all_message_mappings_ros_to_ign()
{
  static std::multimap<std::string, std::string> mappings = {
    {
      "geometry_msgs/msg/Point",  // ROS 2
      "ignition.msgs.Vector3d", // Ignition
    },
    {
      "geometry_msgs/msg/Pose",  // ROS 2
      "ignition.msgs.Pose", // Ignition
    },
    {
      "geometry_msgs/msg/PoseStamped",  // ROS 2
      "ignition.msgs.Pose", // Ignition
    },
    {
      "geometry_msgs/msg/Quaternion",  // ROS 2
      "ignition.msgs.Quaternion", // Ignition
    },
    {
      "geometry_msgs/msg/Transform",  // ROS 2
      "ignition.msgs.Pose", // Ignition
    },
    {
      "geometry_msgs/msg/TransformStamped",  // ROS 2
      "ignition.msgs.Pose", // Ignition
    },
    {
      "geometry_msgs/msg/Twist",  // ROS 2
      "ignition.msgs.Twist", // Ignition
    },
    {
      "geometry_msgs/msg/Vector3",  // ROS 2
      "ignition.msgs.Vector3d", // Ignition
    },
    {
      "geometry_msgs/msg/Wrench",  // ROS 2
      "ignition.msgs.Wrench", // Ignition
    },
    {
      "nav_msgs/msg/Odometry",  // ROS 2
      "ignition.msgs.Odometry", // Ignition
    },
    {
      "ros_ign_interfaces/msg/Contact",  // ROS 2
      "ignition.msgs.Contact", // Ignition
    },
    {
      "ros_ign_interfaces/msg/Contacts",  // ROS 2
      "ignition.msgs.Contacts", // Ignition
    },
    {
      "ros_ign_interfaces/msg/Dataframe",  // ROS 2
      "ignition.msgs.Dataframe", // Ignition
    },
    {
      "ros_ign_interfaces/msg/Entity",  // ROS 2
      "ignition.msgs.Entity", // Ignition
    },
    {
      "ros_ign_interfaces/msg/GuiCamera",  // ROS 2
      "ignition.msgs.GUICamera", // Ignition
    },
    {
      "ros_ign_interfaces/msg/JointWrench",  // ROS 2
      "ignition.msgs.JointWrench", // Ignition
    },
    {
      "ros_ign_interfaces/msg/Light",  // ROS 2
      "ignition.msgs.Light", // Ignition
    },
    {
      "ros_ign_interfaces/msg/StringVec",  // ROS 2
      "ignition.msgs.StringMsg_V", // Ignition
    },
    {
      "ros_ign_interfaces/msg/TrackVisual",  // ROS 2
      "ignition.msgs.TrackVisual", // Ignition
    },
    {
      "ros_ign_interfaces/msg/VideoRecord",  // ROS 2
      "ignition.msgs.VideoRecord", // Ignition
    },
    {
      "rosgraph_msgs/msg/Clock",  // ROS 2
      "ignition.msgs.Clock", // Ignition
    },
    {
      "sensor_msgs/msg/BatteryState",  // ROS 2
      "ignition.msgs.BatteryState", // Ignition
    },
    {
      "sensor_msgs/msg/CameraInfo",  // ROS 2
      "ignition.msgs.CameraInfo", // Ignition
    },
    {
      "sensor_msgs/msg/FluidPressure",  // ROS 2
      "ignition.msgs.FluidPressure", // Ignition
    },
    {
      "sensor_msgs/msg/Image",  // ROS 2
      "ignition.msgs.Image", // Ignition
    },
    {
      "sensor_msgs/msg/Imu",  // ROS 2
      "ignition.msgs.IMU", // Ignition
    },
    {
      "sensor_msgs/msg/JointState",  // ROS 2
      "ignition.msgs.Model", // Ignition
    },
    {
      "sensor_msgs/msg/LaserScan",  // ROS 2
      "ignition.msgs.LaserScan", // Ignition
    },
    {
      "sensor_msgs/msg/MagneticField",  // ROS 2
      "ignition.msgs.Magnetometer", // Ignition
    },
    {
      "sensor_msgs/msg/PointCloud2",  // ROS 2
      "ignition.msgs.PointCloudPacked", // Ignition
    },
    {
      "std_msgs/msg/Bool",  // ROS 2
      "ignition.msgs.Boolean", // Ignition
    },
    {
      "std_msgs/msg/ColorRGBA",  // ROS 2
      "ignition.msgs.Color", // Ignition
    },
    {
      "std_msgs/msg/Empty",  // ROS 2
      "ignition.msgs.Empty", // Ignition
    },
    {
      "std_msgs/msg/Float32",  // ROS 2
      "ignition.msgs.Float", // Ignition
    },
    {
      "std_msgs/msg/Float64",  // ROS 2
      "ignition.msgs.Double", // Ignition
    },
    {
      "std_msgs/msg/Header",  // ROS 2
      "ignition.msgs.Header", // Ignition
    },
    {
      "std_msgs/msg/Int32",  // ROS 2
      "ignition.msgs.Int32", // Ignition
    },
    {
      "std_msgs/msg/String",  // ROS 2
      "ignition.msgs.StringMsg", // Ignition
    },
    {
      "std_msgs/msg/UInt32",  // ROS 2
      "ignition.msgs.UInt32", // Ignition
    },
    {
      "tf2_msgs/msg/TFMessage",  // ROS 2
      "ignition.msgs.Pose_V", // Ignition
    },
    {
      "trajectory_msgs/msg/JointTrajectory",  // ROS 2
      "ignition.msgs.JointTrajectory", // Ignition
    },
  };
  return mappings;
}

}  // namespace ros_ign_bridge
