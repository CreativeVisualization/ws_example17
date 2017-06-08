#include "ofApp.h"

void ofApp::setup(){
    //load xml file
    if( XML.loadFile("sample.xml") ){
        cout << "sample.xml loaded!" << endl;
    }else{
        cout << "load error!" << endl;
    }
}

void ofApp::update(){

}

void ofApp::draw(){
    ofSetColor(0);
    
    //get float value
    float floatData = XML.getValue("data:floatdata", 0.0);
    //get value from attribute value
    float nameValue = XML.getAttribute("data:hoo", "namesample", 0.0);
    vector<float> times;
    for (int i = 0; i < XML.getNumTags("data:record"); i++) {
        cout << "time " << i << " : " << endl;
        times.push_back(XML.getValue("time", 0.0));
    }
    
    //draw value strings
    ofDrawBitmapString("data > floatdata : " + ofToString(floatData), 20, 20);
    ofDrawBitmapString("data > nameValue : " + ofToString(nameValue), 20, 40);
    
    //draw time values
    for (int i = 0; i < times.size(); i++) {
        ofDrawBitmapString("data > nameValue : " + ofToString(i) + ofToString(times[i]), 20, 60 + 20 * i);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
