//
//  enemyShip.hpp
//  asteroids
//
//  Created by Jon Michael Ossola on 4/10/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#ifndef enemyShip_hpp
#define enemyShip_hpp

#include <stdio.h>
#include "flyingObject.h"

class EnemyShip : public FlyingObject
{
private:
    float thrust;
    int radius;
public:
    EnemyShip();
    void advance();
    int getRadius() const { return radius; }
    bool canThrust() const;
    void applyThrust(const float &x);
    void drawEnemyShip() const;
};

#endif /* enemyShip_hpp */
