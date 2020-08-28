//
// Created by sab3r on 24.03.20.
//

#ifndef SRC_COMANDRECEIVER_H
#define SRC_COMANDRECEIVER_H

#include "rosdef.h"
#include <cmath>
class ComandReceiver {
public:
    ros::Publisher  pubAr;
    ros::Publisher  pubTw;
    ros::Subscriber subdir;
    ros::Subscriber subpos;
    ros::Subscriber subdest;

    vec             dest;
    vec             pos;
    vec             dir;
    float           max_speed;
    double          sec;
    bool            pause = false;

    explicit    ComandReceiver(ros::NodeHandle *n);
    void        SetPoint(const algo::vector_msg::ConstPtr& msg);
    void        SetSpeed(const algo::vector_msg::ConstPtr& msg);
    void        Setdir(const nav_msgs::Odometry::ConstPtr &msg);
};


#endif //SRC_COMANDRECEIVER_H
