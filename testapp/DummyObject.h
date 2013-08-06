//
//  DummyObject.h
//  testapp
//
//  Created by Prasan Samtani on 8/5/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef testapp_DummyObject_h
#define testapp_DummyObject_h

#include "GreenhouseHeaders.h"

using namespace oblong::greenhouse;

class DummyObject : public Thing {
public:
    DummyObject(bool connected);
    void DrawSelf();
    void PointingMove (PointingEvent *e);
    void Travail();
private:
    bool isConnected;
    float force;
    Vect direction;
};


#endif
