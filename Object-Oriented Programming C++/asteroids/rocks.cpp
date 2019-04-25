#include "rocks.h"

// Put your Rock methods here
#include <iostream>
#include <vector>
using namespace std;

/**************************************************************
 * Default constructor for the rock class. Set alive to true,
 * and the angle to 3.
 **************************************************************/
Rock :: Rock()
{
    alive = true;
    angle = 3;
}

/****************************************************************
 * This is the Big Rock default constructor. Set radius to 16,
 * alive to true, the rotation, the angle, the velocity and point.
 ****************************************************************/
BigRock :: BigRock()
{
    radius = 16;
    alive = true;
    rotation = random(0, 5);
    angle = 3;
    velocity.setDx(random(-3, 3));
    velocity.setDy(random(-3, 3));
    point = Point(random(-195, 195), random(-195, 195));
}

/*****************************************************************
 * Default constructor for the Medium Rock class. Set the radius
 * to 8, alive to true, the rotation, angle, point, and velocity.
 *****************************************************************/
MediumRock :: MediumRock()
{
    radius = 8;
    alive = true;
    rotation = random(0, 5);
    velocity.setDx(random(-3, 3));
    velocity.setDy(random(-3, 3));
    point = Point(random(-195, 195), random(-195, 195));
}

/***************************************************************
 * Non default medium rock constructor. It takes in a velocity
 * and a point and matches the it to the medium rock default values.
 ***************************************************************/
MediumRock::MediumRock(const float &newDx, const float &newDy, const Point &newPoint)
{
    alive = true;
    radius = 8;
    rotation = random(0, 5);
    
    // declare new velocity object and set values to this
    Velocity v;
    v.setDx(newDx);
    v.setDy(newDy);
    
    // store the new velocity object in the new medium rock vector
    setVelocity(v);
    setPoint(newPoint);
}

/***************************************************************
 * Non default constructor for a small rock. It changes the velocity
 * and point to the point passed in by the break apart function.
 ****************************************************************/
SmallRock::SmallRock(const float &newDx, const float &newDy, const Point &newPoint)
{
    alive = true;
    radius = 4;
    rotation = random(0, 5);
    
    // sets velocity to a new velocity object with the following values.
    Velocity v;
    v.setDx(newDx);
    v.setDy(newDy);
    
    // set the new velocity and the new point to our object
    setVelocity(v);
    this->setPoint(newPoint);
}

/***************************************************************
 * The default constructor of the small rock class. It sets
 * the rotation, angle, velocity, and sets the point of
 * of the small rock on the screen.
 ***************************************************************/
SmallRock :: SmallRock()
{
    radius = 4;
    alive = true;
    rotation = random(0, 5);
    angle = 3;
    velocity.setDx(random(-3, 3));
    velocity.setDy(random(-3, 3));
    point = Point(random(-195, 195), random(-195, 195));
}

/**************************************************************
 * Use the draw function from the Interact class and use that
 * to draw the asteroid, with a incrementing rotation.
 **************************************************************/
void BigRock :: draw()
{
    drawLargeAsteroid(point, rotation);
    rotation += BIG_ROCK_SPIN;
}

/*************************************************************
 * Call on the draw method of the interact class in the
 * other file.
 *************************************************************/
void MediumRock :: draw()
{
    drawMediumAsteroid(point, rotation);
    rotation += MEDIUM_ROCK_SPIN;
}

/**************************************************************
 * call on the draw method from the interact class, and use
 * that draw function to draw a small rock.
 ***************************************************************/
void SmallRock :: draw()
{
    drawSmallAsteroid(point, rotation);
    rotation += SMALL_ROCK_SPIN;
}

/**************************************************************
 * Return a vector of rock pointers that returns what the large
 * rock turns into: two medium rocks and a small rock.
 ***************************************************************/
vector<Rock*> BigRock::hit(Rock &rock)
{
    alive = false;
    vector<Rock*> rocks;
    
    rocks.push_back(new MediumRock(rock.getVelocity().getDx(), rock.getVelocity().getDy()+1, rock.getPoint()));
    rocks.push_back(new MediumRock(rock.getVelocity().getDx(), rock.getVelocity().getDy()-1, rock.getPoint()));
    rocks.push_back(new SmallRock(rock.getVelocity().getDx()+2, rock.getVelocity().getDy(), rock.getPoint()));
    
    return rocks;
}

/*************************************************************
 * Create a vector or Rock pointers that point to the default
 * constructor of the small rock class and stores two new
 * pointers to small rock objects
 **************************************************************/
vector<Rock*> MediumRock::hit(Rock &rock)
{
    
    alive = false;
    vector<Rock*> rocks;
    
    rocks.push_back(new SmallRock(rock.getVelocity().getDx()+3, rock.getVelocity().getDy(), rock.getPoint()));
    rocks.push_back(new SmallRock(rock.getVelocity().getDx()-3, rock.getVelocity().getDy(), rock.getPoint()));
    
    return rocks;
}

/*************************************************************
 * The small rock class, when hit by a bullet, does not become
 * anything else. Therefore, return an empty vector.
 **************************************************************/
vector<Rock*> SmallRock::hit(Rock &rock)
{
    alive = false;
    
    vector<Rock*> rocks;
    return rocks;
}
