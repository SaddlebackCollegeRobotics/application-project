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
    return leftEdge;
}

double RectangularRobot::getRightEdge() {
    return leftEdge;
}

double RectangularRobot::getTopEdge() {
    return leftEdge;
}

double RectangularRobot::getBottomEdge() {
    return bottomEdge;
}