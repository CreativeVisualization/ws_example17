#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetBackgroundColor(0); //背景色を黒に
}

//--------------------------------------------------------------
void ofApp::update(){
    //NUM回くりかえし
    for (int i = 0; i < location.size(); i++) {
        location[i] += velocity[i];
    }
    
    //新規に位置ベクトルと速度ベクトルを生成し、配列に追加
    location.push_back(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
    velocity.push_back(ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)));
    
    //もし上限値を超えたら、先頭の要素を削除する
    if(location.size() > max_num){
        location.erase(location.begin());
        velocity.erase(velocity.begin());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //NUM回くりかえし
    for (int i = 0; i < location.size(); i++) {
        //計算した位置に円を描画
        ofSetColor(15, 127, 255); //円の色
        ofDrawCircle(location[i], 5); //半径5の円を描画
        ofDrawCircle(location[i], 5); //半径5の円を描画
        
        //画面の端でバウンドするように
        if (location[i].x < 0 || location[i].x > ofGetWidth()) {
            velocity[i].x *= -1; //横向きの速度を反転(バウンド)
        }
        if (location[i].y < 0 || location[i].y > ofGetHeight()) {
            velocity[i].y *= -1; //横向きの速度を反転(バウンド)
        }
    }
    
    //現在の物体の数を表示
    ofSetColor(255);
    ofDrawBitmapString("num = " + ofToString(location.size()), 20, 20);
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
