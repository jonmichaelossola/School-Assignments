//
//  toughBird.h
//  Skeet
//
//  Created by Jon Michael Ossola on 3/5/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#ifndef toughBird_h
#define toughBird_h

#include "bird.h"

class ToughBird : public Bird
{
public:
    ToughBird();
    void draw() const;
    int hit() ;
};

#endif /* toughBird_h */
