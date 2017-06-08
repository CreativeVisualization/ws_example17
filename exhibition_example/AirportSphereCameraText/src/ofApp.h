#pragma once

#include "ofMain.h"
#include "ofxCsv.h"
#include "ofxTrueTypeFontUC.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void billboardBegin();
    void billboardEnd();
    
    ofxCsv csv;
    ofVboMesh mesh;
    ofEasyCam cam;
    ofxTrueTypeFontUC font;
    vector<ofVec3f> worldPoint;
    vector<string> airportName;
};
