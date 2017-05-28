#include "ofApp.h"

void ofApp::setup(){
    ofBackground(255);
    ofSetColor(0);
    ofSetLineWidth(1.5);
    ofNoFill();

    //ファイルを指定
    string inputFile = "ant.ndjson";
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
    //カーソル隠す
    ofHideCursor();
}

void ofApp::update(){
    for (int i = 0; i < 5; i++) {
        //QuickDrawオブジェクトを追加
        QuickDraw *q = new QuickDraw(drawDataJson[ofRandom(drawDataJson.size())]);
        q->location.y = 0;
        //q->velocity.y = ofRandom(1);
        quickDraw.push_back(q);
        //一定以上の数になったら先頭削除
        if (quickDraw.size() > 500) {
            delete quickDraw[0];
            quickDraw.erase(quickDraw.begin());
        }
    }
}

void ofApp::draw(){
    //全てのQuickDrawオブジェクトを描画
    for (int i = 0; i < quickDraw.size(); i++) {
        quickDraw[i]->draw();
    }
}
