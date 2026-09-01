#ifndef RECTANGULAR_ROBOT_H
#define RECTANGULAR_ROBOT_H
#include "robot.h"

class RectangularRobot : public Robot {
    public:
        double width;
        double height;

        double leftEdge  = xPos - (width/2);
        double rightEdge = xPos + (width/2);
        double topEdge = yPos + (height/2);
        double bottomEdge = yPos - (height/2);

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