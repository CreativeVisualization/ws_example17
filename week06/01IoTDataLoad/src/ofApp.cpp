#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    
    //CSVファイル読み込み
    if(csv.load("sensor1.csv")) {
        //全てのデータをログに出力
        for(int i = 0; i < csv.getNumRows(); i++) {
            for(int j = 0; j < csv.getNumCols(i); j++) {
                cout << csv[i][j] << ", ";
            }
            cout << endl;
        }
    }
}

void ofApp::update(){
}

void ofApp::draw(){
}
