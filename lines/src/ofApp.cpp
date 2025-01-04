#include "ofApp.h"

int width, height;
int posX, posY;
int velX, velY;
int radius = 100;

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(30);
	ofBackground(255);
	ofSetBackgroundAuto(true);
	ofSetCircleResolution(40);

	width = ofGetWidth();
	height = ofGetHeight();

	posX = width * 0.5;
	posY = height * 0.5;

	velX = -5;
	velY = 10;
}

//--------------------------------------------------------------
void ofApp::update(){

	posX = posX + velX;
	posY = posY + velY;

	if (posX > width + radius) { posX = -radius; }
	if (posY > height + radius) { posY = -radius; }

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(110, 50, 80);
	ofDrawCircle(posX, posY, radius);
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
