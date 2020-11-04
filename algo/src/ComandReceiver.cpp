//

#include "ComandReceiver.h"

ComandReceiver::ComandReceiver(ros::NodeHandle *n)
{
    subdir = n->subscribe("odom", 1, &ComandReceiver::Setdir, this);
    subpos = n->subscribe("position", 1, &ComandReceiver::SetSpeed, this);
    subdest = n->subscribe("destination", 1, &ComandReceiver::SetPoint, this);
    subprevdest = n->subscribe("prevdestination", 1, &ComandReceiver::SetPrevPoint, this);
    subWheelAngle = n->subscribe("wheelAngle", 1, &ComandReceiver::Angle, this);
    subcenter = n->subscribe("Center", 1, &ComandReceiver::Center, this);
    subleft = n->subscribe("Left", 1, &ComandReceiver::Left, this);
    subright = n->subscribe("Right", 1, &ComandReceiver::Right, this);
    pubAr = n->advertise<std_msgs::Float64MultiArray>("MotorForce", 1);
    pubTw = n->advertise<geometry_msgs::Twist>("cmd_vel", 10);
    pubpincomand = n->advertise<std_msgs::String>("motorcomand", 100);
    substop = n->subscribe("stop", 1, &ComandReceiver::stop, this);
    subdismet = n->subscribe("backdistance", 1, &ComandReceiver::backDistance, this);
    subbackcenter = n->subscribe("backcenter", 1, &ComandReceiver::backcenter, this);
    subbackright = n->subscribe("backright", 1, &ComandReceiver::backright, this);
    subbackleft = n->subscribe("backleft", 1, &ComandReceiver::backleft, this);
    subrightcenter = n->subscribe("rightcenter", 1, &ComandReceiver::rightcenter, this);
    subrightforward = n->subscribe("rightforward", 1, &ComandReceiver::rightforward, this);
    subrightback = n->subscribe("rightback", 1, &ComandReceiver::rightback, this);
    subleftcenter = n->subscribe("leftcenter", 1, &ComandReceiver::leftcenter, this);
    subleftforward = n->subscribe("leftforward", 1, &ComandReceiver::leftforward, this);
    subleftback = n->subscribe("leftback", 1, &ComandReceiver::leftback, this);
    subforwardcenter = n->subscribe("forwardcenter", 1, &ComandReceiver::forwardcenter, this);
    subforwardright = n->subscribe("forwardright", 1, &ComandReceiver::forwardright, this);
    subforwardleft = n->subscribe("forwardleft", 1, &ComandReceiver::forwardleft, this);
    subrwheel = n->subscribe("rwheel_ticks", 1, &ComandReceiver::Rwheel, this);
    sublwheel = n->subscribe("lwheel_ticks", 1, &ComandReceiver::Lwheel, this);
    submagnet = n->subscribe("magnit", 1, &ComandReceiver::Magnet, this);


    max_speed = 0;
    sleep(1);
}

void ComandReceiver::Magnet(const std_msgs::Bool::ConstPtr &msg)
{
    magnet = msg->data;
}

//
// Created by sab3r on 24.03.20.
void ComandReceiver::Rwheel(const std_msgs::Int32::ConstPtr &msg)
{
    rwheel = msg->data;
}

void ComandReceiver::Lwheel(const std_msgs::Int32::ConstPtr &msg)
{
    lwheel = msg->data;
}

void ComandReceiver::backcenter(const std_msgs::Float32::ConstPtr &msg)
{
    fbackcenter = msg->data;
}

void ComandReceiver::backright(const std_msgs::Float32::ConstPtr &msg)
{
    fbackright = msg->data;
}

void ComandReceiver::backleft(const std_msgs::Float32::ConstPtr &msg)
{
    fbackleft = msg->data;
}

void ComandReceiver::rightcenter(const std_msgs::Float32::ConstPtr &msg)
{
    frightcenter = msg->data;
    if (frightcenter < 30 || frightforward < 30 || frightback < 30)
        letright = true;
    else
        letright = false;
}

void ComandReceiver::rightforward(const std_msgs::Float32::ConstPtr &msg)
{
    frightforward = msg->data;
    if (frightcenter < 30 || frightforward < 30 || frightback < 30)
        letright = true;
    else
        letright = false;
}

