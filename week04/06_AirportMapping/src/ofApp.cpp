#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    //ログの表示レベル
    ofSetLogLevel("ofxCsv", OF_LOG_VERBOSE);

    //円の解像度
    ofSetCircleResolution(4);
    
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
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //空港の位置格納するベクトル
    ofVec2f airportLoc;
    
    //行の数だけくりかえし
    for(int i = 0; i < csv.getNumRows(); i++) {
        //1行ぶんのデータをとりだしてofxCsvRowに格納
        ofxCsvRow row = csv[i];
        //経度と緯度を抽出して画面のサイズにリサイズ
        airportLoc.x = ofMap(row.getFloat(7), -180, 180, 0, ofGetWidth());
        airportLoc.y = ofMap(row.getFloat(6), 90, -90, 0, ofGetHeight());
        //取得した位置に円を描画
        ofDrawCircle(airportLoc, 1.5);
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
