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
    
    //get Value from XML as strings
    string noteTo = XML.getValue("note:to", "void");
    string noteFrom = XML.getValue("note:frmo", "void");
    string noteHeading = XML.getValue("note:heading", "void");
    string noteBody = XML.getValue("note:body", "void");
    
    //draw value strings
    ofDrawBitmapString("note > to : " + noteTo, 20, 20);
    ofDrawBitmapString("note > from : " + noteFrom, 20, 40);
    ofDrawBitmapString("note > heading : " + noteHeading, 20, 60);
    ofDrawBitmapString("note > body : " + noteBody, 20, 80);
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
