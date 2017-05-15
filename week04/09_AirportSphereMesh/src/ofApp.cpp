#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //ログの表示レベル
    ofSetLogLevel("ofxCsv", OF_LOG_VERBOSE);
    
    //メッシュの頂点を点で表示
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    //距離に応じて点の大きさを変える
    static GLfloat distance[] = { 0.0, 0.0, 1.0 };
    glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
    glPointSize(1500);
    
    //円の解像度
    ofSetCircleResolution(3);
    
    //CSVファイル読み込み
    if(csv.load("airports-extended.dat")) {
        //全てのデータをログに出力
        for(int i = 0; i < csv.getNumRows(); i++) {
            for(int j = 0; j < csv.getNumCols(i); j++) {
                cout << csv[i][j] << ", ";
            }
            cout << endl;
        }
    }
    
    mesh.clear();
    
    for(int i = 0; i < csv.getNumRows(); i++) {
        //1行ぶんのデータをとりだしてofxCsvRowに格納
        ofxCsvRow row = csv[i];
        //種類によって色分け
        string type = row.getString(12);
        ofFloatColor color;
        if(type == "airport"){
            color = ofFloatColor(0.2, 0.5, 1.0);
        } else if(type == "station"){
            color = ofFloatColor(1.0, 0.5, 0.2);
        }else if(type == "port"){
            color = ofFloatColor(0.5, 1.0, 0.2);
        } else {
            color = ofFloatColor(0.8);
        }
        //経度と緯度から球面上の位置を取得
        ofQuaternion latRot, longRot, spinQuat;
        latRot.makeRotate(row.getFloat(6), 1, 0, 0);
        longRot.makeRotate(row.getFloat(7), 0, 1, 0);
        spinQuat.makeRotate(ofGetFrameNum(), 0, 1, 0);
        
        ofVec3f center = ofVec3f(0,0,300);
        ofVec3f worldPoint = latRot * longRot * spinQuat * center;
        
        mesh.addVertex(worldPoint);
        mesh.addColor(color);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //空港の位置格納するベクトル
    ofVec2f airportLoc;

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateY(ofGetFrameNum());
    mesh.draw();
    ofPopMatrix();
    
    ofSetColor(255);
    ofDrawBitmapStringHighlight("fps = " + ofToString(ofGetFrameRate()), 20, 20);
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
