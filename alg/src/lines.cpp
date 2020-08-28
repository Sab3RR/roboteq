#include <ros/ros.h>
#include <std_msgs/String.h>
#include <visualization_msgs/Marker.h>
#include "json.hpp"

#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
using json = nlohmann::json;

struct p {
    float x;
    float y;
    int type;
};

struct plane {
    p p1;
    p p2;
};

class ObjectMap {

public:
    std::vector<p> corners;
    std::vector<plane> planes;
    std::map<int[2], bool> map;

    bool havecorner(p point)
    {
        for (auto & corner : corners)
        {
            ROS_INFO("%f %f %f %f", point.x, corner.x, point.y, corner.y);
            if (point.x == corner.x && point.y == corner.y)
            {
                return true;
            }
        }
        return false;
    }

    explicit ObjectMap(std::ifstream *f)
    {

        json j;
        *f >> j;

        for (int i = 0; i < j["Object"].size(); i++)
        {
            plane new_wall{};
            if (j["Object"][i]["type"] != "PLANE")
                continue;
            new_wall.p1.x = j["Object"][i]["p1"]["x"];
            new_wall.p1.y = j["Object"][i]["p1"]["y"];
            ROS_INFO("p1.x %f p1.y %f", new_wall.p1.x, new_wall.p1.y);
            //this->planes.push_back(new_wall);
            new_wall.p2.x = j["Object"][i]["p2"]["x"];
            new_wall.p2.y = j["Object"][i]["p2"]["y"];
            this->planes.push_back(new_wall);
            ROS_INFO("p2.x %f p2.y %f", new_wall.p2.x, new_wall.p2.y);
        }
        for (auto & plane : planes)
        {
            p new_corner{};
            new_corner.type = 0;
            ROS_INFO("%i", corners.size());
            if (!havecorner(plane.p1))
            {
                new_corner.x = plane.p1.x;
                new_corner.y = plane.p1.y;
                corners.push_back(new_corner);
            }
            if (!havecorner(plane.p2))
            {
                new_corner.x = plane.p2.x;
                new_corner.y = plane.p2.y;
                corners.push_back(new_corner);
            }
        }
        ROS_INFO("q");
        for (int i = 0; i < j["Object"].size(); i++)
        {
            if (j["Object"][i]["type"] != "CORNER")
                continue;
            for (auto & corner : corners)
            {
                if (j["Object"][i]["p"]["x"] == corner.x && j["Object"][i]["p"]["y"] == corner.y)
                    corner.type = 1;
            }
        }
        ROS_INFO("qq");
    }
};

float distance(float x, float y)
{
    return sqrtf(x*x + y*y);
}

// A C++ program to check if two given line segments intersect
using namespace std;

struct Point
{
    float x;
    float y;
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);

}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear             ROS_INFO("a");

// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    float val = (q.y - p.y) * (r.x - q.x) -
                (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases 500000
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}


bool get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y,
                           float p2_x, float p2_y, float p3_x, float p3_y)
{
    float s02_x, s02_y, s10_x, s10_y, s32_x, s32_y, s_numer, t_numer, denom, t;
    s10_x = p1_x - p0_x;
    s10_y = p1_y - p0_y;
    s32_x = p3_x - p2_x;
    s32_y = p3_y - p2_y;

    denom = s10_x * s32_y - s32_x * s10_y;
    if (denom == 0)
        return 0; // Collinear
    bool denomPositive = denom > 0;

    s02_x = p0_x - p2_x;
    s02_y = p0_y - p2_y;
    s_numer = s10_x * s02_y - s10_y * s02_x;
    if ((s_numer < 0) == denomPositive)
        return false; // No collision

    t_numer = s32_x * s02_y - s32_y * s02_x;
    if ((t_numer < 0) == denomPositive)
        return false; // No collision

    if (((s_numer > denom) == denomPositive) || ((t_numer > denom) == denomPositive))
        return false; // No collision
    // Collision detected

    return true;
}

bool findinter(Point p1, Point p2, vector<plane> &planes)
{


    Point q1{};
    Point q2{};
    for (auto & plane : planes)
    {
        q1.x = plane.p1.x;
        q1.y = plane.p1.y;
        q2.x = plane.p2.x;
        q2.y = plane.p2.y;
        if (get_line_intersection(p1.x, p1.y, p2.x, p2.y, q1.x, q1.y, q2.x, q2.y))
        {
            ROS_INFO("true");
            return true;
        }
    }
    return false;
}

