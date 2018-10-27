//
//  bird.cpp
//  Skeet
//
//  Created by Jon Michael Ossola on 3/2/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <stdio.h>
#include "bird.h"

/**********************************************************************
 * This is the default constructor for the bird class. it sets the
 * number of hits to zero as well as the radius to zero. I did this
 * for debugging.
 **********************************************************************/
Bird::Bird()
{
}

/*********************************************************************
 * This just sets the point for the bird class. That's what this
 * function does.
 *********************************************************************/
Bird :: Bird(Point & point)
{
    setPoint(point);
}

/*******************************************************************
 * This is the kill function for the bird class, it simply kills
 * the bird by setting the alive variable to false.
 *******************************************************************/
void Bird::kill()
{
    alive = false;
}
