#include <functional>
#include <future>
#include <memory>
#include <string>
#include <sstream>


#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "rclcpp_components/register_node_macro.hpp"


class NavActionClient : public rclcpp::Node
{
public:
  using NavigateToPose = nav2_msgs::action::NavigateToPose;
  using GoalHandleNav = rclcpp_action::ClientGoalHandle<NavigateToPose>;

  explicit NavActionClient(const rclcpp::NodeOptions & options)
  : Node("nav_client", options)
  {
    this->client_ptr_ = rclcpp_action::create_client<NavigateToPose>(
      this,
      "/navigate_to_pose");

    this->timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&NavActionClient::cancel_goal, this));
  }
   void cancel_goal()
   { 
   if (!this->client_ptr_->wait_for_action_server()) {
      RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
      rclcpp::shutdown();
    }

   this->client_ptr_->async_cancel_all_goals();
   RCLCPP_INFO(this->get_logger(), "All goals cancelled");
   rclcpp::shutdown();
   }
   private:
    rclcpp_action::Client<NavigateToPose>::SharedPtr client_ptr_;
    rclcpp::TimerBase::SharedPtr timer_;
};
RCLCPP_COMPONENTS_REGISTER_NODE(NavActionClient)    
