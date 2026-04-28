#pragma once
#include "Robot.hpp"

class RectangularRobot : public Robot
{
public:
    double length;
    double width;
    RectangularRobot(double center_x, double center_y, double length, double width);
    ~RectangularRobot() = default;
};
