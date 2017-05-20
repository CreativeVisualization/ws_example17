#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    //JSON Elementの可変長配列
    vector<ofxJSONElement> drawDataJson;
    //オブジェクト番号(行数)
    int objectNum;
    //ストローク番号
    int strokeNum;
    //頂点番号
    int vertexNum;
    //スケール
    float scale;
    //描画位置
    ofVec2f location;

};
