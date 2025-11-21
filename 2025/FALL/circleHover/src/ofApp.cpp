#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


    ofSetCircleResolution(32);

    width = ofGetWidth();
    height = ofGetHeight();
    radius = 100;
    isMouseOver = false;

    circleX = 100;
    circleY = 100;
    speedX = 5;
    speedY = 5;


    ofSetFrameRate(20);


}

//--------------------------------------------------------------
void ofApp::update(){

    float diffX = ofGetMouseX() - (width * 0.5);
    float diffY = ofGetMouseY() - (height * 0.5);

    float dist = sqrt( (diffX * diffX) + (diffY * diffY));

    if (dist > radius) {
        isMouseOver = false;
    } else {
        isMouseOver = true;
    }


    circleX = circleX + speedX;
    circleY = circleY + speedY;

    if (circleX + radius > width || circleX - radius < 0)
    {
        speedX = speedX * -1;
    }


    if (circleY + radius > height || circleY - radius < 0)
    {
        speedY = speedY * -1;
    }



}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    // if (isMouseOver) {
    //     ofSetColor(0, 100, 200);
    // } else {
    //     ofSetColor(255);
    // }
    // ofDrawCircle(width * 0.5, height * 0.5, radius);

    for (int i = 0; i < 800; i++)
    {
        ofSetColor(ofRandom(10, 110), (circleX/width)*255, (circleY/height)*255);
        ofDrawCircle(
            ofRandom(-200, width + 200),
            ofRandom(-200, height + 200),
            ofRandom(10, 80)
        );
    }

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
