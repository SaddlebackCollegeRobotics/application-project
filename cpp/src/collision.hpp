#pragma once
#include "CircularRobot.hpp"
#include "RectangularRobot.hpp"

bool isColliding(const Robot& a, const Robot& b);
bool circleVsCircle(const CircularRobot& ca, const CircularRobot& cb);
bool rectVsRect(const RectangularRobot& ra, const RectangularRobot& rb);
bool circleVsRect(const CircularRobot& ca, const RectangularRobot& rb);

double getCenterDistance(const Robot& a, const Robot& b);
double findClosest(double& circle, double& rMin, double& rMax);
