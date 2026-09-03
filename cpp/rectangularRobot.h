#ifndef RECTANGULAR_ROBOT_H
#define RECTANGULAR_ROBOT_H
#include "robot.h"

class RectangularRobot : public Robot {
    public:
        double width;
        double height;

        //functions to get the furthest edges of the rectangular robots
        double getWidth();
        double getHeight();
        double getLeftEdge();
        double getRightEdge();
        double getTopEdge();
        double getBottomEdge();
        
        RectangularRobot(double xPos, double yPos, double width, double height);
        ~RectangularRobot();
};

#endif