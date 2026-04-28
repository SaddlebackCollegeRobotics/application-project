#include "RectangularRobot.hpp"

RectangularRobot::RectangularRobot(double center_x, double center_y, double length, double width) : Robot(center_x, center_y)
{
    this->length = length;
    this->width = width;
}
