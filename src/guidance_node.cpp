#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>

#include <dji/utils.h>
#include <dji/guidance.h>
#include <guidance/guidanceConfig.h>
#include "guidance_manager.hpp"

GuidanceManager *GuidanceManager::s_instance_ = 0;

void config_callback(guidance::guidanceConfig &config, uint32_t level) {}

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "guidance_node");
  ros::NodeHandle nh("~");
  /*
    dynamic_reconfigure::Server<guidance::guidanceConfig> server;
    dynamic_reconfigure::Server<guidance::guidanceConfig>::CallbackType f;

    f = boost::bind(&config_callback, _1, _2);
    server.setCallback(f);
  */
  ROS_INFO("Test");
  if (GuidanceManager::getInstance()->init(nh)) {
    std::cout << "Uh oh..." << std::endl;
    return 1;
  }

  ros::spin();

  return 0;
}
