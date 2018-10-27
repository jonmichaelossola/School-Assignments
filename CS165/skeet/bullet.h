//
//  bullet.h
//  Skeet
//
//  Created by Jon Michael Ossola on 3/2/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#ifndef bullet_h
#define bullet_h

#include "flyingObject.h"

class Bullet : public FlyingObject
{
public:
    Bullet();
    void kill();
    void draw();
    void fire(const Point point, const float angle);
};


#endif /* bullet_h */
