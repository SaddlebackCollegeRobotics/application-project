#include "circularRobot.h"

CircularRobot::CircularRobot(double xPos, double yPos, double radius) {
    this->xPos = xPos;
    this->yPos = yPos;
    this->radius = radius;
}

CircularRobot::~CircularRobot() {

}

double CircularRobot::getRadius() {
    return radius;
}