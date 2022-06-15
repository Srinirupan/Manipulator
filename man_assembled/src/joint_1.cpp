#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Int32.h"
float count=0.50;
int main(int args,char** argv)
{
	ros::init(args,argv,"pub_joint_1");
	ros::NodeHandle node;
	ros::Publisher publish_number=node.advertise<std_msgs::Float64>("/man_assembled/joint_1_controller/command",1);
	ros::Rate loop_rate(5);
	
	while(ros::ok())
	{
		std_msgs::Float64 msg;
		msg.data=count;
		//ROS_INFO("%f",count);
		publish_number.publish(msg);
		loop_rate.sleep();
		count+=0.01;
		if(count>=3.14)
		{
			while(true)
			{
				ROS_INFO("In the loop and count is %f",count);
				msg.data=count;
				publish_number.publish(msg);
				count-=0.01;
				if(count<=0.48) break;

			}
				ROS_INFO("Other direction motion");
		}
	}

}
