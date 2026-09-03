#include "collisions.h"
#include <cmath>
//Used to find the magnitude of vectors between two shapes
double computeDistance(double x1, double x2, double y1, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

bool isColliding(CircularRobot r1, CircularRobot r2) {
    //simply use the distance from each robots center to determine the "zone" in which it must be touching, and if less than the combined radius, returns true
    return (computeDistance(r1.getXPos(), r2.getXPos(), r1.getYPos(), r2.getYPos()) <= (r1.getRadius() + r2.getRadius()));
}

bool isColliding(CircularRobot r1, RectangularRobot r2) {
    //finding the distance between the x and y distances of each shapes center
    double distX = abs(r1.getXPos() - r2.getXPos());
    double distY = abs(r1.getYPos() - r2.getYPos());
    //compares the distance between the center of each shape and if stricly greater than the radius+width/radius+height than the shapes are known to be seperate. Also covers a case where a shape is directly above another, but still not touching
    if (distX > (r2.getWidth() / 2.0 + r1.getRadius()) || distY > (r2.getHeight() / 2.0 + r1.getRadius())) return false;

    //same operation as above function but returns true if touching     Note: this is only true if it is touching on the furthest Left/Right/Top/Bottom part of the circle
    if (distX <= (r2.getWidth() / 2.0) || distY <= (r2.getHeight() / 2.0)) return true;
    
    //checks if the corner of a rectangle is touching the circle by checking if the distance from the rectangle to the circle is less than the radius
    if (computeDistance(distX, r2.getWidth() / 2.0, distY, r2.getHeight() / 2.0) <= r1.getRadius()) return true;

    return false;
}

//using the same function but reversing the calls to code less
bool isColliding(RectangularRobot r1, CircularRobot r2) {
    return isColliding(r2, r1);
}

//using demorgans law to check the position of each edge relative to each other
bool isColliding(RectangularRobot r1, RectangularRobot r2) {
    return !(r1.getLeftEdge() > r2.getRightEdge() || r1.getBottomEdge() > r2.getTopEdge() || r1.getTopEdge() < r2.getBottomEdge() || r1.getRightEdge() < r2.getLeftEdge());
}