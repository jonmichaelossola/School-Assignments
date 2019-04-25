//
//  enemyShip.cpp
//  asteroids
//
//  Created by Jon Michael Ossola on 4/10/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include "enemyShip.h"
#include "uiDraw.h"

/**************************************************************
 * Default constructor of the enemy ship. set alive to false
 * to start, set rotation to 0, and radius to 12.
 **************************************************************/
EnemyShip::EnemyShip()
{
    //angle = 90;
    alive = false;
    point = Point(100, -190);
    //thrust = 0.02;
    rotation = 0;
    radius = 12;
}

/*************************************************************
 * Let's make sure first, that the ship can thrust, by checking
 * if the ship is alive or not.
 *************************************************************/
bool EnemyShip::canThrust() const
{
    if (alive == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*************************************************************
 * Because this ship works differently, let's make a different
 * way to make it thrust.
 *************************************************************/
void EnemyShip::applyThrust(const float &x)
{
    if (canThrust())
    {
        // change the velocity so that it chases the main ship. Pass in the Ships Points for x and y.
        if (getPoint().getX() > x)
        {
            Velocity v;
            v.setDx(getVelocity().getDx() - .2);
            v.setDy(0);
            setVelocity(v);
        }
        else if (getPoint().getX() < x)
        {
            Velocity v;
            v.setDx(getVelocity().getDx() + .2);
            v.setDy(0);
            setVelocity(v);
        }
    }
}

/***************************************************************
 * Simple enough, use the draw ship method from the user interact
 * class. If alive is true.
 ***************************************************************/
void EnemyShip::drawEnemyShip() const
{
    if (alive == true)
    {
        drawShip(point, rotation);
    }
}

/***************************************************************
 * We don't want to wrap the enemy ship around the screen, it
 * makes things too complicated. So lets change the advance method.
 ****************************************************************/
void EnemyShip::advance()
{
    point.setX(point.getX()+velocity.getDx());
    point.setY(point.getY()+velocity.getDy());
    
    if (point.getX() < -200)
    {
        velocity.setDx(0);
        point.setX(-200);
    }
    if (point.getX() > 200)
    {
        velocity.setDx(0);
        point.setX(200);
    }
}
