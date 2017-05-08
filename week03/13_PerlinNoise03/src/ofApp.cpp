#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofBackground(0);
    noiseScale = ofRandom(0.01);
    particleNum = 10000;
    particles = new Particles(particleNum);
    particles->friction = 0.01;

    for (int i = 0; i < particleNum; i++) {
        ofVec3f position = ofVec3f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        particles->addParticle(position);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    float speed = 0.02;
    particles->resetForce();
    for (int i = 0; i < particleNum; i++) {
        float val = ofNoise(particles->positions[i].x * noiseScale, particles->positions[i].y * noiseScale);
        int angle = ofMap(val, 0, 1, 0, TWO_PI);
        ofVec3f force;
        force.x = cos(angle) * speed;
        force.y = sin(angle) * speed;
        particles->addForce(i, force);
    }
    particles->addDampingForce();
    particles->updatePos();
    particles->resetOffWalls();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 15);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255);
    particles->draw();
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
    noiseScale = ofRandom(0.01);
    for (int i = 0; i < particleNum; i++) {
        particles->positions[i] = ofVec3f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
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
