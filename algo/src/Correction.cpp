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
    tf2::Vector3 basic(1,0,0);
    tf2::Vector3 basicTop(0,1,0);

    shot.secs = ros::Time::now().toSec();
    shot.pos.setX(((msg->data - rwheel) / 2.f) * cos((msg->data - rwheel) / BACK));
    shot.pos.setY(((msg->data - rwheel) / 2.f) * sin((msg->data - rwheel) / BACK));
    rwheel = msg->data;
    shot.rwheel = rwheel;
    shot.lwheel = lwheel;
    shot.dir = basic.rotate(basicTop, (rwheel - lwheel) * (0.25 * M_PI / BACKTICKS) / BACK);
    shot.secs = ros::Time::now().toSec();
    shots.push_back(shot);
}

void Correction::Lwheel(const std_msgs::Int32::ConstPtr &msg)
{
    SnapShot shot;
    tf2::Vector3 basic(1,0,0);
    tf2::Vector3 basicTop(0,1,0);


    shot.pos.setX(((lwheel - msg->data) / 2.f) * cos((lwheel - msg->data) / BACK));
    shot.pos.setY(((lwheel - msg->data) / 2.f) * sin((lwheel - msg->data) / BACK));
    lwheel = msg->data;
    shot.rwheel = rwheel;
    shot.lwheel = lwheel;
    shot.dir = basic.rotate(basicTop, (rwheel - lwheel) * (0.25 * M_PI / BACKTICKS) / BACK);
    shot.secs = ros::Time::now().toSec();
    shots.push_back(shot);
}

void Correction::direction(int rwheel, int lwheel, SnapShot shot) {
    double angle;
    tf2::Vector3 basic(1, 0, 0);
    tf2::Vector3 basicTop(0,1,0);

    angle = (rwheel - lwheel) * (0.25 * M_PI / 64.f) / 0.608;
    shot.dir = basic.rotate(basicTop, angle);
}

int main(int ac, char** av)
{
    Correction *correct;
    ros::init(ac, av, "CorrectionMain");
    ros::NodeHandle n;
    correct = new Correction(&n);
    // comand->dest = {1.f, 0.f};
    ros::spin();
    return 0;
}