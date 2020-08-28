//
// Created by sab3r on 24.03.20.
//

#include "ComandReceiver.h"

ComandReceiver::ComandReceiver(ros::NodeHandle *n)
{
    subdir = n->subscribe("odom", 0, &ComandReceiver::Setdir, this);
    subpos = n->subscribe("position", 0, &ComandReceiver::SetSpeed, this);
    subdest = n->subscribe("destination", 0, &ComandReceiver::SetPoint, this);
    pubAr = n->advertise<std_msgs::Float64MultiArray>("MotorForce", 0);
    pubTw = n->advertise<geometry_msgs::Twist>("cmd_vel", 0);
    dest = {0.f, 0.f};
    pos = {0.f, 0.f};
    dir = {0.f, 0.f};
    max_speed = 0;
    sleep(1);
}

void ComandReceiver::SetPoint(const algo::vector_msg::ConstPtr &msg)
{
    dest.x = msg->x;
    dest.y = msg->y;
}

void ComandReceiver::SetSpeed(const algo::vector_msg::ConstPtr &msg)
{
    pos.x = msg->x;
    pos.y = msg->y;
}

void ComandReceiver::Setdir(const nav_msgs::Odometry::ConstPtr &msg)
{
    std_msgs::Float64MultiArray Ar;
    geometry_msgs::Twist Tw;
    float angle;
    float div;
    float distance;
    vec   dist;

    tf::Quaternion quat(msg->pose.pose.orientation.x, msg->pose.pose.orientation.y, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
    tf::Vector3 vecto(1, 0, 0);
    tf::Vector3 rotated_vector = tf::quatRotate(quat, vecto);
    Tw.linear.x = 0;
    Tw.linear.y = 0;
    Tw.linear.z = 0;
    Tw.angular.x = 0;
    Tw.angular.y = 0;
    Tw.angular.z = 0;
    pos.x = msg->pose.pose.position.x;
    pos.y = msg->pose.pose.position.y;
    Ar.data.push_back(0);
    Ar.data.push_back(0);
    dir.x = rotated_vector.x();
    dir.y = rotated_vector.y();
    dist.x = dest.x - pos.x;
    dist.y = dest.y - pos.y;
    distance = sqrtf(pow(dest.x - pos.x, 2) + pow(dest.y - pos.y, 2));
    if (distance < 10)
    {
        if (distance / 2. > 10)
        {
            max_speed = distance / 2.;
        } else
        {
            max_speed = 0.15f;
        }
    }
    else
        max_speed = 0.15f;
    angle = (dir.x * dist.x + dir.y * dist.y) / (sqrtf(dir.x * dir.x + dir.y * dir.y) * sqrtf(dist.x * dist.x + dist.y * dist.y));
    div = dir.x * dist.y - dist.x * dir.y;
    if (div < 0)
    {

        Ar.data[1] = max_speed;
        if (angle > 0.90)
        {
            if (pause)
            {
                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
                pause = false;
            }
            else if (sec - ros::Time::now().toSec() > 0)
            {
                pubTw.publish(Tw);
            }
            else
            {   Tw.linear.x = max_speed;
                Tw.angular.z = -0.1;
                Ar.data[0] = max_speed * angle;
            }


        }
        else if (angle > 0.99)
        {
            if (pause)
            {
                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
                pause = false;
            }
            else if (sec - ros::Time::now().toSec() > 0)
            {
                pubTw.publish(Tw);
            }
            else
                Tw.linear.x = max_speed;
        }
        else {
            Tw.angular.z = -0.1;
            pause = true;
        }
        //pubAr.publish(Ar);
    } else
    {

        Ar.data[0] = max_speed;
        if (angle > 0.90)
        {
            if (pause)
            {
                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
                pause = false;
            }
            else if (sec - ros::Time::now().toSec() > 0)
            {
                pubTw.publish(Tw);
            }
            else
            {
                Tw.linear.x = max_speed;
                Tw.angular.z = 0.1;
                Ar.data[1] = max_speed * angle;
            }

        }
        else if (angle > 0.99)
        {
            if (pause)
            {
                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
                pause = false;
            }
            else if (sec - ros::Time::now().toSec() > 0)
            {
                pubTw.publish(Tw);
            }
            else
                Tw.linear.x = max_speed;
        }
        else
        {
            Tw.angular.z = 0.1;
            pause = true;
        }


        //pubAr.publish(Ar);
    }
    pubTw.publish(Tw);


}

int main(int ac, char** av)
{
    ComandReceiver *comand;
    ros::init(ac, av, "ComandReceiver");
    ros::NodeHandle n;
    comand = new ComandReceiver(&n);
   // comand->dest = {1.f, 0.f};
    ros::spin();
    return 0;
}
