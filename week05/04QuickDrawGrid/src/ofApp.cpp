#include "ofApp.h"

void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(1.0);
    
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
    //表示スケール
    float scale = 0.075;
    //イラストのサイズ(幅・高さ)
    float size = 256 * scale;
    //列の数
    int col = ofGetWidth() / size + 1;
    //行の数
    int row = ofGetHeight() / size + 1;
    //グリッド状にイラストを配置
    for (int i = 0; i < col * row; i++) {
        //表示位置
        ofVec2f location;
        location.x = i % col * size;
        location.y = i / col * size;
        //描画設定
        ofPushMatrix();
        //位置を中心に
        ofTranslate(location.x, location.y);
        //JSONの配列からイラストを再現
        for (int j = 0; j < drawDataJson[i]["drawing"].size(); j++) {
            ofBeginShape();
            for (int k = 0; k < drawDataJson[i]["drawing"][j][0].size(); k++) {
                int x = drawDataJson[i]["drawing"][j][0][k].asInt();
                int y = drawDataJson[i]["drawing"][j][1][k].asInt();
                ofVertex(x * scale, y * scale);
            }
            ofEndShape();
        }
        ofPopMatrix();
    }
}
