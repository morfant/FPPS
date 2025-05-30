#include "ofApp.h"

int Circle::width = 0;
int Circle::height = 0;

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(30);
    ofSetCircleResolution(32);

    width = ofGetWidth();
    height = ofGetHeight();

	Circle::width = width;
	Circle::height = height;

    for (int i = 0; i < NUM; i++)
    {
        circles[i] = new Circle(
			ofRandom(width), ofRandom(height), // posX, posY
			ofRandom(-3, 3), ofRandom(-3, 3), // speedX, speedY,
			ofRandom(40, 120)
		); // radius
    }

}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < NUM; i++)
    {
        circles[i]->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);

    for (int i = 0; i < NUM; i++)
    {
        circles[i]->draw();
    }

}

//--------------------------------------------------------------
void ofApp::exit(){

	for (int i = 0; i < NUM; i++)
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
