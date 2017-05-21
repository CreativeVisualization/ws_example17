#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "QuickDraw.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    //JSON Elementの可変長配列
    vector<ofxJSONElement> drawDataJson;
    //QuickDrawオブジェクトの配列
    vector<QuickDraw *> quickDraw;
};
