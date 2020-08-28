//
// Created by sab3r on 19.03.20.
//

#include "MotorController.h"

MotorController::MotorController(ros::NodeHandle *n)
{
    std_msgs::Float64 msg;

    pubR = n->advertise<std_msgs::Float64>("EngineR", 100);
    pubL = n->advertise<std_msgs::Float64>("EngineL", 100);
    SubAr = n->subscribe("MotorForce", 100, &MotorController::SubscribeArray, this);
    SubLrate = n->subscribe("lwheel_rate", 100, &MotorController::lrate, this);
    SubRrate = n->subscribe("rwheel_rate", 100, &MotorController::rrate, this);
    SubDLrate = n->subscribe("lwheel_desired_rate", 100, &MotorController::Dlrate, this);
    SubDRrate = n->subscribe("rwheel_desired_rate", 100, &MotorController::Drrate, this);
    Substop = n->subscribe("stop", 100, &MotorController::stopmsg, this);
    msg.data = 0.0;
    pubR.publish(msg);
    pubL.publish(msg);
    /*sleep(1);
    Forward(0.2);
    sleep(1);
    Backward(0.2);
    sleep(1);
    Forward(0.5);
    sleep(1);
    Stop();
    sleep(1);
    SetForceL(0.5);
    sleep(1);
    Stop();
    sleep(1);
    SetForceR(0.5);
    sleep(1);
    Stop();
    sleep(1);
    SetForceR(-0.5);
    sleep(1);
    Stop();
    sleep(1);
    SetForceL(-0.5);
    sleep(1);
    Stop();
    sleep(1);
    SetForce(0.5, -0.5);
    sleep(1);
    Stop();
    sleep(1);
    SetForce(-0.5, 0.5);
    sleep(1);
    Stop();
*/
}

void MotorController::stopmsg(const std_msgs::Bool::ConstPtr &msg)
{
    stop = msg->data;
}

void MotorController::Stop()
{
    std_msgs::Float64 msg;

    msg.data = 0;
    pubR.publish(msg);
    pubL.publish(msg);
    MotorR = MotorL = 0;
}

void MotorController::SetForce(float EnR, float EnL)
{
    std_msgs::Float64 msg_EnR;
    std_msgs::Float64 msg_EnL;

    if (EnR < -1)
        EnR = -1;
    else if (EnR > 1)
        EnR = 1;

    if (EnL < -1)
        EnL = -1;
    else if (EnL > 1)
        EnL = 1;

    msg_EnR.data = EnR;
    msg_EnL.data = EnL;

    pubR.publish(msg_EnR);
    pubL.publish(msg_EnL);

    MotorR = EnR;
    MotorL = EnL;
}

void MotorController::Forward(float En)
{
    std_msgs::Float64 msg;

    if (En < 0)
        En = 0;
    else if (En > 1)
        En = 1;

    msg.data = En;

    pubR.publish(msg);
    pubL.publish(msg);
    MotorR = En;
    MotorL = En;
}

void MotorController::Backward(float En)
{
    std_msgs::Float64 msg;

    if (En < 0)
        En = 0;
    else if (En > 1)
        En = 1;

    msg.data = -En;

    pubR.publish(msg);
    pubL.publish(msg);
    MotorR = En;
    MotorL = En;
}

void MotorController::SetForceR(float EnR)
{
    std_msgs::Float64 msg;

    if (EnR < -1)
        EnR = -1;
    else if (EnR > 1)
        EnR = 1;

    msg.data = EnR;

    pubR.publish(msg);
    MotorR = EnR;
}

void MotorController::SetForceL(float EnL)
{
    std_msgs::Float64 msg;

    if (EnL < -1)
        EnL = -1;
    else if (EnL > 1)
        EnL = 1;

    msg.data = EnL;

    pubL.publish(msg);
    MotorL = EnL;
}

void MotorController::SubscribeArray(const std_msgs::Float64MultiArray::ConstPtr& msg)
{
    SetForce(msg->data[0], msg->data[1]);
}

void MotorController::lrate(const std_msgs::Float32::ConstPtr& msg)
{
    std_msgs::Float64 msgpub;
    EncoderL = msg->data;
    if (EncoderL < MotorL)
    {
        if (ForceL * (ForceL + 0.01) < 0)
        {
            ForceL = 0;
        }
        else if (ForceL == 0)
        {
            if (EncoderL == 0)
                ForceL += 0.01;
        }
        else if (ForceL + 0.01 < -0.3 && ForceL + 0.01 < 0)
        {
            ForceL = 0;
        }
        else if (ForceL + 0.01 < 0.3 && ForceL + 0.01 > 0)
        {
            ForceL = 0.3;
        }
        else
            ForceL += 0.01;
    }
    else if (EncoderL > MotorL)
    {
        if (ForceL * (ForceL - 0.01) < 0)
        {
            ForceL = 0;
        }
        else if (ForceL == 0)
        {
            if (EncoderL == 0)
                ForceL -= 0.01;
        }
        else if (ForceL - 0.01 < 0.3 && ForceL - 0.01 > 0)
        {
            ForceL = 0;
        }
        else if (ForceL - 0.01 < -0.3 && ForceL - 0.01 < 0)
        {
            ForceL = -0.3;
        }
        else
            ForceL -= 0.01;
    }
    if (ForceL > 1)
        ForceL = 1;
    else if (ForceL < -1)
        ForceL = -1;
    if (MotorL == 0 && EncoderL == 0)
        ForceL = 0;
    if (stop)
        ForceL = 0;
    msgpub.data = ForceL;
    pubL.publish(msgpub);
}

void MotorController::rrate(const std_msgs::Float32::ConstPtr& msg)
{
    std_msgs::Float64 msgpub;
    EncoderR = msg->data;
    if (EncoderR < MotorR)
    {
        if (ForceR * (ForceR + 0.01) < 0)
        {
            ForceR = 0;
        }
        else if (ForceR == 0)
        {
            if (EncoderR == 0)
                ForceR += 0.01;
        }
        else if (ForceR + 0.01 < -0.3 && ForceR + 0.01 < 0)
        {
            ForceR = 0;
        }
        else if (ForceR + 0.01 < 0.3 && ForceR + 0.01 > 0)
        {
            ForceR = 0.3;
        }
        else
            ForceR += 0.01;
    }
    else if (EncoderR > MotorR)
    {
        if (ForceR * (ForceR - 0.01) < 0)
        {
            ForceR = 0;
        }
        else if (ForceR == 0)
        {
            if (EncoderR == 0)
                ForceR -= 0.01;
        }
        else if (ForceR - 0.01 < 0.3 && ForceR - 0.01 > 0)
        {
            ForceR = 0;
        }
        else if (ForceR - 0.01 < -0.3 && ForceR - 0.01 < 0)
        {
            ForceR = -0.3;
        }
        else
            ForceR -= 0.01;
    }
    if (ForceR > 1)
        ForceR = 1;
    else if (ForceR < -1)
        ForceR = -1;
    if (MotorR == 0 && EncoderR == 0)
        ForceR = 0;
    if (stop)
        ForceR = 0;
    msgpub.data = ForceR;
    pubR.publish(msgpub);
}

void MotorController::Dlrate(const std_msgs::Int32::ConstPtr &msg)
{
    MotorL = msg->data;
}

void MotorController::Drrate(const std_msgs::Int32::ConstPtr &msg)
{
    MotorR = msg->data;
}