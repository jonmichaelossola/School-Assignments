//
//  flyingObject.cpp
//  Skeet
//
//  Created by Jon Michael Ossola on 3/5/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <stdio.h>
#include "flyingObject.h"
#include "game.h"

/******************************************************
 * This is the default constructor for the flying object
 * class.
 ******************************************************/
FlyingObject::FlyingObject()
{
    alive = true;
}

/******************************************************
 * Advance the flying object by adding the velocity to
 * the current x and y coordinates.
 ******************************************************/
void FlyingObject::advance()
{
    if (isAlive())
    {
        point.setX(point.getX()+velocity.getDx());
        point.setY(point.getY()+velocity.getDy());
    }
}

