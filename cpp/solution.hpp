#pragma once

// Following general oop principles because it seems that's what's wanted
#include <cmath>
#include <cstdlib>

class Robot
{
        private:
                double x;
                double y;

        public:
                Robot(const double aX, const double aY) : x(aX), y(aY)
                {
                }

                void setX(double newX)
                {
                        x = newX;
                }
                void setY(double newY)
                {
                        y = newY;
                }

                double getX()
                {
                        return x;
                }
                double getY()
                {
                        return y;
                }
};

class CircularRobot : public Robot
{
        private:
                double radius;

        public:
                CircularRobot(const double aX, const double aY, const double aR)
                    : Robot(aX, aY), radius(aR)
                {
                }

                void setRadius(const double newRadius)
                {
                        radius = newRadius;
                }
                double getRadius() const
                {
                        return radius;
                }
};

class RectangularRobot : public Robot
{
        private:
                double width;
                double height;

        public:
                RectangularRobot(const double aX, const double aY,
                                 const double aW, const double aH)
                    : Robot(aX, aY), width(aW), height(aH)
                {
                }

                void setWidth(const double newWidth)
                {
                        width = newWidth;
                }
                void setHeight(const double newHeight)
                {
                        height = newHeight;
                }

                double getWidth() const
                {
                        return width;
                }
                double getHeight() const
                {
                        return height;
                }
};

bool isColliding(CircularRobot cRobot1, CircularRobot cRobot2)
{
        // For this function we're going to add the radiuses and compare it to
        // the distance but optimize for less instructions The inequality is r1
        // + r2 >= distanceFormula

        double totalRadius = cRobot1.getRadius() + cRobot2.getRadius();

        // We're going to calculates the sum of the squares without the square
        // root because in the inequality we can square both sides which is more
        // efficient for the cpu
        // Not using POW because that takes far more instructions
        double xComponent = cRobot1.getX() - cRobot2.getX();
        double yComponent = cRobot1.getY() - cRobot2.getY();
        double psuedoDistance =
            xComponent * xComponent + yComponent * yComponent;

        // If the totalRadius squared is greater than or equal to the distance
        // then we know they overlap
        return (totalRadius * totalRadius) >= psuedoDistance;
}

bool isColliding(RectangularRobot rRobot1, RectangularRobot rRobot2)
{
        // For this function we're going to find the components of the distance
        // and compare them to the half width and half height but optimize it
        // slightly The inequalities 1/2 Width1 + 1/2 Width2 >= xComponent ->
        // which becomes Width1 + Width2 >= 2 * xComponent -> since
        // multiplication is faster

        double totalWidth  = rRobot1.getWidth() + rRobot2.getWidth();
        double totalHeight = rRobot1.getHeight() + rRobot2.getHeight();

        double xComponent = 2 * std::abs(rRobot1.getX() - rRobot2.getX());
        double yComponent = 2 * std::abs(rRobot1.getY() - rRobot2.getY());

        return (totalWidth >= xComponent) && (totalHeight >= yComponent);
}

bool isColliding(RectangularRobot rRobot, CircularRobot cRobot)
{
        // This is functionally the same as the rectangle one but with corner
        // cases because component wise comparisons do not guarantee anything
        double halfWidth  = rRobot.getWidth() / 2;
        double halfHeight = rRobot.getHeight() / 2;

        double xComponent = rRobot.getX() - cRobot.getX();
        double yComponent = rRobot.getY() - cRobot.getY();

        // absolute value can be done in 1 cycle because of a property
        // with double values in their bit form
        double absXComponent = std::fabs(xComponent);
        double absYComponent = std::fabs(yComponent);

        if (absXComponent < halfWidth)
                return (cRobot.getRadius() >= (halfHeight - absYComponent));
        if (absYComponent < halfHeight)
                return (cRobot.getRadius() >= (halfWidth - absXComponent));
        else
        {
                if (xComponent > 0)
                        halfWidth = -halfWidth;
                if (yComponent > 0)
                        halfHeight = -halfHeight;

                double xCorner = rRobot.getX() + halfWidth;
                double yCorner = rRobot.getY() + halfHeight;

                double xDistance = (xCorner - cRobot.getX());
                double yDistance = (yCorner - cRobot.getY());

                return ((cRobot.getRadius() * cRobot.getRadius()) >=
                        (xDistance * xDistance) + (yDistance * yDistance));
        }
}

bool isColliding(CircularRobot cRobot, RectangularRobot rRobot)
{
        return isColliding(rRobot, cRobot);
}
