#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    width = ofGetWidth();
    height = ofGetHeight();

    ofSetCircleResolution(32);

    ofBackground(255);

    mx = -1;
    my = -1;

}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetMousePressed())
    {
        mx = ofGetMouseX();
        my = ofGetMouseY();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255, 0, 0);
    ofNoFill();
    ofDrawCircle(100, 100, 100);

    ofFill();
    ofSetColor(0, 0, 255);
    ofDrawRectangle(300, 300, 100, 100);

    ofSetColor(0, 200, 100);
    ofDrawLine(0, 0, width, height);

    ofSetColor(0, 100, 200);
    ofDrawLine(0, height, width, 0);

    ofDrawBitmapStringHighlight("FPS: " + ofToString(ofGetFrameRate(), 2), 10, 20);

    if (mx != -1 && my != -1)
    {
        ofSetColor(255, 100, 100);
        ofDrawCircle(mx, my, 10);
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
