#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    sender.setup( HOST, PORT );
}

void ofApp::update(){
    for (int i = 0 ; i < rings.size(); i++) {
        rings[i]->update();
        if (rings[i]->dead) {
            rings.erase(rings.begin()+i);
        }
    }
}

void ofApp::draw(){
    for (int i = 0 ; i < rings.size(); i++) {
        rings[i]->draw();
    }
}

void ofApp::mouseMoved(int x, int y ){
    ofxOscMessage m;
    m.setAddress( "/mouse/position" );
    m.addIntArg( x );
    m.addIntArg( y );
    sender.sendMessage( m );
}

void ofApp::mouseDragged(int x, int y, int button){
}

void ofApp::mousePressed(int x, int y, int button){
    ofxOscMessage m;
    m.setAddress( "/mouse/button" );
    m.addStringArg( "down" );
    m.addIntArg( x );
    m.addIntArg( y );
    sender.sendMessage( m );
}

void ofApp::mouseReleased(int x, int y, int button){
    ofxOscMessage m;
    m.setAddress( "/mouse/button" );
    m.addStringArg( "up" );
    m.addIntArg( x );
    m.addIntArg( y );
    sender.sendMessage( m );
    rings.push_back(new Ring(ofPoint(x, y)));
}
