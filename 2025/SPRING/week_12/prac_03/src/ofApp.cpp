#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetCircleResolution(32);
	ofSetFrameRate(30);

	width = ofGetWidth();
	height = ofGetHeight();

}

//--------------------------------------------------------------
void ofApp::update(){

	if (ofGetMousePressed())
	{
		dots.emplace_back(ofGetMouseX(), ofGetMouseY(), ofRandom(20, 60));
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	for (int i = 0; i < dots.size(); i++)
	{
		dots[i].draw();
	}

	ofDrawBitmapStringHighlight("Current number of dots: " + ofToString(dots.size()), 20, 20);

}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == ' ')
	{
		dots.clear();
	}

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
