#include "ofApp.h"

int posX, posY;
float step;
int WIDTH, HEIGHT;
float radius;

enum class DIRECTION
{
	NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST
};


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofSetBackgroundAuto(false);
	ofBackground(255);

	WIDTH = ofGetWidth();
	HEIGHT = ofGetHeight();

	posX = ofRandom(WIDTH);
	posY = ofRandom(HEIGHT);
	radius = 1;
	step = 1;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	int mx = ofMap(ofGetMouseX(), 0, WIDTH, 0, 400, true);

	for (int i = 0; i < mx; i++)
	{
		int r = rand() % 8;
		DIRECTION dir = (DIRECTION)r;

		switch (dir) {
		case DIRECTION::NORTH:
			posY = posY - step;
			break;

		case DIRECTION::NORTH_EAST:
			posY = posY - step;
			posX = posX + step;
			break;

		case DIRECTION::EAST:
			posX = posX + step;
			break;

		case DIRECTION::SOUTH_EAST:
			posX = posX + step;
			posY = posY + step;
			break;

		case DIRECTION::SOUTH:
			posY = posY + step;
			break;

		case DIRECTION::SOUTH_WEST:
			posY = posY + step;
			posX = posX - step;
			break;

		case DIRECTION::WEST:
			posX = posX - step;
			break;

		case DIRECTION::NORTH_WEST:
			posX = posX - step;
			posY = posY - step;
			break;

		default:
			break;
		};

		if (posX > WIDTH || posX < 0 || posY > HEIGHT || posY < 0)
		{
			posX = ofRandom(WIDTH);
			posY = ofRandom(HEIGHT);
		}

		ofSetColor(0, 255);
		ofDrawCircle(posX, posY, radius);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 's' || key == 'S')
	{
		glReadBuffer(GL_FRONT);
		cout << "Screen saved." << endl;
		ofSaveScreen("screenSave.png");
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
