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
    ros::Publisher  pubpincomand;
    ros::Subscriber submagnet;
    ros::Subscriber subdir;
    ros::Subscriber subpos;
    ros::Subscriber subdest;
    ros::Subscriber subprevdest;
    ros::Subscriber subWheelAngle;
    ros::Subscriber subdismet;
    ros::Subscriber substop;
    ros::Subscriber subcenter;
    ros::Subscriber subleft;
    ros::Subscriber subright;
    ros::Subscriber subbackcenter;
    ros::Subscriber subbackright;
    ros::Subscriber subbackleft;
    ros::Subscriber subrightcenter;
    ros::Subscriber subrightforward;
    ros::Subscriber subrightback;
    ros::Subscriber subleftcenter;
    ros::Subscriber subleftforward;
    ros::Subscriber subleftback;
    ros::Subscriber subforwardcenter;
    ros::Subscriber subforwardright;
    ros::Subscriber subforwardleft;
    ros::Subscriber subrwheel;
    ros::Subscriber sublwheel;



    tf2::Vector3    dest;
    tf2::Vector3    prevdest = tf2::Vector3(0, 0, 0);
    tf2::Vector3    pos;
    tf2::Vector3    dir;
    int             rwheel = 0;
    int             lwheel = 0;
    float           backdistance = 0;
    float           max_speed;
    double           wheelAngle = 0;
    float           fbackcenter = 1;
    float           fbackright = 1;
    float           fbackleft = 1;
    float           frightcenter = 1;
    float           frightforward = 1;
    float           frightback = 1;
    float           fleftcenter = 1;
    float           fleftforward = 1;
    float           fleftback = 1;
    float           fforwardcenter = 1;
    float           fforwardright = 1;
    float           fforwardleft = 1;
    double          sec;
    bool            pause = false;
    bool            Stop = false;
    bool            rev = false;
    bool            revf = false;
    bool            center = false;
    bool            right = false;
    bool            left = false;
    bool            home = false;
    bool            lastright = false;
    bool            lastleft = false;
    bool            letforward = false;
    bool            letright = false;
    bool            letleft = false;
    bool            magnet = false;


    explicit    ComandReceiver(ros::NodeHandle *n);
    void        Magnet(const std_msgs::Bool::ConstPtr &msg);
    void        backDistance(const std_msgs::Float32::ConstPtr &msg);
    void        SetPoint(const algo::vector_msg::ConstPtr& msg);
    void        SetPrevPoint(const algo::vector_msg::ConstPtr& msg);
    void        SetSpeed(const algo::vector_msg::ConstPtr& msg);
    void        Setdir(const nav_msgs::Odometry::ConstPtr &msg);
    void        Angle(const std_msgs::Float32::ConstPtr &msg);
    void        stop(const std_msgs::Bool::ConstPtr &msg);
    void        Center(const std_msgs::Bool::ConstPtr &msg);
    void        Left(const std_msgs::Bool::ConstPtr &msg);
    void        Right(const std_msgs::Bool::ConstPtr &msg);
    void        backcenter(const std_msgs::Float32::ConstPtr &msg);
    void        backright(const std_msgs::Float32::ConstPtr &msg);
    void        backleft(const std_msgs::Float32::ConstPtr &msg);
    void        rightcenter(const std_msgs::Float32::ConstPtr &msg);
    void        rightforward(const std_msgs::Float32::ConstPtr &msg);
    void        rightback(const std_msgs::Float32::ConstPtr &msg);
    void        leftcenter(const std_msgs::Float32::ConstPtr &msg);
    void        leftforward(const std_msgs::Float32::ConstPtr &msg);
    void        leftback(const std_msgs::Float32::ConstPtr &msg);
    void        forwardcenter(const std_msgs::Float32::ConstPtr &msg);
    void        forwardright(const std_msgs::Float32::ConstPtr &msg);
    void        forwardleft(const std_msgs::Float32::ConstPtr &msg);
    void        Rwheel(const std_msgs::Int32::ConstPtr &msg);
    void        Lwheel(const std_msgs::Int32::ConstPtr &msg);

};


#endif //SRC_COMANDRECEIVER_H
