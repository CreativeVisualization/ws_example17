#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    ofSetSphereResolution(32);

    //Number of sphere
    drawLength = 400;
    
    //set camera distance
    cam.setDistance(800);
    
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
    float rad = ofMap(temperature[currentData], min, max, 10, 500);
    
    max = *max_element(humidityAir.begin(), humidityAir.end());
    min = *min_element(humidityAir.begin(), humidityAir.end());
    float x = ofMap(humidityAir[currentData], min, max, -ofGetWidth()/2, ofGetWidth()/2);
    
    max = *max_element(pressure.begin(), pressure.end());
    min = *min_element(pressure.begin(), pressure.end());
    float y = ofMap(pressure[currentData], min, max, -ofGetHeight()/2, ofGetHeight()/2);
    
    max = *max_element(illuminance.begin(), illuminance.end());
    min = *min_element(illuminance.begin(), illuminance.end());
    float z = ofMap(illuminance[currentData], min, max, -ofGetWidth(), -200);
    
    location.push_back(ofVec3f(x, y, z));
    radius.push_back(rad);
    if (location.size() > drawLength) {
        location.erase(location.begin());
        radius.erase(radius.begin());
    }
    
    //Draw 3D shapes
    ofEnableDepthTest();
    cam.begin();
    light.enable();
    ofSetColor(color[0]);
    for (int i = 0; i < location.size(); i++) {
        ofPushMatrix();
        ofTranslate(location[i]);
        ofDrawSphere(0, 0, 0, radius[i]);
        ofPopMatrix();
    }
    light.disable();
    cam.end();
    ofDisableDepthTest();

    
    ofSetColor(255);
    ofDrawBitmapStringHighlight(timeStamp[currentData], 40, 40);
}
