#pragma once
#include "ofMain.h"
#include "ofxJSON.h"

class QuickDraw {
public:
    QuickDraw(ofxJSONElement jsonElement);
    void draw();
    
    //JSON Element
    ofxJSONElement jsonElement;
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
    //移動速度
    ofVec2f velocity;
    //重力
    ofVec2f gravity;
};
