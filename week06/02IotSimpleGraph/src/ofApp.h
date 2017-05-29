#pragma once

#include "ofMain.h"
#include "ofxCsv.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    ofxCsv csv; //CSVデータ
    vector<string> timeStamp; //タイムスタンプ
    vector<float> temperature; //気温
    vector<float> humidityAir; //大気湿度
    vector<float> pressure; //気圧
    vector<float> illuminance; //照度
    vector<float> humiditySoil; //土壌湿度
    ofColor color[5]; //表示する色
};
