//
// Created by sab3r on 20.10.20.
//

#include "Correction.h"

Correction::Correction(ros::NodeHandle *n)
{
    subrwheel = n->subscribe("rwheel_ticks", 1, &Correction::Rwheel, this);
    sublwheel = n->subscribe("lwheel_ticks", 1, &Correction::Lwheel, this);

}

void Correction::Rwheel(const std_msgs::Int32::ConstPtr &msg)
{
    SnapShot shot;

    rwheel = msg->data;
    shot.rwheel = rwheel;
    shot.lwheel = lwheel;
    shot.secs = ros::Time::now().toSec();
    shots.push_back(shot);
}

void Correction::Lwheel(const std_msgs::Int32::ConstPtr &msg)
{
    SnapShot shot;

    lwheel = msg->data;
    shot.rwheel = rwheel;
    shot.lwheel = lwheel;
    shot.secs = ros::Time::now().toSec();
    shots.push_back(shot);
}