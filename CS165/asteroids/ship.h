#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "uiInteract.h"
#include "flyingObject.h"

// Put your Ship class here
class Ship : public FlyingObject
{
private:
    float thrust;
    Interface ui;
    int radius;
public:
    Ship();
    int getRadius() const { return radius; }
    float getThrust() const { return thrust; }
    void setThrust(const float &thrust) { this->thrust = thrust; }
    void drawSpaceShip() const;
    bool canThrust() const;
    void applyThrust();
    float getAngle() const { return angle; }
};

#endif /* ship_h */
