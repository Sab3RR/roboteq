//
// Created by sab3r on 18.08.20.
//

#include "MotorControllerV2.h"

MotorControllerV2::MotorControllerV2(ros::NodeHandle *n)
{
    subTwist = n->subscribe("Twist", 1, &MotorControllerV2::setTwist, this);
    subAngle = n->subscribe("wheelAngle", 1, &MotorControllerV2::setAngle, this);
    subMotor = n->subscribe("wheelSpeed", 1 , &MotorControllerV2::setMotorSpeed, this);
    pubForce = n->advertise<std_msgs::Float64>("ForceR", 1);
    pubForceforAngle = n->advertise<std_msgs::Float64>("ForceR", 1);

}

void MotorControllerV2::setTwist(const geometry_msgs::Twist::ConstPtr &msg)
{
    speed = msg->linear.x;
    angularspeed = msg->angular.z;
    accel = wheelSpeed - speed;
    if (angularspeed == 0)
    {
        angle = 0;
        return;
    }
    float radius = speed / angularspeed;
    angle = acosf(BASIC / radius);
    if (angle < 0)
        angle = M_PI_2 + angle;
    else
        angle = M_PI_2 - angle;
}
void MotorControllerV2::setAngle(const std_msgs::Float32::ConstPtr &msg)
{
    float diff = msg->data - angle;
    std_msgs::Float64 pubmsg;

    if (diff < 0)
        pubmsg.data = -ANGLEFORCE;
    else if (diff > 0)
        pubmsg.data = ANGLEFORCE;
    else
        pubmsg.data = 0;
    pubForceforAngle.publish(pubmsg);
}

void MotorControllerV2::setMotorSpeed(const std_msgs::Int32::ConstPtr &msg)
{
    std_msgs::Float64 msgpub;
    wheelSpeed = msg->data * TICKLENGHT;
    if (wheelSpeed < speed)
    {
        if (force * (force + 0.01) < 0)
        {
            force = 0;
        }
        else if (force == 0)
        {
            if (wheelSpeed == 0)
                force += 0.01;
        }
        else if (force + 0.01 < -0.3 && force + 0.01 < 0)
        {
            force = 0;
        }
        else if (force + 0.01 < 0.3 && force + 0.01 > 0)
        {
            force= 0.3;
        }
        else
            force += 0.01;
    }
    else if (wheelSpeed > speed)
    {
        if (force * (force - 0.01) < 0)
        {
            force = 0;
        }
        else if (force == 0)
        {
            if (wheelSpeed == 0)
                force -= 0.01;
        }
        else if (force - 0.01 < 0.3 && force - 0.01 > 0)
        {
            force = 0;
        }
        else if (force - 0.01 < -0.3 && force - 0.01 < 0)
        {
            force = -0.3;
        }
        else
            force -= 0.01;
    }
    if (force > 1)
        force = 1;
    else if (force < -1)
        force = -1;
    if (speed == 0 && wheelSpeed == 0)
        force = 0;
    if (stop)
        force = 0;
    msgpub.data = force;
    pubForce.publish(msgpub);
}

int main()
{
    return 0;
}