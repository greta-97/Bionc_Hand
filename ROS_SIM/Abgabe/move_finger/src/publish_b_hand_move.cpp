#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/String.h"

#include <sstream>

//for comparing the subscribed messages
std::string faust ("faust");
std::string offen ("offen");
std::string rock ("rock");

//define the publishers
//middle finger
ros::Publisher m_carpi_to_metacarpa;
ros::Publisher m_metacarpa_to_proxi;
ros::Publisher m_proxi_to_media;
ros::Publisher m_media_to_distalis;
//Ring finger
ros::Publisher a_carpi_to_metacarpa;
ros::Publisher a_metacarpa_to_proxi;
ros::Publisher a_proxi_to_media;
ros::Publisher a_media_to_distalis;
//smalll finger
ros::Publisher dm_carpi_to_metacarpa;
ros::Publisher dm_metacarpa_to_proxi;
ros::Publisher dm_proxi_to_media;
ros::Publisher dm_media_to_distalis;
//index finger
ros::Publisher l_carpi_to_metacarpa;
ros::Publisher l_metacarpa_to_proxi;
ros::Publisher l_proxi_to_media;
ros::Publisher l_media_to_distalis;
//thumbs
ros::Publisher p_carpi_to_polloxhalter;
ros::Publisher p_polloxhalter_to_servo;
ros::Publisher p_servo_small_to_proxi;
ros::Publisher p_proxi_to_media;
ros::Publisher p_media_to_distalis;

