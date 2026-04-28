# ----- import your modules here -----
from robots import CircularRobot, RectangularRobot, is_colliding

def print_is_colliding(obj1: str, obj2: str, status: bool):
    print(f'{obj1} is {'' if status else 'not '}colliding with {obj2}')

def main():
    # Define circular robots
    c1 = CircularRobot( 12.5,  -2.5,  2.0);
    c2 = CircularRobot(  1.5,  14.5,  4.0);
    c3 = CircularRobot(  2.5, -22.5, 20.0);
    c4 = CircularRobot(-13.2,  -0.8,  0.5);

    # Define rectangular robots
    r1 = RectangularRobot( -5.0,  5.0,  5.5, 13.0);
    r2 = RectangularRobot( 12.5,  7.5,  2.0, 16.2);
    r3 = RectangularRobot(-15.5,  6.5,  4.0, 14.0);
    r4 = RectangularRobot(  2.5,  4.5,  5.0,  9.0);
    r5 = RectangularRobot( -7.5, 20.5, 10.0,  4.0);
    r6 = RectangularRobot(-10.0,  4.5,  7.0,  3.0);

    # Perform collision checks
    print_is_colliding('c1', 'r2', is_colliding(c1, r2));
    print_is_colliding('c1', 'c3', is_colliding(c1, c3));
    print_is_colliding('r1', 'c2', is_colliding(r1, c2));
    print_is_colliding('r1', 'r5', is_colliding(r1, r5));
    print_is_colliding('r1', 'r6', is_colliding(r1, r6));
    print_is_colliding('c1', 'r5', is_colliding(c1, r5));
    print_is_colliding('c3', 'r5', is_colliding(c3, r5));
    print_is_colliding('r2', 'r5', is_colliding(r2, r5));

if __name__ == "__main__":
    main()
