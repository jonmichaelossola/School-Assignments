//
//  bird.h
//  Skeet
//
//  Created by Jon Michael Ossola on 3/2/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#ifndef bird_h
#define bird_h

#include <iostream>
using namespace std;

#include "velocity.h"
#include "point.h"
#include "flyingObject.h"

class Bird : public FlyingObject
{
protected:
    int numHits;
    int radius;
public:
    Bird();
    Bird(Point &point);
    virtual int hit() = 0;
    virtual void draw() const = 0;
    void kill();
};

#endif /* bird_h */
