//
// Created by sab3r on 17.08.20.
//

#include "PositionV2.h"


PositionV2::PositionV2(ros::NodeHandle *n)
{
    subMotor = n->subscribe("motion", 1, &PositionV2::motion, this);
    subTurner = n->subscribe("turner", 1, &PositionV2::turner, this);
    pubAngle = n->advertise<std_msgs::Float32>("wheelAngle", 1);
    pubpos = n->advertise<geometry_msgs::Pose>("position", 1);
}

void PositionV2::turner(const std_msgs::Int32::ConstPtr &msg)
{
    float angle;
    float lenght;
    std_msgs::Float32 newMsg;
    tf2::Vector3 direction;
    tf2::Vector3 rot_axis(0, 0, 1);
    wheelAngle += msg->data * ANGULARTICK;
    if (angle < 0)
    {
        angle = M_PI / 2 + wheelAngle;
        lenght = BASIC / cosf(angle);
        direction = dir.rotate(rot_axis, M_PI + angle);
        direction = direction * lenght;
        center = pos + direction;
    }
    else if(angle > 0)
    {
        angle = M_PI / 2 - wheelAngle;
        lenght = BASIC / cosf(angle);
        direction = dir.rotate(rot_axis, M_PI - angle);
        direction = direction * lenght;
        center = pos + direction;
    }
    newMsg.data = wheelAngle;
    pubAngle.publish(newMsg);
}

void PositionV2::motion(const std_msgs::Int32::ConstPtr &msg)
{
    float angle;
    tf2::Vector3 basic(1, 0, 0);
    tf2::Vector3 basicTop(0, 0, 1);
    tf2::Vector3 toPos;
    geometry_msgs::Pose newMsg;
    if (wheelAngle == 0)
    {
        pos = pos + (dir * TICKLENGHT * msg->data);
    }
    else if (wheelAngle < 0)
    {
        toPos = pos - center;
        angle = toPos.angle(basic);
        if ((toPos * basic).z() > 0)
            angle *= -1;
        angle = angle - (TICKLENGHT * msg->data / toPos.length());
        pos.setX(center.x() + toPos.length() * cos(angle));
        pos.setY(center.y() + toPos.length() * sin(angle));
        dir = (basicTop * toPos).normalize();
    }
    else if (wheelAngle > 0)
    {
        toPos = pos - center;
        angle = toPos.angle(basic);
        if ((toPos * basic).z() > 0)
            angle *= -1;
        angle = angle + (TICKLENGHT * msg->data / toPos.length());
        pos.setX(center.x() + toPos.length() * cos(angle));
        pos.setY(center.y() + toPos.length() * sin(angle));
        dir = (toPos * basicTop).normalize();
    }
    tf2::Quaternion quat;

    tf2::Vector3 rot;
    rot = dir * basic;
    if (rot.z() < 0)
    {
        angle = dir.angle(basic);
        quat.setRPY(0, 0, -angle);
    }
    else
    {
        angle = dir.angle(basic);
        quat.setRPY(0, 0, angle);
    }
    newMsg.orientation = tf2::toMsg(quat);
    newMsg.position.x = pos.x();
    newMsg.position.y = pos.y();
    newMsg.position.z = pos.z();
    pubpos.publish(newMsg);
}
int main(int ac, char** av)
{
    PositionV2 *pos;
    ros::init(ac, av, "PositionV2");
    ros::NodeHandle n;
    pos = new PositionV2(&n);
    ros::spin();
    return 0;
}