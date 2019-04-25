#include "flyingObject.h"


// Put your FlyingObject method bodies here
/************************************************************
 * Advance function. Move the objects based off of their
 * velocity, and put all objects on the screen, if they
 * veer off of the screen.
 ************************************************************/
void FlyingObject::advance()
{
    point.setX(point.getX()+velocity.getDx());
    point.setY(point.getY()+velocity.getDy());
    
    if (point.getX() > 200 || point.getX() < -200)
    {
        point.setX(point.getX() * -1);
    }
    else if (point.getY() > 200 || point.getY() < -200)
    {
        point.setY(point.getY() * -1);
    }
}

/***********************************************************
 * If the left arrow key is pressed, rotate 6 degrees, and
 * decrement the angle variable by six. Do the oppositte
 * if the right arrow key is pressed.
 **********************************************************/
void FlyingObject::rotateRight()
{
    rotation -= 6;
    angle += 6;
   
}

void FlyingObject::rotateLeft()
{
    rotation += 6;
    angle -= 6;
}
