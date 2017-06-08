#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    
    //ログの表示レベル
    ofSetLogLevel("ofxCsv", OF_LOG_VERBOSE);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //メッシュの頂点を点で表示
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    //距離に応じて点の大きさを変える
    static GLfloat distance[] = { 0.0, 0.0, 1.0 };
    glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
    glPointSize(1500);
    
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
        latRot.makeRotate(row.getFloat(6), -1, 0, 0);
        longRot.makeRotate(row.getFloat(7), 0, 1, 0);
        
        ofVec3f radius = ofVec3f(0,0,300);
        ofVec3f worldPoint = latRot * longRot * radius;
        
        mesh.addVertex(worldPoint);
        mesh.addColor(color);
    }
    
    //フォント読み込み
    font.loadFont("Times.ttc", 24, true, true);
}

void ofApp::update(){
    
}

void ofApp::draw(){
    cam.begin();

    //点を描画
    mesh.draw();

    //マウスを操作していない時だけ文字を描画
    ofSetColor(255, 96);
    if (!ofGetMousePressed()) {
        for(int i = 0; i < csv.getNumRows(); i++) {
            ofPushMatrix();
            ofTranslate(mesh.getVertex(i));
            //ビルボード開始
            billboardBegin();
            //上下反転して縮小
            ofScale(0.15, -0.15);
            //パスでフォントを描画
            font.drawStringAsShapes(csv[i].getString(1), 0, 0);
            //ビルボード終了
            billboardEnd();
            ofPopMatrix();
        }
    }
    
    cam.end();

    //ofSetColor(255);
    //ofDrawBitmapStringHighlight("fps = " + ofToString(ofGetFrameRate()), 20, 20);
}

//ビルボート表示(常に正面に物体の面を向ける)
void ofApp::billboardBegin() {
    float modelview[16];
    int i,j;
    glPushMatrix();
    glGetFloatv(GL_MODELVIEW_MATRIX , modelview);
    for( i=0; i<3; i++ ) {
        for( j=0; j<3; j++ ) {
            if ( i==j ) {
                modelview[i*4+j] = 1.0;
            } else {
                modelview[i*4+j] = 0.0;
            }
        }
    }
    glLoadMatrixf(modelview);
}

void ofApp::billboardEnd() {
    glPopMatrix();
}
