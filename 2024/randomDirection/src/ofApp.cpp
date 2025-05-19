#include "ofApp.h"


int WIDTH, HEIGHT;
float posX, posY;
float radius;
float stepSize;

enum class DIR
{
	NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST
};

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);
	ofSetCircleResolution(42);
	//ofEnableAntiAliasing();
	ofSetBackgroundAuto(false);
	ofBackground(255);

	WIDTH = ofGetWidth();
	HEIGHT = ofGetHeight();

	posX = ofRandom(WIDTH);
	posY = ofRandom(HEIGHT);

	radius = 1;
	stepSize = 1;

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

	int mx = ofMap(ofGetMouseX(), 0, WIDTH, 0, 100, true);
	for (int i = 0; i < mx; i++)
	{
		int randIdx = rand() % 8;
		DIR dir = (DIR)randIdx;

		switch (dir) {
			case DIR::NORTH:
				posY -= stepSize;
				break;

			case DIR::NORTHEAST:
				posY -= stepSize;
				posX += stepSize;
				break;

			case DIR::EAST:
				posX += stepSize;
				break;

			case DIR::SOUTHEAST:
				posY += stepSize;
				posX += stepSize;
				break;

			case DIR::SOUTH:
				posY += stepSize;
				break;

			case DIR::SOUTHWEST:
				posY += stepSize;
				posX -= stepSize;
				break;

			case DIR::WEST:
				posX -= stepSize;
				break;

			case DIR::NORTHWEST:
				posY -= stepSize;
				posX -= stepSize;
				break;

			default:
				break;
		}

		if (posX > WIDTH || posX < 0 || posY > HEIGHT || posY < 0)
		{
			posX = ofRandom(WIDTH);
			posY = ofRandom(HEIGHT);
		}

		ofSetColor(0, 10);
		ofDrawCircle(posX, posY, radius);
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
