#include "QuickDraw.hpp"

QuickDraw::QuickDraw(ofxJSONElement _jsonElement){
    //オブジェクト、ストローク、頂点の数、スケール、位置、速度、重力を初期化
    jsonElement = _jsonElement;
    strokeNum = 0;
    vertexNum = 0;
    scale = 0.15;
    location = ofVec2f(ofRandom(ofGetWidth()) - 128 * scale,
                       ofRandom(ofGetHeight() - 128 * scale));
    velocity = ofVec2f(0, 0);
    gravity = ofVec2f(0, 0.15);
}


void QuickDraw::draw(){
    //位置を更新
    velocity += gravity;
    location += velocity;
    
    ofPushMatrix();
    //位置を中心に
    ofTranslate(location);
    
    //今まで描いたパスを描画
    for (int j = 0; j < strokeNum; j++) {
        ofBeginShape();
        for (int i = 0; i < jsonElement["drawing"][j][0].size(); i++) {
            int x = jsonElement["drawing"][j][0][i].asInt();
            int y = jsonElement["drawing"][j][1][i].asInt();
            ofVertex(x * scale, y * scale);
        }
        ofEndShape();
    }
    if (strokeNum < jsonElement["drawing"].size()) {
        //最新のパスを描画
        ofBeginShape();
        for (int i = 0; i < vertexNum; i++) {
            int x = jsonElement["drawing"][strokeNum][0][i].asInt();
            int y = jsonElement["drawing"][strokeNum][1][i].asInt();
            ofVertex(x * scale, y * scale);
        }
        ofEndShape();
        //頂点の数を1つ追加
        vertexNum++;
        //もし頂点の数が上限に達したら次のパスへ
        if (vertexNum > jsonElement["drawing"][strokeNum][0].size()) {
            vertexNum = 0;
            strokeNum++;
        }
    }
    ofPopMatrix();
}
