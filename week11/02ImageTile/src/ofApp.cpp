#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    
    //set the directory contain images
    ofDirectory dir(ofToDataPath("./"));
    //get the number of images
    total = dir.listDir();
    //arrocate memories
    images.resize(total);
    //load images into vector
    for(int i = 0; i < total; i++) {
        loader.loadFromDisk(images[i], dir.getName(i));
        images[i].resize(60, 40);
    }
    cout << total << " images loaded" << endl;
    
    current = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //tiling images
    current = ofGetFrameNum() % total;
    float div = 40.0;
    float imageWidth = ofGetWidth() / div;
    float imageHeight = ofGetHeight() / div;
    float x = imageWidth * (current % int(div));
    float y = imageHeight * (current / int(div));
    while(y >= ofGetHeight()){
        y -= ofGetHeight();
    }
    images[current].draw(x, y, imageWidth, imageHeight);
    current++;
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
