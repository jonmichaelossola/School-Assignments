#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40


#include "flyingObject.h"
// Put your Bullet class here

class Bullet : public FlyingObject
{
private:
    float angle;
    int life;
public:
    Bullet();
    void draw();
    void fire(const Point &point, const float angle, const Velocity &velocity);
    void fireEnemyBullet(const Point &point);
};


#endif /* bullet_h */
