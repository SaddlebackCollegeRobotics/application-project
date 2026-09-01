#ifndef CIRCULAR_ROBOT_H
#define CIRCULAR_ROBOT_H
#include "robot.h"

class CircularRobot : public Robot {
    public:
        double radius;
        double getRadius();
        CircularRobot(double xPos, double yPos, double radius);
        ~CircularRobot();
};

#endif