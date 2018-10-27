//
//  standardBird.h
//  Skeet
//
//  Created by Jon Michael Ossola on 3/5/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#ifndef standardBird_h
#define standardBird_h

#include <iostream>
using namespace std;

#include "bird.h"
#include "point.h"

class StandardBird : public Bird
{
public:
    StandardBird();
    void draw() const;
    int hit() ;
};

#endif /* standardBird_h */
