#include "CircularRobot.hpp"

CircularRobot::CircularRobot(double center_x, double center_y, double radius) : Robot(center_x, center_y)
{
    this->radius = radius;
}
