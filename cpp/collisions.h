#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "rectangularRobot.h"
#include "circularRobot.h"

double computeDistance(double x1, double x2, double y1, double y2);

bool isColliding(CircularRobot r1, CircularRobot r2);
bool isColliding(CircularRobot r1, RectangularRobot r2);
bool isColliding(RectangularRobot r1, CircularRobot r2);
bool isColliding(RectangularRobot r1, RectangularRobot r2);

#endif