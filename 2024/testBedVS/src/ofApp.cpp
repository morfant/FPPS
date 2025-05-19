#include "ofApp.h"

int step;
int numX, numY;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(42);
    //ofSetBackgroundAuto(false);
    ofBackground(255);

    width = ofGetWidth();
    height = ofGetHeight();

    numX = 20;
    numY = 20;
    step = width / numX;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    int mx = ofGetMouseX();
    ofNoFill();
    for (int i = 0; i < numY; i++) {
        for (int j = 0; j < numX; j++) {
            ofSetColor(0);
            ofDrawCircle(i * step + step * 0.5, j * step + step * 0.5, mx);
        }
    }


}

void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
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
