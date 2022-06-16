# CMake generated Testfile for 
# Source directory: /home/muhayy/mbzirc_ws/src/mbzirc/mbzirc_ros
# Build directory: /home/muhayy/mbzirc_ws/src/build/mbzirc_ros
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_launch_test_ros_api.launch.py "/usr/bin/python3" "-u" "/opt/ros/galactic/share/ament_cmake_test/cmake/run_test.py" "/home/muhayy/mbzirc_ws/src/build/mbzirc_ros/test_results/mbzirc_ros/test_launch_test_ros_api.launch.py.xunit.xml" "--package-name" "mbzirc_ros" "--output-file" "/home/muhayy/mbzirc_ws/src/build/mbzirc_ros/launch_test/test_launch_test_ros_api.launch.py.txt" "--command" "/usr/bin/python3" "-m" "launch_testing.launch_test" "/home/muhayy/mbzirc_ws/src/mbzirc/mbzirc_ros/test/launch/test_ros_api.launch.py" "--junit-xml=/home/muhayy/mbzirc_ws/src/build/mbzirc_ros/test_results/mbzirc_ros/test_launch_test_ros_api.launch.py.xunit.xml" "--package-name=mbzirc_ros")
set_tests_properties(test_launch_test_ros_api.launch.py PROPERTIES  TIMEOUT "300" WORKING_DIRECTORY "/home/muhayy/mbzirc_ws/src/build/mbzirc_ros" _BACKTRACE_TRIPLES "/opt/ros/galactic/share/ament_cmake_test/cmake/ament_add_test.cmake;124;add_test;/opt/ros/galactic/share/launch_testing_ament_cmake/cmake/add_launch_test.cmake;125;ament_add_test;/home/muhayy/mbzirc_ws/src/mbzirc/mbzirc_ros/CMakeLists.txt;104;add_launch_test;/home/muhayy/mbzirc_ws/src/mbzirc/mbzirc_ros/CMakeLists.txt;0;")
subdirs("gtest")
