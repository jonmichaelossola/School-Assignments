#include "ship.h"
#include "uiDraw.h"
// Put your ship methods here

#include <cmath>

/*******************************************************
 * Default constructor. Set the rotation to zero, angle
 * to 90, alive to true, and thrust to the amount allocated.
 *******************************************************/
Ship :: Ship()
{
    angle = 90;
    thrust = THRUST_AMOUNT;
    rotation = 0;
    alive = true;
    radius = 12;
}

/*******************************************************
 * Check if the ship can thrust by first checking if
 * the ship is alive, else return false.
 *******************************************************/
bool Ship :: canThrust() const
{
    if (alive)
    {
        return true;
    }
    else {
        return false;
    }
}

/********************************************************
 * Draw the space ship, by using the method given in the
 * other files.
 *********************************************************/
void Ship :: drawSpaceShip() const
{
    if (alive)
    {
        drawShip(point, rotation);
    }
}

/*********************************************************
 * Apply the thrust by using the bullet's cosine and sine
 * function to fire the bullets and apply it here.
 *********************************************************/
void Ship :: applyThrust()
{
    if (canThrust())
    {
        float newDx = thrust * (-cos(M_PI / 180.0 * angle));
        float newDy = thrust * (sin(M_PI / 180.0 * angle));
        
        velocity.setDx(velocity.getDx() + newDx);
        velocity.setDy(velocity.getDy() + newDy);
    }
}
