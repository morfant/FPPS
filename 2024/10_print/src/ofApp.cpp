#include "ofApp.h"

bool coins[20][20];
int width, height;
int numX, numY;
float step = 0;


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255, 255, 255);
    ofSetFrameRate(20);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    numX = 20;
    numY = 20;
    step = width / numX;
    
    for (int y = 0; y < numX; y++)
    {
        for (int x = 0; x < numY; x++)
        {
            bool r = rand() % 2;
            coins[y][x] = r;
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255);
    
    ofSetColor(0, 0, 0);
    ofSetLineWidth(5);
    
    for (int y = 0; y < numX; y++)
    {
        for (int x = 0; x < numY; x++)
        {
            if (coins[y][x])
            {
                ofDrawLine(x * step, y * step, (x + 1) * step, (y + 1) * step);
            }
            else
            {
                ofDrawLine(x * step, (y + 1) * step, (x + 1) * step, y * step);
            }

        }
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
