//
//  lander.h
//  moonLander
//
//  Created by Jon Michael Ossola on 2/16/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#ifndef lander_h
#define lander_h
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class Lander
{
private:
    Point point;
    Velocity velocity;
    bool alive;
    bool landed;
    int fuel;
    
public:
    Lander();
    Point getPoint() const { return point; }
    Velocity getVelocity() const { return velocity; }
    int getFuel() const { return fuel; }
    bool isAlive() const { return alive; }
    bool isLanded() const { return landed; }
    void setLanded(const bool landed) { this->landed = landed; }
    void setAlive(const bool alive) { this->alive = alive; }
    void setFuel(const int fuel) { this->fuel = fuel; }
    bool canThrust() const;
    void applyGravity(float gravity);
    void applyThrustLeft();
    void applyThrustRight();
    void applyThrustBottom();
    void advance();
    void draw() const;
};

#endif /* lander_h */
