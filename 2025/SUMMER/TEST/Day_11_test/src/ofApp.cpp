#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(42);
    ofSetFrameRate(30);

    width = ofGetWidth();
    height = ofGetHeight();

    for (int i = 0; i < 50; i++)
    {
        circles[i] = Circle(width * 0.5, height * 0.5, ofRandom(50, 100));
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 50; i++)
    {
        circles[i].move();

        // if (ofGetMousePressed())
        // {
        //     circles[i].setRadius(ofRandom(10, width * 0.5));
        // }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    for (int i = 0; i < 50; i++)
    {
        circles[i].show();

    }
    // c1.hello(); // call hello() from the outside
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
