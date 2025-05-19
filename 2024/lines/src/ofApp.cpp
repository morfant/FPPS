#include "ofApp.h"

int width, height;
int posX, posY;
int velX, velY;
int radius = 100;
bool isInside = false;

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

	velX = 10;
	velY = 15;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    posX = posX + velX;
    posY = posY + velY;

	float dx = posX - ofGetMouseX();
	float dy = posY - ofGetMouseY();
	float dd = (dx * dx) + (dy * dy);

	float rr = radius * radius;
	if (dd < rr)
	{
		isInside = true;
	}
	else
	{
		isInside = false;
	}


	// Flowing
	//if (posX > width + radius) { posX = -radius; }
	//else if (posX < 0 - radius) { posX = width + radius; }

	//if (posY > height + radius) { posY = -radius; }
	//else if (posY < 0 - radius) { posY = height + radius; }

	if (posX >= width - radius)
	{
		posX = width - radius;
		velX = velX * -1;
	}
	else if (posX <= radius)
	{
		posX = radius;
		velX = velX * -1;
	}

	if (posY >= height - radius)
	{
		posY = height - radius;
		velY = velY * -1; // velY *= -1
	}
	else if (posY <= radius)
	{
		posY = radius;
		velY = velY * -1;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	if (isInside) ofSetColor(110, 50, 80);
	else ofSetColor(0);
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
