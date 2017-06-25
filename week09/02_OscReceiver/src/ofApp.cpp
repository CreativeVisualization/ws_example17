#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0, 0, 0);
    //connect with port num
    receiver.setup(PORT);
    //init veriables
    mouseButtonState = "";
}

void ofApp::update(){
    while(receiver.hasWaitingMessages()){
        //get next osc message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        //if the osc address is /mouse/position
        if (m.getAddress() == "/mouse/position"){
            //set the mouse position
            remoteMouse.x = m.getArgAsInt32(0);
            remoteMouse.y = m.getArgAsInt32(1);
        }
        //if the osc address is /mouse/botton
        else if (m.getAddress() == "/mouse/button"){
            //change button state
            mouseButtonState = m.getArgAsString(0) ;
        }
        //dump osc messages
        dumpOSC(m);
    }
}

void ofApp::draw(){
    int radius;
    //if mouse pressed, draw red circle
    if (mouseButtonState == "down") {
        radius = 20;
        ofSetColor(255, 127, 0);
    } else {
        //else, draw blue circle
        radius = 10;
        ofSetColor(0, 127, 255);
    }
    ofDrawCircle(remoteMouse.x, remoteMouse.y, radius);
}

//dump osc message into console
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

