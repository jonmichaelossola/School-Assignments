//
//  sacredBird.cpp
//  Skeet
//
//  Created by Jon Michael Ossola on 3/5/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <stdio.h>

#include "sacredBird.h"
#include "uiDraw.h"

/***********************************************************
 * This is the default constructor for the sacred bird.
 * it sets the various inherited objects to their default.
 ***********************************************************/
SacredBird :: SacredBird()
{
    this->numHits = 1;
    this->radius = 15;
    point = Point(-200, random(-200, 200));
    velocity.setDx(3);
    velocity.setDy(3);
}

/**********************************************************
 * Draw the sacred bird using the function in the user
 * interact file.
 **********************************************************/
void SacredBird::draw() const
{
    drawSacredBird(point, radius);
}

/***********************************************************
 * Decrement the number of hits, set it to dead if number
 * of hits is less than one, and return the negative one
 * as the score.
 **********************************************************/
int SacredBird::hit() 
{
    numHits--;
    if (numHits < 1)
    {
        alive = false;
    }
    return -1;
}
