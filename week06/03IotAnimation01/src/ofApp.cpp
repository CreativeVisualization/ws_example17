#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    
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
    //グラフの領域指定
    ofRectangle graphRect = ofRectangle(20, 100, ofGetWidth()-40, ofGetHeight()-200);
    //最大値、最小値
    float max, min;
    //グラフ高さ
    float height;
    //ピックアップするデータ(列)
    int currentData = ofGetFrameNum() % temperature.size();
    
    ofPushMatrix();
    
    //気温
    max = *max_element(temperature.begin(), temperature.end());
    min = *min_element(temperature.begin(), temperature.end());
    ofSetColor(color[0]);
    height = ofMap(temperature[currentData], min, max, 0, graphRect.height);
    ofDrawRectangle(graphRect.x, graphRect.y + graphRect.height, graphRect.width / 5, -height);
    ofSetColor(255);
    ofDrawBitmapString("Temperture : " + ofToString(temperature[currentData]),
                       graphRect.x, graphRect.y + graphRect.height + 20);
    
    //大気湿度
    ofTranslate(graphRect.width / 5, 0);
    max = *max_element(humidityAir.begin(), humidityAir.end());
    min = *min_element(humidityAir.begin(), humidityAir.end());
    ofSetColor(color[1]);
    height = ofMap(humidityAir[currentData], min, max, 0, graphRect.height);
    ofDrawRectangle(graphRect.x, graphRect.y + graphRect.height, graphRect.width / 5, -height);
    ofSetColor(255);
    ofDrawBitmapString("Humidity Air : " + ofToString(humidityAir[currentData]),
                       graphRect.x, graphRect.y + graphRect.height + 20);
    
    //気圧
    ofTranslate(graphRect.width / 5, 0);
    max = *max_element(pressure.begin(), pressure.end());
    min = *min_element(pressure.begin(), pressure.end());
    ofSetColor(color[2]);
    height = ofMap(pressure[currentData], min, max, 0, graphRect.height);
    ofDrawRectangle(graphRect.x, graphRect.y + graphRect.height, graphRect.width / 5, -height);
    ofSetColor(255);
    ofDrawBitmapString("Pressure : " + ofToString(pressure[currentData]),
                       graphRect.x, graphRect.y + graphRect.height + 20);
    
    //照度
    ofTranslate(graphRect.width / 5, 0);
    max = *max_element(illuminance.begin(), illuminance.end());
    min = *min_element(illuminance.begin(), illuminance.end());
    ofSetColor(color[3]);
    height = ofMap(illuminance[currentData], min, max, graphRect.height, 0);
    ofDrawRectangle(graphRect.x, graphRect.y + graphRect.height, graphRect.width / 5, -height);
    ofSetColor(255);
    ofDrawBitmapString("Illuminance : " + ofToString(illuminance[currentData]),
                       graphRect.x, graphRect.y + graphRect.height + 20);

    //土壌湿度
    ofTranslate(graphRect.width / 5, 0);
    max = *max_element(humiditySoil.begin(), humiditySoil.end());
    min = *min_element(humiditySoil.begin(), humiditySoil.end());
    ofSetColor(color[4]);
    height = ofMap(humiditySoil[currentData], min, max, 0, graphRect.height);
    ofDrawRectangle(graphRect.x, graphRect.y + graphRect.height, graphRect.width / 5, -height);
    ofSetColor(255);
    ofDrawBitmapString("Humidity Soil : " + ofToString(humiditySoil[currentData]),
                       graphRect.x, graphRect.y + graphRect.height + 20);
    
    ofPopMatrix();
    
    //日付表示
    ofDrawBitmapStringHighlight(timeStamp[currentData], 40, 40);
}
