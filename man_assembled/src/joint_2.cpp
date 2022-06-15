#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int args,char** argv)
{
	ROS_INFO("Starting to publish the Joint2 positions");
	ros::init(args,argv,"publish_joint2");
	ros::NodeHandle node;
	ros::Publisher pub_state=node.advertise<std_msgs::Float64>("/man_assembled/joint_2_controller/command",10);
	ros::Rate loop_rate(10);
	float temp=-1.60;
	std_msgs::Float64 msg;
	bool k=true;
	while(ros::ok())
	{
		msg.data=temp;
		pub_state.publish(msg);
		loop_rate.sleep();
		temp+=0.01;
		//ROS_INFO("joint position is %f",temp);
		if(temp>=0.50)
		{
			ROS_INFO("Other direction");
			while(true)
			{
				msg.data=temp;
				temp-=0.01;
				pub_state.publish(msg);
				loop_rate.sleep();
				if(temp<=-1.58) break;
			}
		}	
	}
}

