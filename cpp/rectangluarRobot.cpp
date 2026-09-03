#include "rectangularRobot.h"

RectangularRobot::RectangularRobot(double xPos, double yPos, double width, double height) {
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
}

RectangularRobot::~RectangularRobot() {

}

double RectangularRobot::getWidth() {
    return width;
}

double RectangularRobot::getHeight() {
    return height;
}

double RectangularRobot::getLeftEdge() {
    return xPos - (width/2);
}

double RectangularRobot::getRightEdge() {
    return xPos + (width/2);
}

double RectangularRobot::getTopEdge() {
    return yPos + (height/2);
}

double RectangularRobot::getBottomEdge() {
    return yPos - (height/2);
}