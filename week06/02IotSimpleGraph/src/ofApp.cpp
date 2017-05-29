#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    
    //色を初期化
    color[0] = ofColor(141,211,199);
    color[1] = ofColor(255,255,179);
    color[2] = ofColor(190,186,218);
    color[3] = ofColor(251,128,114);
    color[4] = ofColor(128,177,211);
    
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
}

void ofApp::update(){
    
}

void ofApp::draw(){
    //グラフの領域指定
    ofRectangle graphRect = ofRectangle(20, 100, ofGetWidth()-40, ofGetHeight()-200);
    //最大値、最小値
    float max, min;

    ofNoFill();
    ofSetLineWidth(1.5);
    
    //気温
    max = *max_element(temperature.begin(), temperature.end());
    min = *min_element(temperature.begin(), temperature.end());
    ofSetColor(color[0]);
    ofBeginShape();
    for (int i = 0; i < temperature.size(); i++) {
        float x = ofMap(i, 0, temperature.size(), graphRect.x, graphRect.x + graphRect.width);
        float y = ofMap(temperature[i], min, max, graphRect.y + graphRect.height, graphRect.y);
        ofVertex(x, y);
    }
    ofEndShape();
    
    //空気湿度
    max = *max_element(humidityAir.begin(), humidityAir.end());
    min = *min_element(humidityAir.begin(), humidityAir.end());
    ofSetColor(color[1]);
    ofBeginShape();
    for (int i = 0; i < humidityAir.size(); i++) {
        float x = ofMap(i, 0, humidityAir.size(), graphRect.x, graphRect.x + graphRect.width);
        float y = ofMap(humidityAir[i], min, max, graphRect.y + graphRect.height, graphRect.y);
        ofVertex(x, y);
    }
    ofEndShape();
    
    //気圧
    max = *max_element(pressure.begin(), pressure.end());
    min = *min_element(pressure.begin(), pressure.end());
    ofSetColor(color[2]);
    ofBeginShape();
    for (int i = 0; i < pressure.size(); i++) {
        float x = ofMap(i, 0, pressure.size(), graphRect.x, graphRect.x + graphRect.width);
        float y = ofMap(pressure[i], min, max, graphRect.y + graphRect.height, graphRect.y);
        ofVertex(x, y);
    }
    ofEndShape();
    
    //照度
    max = *max_element(illuminance.begin(), illuminance.end());
    min = *min_element(illuminance.begin(), illuminance.end());
    ofSetColor(color[3]);
    ofBeginShape();
    for (int i = 0; i < illuminance.size(); i++) {
        float x = ofMap(i, 0, illuminance.size(), graphRect.x, graphRect.x + graphRect.width);
        float y = ofMap(illuminance[i], min, max, graphRect.y, graphRect.y + graphRect.height);
        ofVertex(x, y);
    }
    ofEndShape();
    
    //土壌湿度
    max = *max_element(humiditySoil.begin(), humiditySoil.end());
    min = *min_element(humiditySoil.begin(), humiditySoil.end());
    ofSetColor(color[4]);
    ofBeginShape();
    for (int i = 0; i < humiditySoil.size(); i++) {
        float x = ofMap(i, 0, humiditySoil.size(), graphRect.x, graphRect.x + graphRect.width);
        float y = ofMap(humiditySoil[i], min, max, graphRect.y + graphRect.height, graphRect.y);
        ofVertex(x, y);
    }
    ofEndShape();
}
