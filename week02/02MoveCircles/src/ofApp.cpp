#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(0); //背景色を黒に
    
    //位置と速度を初期化
    location1 = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    velocity1 = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10));
    location2 = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    velocity2 = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10));
}

//--------------------------------------------------------------
void ofApp::update(){
    location1 += velocity1;
    location2 += velocity2;
}

//--------------------------------------------------------------
void ofApp::draw(){
    //計算した位置に円を描画
    ofSetColor(31, 12, 255); //円の色
    ofDrawCircle(location1, 40); //半径40の円を描画
    ofDrawCircle(location2, 40); //半径40の円を描画
    
    //画面の端でバウンドするように
    if (location1.x < 0 || location1.x > ofGetWidth()) { //画面の左右ではみ出したら
        velocity1.x *= -1; //横向きの速度を反転(バウンド)
    }
    if (location1.y < 0 || location1.y > ofGetHeight()) { //画面の左右ではみ出したら
        velocity1.y *= -1; //横向きの速度を反転(バウンド)
    }

    if (location2.x < 0 || location2.x > ofGetWidth()) { //画面の左右ではみ出したら
        velocity2.x *= -1; //横向きの速度を反転(バウンド)
    }
    if (location2.y < 0 || location2.y > ofGetHeight()) { //画面の左右ではみ出したら
        velocity2.y *= -1; //横向きの速度を反転(バウンド)
    }
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
