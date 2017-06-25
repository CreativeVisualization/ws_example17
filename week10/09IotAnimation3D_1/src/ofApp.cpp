#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(64);
    
    //Load CSV data
    if(csv.load("sensor1.csv")) {
        cout << "data loaded" << endl;
    } else {
        cout << "load error!" << endl;
    }
    
    //Put data into vector
    for (int i = 0; i < csv.size(); i++) {
        ofxCsvRow row = csv[i];
        timeStamp.push_back(row.getString(0));
        temperature.push_back(row.getFloat(1));
        humidityAir.push_back(row.getFloat(2));
        pressure.push_back(row.getFloat(3));
        illuminance.push_back(row.getFloat(4));
        humiditySoil.push_back(row.getFloat(5));
    }
    //Set color palette
    color[0] = ofColor(141,211,199);
    color[1] = ofColor(255,255,179);
    color[2] = ofColor(190,186,218);
    color[3] = ofColor(251,128,114);
    color[4] = ofColor(128,177,211);
}

void ofApp::update(){
    
}

void ofApp::draw(){
    float max, min;
    float height;
    int currentData = ofGetFrameNum() % temperature.size();
    
    max = *max_element(temperature.begin(), temperature.end());
    min = *min_element(temperature.begin(), temperature.end());
    float radius = ofMap(temperature[currentData], min, max, 0, 400);
    
    max = *max_element(humidityAir.begin(), humidityAir.end());
    min = *min_element(humidityAir.begin(), humidityAir.end());
    float x = ofMap(humidityAir[currentData], min, max, -ofGetWidth()/2, ofGetWidth()/2);
    
    max = *max_element(pressure.begin(), pressure.end());
    min = *min_element(pressure.begin(), pressure.end());
    float y = ofMap(pressure[currentData], min, max, -ofGetHeight()/2, ofGetHeight()/2);
    
    max = *max_element(illuminance.begin(), illuminance.end());
    min = *min_element(illuminance.begin(), illuminance.end());
    float z = ofMap(illuminance[currentData], min, max, -ofGetHeight(), 0);
    
    light.enable();
    ofEnableDepthTest();
    cam.begin();
    ofSetColor(color[0]);
    ofTranslate(x, y, z);
    ofDrawSphere(0, 0, 0, radius);
    cam.end();
    ofDisableDepthTest();
    light.disable();
    
    ofSetColor(255);
    ofDrawBitmapStringHighlight(timeStamp[currentData], 40, 40);
}
