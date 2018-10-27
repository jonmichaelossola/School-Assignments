#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include "uiDraw.h"
#include "velocity.h"
#include <vector>
#include <iostream>
using namespace std;

// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock
class Rock : public FlyingObject
{
protected:
    int radius;
public:
    Rock();
    virtual void draw() = 0;
    virtual vector<Rock*> hit(Rock & rock) = 0;
    int getRadius() const { return radius; }
    void setRadius(const int radius) { this->radius = radius; }
};

class BigRock : public Rock
{
public:
    BigRock();
    void draw();
    vector<Rock*> hit(Rock &rock);
};

class MediumRock : public Rock
{
public:
    MediumRock(const float &newDx, const float &newDy, const Point &point);
    MediumRock();
    void draw();
    vector<Rock*> hit(Rock &rock);
};

class SmallRock : public Rock
{
public:
    SmallRock(const float &newDx, const float &newDy, const Point &newPoint);
    SmallRock();
    void draw();
    vector<Rock*> hit(Rock &rock);
};

#endif /* rocks_h */
