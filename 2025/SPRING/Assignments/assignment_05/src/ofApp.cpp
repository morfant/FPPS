#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(10);
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(32);
    ofBackground(255);

    width = ofGetWidth();
    height = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    if (ofGetMousePressed())
    {
        ofBackground(255);
    }
    
    int cx = ofRandom(width);
    int cy = ofRandom(height);
    
    float radius = ofRandom(20, 50);
    
    // ofNoFill();
    ofSetColor(0, 40);

    int step = 2;
    int numOfCircles = radius / step;

    for (int i = 0; i < numOfCircles; i++)
    {
        ofDrawCircle(cx, cy, (i + 1) * step);
    }


}

//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
