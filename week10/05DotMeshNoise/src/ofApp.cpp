#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //画面の設定
    ofBackground(0);
    ofEnableDepthTest();
    cam.setDistance(500);
    
    //面(ofPlanePrimitive)からメッシュを生成
    w = 100;
    h = 100;
    mesh = ofPlanePrimitive(1000, 1000, w, h).getMesh();
    
    //メッシュを点で描画
    glPointSize(3.0);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    //頂点の色を初期化
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        mesh.addColor(ofFloatColor(0.0, 1.0, 1.0, 1.0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //まず全ての頂点情報を削除
    //mesh.clearVertices();
    
    //全ての頂点の位置を更新して頂点情報として追加
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        ofVec3f loc = mesh.getVertices()[i] / 400.0;
        float z = ofNoise(loc.x, loc.y, ofGetElapsedTimef()) * 200.0;
        mesh.setVertex(i, ofVec3f(mesh.getVertices()[i].x, mesh.getVertices()[i].y, z));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //メッシュの描画
    cam.begin(); //カメラ開始
    //ワイヤーフレームで描画
    mesh.drawWireframe();
    cam.end(); //カメラ終了
    
    //ログの表示
    string info;
    info = "Vertex num = " + ofToString(w * h, 0) + "\n";
    info += "FPS = " + ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(info, 30, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //fキーでフルスクリーン表示
    if (key == 'f') {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}