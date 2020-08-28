//
// Created by sab3r on 22.06.2020.
//

#include "ManControll.h"

ManControll::ManControll(ros::NodeHandle *n)
{
    pubForce = n->advertise<std_msgs::Float64>("ForceR", 0);
    pubAngular = n->advertise<std_msgs::Float64>("ForceL", 0);
    pubTwist = n->advertise<geometry_msgs::Twist>("roboteq_driver/cmd", 1);
}

int ManControll::getch()
{
    static struct termios oldt, newt;
    tcgetattr( STDIN_FILENO, &oldt);           // save old settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON);                 // disable buffering
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new settings

    int c = getchar();  // read character (non-blocking)

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
    return c;
}

int main(int ac, char** av)
{
    ManControll *cont;
    ros::init(ac, av, "mancontroll");
    ros::NodeHandle n;
    cont = new ManControll(&n);
    int last = 0;
    std_msgs::Float64 Force;
    std_msgs::Float64 Angular;
    geometry_msgs::Twist Tw;
    Tw.angular.x = 0;
    Tw.angular.y = 0;
    Tw.angular.z = 0;
    Tw.linear.x = 0;
    Tw.linear.y = 0;
    Tw.linear.z = 0;
    double s = 0;
    double f = 0;
    while (ros::ok()) {
        int c = cont->getch();   // call your non-blocking input function
        if (c == 'w')
        {
            Force.data = f;
            Tw.linear.x = s;
            cont->pubForce.publish(Force);
            cont->pubTwist.publish(Tw);
        }
        else if (c == 'd')
        {
            Angular.data = ANGULARTICK;
            Tw.angular.z = s;
            cont->pubAngular.publish(Angular);
        }
        else if (c == 'a')
        {
            Angular.data = -ANGULARTICK;
            Tw.angular.z = s;
            cont->pubTwist.publish(Tw);
            cont->pubAngular.publish(Angular);
        }
        else if (c == 'x')
        {
            Angular.data = 0;
            Tw.angular.z = 0;
            cont->pubAngular.publish(Angular);
            cont->pubTwist.publish(Tw);

        }
        else if (c == 'r')
        {
            f += 0.01;
            s += 0.1;
        }
        else if (c == 'f')
        {
            f -= 0.01;
            s -= 0.1;
        }
        else
        {
            if (last == 'w' || last == 'a' || last == 'd' || last == 'x' || last == 'r' || last == 'f')
            {
                Angular.data = 0;
                cont->pubAngular.publish(Angular);
                Force.data = 0;
                cont->pubForce.publish(Force);
                Tw.angular.z = 0;
                Tw.linear.x = 0;
                cont->pubTwist.publish(Tw);
            }
        }
        last = c;
        ros::spinOnce();
    }
}
