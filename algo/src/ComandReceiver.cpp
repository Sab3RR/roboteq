//
// Created by sab3r on 24.03.20.
//

#include "ComandReceiver.h"

ComandReceiver::ComandReceiver(ros::NodeHandle *n)
{
    subdir = n->subscribe("odom", 1, &ComandReceiver::Setdir, this);
    subpos = n->subscribe("position", 1, &ComandReceiver::SetSpeed, this);
    subdest = n->subscribe("destination", 1, &ComandReceiver::SetPoint, this);
    subWheelAngle = n->subscribe("wheelAngle", 1, &ComandReceiver::Angle, this);
    pubAr = n->advertise<std_msgs::Float64MultiArray>("MotorForce", 1);
    pubTw = n->advertise<geometry_msgs::Twist>("cmd_vel", 10);
    substop = n->subscribe("stop", 1, &ComandReceiver::stop, this);
    max_speed = 0;
    sleep(1);
}

void ComandReceiver::SetPoint(const algo::vector_msg::ConstPtr &msg)
{
    dest.setX(msg->x);
    dest.setY(msg->y);
    dest.setZ(0);
}

void ComandReceiver::SetSpeed(const algo::vector_msg::ConstPtr &msg)
{
    pos.setX(msg->x);
    pos.setY(msg->y);
    pos.setZ(0);
}

void ComandReceiver::Angle(const std_msgs::Float32::ConstPtr &msg)
{
    wheelAngle = msg->data + (123 * M_PI / 180);
}

void ComandReceiver::stop(const std_msgs::Bool::ConstPtr &msg)
{
    pause = msg->data;
}

void ComandReceiver::Setdir(const nav_msgs::Odometry::ConstPtr &msg)
{
    std_msgs::Float64MultiArray Ar;
    geometry_msgs::Twist Tw;
    tf2::Vector3 pos;
    float angle;
    float speed;
    float wheel;
    float div;
    float distance;
    vec   dist;

    tf2::Quaternion quat(msg->pose.pose.orientation.x, msg->pose.pose.orientation.y, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
    tf2::Vector3 vecto(1, 0, 0);
    tf2::Vector3 rotated_vector = tf2::quatRotate(quat, vecto);
    Tw.linear.x = 0;
    Tw.linear.y = 0;
    Tw.linear.z = 0;
    Tw.angular.x = 0;
    Tw.angular.y = 0;
    Tw.angular.z = 0;
    pos.setX(msg->pose.pose.position.x);
    pos.setY(msg->pose.pose.position.y);
    pos.setZ(0);
    dir = rotated_vector;

    angle = dir.angle(dest - pos);
    if (tf2::tf2Cross(dir, dest - pos).z() > 0)
    {
        angle *= -1;
    }
    float nAngle = angle + (123 * M_PI / 180);
    if (angle < -0.1)
    {
        speed = (abs(nAngle - wheelAngle)* 300);

        if (((speed) > 3 && (speed) < 110))
            wheel = 110;
        else if (speed > 300)
            wheel = 300;
        else
            wheel = speed;
        if (wheelAngle > nAngle) {
            wheel = wheel * (-1);
        }
        Tw.linear.x = 200;
    }
    else if (angle > 0.1)
    {
        speed = (abs(nAngle - wheelAngle) * 300);
        if (speed > 3 && speed < 110)
            wheel = 110;
        else if (speed > 300)
            wheel = 300;
        else
            wheel = speed;
        if (wheelAngle > nAngle)
        {
           wheel = wheel * (-1);
        }
        Tw.linear.x = 200;
    }
    else
    {
        speed = (abs(nAngle - wheelAngle) * 300);
        if (speed > 3 && speed < 110)
            wheel = 110;
        else if (speed > 300)
            wheel = 300;
        else
            wheel = speed;
        if (wheelAngle > nAngle)
        {
            wheel = wheel * (-1);
        }
        Tw.linear.x = 200;
    }
    if (pause)
        Tw.linear.x = 0;
    Tw.angular.z = wheel;
    pubTw.publish(Tw);

//    usleep(150000);
//    Ar.data.push_back(0);
//    Ar.data.push_back(0);
//    dir.x = rotated_vector.x();
//    dir.y = rotated_vector.y();
//    dist.x = dest.x - pos.x;
//    dist.y = dest.y - pos.y;
//    distance = sqrtf(pow(dest.x - pos.x, 2) + pow(dest.y - pos.y, 2));
//    if (distance < 10)
//    {
//        if (distance / 2. > 10)
//        {
//            max_speed = distance / 2.;
//        } else
//        {
//            max_speed = 0.15f;
//        }
//    }
//    else
//        max_speed = 0.15f;
//    angle = (dir.x * dist.x + dir.y * dist.y) / (sqrtf(dir.x * dir.x + dir.y * dir.y) * sqrtf(dist.x * dist.x + dist.y * dist.y));
//    div = dir.x * dist.y - dist.x * dir.y;
//    if (div < 0)
//    {
//
//        Ar.data[1] = max_speed;
//        if (angle > 0.90)
//        {
//            if (pause)
//            {
//                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
//                pause = false;
//            }
//            else if (sec - ros::Time::now().toSec() > 0)
//            {
//                pubTw.publish(Tw);
//            }
//            else
//            {   Tw.linear.x = max_speed;
//                Tw.angular.z = -0.1;
//                Ar.data[0] = max_speed * angle;
//            }
//
//
//        }
//        else if (angle > 0.99)
//        {
//            if (pause)
//            {
//                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
//                pause = false;
//            }
//            else if (sec - ros::Time::now().toSec() > 0)
//            {
//                pubTw.publish(Tw);
//            }
//            else
//                Tw.linear.x = max_speed;
//        }
//        else {
//            Tw.angular.z = -0.1;
//            pause = true;
//        }
//        //pubAr.publish(Ar);
//    } else
//    {
//
//        Ar.data[0] = max_speed;
//        if (angle > 0.90)
//        {
//            if (pause)
//            {
//                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
//                pause = false;
//            }
//            else if (sec - ros::Time::now().toSec() > 0)
//            {
//                pubTw.publish(Tw);
//            }
//            else
//            {
//                Tw.linear.x = max_speed;
//                Tw.angular.z = 0.1;
//                Ar.data[1] = max_speed * angle;
//            }
//
//        }
//        else if (angle > 0.99)
//        {
//            if (pause)
//            {
//                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
//                pause = false;
//            }
//            else if (sec - ros::Time::now().toSec() > 0)
//            {
//                pubTw.publish(Tw);
//            }
//            else
//                Tw.linear.x = max_speed;
//        }
//        else
//        {
//            Tw.angular.z = 0.1;
//            pause = true;
//        }
//
//
//        //pubAr.publish(Ar);
//    }
//    pubTw.publish(Tw);
//

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
