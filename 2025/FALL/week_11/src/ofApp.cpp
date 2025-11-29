#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetCircleResolution(32);
    ofSetFrameRate(30);

    width = ofGetWidth();
    height = ofGetHeight();

    cir1 = Circle(width * 0.5, height * 0.5, 100);

}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetMousePressed() == true)
    {
        cir1.setRadius(ofRandom(10, 200));
    }

    cir1.move();

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255, 255, 255);

    cir1.show();

    ofDrawBitmapStringHighlight(
        "FPS: " + ofToString(ofGetFrameRate(), 2), 10, 20);

}

