#ifndef ROBOT_H
#define ROBOT_H

class Robot {
    public:
        double xPos;
        double yPos;
        double getXPos();
        double getYPos();
        Robot(double xPos, double yPos);
        Robot();
        ~Robot();
};

#endif