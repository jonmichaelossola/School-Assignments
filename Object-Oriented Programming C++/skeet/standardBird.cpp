//
//  standardBird.cpp
//  Skeet
//
//  Created by Jon Michael Ossola on 3/5/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <stdio.h>
#include "standardBird.h"
#include "uiDraw.h"

/************************************************************
 * This is the default constructor for the standard bird class.
 * it sets the velocity, point, radius, and number of hits.
 ************************************************************/
StandardBird::StandardBird()
{
    radius = 15;
    numHits = 1;
    point = Point(-200, random(-200, 200));
    velocity.setDx(3);
    velocity.setDy(3);
}

/*************************************************************
 * Draw the bird to the screen using the draw bird function
 * in the interact file.
 ************************************************************/
void StandardBird::draw() const
{
    drawCircle(point, radius);
}

/************************************************************
 * The bird has been hit! Decrease its health by one and
 * if the number of hits is less than one, kill the bird.
 ************************************************************/
int StandardBird::hit() 
{
    numHits--;
    if (numHits < 1)
    {
        alive = false;
    }
    return 1;
}
