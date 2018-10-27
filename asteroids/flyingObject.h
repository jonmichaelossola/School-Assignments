#ifndef flyingObject_h
#define flyingObject_h


#include "point.h"
#include "velocity.h"
#include "uiInteract.h"

// Put your FlyingObject class here
class FlyingObject
{
protected:
    Interface ui;
    bool alive;
    Point point;
    Velocity velocity;
    int rotation;
    int angle;
public:
    Point getPoint() const { return point; }
    int getAngle() const { return angle; }
    Velocity getVelocity() const { return velocity; }
    void setPoint(const Point &point) { this->point = point; }
    void setVelocity(const Velocity &velocity) { this->velocity = velocity; }
    bool isAlive() const { return alive; }
    void setAlive() { alive = true; }
    virtual void advance();
    void rotateRight();
    void rotateLeft();
    void kill() { alive = false; }
};



#endif /* flyingObject_h */
