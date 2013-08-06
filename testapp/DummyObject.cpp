//
//  DummyObject.cpp
//  testapp
//
//  Created by Prasan Samtani on 8/5/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "DummyObject.h"

const float REPULSION_MAGNITUDE = 30.0f;
const float EPSILON = 0.01f;
const float MULTIPLIER = 0.1F;
const float FRICTION = 0.2f;

DummyObject::DummyObject(bool connected): 
    force(0.0f), isConnected(connected) 
{
    SlapOnFeld();
    INFORM("Location=" + ToStr(this->Loc()));
    INFORM("Norm=" + ToStr(this->Norm()));
    INFORM("Over=" + ToStr(this->Over()));
    
}

void DummyObject::PointingMove (PointingEvent *e)
{ 
    if (isConnected) {
        Vect nextLoc = e->PhysOrigin();
        nextLoc.z = this->PhysLoc().z;
        SetTranslation(nextLoc);
    } else {
        Vect diff = this->PhysLoc() - e->PhysOrigin();
        diff.z = 0.0f;
        if (diff.Mag() < REPULSION_MAGNITUDE) {
            if (force <= EPSILON) {
                INFORM("Diff mag = " + ToStr(diff.Mag()));
                force = diff.Mag() * MULTIPLIER;
                direction = diff.Norm();
            }
        }
    }
}

void DummyObject::Travail() {
    if (force >= EPSILON) {
        IncTranslation(direction * force);
        force-=FRICTION;
    }
}

void DummyObject::DrawSelf() {
    SetGLColor(Color(1, 0, 0));
    DrawQuad(Vect(-5, -5, 0), Vect (10, 0, 0), Vect (0, 10, 0), false);  
}