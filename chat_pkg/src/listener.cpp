#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace ros;

void chatterCallback(const std_msgs::String::ConstPtr &msg)
{
	ROS_INFO("I herd: [%s]", msg->data.c_str());
}


int main (int argc, char **argv)
{
	init(argc, argv, "listener");
	NodeHandle node;

	Subscriber sub = node.subscribe("chatter", 1000, chatterCallback);

	ros::spin();
}
