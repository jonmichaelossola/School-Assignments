/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5
#define CLOSE_ENOUGH 15

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
    dMax = max(dMax, abs(obj2.getVelocity().getDx()));
    dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}

/********************************************************************
 * Non default constructor for the game class. Start the game by
 * creating a bunch of big asteroids.
 *********************************************************************/
Game::Game(Point topLeft, Point bottomRight)
{
    createAsteroid();
}

/********************************************************************
 * Destructor for the game.
 *
 *********************************************************************/
Game :: ~Game()
{
    vector<Rock*>:: iterator rockIt = rocks.begin();
    
    while (rockIt != rocks.end())
    {
        if (*rockIt != NULL)
        {
            delete *rockIt;
            rockIt = rocks.erase(rockIt);
        }
        else
        {
            rockIt++;
        }
    }
}

/*********************************************************************
 * handle the input from the user and use the input to advance the ship
 * and to fire bullets.
 *********************************************************************/
void Game::handleInput(const Interface &ui)
{
    if (ui.isSpace())
    {
        if (ship.isAlive())
        {
            Bullet newBullet;
            newBullet.fire(ship.getPoint(), ship.getAngle(), ship.getVelocity());
            
            bullets.push_back(newBullet);
        }
    }
    if (ui.isUp())
    {
        ship.applyThrust();
    }
    if (ui.isRight())
    {
        ship.rotateRight();
    }
    if (ui.isLeft())
    {
        ship.rotateLeft();
    }
    
    // did you die? Go ahead and respawn yourself
    if (ui.isR())
    {
        ship.setAlive();
    }
    
    // want some fun? Press the h key. It creates 5 more asteroids and an enemy ship.
    if (ui.isH())
    {
        enemyShip.setAlive();
        createAsteroid();
    }
}

/************************************************************************
 * Draw everything to the screen, including the rocks, the space ship,
 * and the bullets.
 ***********************************************************************/
void Game::draw(const Interface &ui)
{
    for (int i = 0; i < rocks.size(); i++)
    {
        if (rocks[i]->isAlive())
        {
            rocks[i]->draw();
        }
    }
    
    // draw the ship, and the enemy ship if they are alive
    if (ship.isAlive())
    {
        ship.drawSpaceShip();
    }
    if (enemyShip.isAlive())
    {
        enemyShip.drawEnemyShip();
    }
    
    // draw the bullets, if they are alive
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            bullets[i].draw();
        }
    }
    for (int i = 0; i < enemyBullets.size(); i++)
    {
        if (enemyBullets[i].isAlive())
        {
            enemyBullets[i].draw();
        }
    }
    
}

/**************************************************************************
 * This function simply checks to make sure that a certain point
 * is on the screen.
 *************************************************************************/
