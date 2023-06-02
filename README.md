# void_interview
*nav_cpp* is a ros2 package responsible for cancelling all goals send to the BT navigator of nav2 package. The video shows the robot going to the goal pose,
which is set by using rviz interface. Then the node *cancel_all_goals* responsible for cancelling all goals is spawned in the terminal and the robot stops. 

## How To run:
Install ROS2 Humble and Gazebo classic. Source ros2 and gazebo workspace:
```
source /opt/ros/humble/setup.bash
source /usr/share/gazebo/setup.sh
```
Install Nav2 and turtlebot 3 packages for ros2:
```
sudo apt install ros-humble-navigation2
sudo apt install ros-humble-nav2-bringup
sudo apt install ros-humble-turtlebot3*
sudo apt install ros-humble-turtlebot3-gazebo
```
export following environment variables:
```
export TURTLEBOT3_MODEL=waffle
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/opt/ros/<ros2-distro>/share/turtlebot3_gazebo/models
```
Create a ros2 workspace. Then put the *nav_cpp* folder in the src folder of the workspace. Then run following in the root folder of the workspace:
```
colcon build
source install/local_setup.bash
```
Run the following for spawning turtlebot3 in rviz and gazebo along with the navigation packages:
```
ros2 launch nav2_bringup tb3_simulation_launch.py headless:=False
```
Run the following for cancelling goals:
```
ros2 run nav_cpp cancel_all_goals
```
