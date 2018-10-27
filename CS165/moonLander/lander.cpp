//
//  lander.cpp
//  moonLander
//
//  Created by Jon Michael Ossola on 2/16/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <stdio.h>
#include "lander.h"

/*************************************************************
 * The function below is the default constructor for the
 * Lander Class.
 *************************************************************/
Lander::Lander(): point(180, 180)
{
    setAlive(true);
    setFuel(500);
    setLanded(false);
}

/*************************************************************
 * Below is the function that determines if the lander can
 * use the fuel;
 *************************************************************/
bool Lander::canThrust() const
{
    if (fuel < 1)
        return false;
    else if (isLanded() || !isAlive())
        return false;
    
    // return false unless fuel is more than zero
    return true;
}

/************************************************************
 * This function applys the gravity settings to the game, so
 * that there is a constant pull on the lander to the ground.
 ************************************************************/
void Lander::applyGravity(float gravity)
{
    velocity.setDy(velocity.getDy()-gravity);
}

/***********************************************************
 * In this function, the lander can thrust to the left, and
 * as the left arrow key is pressed, the fuel goes down.
 **********************************************************/
void Lander::applyThrustLeft()
{
    if (canThrust())
    {
        velocity.setDx(velocity.getDx()+0.1);
        fuel--;
    }
}

/**********************************************************
 * The Lander thrusts to the right with this function,
 * and decreases the fuel each time.
 **********************************************************/
void Lander::applyThrustRight()
{
    if (canThrust())
    {
        velocity.setDx(velocity.getDx()-0.1);
        fuel--;
    }
}

/***********************************************************
 * This funtion applys the thrusters from the bottom so that
 * the lander can advance.
 ***********************************************************/
void Lander::applyThrustBottom()
{
    if (canThrust())
    {
        velocity.setDy(velocity.getDy()+.3);
        fuel--;
    }
}

/***********************************************************
 * This function allows the lander to move up and down and
 * to the side.
 ***********************************************************/
void Lander::advance()
{
    point.setX(point.getX()+velocity.getDx());
    point.setY(point.getY()+velocity.getDy());
}

/**********************************************************
 * This simply draws the lander to the screen. It calls
 * on the other functions to do the actual drawing.
 **********************************************************/
void Lander::draw() const
{
    drawLander(point);
}

