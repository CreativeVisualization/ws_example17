#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0, 0, 0);
    //Connect reseicer with setuped IP and Port
    sender.setup(HOST, PORT);
}

void ofApp::update(){
}

void ofApp::draw(){
    //draw circle at mouse point
    ofSetColor(255, 255, 255);
    ofDrawCircle(mouseX, mouseY, 10);
}

void ofApp::mouseMoved(int x, int y){
    //osc message instance
    ofxOscMessage m;
    //set osc address
    m.setAddress("/mouse/position");
    //set current mouse position as OSC arguments
    m.addIntArg(x);
    m.addIntArg(y);
    //send message
    sender.sendMessage(m);
}

void ofApp::mousePressed(int x, int y, int button){
    //osc message instance
    ofxOscMessage m;
    //set osc address
    m.setAddress("/mouse/button");
    //set "down" as a osc argument
    m.addStringArg("down");
    //send message
    sender.sendMessage(m);
}

void ofApp::mouseReleased(int x, int y, int button){
    //osc message instance
    ofxOscMessage m;
    //set osc address
    m.setAddress("/mouse/button");
    //set "up" as a osc argument
    m.addStringArg("up");
    //send message
    sender.sendMessage( m );
}
