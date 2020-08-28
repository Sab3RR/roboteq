//
// Created by sab3r on 17.08.20.
//

#ifndef ALGO_POSITIONV2_H
#define ALGO_POSITIONV2_H

#include "rosdef.h"


class PositionV2 {
public:
    ros::Subscriber subMotor;
    ros::Subscriber subTurner;

    ros::Publisher pubForce;
    ros::Publisher pubAngle;
    ros::Publisher pubpos;
    ros::Publisher pubdir;

    float wheelAngle = 0;

    tf2::Vector3 pos = tf2::Vector3(0, 0, 0);
    tf2::Vector3 center;
    tf2::Vector3 dir = tf2::Vector3(1, 0, 0);

    explicit PositionV2(ros::NodeHandle *n);
    void motion(const std_msgs::Int32::ConstPtr &msg);
    void turner(const std_msgs::Int32::ConstPtr &msg);
};


#endif //ALGO_POSITIONV2_H
