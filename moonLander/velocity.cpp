//
//  velocity.cpp
//  moonLander
//
//  Created by Jon Michael Ossola on 2/16/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <stdio.h>
#include "velocity.h"

/***************************************************************
 * This is a default constructor for the Velocity class.
 * it sets the variables below to zero.
 **************************************************************/
Velocity::Velocity()
{
    setDx(0);
    setDy(0);
}

/**************************************************************
 * Below is the non default constructor for the Velocity class.
 * it sets the users input to the variables below.
 *************************************************************/
Velocity::Velocity(float Dx, float Dy)
{
    this->Dx = Dx;
    this->Dy = Dy;
}
