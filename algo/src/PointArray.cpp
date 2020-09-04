//
// Created by sab3r on 25.03.20.
//

#include "PointArray.h"

void PointArray::handPoint(const std_msgs::Float64::ConstPtr &msg)
{
    if (secondpoint)
    {
        hendpoint.y = msg->data;
        secondpoint = false;
        bhendpoint = true;
    }
    else
    {
        hendpoint.x = msg->data;
        secondpoint = true;
        bhendpoint = false;
    }
}

void PointArray::PointTransmitter(const nav_msgs::Odometry::ConstPtr &msg)
{
    float lenght;
    std_msgs::Bool stop;

    stop.data = true;
    tf::Quaternion quat(msg->pose.pose.orientation.x, msg->pose.pose.orientation.y, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
    tf::Vector3 vecto(msg->pose.pose.position.x, msg->pose.pose.position.y, 0);
    tf::Vector3 r = tf::quatRotate(quat, vecto);
    if (bhendpoint)
    {
        pubdest.publish(hendpoint);
        return;
    }
    if (points.size() == 0)
        return ;
    lenght = sqrtf(pow(vecto.x() - points[pointI].x, 2) + pow(vecto.y() - points[pointI].y, 2));
    //std::cout << points[pointI] << std::endl;
    if (lenght < 0.15)
    {
        pointI++;
        /*if (points.size() <= pointI)
        {
            pubstop.publish(stop);
            pointI--;
        }*/
        if (points.size() <= pointI)
        {
            pointI = 0;
            loop++;
            std::cout << loop << std::endl;
        }
    }
    pubdest.publish(points[pointI]);
}

void    PointArray::createArray(const algo::vector_array::ConstPtr &msg)
{
    algo::vector_msg v;
    for (auto j = msg->vec.begin(); j != msg->vec.end(); j++)
    {
        v.x = j->x;
        v.y = j->y;
        points.push_back(v);
    }
}

PointArray::PointArray(ros::NodeHandle *n)
{
    algo::vector_msg point;

    subpos = n->subscribe("odom", 0, &PointArray::PointTransmitter, this);
    subpoints = n->subscribe("handpoint", 0, &PointArray::handPoint, this);
    subdots = n->subscribe("dots", 0, &PointArray::createArray, this);
    pubdest = n->advertise<algo::vector_msg>("destination", 1);
    pubstop = n->advertise<std_msgs::Bool>("stop", 1);

   /* point.x = 1;
    point.y = 0;
    points.push_back(point);
    point.y = 0.25;
    points.push_back(point);
    point.x = 0;
    points.push_back(point);
    point.y = 0.5;
    points.push_back(point);
    point.x = 1;
    points.push_back(point);
    point.y = 0.75;
    points.push_back(point);
    point.x = 0;
    points.push_back(point);
    point.y = 1;
    points.push_back(point);
    point.x = 1;
    points.push_back(point);
    point.y = 1.25;
    points.push_back(point);
    point.x = 0;
    points.push_back(point);
    point.y = 1.5;
    points.push_back(point);
    point.x = 1;
    points.push_back(point);
    point.y = 1.75;
    points.push_back(point);
    point.x = 0;
    points.push_back(point);
    point.y = 2;
    points.push_back(point);
    point.x = 1;
    points.push_back(point);
    point.x = 0;
    point.y = 0;
    points.push_back(point);*/

}

int main(int ac, char** av)
{
    PointArray *pointarray;
    ros::init(ac, av, "PointArray");
    ros::NodeHandle n;
    pointarray = new PointArray(&n);
    ros::spin();
    return 0;
}