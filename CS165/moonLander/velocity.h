//
//  velocity.h
//  moonLander
//
//  Created by Jon Michael Ossola on 2/16/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#ifndef velocity_h
#define velocity_h

class Velocity
{
private:
    float Dx;
    float Dy;
    
public:
    Velocity();
    Velocity(float Dx, float Dy);
    float getDx() const { return Dx; }
    float getDy() const { return Dy; }
    void setDx(float Dx) { this->Dx = Dx; }
    void setDy(float Dy) { this->Dy = Dy; }
};

#endif /* velocity_h */
