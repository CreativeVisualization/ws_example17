#include "ofApp.h"

void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
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
    //タイムスタンプを表示
    string timestamp = drawDataJson[objectNum]["timestamp"].asString();
    ofDrawBitmapString(timestamp, 20, 10 * objectNum);
    objectNum++;
}
