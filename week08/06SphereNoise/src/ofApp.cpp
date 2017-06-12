#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //画面基本設定
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableDepthTest();
    //ライトを配置
    light.enable();
    light.setPosition(-100, 100, 500);
    //球からメッシュを生成
    myMesh = ofSpherePrimitive(200, 72).getMesh();
    //メッシュの色を設定
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        myMesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //頂点の数だけ繰り返し
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        //頂点の位置を取得
        ofVec3f loc = myMesh.getVertices()[i] / 300.0;
        //perlinノイズを生成
        float noise = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, 80, 240);
        //ノイズの値で頂点位置を変更
        ofVec3f newLoc = loc.normalize()* noise;
        myMesh.setVertex(i, newLoc);
        //頂点の色を設定
        float c = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()),0, 1, 0.5, 1.0);
        myMesh.setColor(i, ofFloatColor(c, c, c, 1.0));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //メッシュを描画
    cam.begin();
    ofPushMatrix();
    ofRotateY(ofGetElapsedTimef()*10.0);
    myMesh.draw();
    ofPopMatrix();
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