void ComandReceiver::rightback(const std_msgs::Float32::ConstPtr &msg)
{
    frightback = msg->data;
    if (frightcenter < 30 || frightforward < 30 || frightback < 30)
        letright = true;
    else
        letright = false;
}

void ComandReceiver::leftcenter(const std_msgs::Float32::ConstPtr &msg)
{
    fleftcenter = msg->data;
    if (fleftcenter < 30 || fleftback < 30 || fleftforward < 30)
        letleft = true;
    else
        letleft = false;
}

void ComandReceiver::leftforward(const std_msgs::Float32::ConstPtr &msg)
{
    fleftforward = msg->data;
    if (fleftcenter < 30 || fleftback < 30 || fleftforward < 30)
        letleft = true;
    else
        letleft = false;
}

void ComandReceiver::leftback(const std_msgs::Float32::ConstPtr &msg)
{
    fleftback = msg->data;
    if (fleftcenter < 30 || fleftback < 30 || fleftforward < 30)
        letleft = true;
    else
        letleft = false;
}

void ComandReceiver::forwardcenter(const std_msgs::Float32::ConstPtr &msg)
{
    fforwardcenter = msg->data;
    if (fforwardcenter < 30 || fforwardleft < 30 || fforwardright < 30)
        letforward = true;
    else
        letforward = false;
}

void ComandReceiver::forwardright(const std_msgs::Float32::ConstPtr &msg)
{
    fforwardright = msg->data;
    if (fforwardcenter < 30 || fforwardleft < 30 || fforwardright < 30)
        letforward = true;
    else
        letforward = false;
}

void ComandReceiver::forwardleft(const std_msgs::Float32::ConstPtr &msg)
{
    fforwardleft = msg->data;
    if (fforwardcenter < 30 || fforwardleft < 30 || fforwardright < 30)
        letforward = true;
    else
        letforward = false;
}

void ComandReceiver::backDistance(const std_msgs::Float32::ConstPtr &msg)
{
    backdistance = msg->data;
}

void ComandReceiver::Center(const std_msgs::Bool::ConstPtr &msg)
{
    center = msg->data;
}

void ComandReceiver::Left(const std_msgs::Bool::ConstPtr &msg)
{
    left = msg->data;
}

void ComandReceiver::Right(const std_msgs::Bool::ConstPtr &msg)
{
    right = msg->data;
}

void ComandReceiver::SetPoint(const algo::vector_msg::ConstPtr &msg)
{
    dest.setX(msg->x);
    dest.setY(msg->y);
    dest.setZ(0);
}

void ComandReceiver::SetPrevPoint(const algo::vector_msg::ConstPtr &msg)
{
    prevdest.setX(msg->x);
    prevdest.setY(msg->y);
    prevdest.setZ(0);
}

void ComandReceiver::SetSpeed(const algo::vector_msg::ConstPtr &msg)
{
    pos.setX(msg->x);
    pos.setY(msg->y);
    pos.setZ(0);
}

void ComandReceiver::Angle(const std_msgs::Float32::ConstPtr &msg)
{
    wheelAngle = msg->data + (123 * M_PI / 180);
}

void ComandReceiver::stop(const std_msgs::Bool::ConstPtr &msg)
{
    Stop = msg->data;
}