int main(int ac, char** ar)
{
    ros::init(ac, ar, "points_and_lines");
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);

    ros::Rate r(10);
    ObjectMap *map;

    ROS_INFO("init");
    std::ifstream f("json.json");
    map = new ObjectMap(&f);

    //json j;
    //f >> j;

    //std::vector<p> walls;
    //std::string s;
    //f >> s;
    //ROS_INFO("Objects size %i", j["Object"].size());
    //ROS_INFO("%s", s);

    //for (int k = 0; k < j["Object"].size(); k++)
    //{
    //    p new_wall;
    //    new_wall.x = j["Object"][k]["p1"]["x"];
    //    new_wall.y = j["Object"][k]["p1"]["y"];
    //    ROS_INFO("p1.x %f p1.y %f", new_wall.x, new_wall.y);
    //    walls.push_back(new_wall);
    //   new_wall.x = j["Object"][k]["p2"]["x"];
    //    new_wall.y = j["Object"][k]["p2"]["y"];
    //    walls.push_back(new_wall);
    //    ROS_INFO("p2.x %f p2.y %f", new_wall.x, new_wall.y);

    //}
    // float f = 0.0;
    visualization_msgs::Marker points, line_strip, line_list, wpoint, way_strip;
    points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = wpoint.header.frame_id = way_strip.header.frame_id = "/my_frame";

    points.header.stamp = wpoint.header.stamp = way_strip.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
    points.ns = line_list.ns = line_strip.ns = wpoint.ns = way_strip.ns = "points_and_lines";
    points.action = line_strip.action = line_list.action = wpoint.action = way_strip.action = visualization_msgs::Marker::ADD;
    points.pose.orientation.w = line_list.pose.orientation.w = line_strip.pose.orientation.w = wpoint.pose.orientation.w = way_strip.pose.orientation.w = 1.0;


    points.id = 0;
    line_strip.id = 1;
    line_list.id = 2;
    wpoint.id = 3;
    way_strip.id = 4;



    points.type = visualization_msgs::Marker::POINTS;
    line_strip.type = visualization_msgs::Marker::LINE_STRIP;
    line_list.type = visualization_msgs::Marker::LINE_LIST;
    wpoint.type = visualization_msgs::Marker::POINTS;
    way_strip.type = visualization_msgs::Marker::LINE_STRIP;

    points.scale.x = 0.2;
    points.scale.y = 0.2;
    wpoint.scale.x = 0.4;
    wpoint.scale.y = 0.4;

    line_list.scale.x = 0.1;
    line_strip.scale.x = 0.1;
    way_strip.scale.x = 0.1;

    points.color.g = 1.0f;
    points.color.a = 1.0;
    wpoint.color.r = 1.0;
    wpoint.color.a = 1.0;

    line_strip.color.b = 1.0;
    line_strip.color.a = 1.0;

    line_list.color.r = 1.0;
    line_list.color.a = 1.0;

    way_strip.color.r = 1.0;            ROS_INFO("a");

    way_strip.color.a = 1.0;

    ROS_INFO("hi");
    for( uint32_t i = 0; i <= map->corners.size(); i++)
    {

        geometry_msgs::Point p;
        ROS_INFO("a");
        ROS_INFO("%i", map->corners.size());
        if (i < map->corners.size())
        {
            p.x = map->corners[i].x;
            p.y = map->corners[i].y;
            p.z = 0.0;
        }
        else
        {
            p.x = map->corners[0].x;
            p.y = map->corners[0].y;
            p.z = 0.0;
        }
        ROS_INFO("b");


        points.points.push_back(p);
        line_strip.points.push_back(p);
        ROS_INFO("a");

        //    float y = 5 * sin(f + i / 100.0f * 2 * M_PI);
        //    float z = 5 * cos(f + i / 100.0f * 2 * M_PI);

        //    geometry_msgs::Point p;
        //    p.x = (int32_t)i - 50;
        //    p.y = y;
        //    p.z = z;

        //    points.points.push_back(p);
        //    line_strip.points.push_back(p);


        //    line_list.points.push_back(p);
        //    p.z += 1.0;
        //    line_list.points.push_back(p);


    }
    ROS_INFO("bye" );
    geometry_msgs::Point p;
    p.x = 0;
    p.y = 0;
    p.z = 0;

    wpoint.points.push_back(p);
    way_strip.points.push_back(p);

    Point p1{};
    Point p2{};
    for (auto & corner : map->corners)
    {
        if (corner.type == 1)
        {
            p1.x = corner.x - 0.5;
            p1.y = corner.y - 0.5;
        }
    }
    ROS_INFO("ku");
    while (bool t = true)
    {
        p2.x = p1.x;
        p2.y = p1.y - 1;
        if (findinter(p1, p2, map->planes))
        {
            p.x = p1.x;
            p.y = p1.y;
            wpoint.points.push_back(p);
            way_strip.points.push_back(p);
            marker_pub.publish(wpoint);
            marker_pub.publish(way_strip);
            marker_pub.publish(points);
            marker_pub.publish(line_strip);
            r.sleep();
            ROS_INFO("ky");
            p2.x = p1.x - 1;
            p2.y = p1.y;
            if(findinter(p1, p2, map->planes))
            {

                while (bool tttt = true)
                {
                    p2.x = p1.x -1;
                    p2.y = p1.y;
                    if (findinter(p1, p2, map->planes))
                    {
                        p2.x = p1.x;
                        p2.y = p2.y + 1;
                        if (findinter(p1, p2, map->planes))
                        {
                            t = false;
                            break;
                        }
                        p.x = p1.x;
                        p.y = p1.y;
                        wpoint.points.push_back(p);
                        way_strip.points.push_back(p);
                        marker_pub.publish(wpoint);
                        marker_pub.publish(way_strip);
                        marker_pub.publish(points);
                        marker_pub.publish(line_strip);
                        r.sleep();
                        p1.y++;

                    }
                    else
                    {
                        p.x = p1.x;
                        p.y = p1.y;
                        wpoint.points.push_back(p);
                        way_strip.points.push_back(p);
                        marker_pub.publish(wpoint);
                        marker_pub.publish(points);
                        marker_pub.publish(line_strip);
                        marker_pub.publish(way_strip);
                        r.sleep();
                        p1.x--;
                    }
                }

            }
            else
            {
                p1.x--;
                while (bool tt = true)
                {
                    p2.x = p1.x;
                    p2.y = p1.y + 1;
                    if (findinter(p1, p2, map->planes))
                    {
                        while(bool ttt = true)
                        {

                            p2.x = p1.x - 1;
                            p2.y = p1.y;
                            if (findinter(p1, p2, map->planes))
                            {
                                p2.x = p1.x;
                                p2.y = p2.y - 1;
                                if (findinter(p1, p2, map->planes))
                                {
                                    t = false;
                                    tt = false;
                                    break;
                                }
                                p.x = p1.x;
                                p.y = p1.y;
                                wpoint.points.push_back(p);
                                way_strip.points.push_back(p);
                                marker_pub.publish(wpoint);
                                marker_pub.publish(points);
                                marker_pub.publish(line_strip);
                                marker_pub.publish(way_strip);
                                r.sleep();
                                p1.y--;
                            }
                            else
                            {
                                p.x = p1.x;
                                p.y = p1.y;
                                wpoint.points.push_back(p);
                                way_strip.points.push_back(p);
                                marker_pub.publish(wpoint);
                                marker_pub.publish(way_strip);
                                marker_pub.publish(points);
                                marker_pub.publish(line_strip);
                                r.sleep();
                                p1.x--;
                                break;
                            }

                        }
                        break;
                    }
                    p.x = p1.x;
                    p.y = p1.y;
                    wpoint.points.push_back(p);
                    way_strip.points.push_back(p);
                    marker_pub.publish(wpoint);
                    marker_pub.publish(points);
                    marker_pub.publish(line_strip);
                    marker_pub.publish(way_strip);
                    r.sleep();
                    p1.y++;
                }
            }
        }
        p.x = p1.x;
        p.y = p1.y;
        wpoint.points.push_back(p);
        way_strip.points.push_back(p);
        marker_pub.publish(wpoint);
        marker_pub.publish(way_strip);
        marker_pub.publish(points);
        marker_pub.publish(line_strip);
        r.sleep();
        p1.y--;
    }


    while (ros::ok())
    {



        marker_pub.publish(points);
        marker_pub.publish(line_strip);
        marker_pub.publish(wpoint);
        marker_pub.publish(way_strip);
        //marker_pub.publish(line_list);

        r.sleep();

        //  f += 0.04;
    }
}
