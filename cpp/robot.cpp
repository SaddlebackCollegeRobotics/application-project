#include "robot.h"

Robot::Robot(double xPos, double yPos) {
    this->xPos = xPos;
    this->yPos = yPos;
}

Robot::Robot(){

}

Robot::~Robot() {

}

double Robot::getXPos() {
    return xPos;
}

double Robot::getYPos() {
    return yPos;
}