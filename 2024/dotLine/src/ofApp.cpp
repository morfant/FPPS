#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(255);
	WIDTH = ofGetWidth();
	HEIGHT = ofGetHeight();

	for (int i = 0; i < MAX_LINE_NUM; i++)
	{
		Dot begin = Dot(ofRandom(WIDTH), ofRandom(HEIGHT));
		Dot end = Dot(ofRandom(WIDTH), ofRandom(HEIGHT));
		lines[i] = Line(begin, end);
	}

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < MAX_LINE_NUM; i++)
	{
		lines[i].draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == ' ')
	{
		for (int i = 0; i < MAX_LINE_NUM; i++)
		{
			lines[i].changeColor();
		}
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
