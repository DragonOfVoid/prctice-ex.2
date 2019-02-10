#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

using namespace ros;

void poseCallback(const turtlesim::PoseConstPtr &msg)
{
	ROS_INFO("x: %.2f; y: %.2f", msg->x, msg->y);
}



int main (int argc, char **argv)
{
	const double FS_MPS = 0.5;
	
	init(argc, argv, "MoveTurtle");
	NodeHandle node;

	Publisher pub = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
	Subscriber sub = node.subscribe("turtle1/pose", 10, poseCallback);

	geometry_msgs::Twist msg;
	msg.linear.x = FS_MPS;
	
	Rate rate(10);
	while (ok())
	{
		pub.publish(msg);
		spinOnce();
		rate.sleep();
	}
	return 0;
}
