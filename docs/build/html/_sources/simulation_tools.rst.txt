Simulation Tools
=================
Below is the list of tools (ros2 packages) that are used.

Cartographer
-------------

Cartographer is used to build the map using lidar and IMU. 

.. note:: To run the cartographer turtlebot3 example, source the following in the terminal.

::

    source /opt/ros/galactic/setup.bash
    source install/setup.bash
    source /usr/share/colcon_cd/function/colcon_cd.sh
    export _colcon_cd_root=~/mbzirc_ws
    source ~/mbzirc_ws/install/setup.bash
    export TURTLEBOT3_MODEL=burger
    export GAZEBO_MODEL_PATH=~/mbzirc_ws/src/ros2_explorer/explorer_gazebo/models

Navigation2
------------

Navigation2 is used for autonomous navigation 







