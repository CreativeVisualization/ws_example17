#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "127.0.0.1" //Receiver's IP address
#define PORT 8000 //Receiver's Port Number

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mouseMoved(int x, int y );
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    //OSC message sender
    ofxOscSender sender;
};

