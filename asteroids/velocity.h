#ifndef VELOCITY_H
#define VELOCITY_H


// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project
class Velocity
{
private:
    float x;
    float y;
public:
    void setDx(const float x) { this->x = x; }
    void setDy(const float y) { this->y = y; }
    float getDx() const { return x; }
    float getDy() const { return y; }
};

#endif /* velocity_h */