void ComandReceiver::Setdir(const nav_msgs::Odometry::ConstPtr &msg)
{
    std_msgs::Float64MultiArray Ar;
    geometry_msgs::Twist Tw;
    tf2::Vector3 pos;
    float angle;
    float speed;
    float wheel;
    float div;
    float distance;
    vec   dist;

    tf2::Quaternion quat(msg->pose.pose.orientation.x, msg->pose.pose.orientation.y, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
    tf2::Vector3 vecto(1, 0, 0);
    tf2::Vector3 basicTop(0, 0, 1);
    tf2::Vector3 rotated_vector = tf2::quatRotate(quat, vecto);
    Tw.linear.x = 0;
    Tw.linear.y = 0;
    Tw.linear.z = 0;
    Tw.angular.x = 0;
    Tw.angular.y = 0;
    Tw.angular.z = 0;
    pos.setX(msg->pose.pose.position.x);
    pos.setY(msg->pose.pose.position.y);
    pos.setZ(0);
    dir = rotated_vector;
    tf2::Vector3 pPos(-0.23, -0.07, 0);
    tf2::Vector3 pDir(1, 0.05 ,0);
    tf2::Vector3 lpos(1, 0 ,0);
    tf2::Vector3 lrdir(1, -1,0);
    tf2::Vector3 lldir(1, 1, 0);

    lrdir.normalize();
    lldir.normalize();
    pDir.normalize();
    pPos = prevdest;
    pDir = (dest - prevdest).normalized();
    angle = (pos - pPos).angle(pDir);
/*    if ((pos - pPos).length() < 0.05)
        pause = true;
    else
        pause = false;
    if ((pos + dir * (-BASIC - 0.15) - pPos).length() * sin((pos + dir * (-BASIC - 0.15) - pPos).angle(pDir)) < 0.025)
        center = true;
    else
        center = false;*/
//    {
//        angle = (pos + dir * (-BASIC - 0.15)).angle(lrdir);
//        if (angle < 1.57)
//        {
//            if ((pos + dir * (-BASIC - 0.15) - lpos).length() * sin((pos + dir * (-BASIC - 0.15) - lpos).angle(lrdir)) < 0.025)
//                center = true;
//            else
//                center = false;
//        }
//        angle = (pos + dir * (-BASIC - 0.15)).angle(lldir);
//        if (angle < 1.57)
//        {
//            if ((pos + dir * (-BASIC - 0.15) - lpos).length() * sin((pos + dir * (-BASIC - 0.15) - lpos).angle(lldir)) < 0.025)
//                center = true;
//            else
//                center = false;
//        }
//    }

    /*if ((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(dir, basicTop).normalized() * 0.03 - pPos).length() * sin((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(dir, basicTop).normalized() * 0.03 - pPos).angle(pDir)) < 0.025)
        right = true;
    else
        right = false;*/
//    {
//        angle = (pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(dir, basicTop).normalized() * 0.03).angle(lrdir);
//        if (angle < 1.57)
//        {
//            if ((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(dir, basicTop).normalized() * 0.03 - lpos).length() * sin((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(dir, basicTop).normalized() * 0.03 - lpos).angle(lrdir)) < 0.025)
//                right = true;
//            else
//                right = false;
//        }
//        angle = (pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(dir, basicTop).normalized() * 0.03).angle(lldir);
//        if (angle < 1.57)
//        {
//            if ((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(dir, basicTop).normalized() * 0.03 - lpos).length() * sin((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(dir, basicTop).normalized() * 0.03 - lpos).angle(lldir)) < 0.025)
//                right = true;
//            else
//                right = false;
//        }
//    }
    /*if ((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(basicTop, dir).normalized() * 0.03 - pPos).length() * sin((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(basicTop, dir).normalized() * 0.03 - pPos).angle(pDir)) < 0.025)
        left = true;
    else
        left = false;*/
//    {
//        angle = (pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(basicTop, dir).normalized() * 0.03).angle(lrdir);
//        if (angle < 1.57)
//        {
//            if ((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(basicTop, dir).normalized() * 0.03 - lpos).length() * sin((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(basicTop, dir).normalized() * 0.03 - lpos).angle(lrdir)) < 0.025)
//                left = true;
//            else
//                left = false;
//        }
//        angle = (pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(basicTop, dir).normalized() * 0.03).angle(lldir);
//        if (angle < 1.57)
//        {
//            if ((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(basicTop, dir).normalized() * 0.03 - lpos).length() * sin((pos + dir * (-BASIC - 0.15) + tf2::tf2Cross(basicTop, dir).normalized() * 0.03 - lpos).angle(lldir)) < 0.025)
//                left = true;
//            else
//                left = false;
//        }
//    }

    if (center || right || left)
        home = true;
    if (center && right && left)
        pause = true;
    else
        pause = false;
    if (left && !right)
    {
        lastright = false;
        lastleft = true;
    }
    else if (right && !left)
    {
        lastleft = false;
        lastright = true;
    }
    if (home)
        rev = true;
    else
        rev = false;
    if ((fforwardcenter < 60 || fforwardleft < 60 || fforwardright < 60) && revf)
    {
        revf = true;
        dest = pos + dir;
    }
    else
        revf = false;
//    if (backdistance < 0.16)
//        pause = true;
    if (home)
        dest = (pos + dir * center +  dir.rotate(basicTop, -1) * right + dir.rotate(basicTop, 1) * left);
    if (!center && !left && !right && home)
        dest = pos + dir.rotate(basicTop, -1.57) * lastright + dir.rotate(basicTop, 1.57) * lastleft;
    if (letforward && !home)
    {
        if (letright && !letleft)
        {
            dest = pos + dir.rotate(basicTop, -1.57);
            revf = false;
        }
        else if (letleft && !letright)
        {
            dest = pos + dir.rotate(basicTop, 1.57);
            revf = false;
        }
        else
        {
            dest = pos + dir;
            revf = true;
        }
    }
    else if (letright)
    {
        if (tf2::tf2Cross(dir, dest - pos).z() < 0)
        {
            dest = pos + dir;
        }
    }
    else if (letleft)
    {
        if (tf2::tf2Cross(dir, dest - pos).z() > 0)
        {
            dest = pos + dir;
        }
    }
    angle = (pos - pPos).angle(pDir);
    tf2::Vector3 newdest = pPos + pDir * (((pos - pPos).length()) * cos(angle)) + pDir / 2.f;
    if ((dest - pPos).length() > (newdest - pPos).length())
        dest = newdest;
    //dest = pPos + pDir * (((pos - pPos).length() + 1)  * cos(angle));

//
//    parking
//    didnt work
//    if (angle > 0.01)
//    {
//        dest = pPos + pDir * ((pos - pPos).length() * cos(angle));
//        rev = false;
//    }
//    else
//    {
//        angle = dir.angle(pDir);
//        if (angle < 0.1)
//        {
//            if(tf2::tf2Cross(dir, pDir).z() > 0)
//                angle *= -1;
//            dest = pos + dir.rotate(basicTop, angle) * 0.5;
//            rev = true;
//        }
//        else
//        {
//            dest = pPos + pDir * ((pos - pPos).length() * cos((pos - pPos).angle(pDir))) + pDir * 0.5;
//            rev = false;
//        }
//    }

    angle = dir.angle(dest - pos);
    if (tf2::tf2Cross(dir, dest - pos).z() > 0)
    {
        angle *= -1;
    }

    float nAngle = angle + (123 * M_PI / 180);
    if (angle < -0.1)
    {
        speed = (abs(nAngle - wheelAngle)* 300);

        if (((speed) > 3 && (speed) < 110))
            wheel = 110;
        else if (speed > 300)
            wheel = 300;
        else
            wheel = speed;
        if (wheelAngle > nAngle) {
            wheel = wheel * (-1);
        }
        if (speed > 200)
            Tw.linear.x = 100;
        else if (speed < 200 && speed > 100)
            Tw.linear.x = 300 - speed;
        else
            Tw.linear.x = 200;
    }
    else if (angle > 0.1)
    {
        speed = (abs(nAngle - wheelAngle) * 300);
        if (speed > 3 && speed < 110)
            wheel = 110;
        else if (speed > 300)
            wheel = 300;
        else
            wheel = speed;
        if (wheelAngle > nAngle)
        {
           wheel = wheel * (-1);
        }
        if (speed > 200)
            Tw.linear.x = 100;
        else if (speed < 200 && speed > 100)
            Tw.linear.x = 300 - speed;
        else
            Tw.linear.x = 200;
    }
    else
    {
        speed = (abs(nAngle - wheelAngle) * 300);
        if (speed > 3 && speed < 110)
            wheel = 110;
        else if (speed > 300)
            wheel = 300;
        else
            wheel = speed;
        if (wheelAngle > nAngle)
        {
            wheel = wheel * (-1);
        }
        if (speed > 200)
            Tw.linear.x = 100;
        else if (speed < 200 && speed > 100)
            Tw.linear.x = 300 - speed;
        else
            Tw.linear.x = 200;
    }
    Tw.linear.x = 500;
    if (abs(angle) < 0.03)
        Tw.linear.x = 500;
    if (rev || revf)
        Tw.linear.x *= -1;
    if (pause || Stop)
    {
        Tw.linear.x = 0;
        if (pause)
        {
            pubpincomand.publish("rackelon");
            pubpincomand.publish("schetkaon");
            pubpincomand.publish("turbinaoff");
            pubpincomand.publish("pumpoff");
        }
        else
        {
            pubpincomand.publish("rackeloff");
            pubpincomand.publish("schetkaoff");
            pubpincomand.publish("turbinaoff");
            pubpincomand.publish("pumpoff");
        }
    }
    else
    {
        pubpincomand.publish("rackelon");
        pubpincomand.publish("schetkaon");
        if (magnet) {
            pubpincomand.publish("turbinaon");
            pubpincomand.publish("pumpon");
        }
        else
        {
            pubpincomand.publish("turbinaoff");
            pubpincomand.publish("pumpoff");
        }
    }

    Tw.angular.z = wheel;
    if (angle > 1.2)
        angle = 1.2;
    else if (angle < -1.2)
        angle = -1.2;
    Tw.angular.z = (angle / ANGULARTICK) / 10.f;

//    pubTw.publish(Tw);

    angle = (rwheel - lwheel) * (0.25 * M_PI / 32.f) / 0.608;
    while (angle > M_PI * 2)
        angle -= M_PI * 2;
    while (angle < -M_PI * 2)
        angle += M_PI * 2;

    std::cout << angle << std::endl;


//    usleep(150000);
//    Ar.data.push_back(0);
//    Ar.data.push_back(0);
//    dir.x = rotated_vector.x();
//    dir.y = rotated_vector.y();
//    dist.x = dest.x - pos.x;
//    dist.y = dest.y - pos.y;
//    distance = sqrtf(pow(dest.x - pos.x, 2) + pow(dest.y - pos.y, 2));
//    if (distance < 10)
//    {
//        if (distance / 2. > 10)
//        {
//            max_speed = distance / 2.;
//        } else
//        {
//            max_speed = 0.15f;
//        }
//    }
//    else
//        max_speed = 0.15f;
//    angle = (dir.x * dist.x + dir.y * dist.y) / (sqrtf(dir.x * dir.x + dir.y * dir.y) * sqrtf(dist.x * dist.x + dist.y * dist.y));
//    div = dir.x * dist.y - dist.x * dir.y;
//    if (div < 0)
//    {
//
//        Ar.data[1] = max_speed;
//        if (angle > 0.90)
//        {
//            if (pause)
//            {
//                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
//                pause = false;
//            }
//            else if (sec - ros::Time::now().toSec() > 0)
//            {
//                pubTw.publish(Tw);
//            }
//            else
//            {   Tw.linear.x = max_speed;
//                Tw.angular.z = -0.1;
//                Ar.data[0] = max_speed * angle;
//            }
//
//
//        }
//        else if (angle > 0.99)
//        {
//            if (pause)
//            {
//                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
//                pause = false;
//            }
//            else if (sec - ros::Time::now().toSec() > 0)
//            {
//                pubTw.publish(Tw);
//            }
//            else
//                Tw.linear.x = max_speed;
//        }
//        else {
//            Tw.angular.z = -0.1;
//            pause = true;
//        }
//        //pubAr.publish(Ar);
//    } else
//    {
//
//        Ar.data[0] = max_speed;
//        if (angle > 0.90)
//        {
//            if (pause)
//            {
//                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
//                pause = false;
//            }
//            else if (sec - ros::Time::now().toSec() > 0)
//            {
//                pubTw.publish(Tw);
//            }
//            else
//            {
//                Tw.linear.x = max_speed;
//                Tw.angular.z = 0.1;
//                Ar.data[1] = max_speed * angle;
//            }
//
//        }
//        else if (angle > 0.99)
//        {
//            if (pause)
//            {
//                sec = (ros::Time::now() + ros::Duration(0.5)).toSec();
//                pause = false;
//            }
//            else if (sec - ros::Time::now().toSec() > 0)
//            {
//                pubTw.publish(Tw);
//            }
//            else
//                Tw.linear.x = max_speed;
//        }
//        else
//        {
//            Tw.angular.z = 0.1;
//            pause = true;
//        }
//
//
//        //pubAr.publish(Ar);
//    }
//    pubTw.publish(Tw);
//

}

int main(int ac, char** av)
{
    ComandReceiver *comand;
    ros::init(ac, av, "ComandReceiver");
    ros::NodeHandle n;
    comand = new ComandReceiver(&n);
   // comand->dest = {1.f, 0.f};
    ros::spin();
    return 0;
}
