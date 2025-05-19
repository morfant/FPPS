#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(30);
    ofSetCircleResolution(32);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    radius = 50;
    
    circleX = width * 0.5;
    circleY = height * 0.5;
    
    speedX = ofRandom(-10, 10);
    speedY = ofRandom(-10, 10);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    circleX += speedX;
    circleY += speedY;
    
    if (circleX >= width - radius || circleX <= 0 + radius)
    {
        speedX *= -1;
    }
    
    if (circleY >= height - radius || circleY <= 0 + radius)
    {
        speedY *= -1;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSetColor(0, 100, 100);
    ofDrawCircle(circleX, circleY, radius);
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
