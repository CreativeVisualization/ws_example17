#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
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
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //set image num
    int currentImage = ofGetFrameNum() % total;
    //setup image location
    ofVec2f imageLoc;
    imageLoc.x = ofGetWidth()/2 - images[currentImage].getWidth()/2;
    imageLoc.y = ofGetHeight()/2 - images[currentImage].getHeight()/2;
    //draw image
    images[currentImage].draw(imageLoc);
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
