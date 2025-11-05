#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(3);
	ofSetBackgroundAuto(false);
	ofFill();
	circlenum = 0;
	width = ofGetWidth();
	height = ofGetHeight();
}

void ofApp::update(){
	if (ofGetMousePressed()) {
		circlenum = 0;
		ofBackground(0); // 화면 초기화
	}
}

void ofApp::draw(){

	if (ofGetFrameNum() > delayFrame && circlenum < 5){  // 0부터 시작이니까 <5로
		float x = ofRandom(ofGetWidth());
		float y = ofRandom(ofGetHeight());
		float r = ofRandom(30, 80);

		ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), 50);

		int numOfCircles = r / 4;
		float step = r / numOfCircles;

		for (int j = 0; j < numOfCircles; j++) {
			float rad = step * (j + 1);
			ofDrawCircle(x, y, rad);
		}

		circlenum++;
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
