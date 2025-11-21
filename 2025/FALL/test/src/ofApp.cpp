#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    width = ofGetWidth();
    height = ofGetHeight();

    ofSetCircleResolution(32);

    // ofSetLineWidth(10);


}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);

    ofSetColor(0, 0, 255);
    ofFill();
    ofDrawRectangle(300, 300, 100, 100);

    ofSetColor(0, 200, 100);
    ofDrawLine(0, 0, width, height);

    ofSetColor(0, 200, 100);
    ofDrawLine(0, height, width, 0);

    if (ofGetMousePressed())
    {
        ofSetColor(255, 0, 0);
        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 10);
    }



    string fps = ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapStringHighlight("FPS: " + fps, 10, 20);

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
