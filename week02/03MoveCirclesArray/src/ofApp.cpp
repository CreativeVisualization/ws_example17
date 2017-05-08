#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(0); //背景色を黒に
    
    //NUM回くりかえし
    for (int i = 0; i < NUM; i++) {
        //位置と速度を初期化
        location[i] = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
        velocity[i] = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //NUM回くりかえし
    for (int i = 0; i < NUM; i++) {
        location[i] += velocity[i];
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //NUM回くりかえし
    for (int i = 0; i < NUM; i++) {
        //計算した位置に円を描画
        ofSetColor(31, 12, 255); //円の色
        ofDrawCircle(location[i], 20); //半径40の円を描画
        ofDrawCircle(location[i], 20); //半径40の円を描画
        
        //画面の端でバウンドするように
        if (location[i].x < 0 || location[i].x > ofGetWidth()) { //画面の左右ではみ出したら
            velocity[i].x *= -1; //横向きの速度を反転(バウンド)
        }
        if (location[i].y < 0 || location[i].y > ofGetHeight()) { //画面の左右ではみ出したら
            velocity[i].y *= -1; //横向きの速度を反転(バウンド)
        }
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
