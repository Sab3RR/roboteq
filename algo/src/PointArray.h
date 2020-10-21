//
// Created by sab3r on 25.03.20.
//

#ifndef SRC_POINTARRAY_H
#define SRC_POINTARRAY_H

#include "rosdef.h"
#include <cmath>

class PointArray {
public:
    ros::Subscriber subpos;
    ros::Subscriber subpoints;

    ros::Subscriber subdots;
    ros::Publisher  pubdest;
    ros::Publisher  pubstop;
    ros::Publisher  pubprevdest;

    std::vector<algo::vector_msg> points;
    algo::vector_msg hendpoint;
    bool bhendpoint = false;
    bool Ework;
    bool secondpoint = false;
    int pointI  = 0;
    unsigned int loop = 0;
    explicit PointArray(ros::NodeHandle *n);
    void     PointTransmitter(const nav_msgs::Odometry::ConstPtr &msg);
    void    handPoint(const std_msgs::Float64::ConstPtr &msg);
    void    createArray(const algo::vector_array::ConstPtr &msg);

};


#endif //SRC_POINTARRAY_H
