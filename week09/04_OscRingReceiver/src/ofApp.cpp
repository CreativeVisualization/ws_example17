#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    receiver.setup( PORT );
    mouseX = 0;
    mouseY = 0;
    mouseButtonState = "";
}

void ofApp::update(){
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        oscString = m.getAddress();
        receiver.getNextMessage(m);
        if(m.getAddress() == "/mouse/position"){
            remoteMouse.x = m.getArgAsInt32(0);
            remoteMouse.y = m.getArgAsInt32(1);
        } else if (m.getAddress() == "/mouse/button") {
            mouseButtonState = m.getArgAsString(0) ;
        }
        dumpOSC(m);
    }
    if(mouseButtonState == "up"){
        rings.push_back(new Ring(ofPoint(remoteMouse.x, remoteMouse.y)));
        mouseButtonState = "";
    }
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

void ofApp::dumpOSC(ofxOscMessage m) {
    string msg_string;
    msg_string = m.getAddress();
    for (int i=0; i<m.getNumArgs(); i++ ) {
        msg_string += " ";
        if(m.getArgType(i) == OFXOSC_TYPE_INT32)
            msg_string += ofToString( m.getArgAsInt32(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT)
            msg_string += ofToString( m.getArgAsFloat(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_STRING)
            msg_string += m.getArgAsString(i);
    }
    cout << msg_string << endl;
}
