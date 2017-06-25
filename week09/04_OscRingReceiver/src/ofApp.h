#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Ring.h"

#define PORT 8000

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void dumpOSC(ofxOscMessage m);
    
    ofxOscReceiver	receiver;
    ofPoint remoteMouse;
    string mouseButtonState;
    string oscString;
    vector <Ring *> rings;
};
