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
    ros::Subscriber subWheelAngle;
    ros::Subscriber substop;

    tf2::Vector3    dest;
    tf2::Vector3    pos;
    tf2::Vector3    dir;
    float           max_speed;
    float           wheelAngle = 0;
    double          sec;
    bool            pause = false;


    explicit    ComandReceiver(ros::NodeHandle *n);
    void        SetPoint(const algo::vector_msg::ConstPtr& msg);
    void        SetSpeed(const algo::vector_msg::ConstPtr& msg);
    void        Setdir(const nav_msgs::Odometry::ConstPtr &msg);
    void        Angle(const std_msgs::Float32::ConstPtr &msg);
    void        stop(const std_msgs::Bool::ConstPtr &msg);

};


#endif //SRC_COMANDRECEIVER_H
