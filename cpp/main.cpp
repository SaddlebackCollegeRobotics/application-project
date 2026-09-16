#include "solution.hpp" // modify solution.hpp to include everything necessary

#include <string>
#include <cstdio>
using std::string;

// Method to display two objects' names and whether they're colliding
bool printIsColliding(const string& obj1, const string& obj2, bool status) {
    printf("%s is %scolliding with %s\n",
            obj1.c_str(), status ? "" : "not ", obj2.c_str());
    return status;
}

int main() {
    // Define circular robots
    CircularRobot c1( 12.5,  -2.5,  2.0);
    CircularRobot c2(  1.5,  14.5,  4.0);
    CircularRobot c3(  2.5, -22.5, 20.0);
    CircularRobot c4(-13.2,  -0.8,  0.5);

    // Define rectangular robots
    RectangularRobot r1( -5.0,  5.0,  5.5, 13.0);
    RectangularRobot r2( 12.5,  7.5,  2.0, 16.2);
    RectangularRobot r3(-15.5,  6.5,  4.0, 14.0);
    RectangularRobot r4(  2.5,  4.5,  5.0,  9.0);
    RectangularRobot r5( -7.5, 20.5, 10.0,  4.0);
    RectangularRobot r6(-10.0,  4.5,  7.0,  3.0);

    // Perform collision checks.
    bool allCorrect = true, symmetric = true;

    allCorrect &= printIsColliding("c1", "c2", isColliding( c1,  c2)) == false;
    allCorrect &= printIsColliding("c1", "c3", isColliding( c1,  c3)) == false;
    allCorrect &= printIsColliding("c1", "c4", isColliding( c1,  c4)) == false;
    allCorrect &= printIsColliding("c1", "r1", isColliding( c1,  r1)) == false;
    allCorrect &= printIsColliding("c1", "r2", isColliding( c1,  r2)) == true;
    allCorrect &= printIsColliding("c1", "r3", isColliding( c1,  r3)) == false;
    allCorrect &= printIsColliding("c1", "r4", isColliding( c1,  r4)) == false;
    allCorrect &= printIsColliding("c1", "r5", isColliding( c1,  r5)) == false;
    allCorrect &= printIsColliding("c1", "r6", isColliding( c1,  r6)) == false;

    allCorrect &= printIsColliding("c2", "c3", isColliding( c2,  c3)) == false;
    allCorrect &= printIsColliding("c2", "c4", isColliding( c2,  c4)) == false;
    allCorrect &= printIsColliding("c2", "r1", isColliding( c2,  r1)) == false;
    allCorrect &= printIsColliding("c2", "r2", isColliding( c2,  r2)) == false;
    allCorrect &= printIsColliding("c2", "r3", isColliding( c2,  r3)) == false;
    allCorrect &= printIsColliding("c2", "r4", isColliding( c2,  r4)) == false;
    allCorrect &= printIsColliding("c2", "r5", isColliding( c2,  r5)) == false;
    allCorrect &= printIsColliding("c2", "r6", isColliding( c2,  r6)) == false;

    allCorrect &= printIsColliding("c3", "c4", isColliding( c3,  c4)) == false;
    allCorrect &= printIsColliding("c3", "r1", isColliding( c3,  r1)) == false;
    allCorrect &= printIsColliding("c3", "r2", isColliding( c3,  r2)) == false;
    allCorrect &= printIsColliding("c3", "r3", isColliding( c3,  r3)) == false;
    allCorrect &= printIsColliding("c3", "r4", isColliding( c3,  r4)) == false;
    allCorrect &= printIsColliding("c3", "r5", isColliding( c3,  r5)) == false;
    allCorrect &= printIsColliding("c3", "r6", isColliding( c3,  r6)) == false;

    allCorrect &= printIsColliding("c4", "r1", isColliding( c4,  r1)) == false;
    allCorrect &= printIsColliding("c4", "r2", isColliding( c4,  r2)) == false;
    allCorrect &= printIsColliding("c4", "r3", isColliding( c4,  r3)) == true;
    allCorrect &= printIsColliding("c4", "r4", isColliding( c4,  r4)) == false;
    allCorrect &= printIsColliding("c4", "r5", isColliding( c4,  r5)) == false;
    allCorrect &= printIsColliding("c4", "r6", isColliding( c4,  r6)) == false;

    allCorrect &= printIsColliding("r1", "r2", isColliding( r1,  r2)) == false;
    allCorrect &= printIsColliding("r1", "r3", isColliding( r1,  r3)) == false;
    allCorrect &= printIsColliding("r1", "r4", isColliding( r1,  r4)) == false;
    allCorrect &= printIsColliding("r1", "r5", isColliding( r1,  r5)) == false;
    allCorrect &= printIsColliding("r1", "r6", isColliding( r1,  r6)) == true;

    allCorrect &= printIsColliding("r2", "r3", isColliding( r2,  r3)) == false;
    allCorrect &= printIsColliding("r2", "r4", isColliding( r2,  r4)) == false;
    allCorrect &= printIsColliding("r2", "r5", isColliding( r2,  r5)) == false;
    allCorrect &= printIsColliding("r2", "r6", isColliding( r2,  r6)) == false;

    allCorrect &= printIsColliding("r3", "r4", isColliding( r3,  r4)) == false;
    allCorrect &= printIsColliding("r3", "r5", isColliding( r3,  r5)) == false;
    allCorrect &= printIsColliding("r3", "r6", isColliding( r3,  r6)) == true;

    allCorrect &= printIsColliding("r4", "r5", isColliding( r4,  r5)) == false;
    allCorrect &= printIsColliding("r4", "r6", isColliding( r4,  r6)) == false;

    allCorrect &= printIsColliding("r5", "r6", isColliding( r5,  r6)) == false;

    // Swapped operands: isColliding(a, b) must agree with isColliding(b, a).
    allCorrect &= symmetric &= isColliding(c1, r2) == isColliding(r2, c1);
    allCorrect &= symmetric &= isColliding(c1, c3) == isColliding(c3, c1);
    allCorrect &= symmetric &= isColliding(c1, r5) == isColliding(r5, c1);
    allCorrect &= symmetric &= isColliding(c2, r5) == isColliding(r5, c2);
    allCorrect &= symmetric &= isColliding(c4, r3) == isColliding(r3, c4);
    allCorrect &= symmetric &= isColliding(r1, r2) == isColliding(r2, r1);
    allCorrect &= symmetric &= isColliding(r1, r6) == isColliding(r6, r1);
    allCorrect &= symmetric &= isColliding(r3, r6) == isColliding(r6, r3);

    // The verdict, after every individual result has been shown.
    printf("\n45 pairwise checks (expected collisions: c1-r2, r1-r6, c4-r3, r3-r6)\n");
    printf("all pair results correct: %s\n", allCorrect ? "PASS" : "FAIL");
    printf("argument order symmetric: %s\n", symmetric ? "PASS" : "FAIL");
    printf("%s\n", allCorrect ? "true" : "false");

    return 0;
}
