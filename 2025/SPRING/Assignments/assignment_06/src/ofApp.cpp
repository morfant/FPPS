#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetCircleResolution(32);
	ofSetFrameRate(30);

	cc = ConcentricCircle(ofGetWidth() * 0.5, ofGetHeight() * 0.5, 100);

}

//--------------------------------------------------------------
void ofApp::update(){

	if (ofGetMousePressed())
	{
		cc.setPosX(ofGetMouseX());
		cc.setPosY(ofGetMouseY());
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(255);

	cc.draw();

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
