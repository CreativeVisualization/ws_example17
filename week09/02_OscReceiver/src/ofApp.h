#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

// set OSC port number as 8000
#define PORT 8000

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void dumpOSC(ofxOscMessage m);
    
    //OSC receiver instance
    ofxOscReceiver receiver;
    //Mouse position
    ofPoint remoteMouse;
    //Mouse button state
    string mouseButtonState;
};
