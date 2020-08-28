//
// Created by sab3r on 20.03.20.
//

#ifndef SRC_ROSDEF_H
#define SRC_ROSDEF_H
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Vector3.h>
#include <tf/LinearMath/Quaternion.h>
#include <sensor_msgs/Imu.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
//#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Point.h>
#include <sensor_msgs/MagneticField.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/TransformStamped.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include "algo/Encoder_msg.h"
#include "algo/vector_msg.h"
#include "algo/vector_array.h"
#include "algo/point_msg.h"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <vector>
#include <termios.h>
#include <nav_msgs/Odometry.h>
#include <tf/tf.h>
//#include <serial/serial.h>
#define LENGTH norm_2
#define TICKLENGHT 0.1
#define ANGULARTICK 0.001
#define BASIC 1
#define STARTFORCE
#define ANGLEFORCE 0.01
#define WEIGHT 50

/*    float angle;
    tf2::Vector3 vec(0.75, 3, 0);
    vec.normalize();
    tf2::Vector3 basic(1, 0, 0);
    tf2::Quaternion quat;

    tf2::Vector3 rot;
    rot = vec * basic;
    if (rot.z() < 0)
    {
        angle = vec.angle(basic);
        quat.setRPY(0, 0, -angle);
    }
    else
    {
        angle = vec.angle(basic);
        quat.setRPY(0, 0, angle);
    }



    tf2::Vector3 vec2 = tf2::quatRotate(quat, basic);*/

using namespace boost::numeric::ublas;
struct vec
{
    float x;
    float y;
};

class Sector
{
public:
    vector<double> leftup = vector<double>(2);
    vector<double> leftdown = vector<double>(2);
    vector<double> rightup = vector<double>(2);
    vector<double> rightdown =  vector<double>(2);
    std::vector<Sector *> transit;
};
#endif //SRC_ROSDEF_H
