//
//  flyingObject.h
//  Skeet
//
//  Created by Jon Michael Ossola on 3/5/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"

class FlyingObject
{
protected:
    Point point;
    Velocity velocity;
    bool alive;
public:
  FlyingObject();
    Point getPoint() const { return point; }
    Velocity getVelocity() const { return velocity; }
  bool isAlive() const { return alive; }
  void setPoint(Point &point) { this->point = point; }
  void setVelocity(Velocity &velocity) { this->velocity = velocity; }
  void advance();
};


#endif /* flyingObject_h */
