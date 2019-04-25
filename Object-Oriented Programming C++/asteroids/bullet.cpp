#include "bullet.h"


// Put your bullet methods here
#include <cmath> // used for sin, cos, and M_PI
#include "uiDraw.h"

/***************************************************************
 * Use the method found in the Interact class to draw a bullet
 * to the screen.
 **************************************************************/
void Bullet :: draw() 
{
    drawDot(point);
    life--;
    if (life == 0)
    {
        alive = false;
    }
}

/***************************************************************
 * Use some cosine and sine, also using the ship's speed and
 * the angle to determine the direction the bullets travel.
 ***************************************************************/
void Bullet::fire(const Point &point, const float angle, const Velocity &velocity2)
{
    // Set the bullet speed to the angle provided online.
    float dx = velocity2.getDx() + 5 * (-cos(M_PI / 180.0 * angle));
    float dy = velocity2.getDy() + 5 * (sin(M_PI / 180.0 * angle));
    
    setPoint(point);
    velocity.setDx(dx);
    velocity.setDy(dy);
}

/**************************************************************
 * Because we don't really want the same fire function for
 * the enemy ship, lets make a different one, that makes the
 * bullets of the enemy ship fly straight.
 **************************************************************/
void Bullet::fireEnemyBullet(const Point &point)
{
    setPoint(point);
    velocity.setDx(0);
    velocity.setDy(6);
}

/***************************************************************
 * In the default constructor of bullet, set alive to true. And
 * that's it!
 ***************************************************************/
Bullet :: Bullet()
{
    alive = true;
    life = BULLET_LIFE;
}

