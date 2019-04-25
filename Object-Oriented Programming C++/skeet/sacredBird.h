//
//  sacredBird.h
//  Skeet
//
//  Created by Jon Michael Ossola on 3/5/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#ifndef sacredBird_h
#define sacredBird_h

#include "bird.h"

class SacredBird : public Bird
{
public:
    SacredBird();
    void draw() const;
    int hit();
};

#endif /* sacredBird_h */
