//
// Created by sab3r on 18.08.20.
//

#ifndef ALGO_MOTORCONTROLLERV2_H
#define ALGO_MOTORCONTROLLERV2_H

#include "rosdef.h"

class MotorControllerV2 {
public:
    ros::Publisher pubForce;
    ros::Publisher pubForceforAngle;
    ros::Subscriber subMotor;
    ros::Subscriber subAngle;
    ros::Subscriber subTwist;

    float angle;
    float force;
    float speed;
    float angularspeed;
    float accel;
    float wheelSpeed;
    bool stop = false;

    explicit MotorControllerV2(ros::NodeHandle *n);
    void setTwist(const geometry_msgs::Twist::ConstPtr &msg);
    void setAngle(const std_msgs::Float32::ConstPtr &msg);
    void setMotorSpeed(const std_msgs::Int32::ConstPtr &msg);

};


#endif //ALGO_MOTORCONTROLLERV2_H
