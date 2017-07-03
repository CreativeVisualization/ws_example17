#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //3D draw settings
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableNormalizedTexCoords();
    ofEnableDepthTest();

    //light
    light.enable();
    light.setPosition(300, 300, 500);
    
    //load texture image
    image.load("20170419_172943.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofSetColor(255);
    ofRotateX(ofGetElapsedTimef()*60);
    ofRotateY(ofGetElapsedTimef()*70);
    box.set(200);
    image.bind();
    box.draw();
    image.unbind();
    cam.end();
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
