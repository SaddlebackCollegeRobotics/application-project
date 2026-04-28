# Overview:
# Three collision cases are handled:
# circle vs circle, rectangle vs rectangle, and circle vs rectangle.
# Each case has its own helper function to keep the logic clean and separated.
# is_colliding() dispatches to the correct helper based on the type of each robot.

class Robot(object): # parent class, for is_colliding, we can pass in per robot arguments
    def __init__(self, x, y):
        self.x = x
        self.y = y

class CircularRobot(Robot): # center position (x, y) and radius
    def __init__(self, x, y, radius):
        self.radius = radius
        super().__init__(x, y) #inherit from parent

class RectangularRobot(Robot): # center position (x, y) and width and height
    def __init__(self, x, y, width, height):
        self.width = width
        self.height = height
        super().__init__(x, y) #inherit from parent


# decided to have the helpers be standalone rather than methods within the class
# (collisions would be how two robots interact, not properties of each robot)
# using <= for all helper function comparisons so that robots touching at exactly one point are considered colliding

def circle_vs_circle(c1, c2):
    # if the distance between the centers is less than the total radius (so sum up both radi)
    if (c1.x - c2.x)**2 + (c1.y - c2.y)**2 <= (c1.radius + c2.radius)**2:
        return True
    else:
        return False

def rectangle_vs_rectangle(r1, r2):
    # rectangles overlap on the x-- if ones right edge is further than the others left edge,
    # and if the top is past the bottom of the other
    # if both x and y axes overlap then there is a collision (assuming there are no rotations)

    #get all the measurements:
    r1_right = r1.x + r1.width/2
    r1_bottom = r1.y + r1.height/2
    r1_left = r1.x - r1.width/2
    r1_top = r1.y - r1.height/2

    r2_right = r2.x + r2.width/2
    r2_bottom = r2.y + r2.height/2
    r2_left = r2.x - r2.width/2
    r2_top = r2.y - r2.height/2

    # find x and y overlap and return true if it overlaps on both axes
    x_overlap = r1_right >= r2_left and r2_right >= r1_left
    y_overlap = r1_bottom >= r2_top and r2_bottom >= r1_top
    return x_overlap and y_overlap

def rectangle_vs_circle(c1, r1):
    # get the closest point on the rectangle (closest to the circles center)
    # if that point is wihtin the circles radius then the rect and circle overlap
    r1_left = r1.x - r1.width/2
    r1_right = r1.x + r1.width/2
    r1_top = r1.y - r1.height/2
    r1_bottom = r1.y + r1.height/2

    # if x is to the left of the rect then use left
    # if its to the right then use right and if its inside then just use x
    n_x = max(r1_left, min(c1.x, r1_right))
    # same thing for y (if y is above top then use top, else use bottom and if its equal use y)
    n_y = max(r1_top, min(c1.y, r1_bottom))

    # now just check if that point is inside the circle (get squared distance)
    dx = c1.x - n_x
    dy = c1.y - n_y
    return dx**2 + dy**2 <= c1.radius**2



def is_colliding(s1, s2):
    # first we check the robots instance to decide which intersection function to use
    # Three main comparisons we need to check:
    # circle vs circle, rectangle vs rectangle, circle vs rectangle
    if isinstance(s1, CircularRobot) and isinstance(s2, CircularRobot):
        return circle_vs_circle(s1, s2)
    elif isinstance(s1, RectangularRobot) and isinstance(s2, RectangularRobot):
        return rectangle_vs_rectangle(s1, s2)
    else: # first parameter is circular
        if isinstance(s1, CircularRobot):
            c = s1
        else:
            c = s2
        if isinstance(s1, RectangularRobot): # second parameter is rectangular
            r = s1
        else:
            r = s2
        return rectangle_vs_circle(c, r) # final comparison case
