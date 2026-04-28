#include "collision.hpp"
#include <stdexcept>
#include <cmath>

// Dispatches to the right helper depending on data type
// dynamic_cast returns nullptr if the cast fails, so we can check all combinations :)
bool isColliding(const Robot& a, const Robot& b)
{
    const CircularRobot* ca = dynamic_cast<const CircularRobot*>(&a);
    const CircularRobot* cb = dynamic_cast<const CircularRobot*>(&b);
    const RectangularRobot* ra = dynamic_cast<const RectangularRobot*>(&a);
    const RectangularRobot* rb = dynamic_cast<const RectangularRobot*>(&b);
    if (ca && cb) return circleVsCircle(*ca, *cb);
    if (ra && rb) return rectVsRect(*ra, *rb);
    if (ca && rb) return circleVsRect(*ca, *rb);
    if (ra && cb) return circleVsRect(*cb, *ra); // flip order to match signature

    throw std::invalid_argument("unhandled robot type combination");
}

// Euclidean distance between two robot centers.
double getCenterDistance(const Robot& a, const Robot& b)
{
    double dx = a.center_x - b.center_x;
    double dy = a.center_y - b.center_y;
    return sqrt(dx*dx + dy*dy);
}

// Two circles collide if the distance between centers is less than the sum of their radii.
bool circleVsCircle(const CircularRobot& ca, const CircularRobot& cb)
{
    return (ca.radius + cb.radius) >= getCenterDistance(ca, cb);
}

// rectangles collide if they overlap on both the x and y axes independently.
bool rectVsRect(const RectangularRobot& ra, const RectangularRobot& rb)
{
    double dx = std::abs(ra.center_x - rb.center_x);
    double dy = std::abs(ra.center_y - rb.center_y);
    return (ra.width + rb.width) / 2 >= dx && (ra.length + rb.length) / 2 >= dy;
}

// finds the closest point between the circle and a line
double findClosest(const double &circle, const double &rMin, const double &rMax)
{
    if (circle >= rMin && circle <= rMax) return circle;
    else if (circle < rMin) return rMin;
    else return rMax;
}

// Find the closest point on the rectangle to the circle center, then check if that distance is within the circle's radius.
bool circleVsRect(const CircularRobot& ca, const RectangularRobot& rb)
{
    double closest_x = findClosest(ca.center_x, rb.center_x - rb.length/2, rb.center_x + rb.length/2);
    double closest_y = findClosest(ca.center_y, rb.center_y - rb.width/2,  rb.center_y + rb.width/2);

    double dx = closest_x - ca.center_x;
    double dy = closest_y - ca.center_y;

    return std::sqrt(dx*dx + dy*dy) <= ca.radius;
}