bool Game::isOnScreen(Point)
{
    return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
            && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
            && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
            && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * After the objects have been killed, free up the memory by deleting the
 * objects and then setting the pointers to NULL.
 **************************************************************************/
void Game::cleanUp()
{
    vector<Rock*>:: iterator rockIt = rocks.begin();
    while(rockIt != rocks.end())
    {
        Rock* pRock = *rockIt;
        
        if (!pRock->isAlive())
        {
            rockIt = rocks.erase(rockIt);
        }
        else
        {
            rockIt++;
        }
    }
    
    // Look for dead bullets
    vector<Bullet>::iterator bulletIt = bullets.begin();
    while (bulletIt != bullets.end())
    {
        Bullet bullet = *bulletIt;
        
        if (!bullet.isAlive())
        {
            // If we had a list of pointers, we would need to delete the memory here...
            
            
            // remove from list and advance
            bulletIt = bullets.erase(bulletIt);
        }
        else
        {
            bulletIt++; // advance
        }
    }
    
    vector<Bullet>::iterator bullIt = enemyBullets.begin();
    while (bulletIt != enemyBullets.end())
    {
        Bullet bullet = *bullIt;
        // Asteroids Hint:
        // If we had a list of pointers, we would need this line instead:
        //Bullet* pBullet = *bulletIt;
        
        if (!bullet.isAlive())
        {
            // If we had a list of pointers, we would need to delete the memory here...
            
            
            // remove from list and advance
            bullIt = enemyBullets.erase(bullIt);
        }
        else
        {
            bullIt++; // advance
        }
    }
}

/***************************************************************************
 * Handle collisions. Recognize when bullets hit asteroids, when the enemy
 * ship hits the ship, and when ships run into asteroids.
 **************************************************************************/
void Game::handleCollisions()
{
    // check to see if bullets are hitting the rocks
    for (int i = 0; i < bullets.size(); i++)
    {
        // check to see if the bullets are alive
        if (bullets[i].isAlive())
        {
            for (int x = 0; x < rocks.size(); x++)
            {
                // loop through each of the rocks and check to make sure it
                // isn't close to the bullet
                if (rocks[x] != NULL && rocks[x]->isAlive())
                {
                    if (getClosestDistance(bullets[i], *rocks[x]) <= rocks[x]->getRadius())
                    {
                        
                        // kill rock while inserting the new rocks into the vector
                        // using the built in insert function
                        vector<Rock*> newRocks = rocks[x]->hit(*rocks[x]);
                        rocks.insert( rocks.end(), newRocks.begin(), newRocks.end() );
                        
                        // kill the bullet 
                        bullets[i].kill();
                    }
                }
            }
            // allow the ship to kill the enemy ship.
            if (enemyShip.isAlive() && getClosestDistance(bullets[i], enemyShip) <= enemyShip.getRadius())
            {
                enemyShip.kill();
            }
        }
    }
    
    // make it so that the asteroids can kill the ship.
    for (int i = 0; i < rocks.size(); i++)
    {
        // make sure that the rock is alive
        if (rocks[i]->isAlive())
        {
            // check if the asteroids are close to the ship
            if (getClosestDistance(*rocks[i], ship) <= rocks[i]->getRadius())
            {
                ship.kill();
            }
        }
    }
    
    // make it so that enemy bullets can kill the ship or asteroids
    for (int x = 0; x < enemyBullets.size(); x++)
    {
        // make sure that the bullet is alive
        if (enemyBullets[x].isAlive() && ship.isAlive())
        {
            // if the enemy bullets are within the ships radius, kill the ship
            if (getClosestDistance(enemyBullets[x], ship) <= ship.getRadius())
            {
                ship.kill();
            }
        }
        if (enemyBullets[x].isAlive())
        {
            for (int i = 0; i < rocks.size(); i++)
            {
                if (rocks[i] != NULL && rocks[i]->isAlive())
                {
                    // thankfully, the enemy ship can also kill the asteroids
                    if (getClosestDistance(enemyBullets[x], *rocks[i]) <= rocks[i]->getRadius())
                    {
                        // kill rock while inserting the new rocks into the vector
                        // using the built in insert function
                        vector<Rock*> newRocks = rocks[i]->hit(*rocks[i]);
                        rocks.insert( rocks.end(), newRocks.begin(), newRocks.end() );
                        
                        // kill the bullet
                        enemyBullets[i].kill();
                    }
                }
            }
        }
    }
}

/**************************************************************
 * Create an asteroid that can be drawn to the screen. It
 * will store the new asteroids in the rock vector.
 **************************************************************/
void Game::createAsteroid()
{
    // create five asteroids
    for (int i = 0; i < 5; i++)
    {
        rocks.push_back(new BigRock());
    }
}

/*********************************************************************
 * Use the rock's advance method to advance one of the asteroids in
 * the vector of asteroids.
 **********************************************************************/
void Game::advanceAsteroid()
{
    for (int i = 0; i < rocks.size(); i++)
    {
        if (rocks[i]->isAlive())
        {
            rocks[i]->advance();
        }
    }
}

/*********************************************************************
 * Advance the bullets by checking if the bullets are alive, then use
 * the bullets class advance method, and if the bullets are off the
 * screen, kill the bullet.
 ********************************************************************/
void Game::advanceBullets()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            // this bullet is alive, so tell it to move forward
            bullets[i].advance();
        }
    }
    
    for (int i = 0; i < enemyBullets.size(); i++)
    {
        if (enemyBullets[i].isAlive())
        {
            enemyBullets[i].advance();
        }
    }
}

/******************************************************************
 * If the ship is alive, call on the advance function from its
 * mother class, the flying object class.
 ******************************************************************/
void Game::advanceShip()
{
    if (ship.isAlive())
    {
        ship.advance();
    }
    if (enemyShip.isAlive())
    {
        // if the ship is alive, have it chase the main ship and advance it
        enemyShip.applyThrust(ship.getPoint().getX());
        enemyShip.advance();
        
        // check to make sure the x coordinates are within 40 of each other before firing
        // a bullet.
        if (enemyShip.getPoint().getX() - ship.getPoint().getX() <= 20
            && enemyShip.getPoint().getX() - ship.getPoint().getX() >= -20)
        {
            Bullet newBullet;
            newBullet.fireEnemyBullet(enemyShip.getPoint());
            
            enemyBullets.push_back(newBullet);
        }
    }
}

/***********************************************************************
 * Advance the game. This is the first thing main calls on to advance
 * the game.
 ***********************************************************************/
void Game :: advance()
{
    advanceShip();
    advanceBullets();
    advanceAsteroid();
    
    handleCollisions();
    cleanUp();
}

