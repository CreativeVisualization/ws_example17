#include "ofApp.h"

void ofApp::setup(){
    ofBackground(255);
    ofSetColor(0);
    objectNum = 0;
    
    //ファイルを指定
    string inputFile = "face.ndjson";
    ifstream input(ofToDataPath(inputFile), ifstream::in);
    
    //JSONファイルを1行ずつ読み込む
    ofxJSONElement jsonElement;
    Json::Reader reader;
    string currentLine;
    //最終行に行くまで1行読み込み
    while(getline(input, currentLine)) {
        //JSONElement形式にパース
        reader.parse(currentLine, jsonElement);
        //読み込んだJSONデータを配列に追加
        drawDataJson.push_back(jsonElement);
    }
    //ログ表示
    cout << "Done : read " << drawDataJson.size() << " drawings!"<< endl;
}

void ofApp::update(){

}

void ofApp::draw(){
    //フレーム番号から表示するオブジェクトを決定
    objectNum = ofGetFrameNum()/6;
    //描画設定
    ofNoFill();
    ofSetLineWidth(2.0);
    ofPushMatrix();
    //位置を中心に
    ofTranslate(ofGetWidth()/2 - 128, ofGetHeight()/2 - 128);
    //JSONの配列からイラストを再現
    for (int j = 0; j < drawDataJson[objectNum]["drawing"].size(); j++) {
        ofBeginShape();
        for (int k = 0; k < drawDataJson[objectNum]["drawing"][j][0].size(); k++) {
            int x = drawDataJson[objectNum]["drawing"][j][0][k].asInt();
            int y = drawDataJson[objectNum]["drawing"][j][1][k].asInt();
            ofVertex(x, y);
        }
        ofEndShape();
    }
    ofPopMatrix();
}
