#pragma once
#include "ofMain.h"

class Ring {
public:
    Ring(ofPoint pos);
    void update();
    void draw();
    
    ofPoint pos;
    float radius;
    float radiusSpeed;
    bool dead;
};
