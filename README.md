# void_interview
*nav_cpp* is a ros2 package responsible for cancelling all goals send to the BT navigator of nav2 package. The video shows the motion of robot going to the goal pose,
which is set by using rviz interface. Then the node *cancel_all_goals* responsible for cancelling all goals is spawned in the terminal and the robot stops. 

## How To run:
First install ROS2 Humble.
Then run this command to install turtlebot3 packages:
```
sudo apt install ros-foxy-turtlebot3*
```

create a ros2 workspace. Then put the *nav_cpp* folder in the src folder of the workspace. Then run *
