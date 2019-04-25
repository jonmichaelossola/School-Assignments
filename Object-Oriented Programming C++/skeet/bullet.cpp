//
//  bullet.cpp
//  Skeet
//
//  Created by Jon Michael Ossola on 3/2/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include "bullet.h"
#include "uiDraw.h"

#define BULLET_SPEED 15.0

/******************************************************************************
 * This is the default constructor for the bullet. it just sets bullet at a
 * random angle.
 *****************************************************************************/
Bullet :: Bullet()
{
    velocity.setDy(10);
    velocity.setDx(10);
}

/****************************************************************************
 * The bullet has hit the target, we now need to kill the bullet, or delete
 * it from the screen. We just set alive to false.
 ****************************************************************************/
void Bullet::kill()
{
    alive = false;
}

/***************************************************************************
 * The bullet needs to know where to go once it is formed, at what angle,
 * and also needs to know where it is going to be formed.
 ***************************************************************************/
void Bullet::fire(Point point, float angle)
{
    float dx = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
    float dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));

    setPoint(point);
    velocity.setDx(dx);
    velocity.setDy(dy);
}

/*******************************************************************
 * Draw the bullet on the screen. This function is as simple as
 * that.
 *******************************************************************/
void Bullet::draw()
{
    drawDot(point);
}

