//
// Created by sab3r on 20.10.20.
//

#ifndef ALGO_CORRECTION_H
#define ALGO_CORRECTION_H

#include "rosdef.h"

class SnapShot {
public:
    double secs;
    int rwheel;
    int lwheel;
    tf2::Vector3 dir;
    tf2::Vector3 pos;
};

class Correction {
public:
    ros::Subscriber subrwheel;
    ros::Subscriber sublwheel;

    int rwheel = 0;
    int lwheel = 0;
    std::vector<SnapShot> shots;

    explicit    Correction(ros::NodeHandle *n);
    void        Rwheel(const std_msgs::Int32::ConstPtr &msg);
    void        Lwheel(const std_msgs::Int32::ConstPtr &msg);
    void        direction(int rwheel, int lwheel, SnapShot shot);
};


#endif //ALGO_CORRECTION_H
