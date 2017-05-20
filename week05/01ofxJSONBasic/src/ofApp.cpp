#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);

    string file = "example.json";
    bool success = json.open(file);

    if (success) {
        cout << json.getRawString() << endl;
    } else {
        cout << "Failed to parse JSON" << endl;
    }
}

void ofApp::update(){ }

void ofApp::draw(){
    string conpanyName = json["companyName"].asString();
    ofDrawBitmapString(conpanyName, 20, 20);
    
    string country = json["country"].asString();
    ofDrawBitmapString(country, 20, 40);
    
    int numEmployees = json["numEmployees"].asInt();
    ofDrawBitmapString(ofToString(numEmployees,0), 20, 60);
    
    for (int i = 0; i < json["employees"].size(); i++) {
        string firstName = json["employees"][i]["firstName"].asString();
        string lastName = json["employees"][i]["lastName"].asString();
        ofDrawBitmapString(firstName + " " + lastName, 20, 80 + 20 * i);
    }
}