//callback function for subscribing from /Hand_move
void Pose_callback(const std_msgs::String::ConstPtr& msg)
{
	//define messages for each value
	//middle finger
	std_msgs::Float64 m_carpi_to_metacarpa_msg;
	std_msgs::Float64 m_metacarpa_to_proxi_msg;
	std_msgs::Float64 m_proxi_to_media_msg;
	std_msgs::Float64 m_media_to_distalis_msg;

	//ring finger
	std_msgs::Float64 a_carpi_to_metacarpa_msg;
	std_msgs::Float64 a_metacarpa_to_proxi_msg;
	std_msgs::Float64 a_proxi_to_media_msg;
	std_msgs::Float64 a_media_to_distalis_msg;

	//index finger
	std_msgs::Float64 l_carpi_to_metacarpa_msg;
	std_msgs::Float64 l_metacarpa_to_proxi_msg;
	std_msgs::Float64 l_proxi_to_media_msg;
	std_msgs::Float64 l_media_to_distalis_msg;

	//small finger
	std_msgs::Float64 dm_carpi_to_metacarpa_msg;
	std_msgs::Float64 dm_metacarpa_to_proxi_msg;
	std_msgs::Float64 dm_proxi_to_media_msg;
	std_msgs::Float64 dm_media_to_distalis_msg;

	//thumbs
	std_msgs::Float64 p_carpi_to_polloxhalter_msg;
	std_msgs::Float64 p_polloxhalter_to_servo_msg;
	std_msgs::Float64 p_servo_small_to_proxi_msg;
	std_msgs::Float64 p_proxi_to_media_msg;
	std_msgs::Float64 p_media_to_distalis_msg;
	//compare message string with "faust"
	if (msg->data.compare(faust) == 0)
	{
		ROS_INFO_STREAM("Faust");
		//middle finger
		m_carpi_to_metacarpa_msg.data = 0.0;	//in bogenmaß
		m_metacarpa_to_proxi_msg.data = 1.7;
		m_proxi_to_media_msg.data = 1.7;
		m_media_to_distalis_msg.data = 1.7;

		//ring finger
		a_carpi_to_metacarpa_msg.data = 0.0;
		a_metacarpa_to_proxi_msg.data = 1.7;
		a_proxi_to_media_msg.data = 1.7;
		a_media_to_distalis_msg.data = 1.7;

		//index finger
		l_carpi_to_metacarpa_msg.data = 0.0;
		l_metacarpa_to_proxi_msg.data = 1.7;
		l_proxi_to_media_msg.data = 1.7;
		l_media_to_distalis_msg.data = 1.7;

		//small finger
		dm_carpi_to_metacarpa_msg.data = 0.0;
		dm_metacarpa_to_proxi_msg.data = 1.7;
		dm_proxi_to_media_msg.data = 1.7;
		dm_media_to_distalis_msg.data = 1.7;

		//thumbs
		p_carpi_to_polloxhalter_msg.data = 1.7;								/////ca 90 grad einstellen
		p_polloxhalter_to_servo_msg.data = 0.0;//90 grad					//fix
		p_servo_small_to_proxi_msg.data = 0.0;
		p_proxi_to_media_msg.data = 1.7;
		p_media_to_distalis_msg.data = 1.7;
	}
	//compare message string with "offen"
	if (msg->data.compare(offen) == 0)
	{
		ROS_INFO_STREAM("offen");
		//middle finger
		m_carpi_to_metacarpa_msg.data = 0.01;
		m_metacarpa_to_proxi_msg.data = 0.01;
		m_proxi_to_media_msg.data = 0.01;
		m_media_to_distalis_msg.data = 0.01;

		//ring finger
		a_carpi_to_metacarpa_msg.data = 0.01;
		a_metacarpa_to_proxi_msg.data = 0.01;
		a_proxi_to_media_msg.data = 0.01;
		a_media_to_distalis_msg.data = 0.01;

		//index finger
		l_carpi_to_metacarpa_msg.data = 0.01;
		l_metacarpa_to_proxi_msg.data = 0.01;
		l_proxi_to_media_msg.data = 0.01;
		l_media_to_distalis_msg.data = 0.01;

		//small finger
		dm_carpi_to_metacarpa_msg.data = 0.01;
		dm_metacarpa_to_proxi_msg.data = 0.01;
		dm_proxi_to_media_msg.data = 0.01;
		dm_media_to_distalis_msg.data = 0.01;

		//thumbs
		p_carpi_to_polloxhalter_msg.data = 0.01;
		p_polloxhalter_to_servo_msg.data = 0.01;
		p_servo_small_to_proxi_msg.data = 0.01;
		p_proxi_to_media_msg.data = 0.01;
		p_media_to_distalis_msg.data = 0.01;
	}
	//compare message string with "rock"
	if (msg->data.compare(rock) == 0)
	{
		ROS_INFO("Rock");
		//middle finger
		m_carpi_to_metacarpa_msg.data = 0.0;
		m_metacarpa_to_proxi_msg.data = 1.5;
		m_proxi_to_media_msg.data = 1.5;
		m_media_to_distalis_msg.data = 1.5;

		//ring finger
		a_carpi_to_metacarpa_msg.data = 0.0;
		a_metacarpa_to_proxi_msg.data = 1.5;
		a_proxi_to_media_msg.data = 1.5;
		a_media_to_distalis_msg.data = 1.5;

		//index finger
		l_carpi_to_metacarpa_msg.data = 0.0;
		l_metacarpa_to_proxi_msg.data = 0.0;
		l_proxi_to_media_msg.data = 0.0;
		l_media_to_distalis_msg.data = 0.0;

		//small finger
		dm_carpi_to_metacarpa_msg.data = 0.0;
		dm_metacarpa_to_proxi_msg.data = 0.0;
		dm_proxi_to_media_msg.data = 0.0;
		dm_media_to_distalis_msg.data = 0.0;

		//thumbs
		p_carpi_to_polloxhalter_msg.data = 1.7;
		p_polloxhalter_to_servo_msg.data = 0.0;
		p_servo_small_to_proxi_msg.data = 1.5;
		p_proxi_to_media_msg.data = 1.5;
		p_media_to_distalis_msg.data = 1.5;
	}

	//publish the data
	//middle finger
	m_carpi_to_metacarpa.publish(m_carpi_to_metacarpa_msg);
	m_metacarpa_to_proxi.publish(m_metacarpa_to_proxi_msg);
	m_proxi_to_media.publish(m_proxi_to_media_msg);
	m_media_to_distalis.publish(m_media_to_distalis_msg);

	//ring finger
	a_carpi_to_metacarpa.publish(a_carpi_to_metacarpa_msg);
	a_metacarpa_to_proxi.publish(a_metacarpa_to_proxi_msg);
	a_proxi_to_media.publish(a_proxi_to_media_msg);
	a_media_to_distalis.publish(a_media_to_distalis_msg);

	//index finger
	l_carpi_to_metacarpa.publish(l_carpi_to_metacarpa_msg);
	l_metacarpa_to_proxi.publish(l_metacarpa_to_proxi_msg);
	l_proxi_to_media.publish(l_proxi_to_media_msg);
	l_media_to_distalis.publish(l_media_to_distalis_msg);

	//small finger
	dm_carpi_to_metacarpa.publish(dm_carpi_to_metacarpa_msg);
	dm_metacarpa_to_proxi.publish(dm_metacarpa_to_proxi_msg);
	dm_proxi_to_media.publish(dm_proxi_to_media_msg);
	dm_media_to_distalis.publish(dm_media_to_distalis_msg);

	//thumbss
	p_carpi_to_polloxhalter.publish(p_carpi_to_polloxhalter_msg);
	p_polloxhalter_to_servo.publish(p_polloxhalter_to_servo_msg);
	p_servo_small_to_proxi.publish(p_servo_small_to_proxi_msg);
	p_proxi_to_media.publish(p_proxi_to_media_msg);
	p_media_to_distalis.publish(p_media_to_distalis_msg);

}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "Move_Hand");

  ros::NodeHandle n;
  //define a subscriber to subscribe from topic /Hand_pose
  ros::Subscriber sub = n.subscribe("/Hand_pose", 50, Pose_callback);

  //define publishers to publishe in the .../command topic, message type = std_msgs::Float64
  //Mittel finger
  m_carpi_to_metacarpa = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/carpi_to_metacarpa_position_controller/command", 1000);
  m_metacarpa_to_proxi = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/metacarpa_to_proxi_position_controller/command", 1000);
  m_proxi_to_media = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/proxi_to_media_position_controller/command", 1000);
  m_media_to_distalis = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/media_to_distalis_position_controller/command", 1000);

  //ring finger
  a_carpi_to_metacarpa = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/a_carpi_to_metacarpa_position_controller/command", 1000);
  a_metacarpa_to_proxi = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/a_metacarpa_to_proxi_position_controller/command", 1000);
  a_proxi_to_media = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/a_proxi_to_media_position_controller/command", 1000);
  a_media_to_distalis = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/a_media_to_distalis_position_controller/command", 1000);

  //small finger
  dm_carpi_to_metacarpa = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/dm_carpi_to_metacarpa_position_controller/command", 1000);
  dm_metacarpa_to_proxi = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/dm_metacarpa_to_proxi_position_controller/command", 1000);
  dm_proxi_to_media = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/dm_proxi_to_media_position_controller/command", 1000);
  dm_media_to_distalis = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/dem_media_to_distalis_position_controller/command", 1000);

  //index finger
  l_carpi_to_metacarpa = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/l_carpi_to_metacarpa_position_controller/command", 1000);
  l_metacarpa_to_proxi = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/l_metacarpa_to_proxi_position_controller/command", 1000);
  l_proxi_to_media = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/l_proxi_to_media_position_controller/command", 1000);
  l_media_to_distalis = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/l_media_to_distalis_position_controller/command", 1000);

  //thumbs
  p_carpi_to_polloxhalter = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/p_carpi_to_polloxhalter_position_controller/command", 1000);
  p_polloxhalter_to_servo = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/p_polloxhalter_to_servo_small_position_controller/command", 1000);
  p_servo_small_to_proxi = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/p_servo_small_to_proxi_position_controller/command", 1000);
  p_proxi_to_media = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/p_proxi_to_media_position_controller/command", 1000);
  p_media_to_distalis = n.advertise<std_msgs::Float64>("/bionc_hand_with_base/p_media_to_distalis_position_controller/command", 1000);

  ros::Rate loop_rate(1);
  ros::spin();


}
