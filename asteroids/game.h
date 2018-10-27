/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;

#include <vector>
#include "point.h"
#include "bullet.h"
#include "rocks.h"
#include "uiInteract.h"
#include "flyingObject.h"
#include "ship.h"
#include "enemyShip.h"

class Game
{
private:
    Ship ship;
    EnemyShip enemyShip;
    Point point;
    Point topLeft;
    Point bottomRight;
    vector<Bullet> bullets;
    vector<Bullet> enemyBullets;
    vector<Rock*> rocks;
    bool isOnScreen(Point);
    void cleanUp();
    void handleCollisions();
    void createAsteroid();
    void advanceAsteroid();
    void advanceBullets();
    void advanceShip();
    float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
public:
    Game(Point topLeft, Point bottomRight);
    ~Game();
    void handleInput(const Interface &ui);
    void draw(const Interface &ui);
    void advance();
};


#endif /* GAME_H */
