#pragma once
#include "Robot.hpp"

class CircularRobot : public Robot
{
public:
    double radius;
    CircularRobot(double x, double y, double radius);
    ~CircularRobot() = default;
};
