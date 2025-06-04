#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetCircleResolution(32);
	ofSetFrameRate(30);

}

//--------------------------------------------------------------
void ofApp::update(){

	if (ofGetMousePressed())
	{
		circles.push_back(new Circle(ofGetMouseX(), ofGetMouseY(), ofRandom(10, 80)));
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(255);

	for (int i = 0; i < circles.size(); i++)
	{
		circles[i]-> draw();
	}

}

//--------------------------------------------------------------
void ofApp::exit(){

	for (int i = 0; i < circles.size(); i++)
	{
		delete circles[i];
	}

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
