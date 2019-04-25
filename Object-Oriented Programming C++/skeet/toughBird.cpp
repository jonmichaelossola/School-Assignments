//
//  toughBird.cpp
//  Skeet
//
//  Created by Jon Michael Ossola on 3/5/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <stdio.h>

#include "toughBird.h"
#include "uiDraw.h"

/*************************************************************
 * The default constructor for the bird. Set the radius to zero,
 * number of hits to zero, create a point, and set the velocity.
 **************************************************************/
ToughBird :: ToughBird()
{
    radius = 15;
    numHits = 3;
    point = Point(-200, random(-200, 200));
    velocity.setDx(3);
    velocity.setDy(3);
}

/************************************************************
 * Draw the tough bird to the screen using a function
 * from the user interact file.
 ************************************************************/
void ToughBird::draw() const
{
    drawToughBird(point, radius, numHits);
}

/***********************************************************
 * The bird has been hit! Decrement the number of hits, and
 * if the number of hits is zero, kill the bird.
 ************************************************************/
int ToughBird::hit()
{
    numHits--;
    if (numHits < 1)
    {
        alive = false;
        return 3;
    }
    return 0;
}
