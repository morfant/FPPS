#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(30); // FPS(frame per second) 30

    width = ofGetWidth();
    height = ofGetHeight();

    circleX = width * 0.5; // center of x-axis
    circleY = height * 0.5;
    speedX = 5;
    speedY = 5;
    radius = 100;

}

//--------------------------------------------------------------
void ofApp::update(){

    circleX = circleX + speedX;
    circleY = circleY + speedY;

    if (circleX + radius >= width) // check right edge
    {
        speedX *= -1;
    }
    else if (circleX - radius <= 0) // check left edge
    {
        speedX *= -1;
    }

    if (circleY + radius >= height) // check bottom edge
    {
        speedY *= -1;
    }
    else if (circleY - radius <= 0) // check top edge
    {
        speedY *= -1;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

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
