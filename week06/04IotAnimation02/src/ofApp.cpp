#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(64);
    
    //CSVファイル読み込み
    if(csv.load("sensor1.csv")) {
        cout << "data loaded" << endl;
    } else {
        cout << "load error!" << endl;
    }
    
    //データ配列に読み込み
    for (int i = 0; i < csv.size(); i++) {
        ofxCsvRow row = csv[i];
        timeStamp.push_back(row.getString(0));
        temperature.push_back(row.getFloat(1));
        humidityAir.push_back(row.getFloat(2));
        pressure.push_back(row.getFloat(3));
        illuminance.push_back(row.getFloat(4));
        humiditySoil.push_back(row.getFloat(5));
    }
    //色を初期化
    color[0] = ofColor(141,211,199);
    color[1] = ofColor(255,255,179);
    color[2] = ofColor(190,186,218);
    color[3] = ofColor(251,128,114);
    color[4] = ofColor(128,177,211);
}

void ofApp::update(){
    
}

void ofApp::draw(){
    //最大値、最小値
    float max, min;
    //グラフ高さ
    float height;
    //ピックアップするデータ(列)
    int currentData = ofGetFrameNum() % temperature.size();
    
    //照度を背景色に
    max = *max_element(illuminance.begin(), illuminance.end());
    min = *min_element(illuminance.begin(), illuminance.end());
    float bgcolor = ofMap(illuminance[currentData], min, max, 255, 0);
    ofBackground(bgcolor);
    
    //気温を半径に
    max = *max_element(temperature.begin(), temperature.end());
    min = *min_element(temperature.begin(), temperature.end());
    float radius = ofMap(temperature[currentData], min, max, 0, 400);
    
    //大気湿度をX座標に
    max = *max_element(humidityAir.begin(), humidityAir.end());
    min = *min_element(humidityAir.begin(), humidityAir.end());
    float x = ofMap(humidityAir[currentData], min, max, 100, ofGetWidth()-100);
    
    //気圧をY座標に
    max = *max_element(pressure.begin(), pressure.end());
    min = *min_element(pressure.begin(), pressure.end());
    float y = ofMap(pressure[currentData], min, max, ofGetHeight()-100, 100);
    
    //円を描画
    ofSetColor(color[0]);
    ofDrawCircle(x, y, radius);
        
    //日付表示
    ofSetColor(255);
    ofDrawBitmapStringHighlight(timeStamp[currentData], 40, 40);
}
