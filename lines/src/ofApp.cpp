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

	velX = -5;
	velY = 10;
}

//--------------------------------------------------------------
void ofApp::update(){

	if (!isInside)
	{
		posX = posX + velX;
		posY = posY + velY;
	}

	// Flowing
	if (posX > width + radius) { posX = -radius; }
	else if (posX < 0 - radius) { posX = width + radius; }

	//if (posY > height + radius) { posY = -radius; }
	//else if (posY < 0 - radius) { posY = height + radius; }


	// Bouncing
	//if (posX + radius >= width)
	//{
	//	posX = width - radius;
	//	velX *= -1;
	//}
	//else if (posX - radius <= 0)
	//{
	//	posX = radius;
	//	velX *= -1;
	//}

	//if (posY + radius >= height)
	//{
	//	posY = height - radius;
	//	velY *= -1;
	//}
	//else if (posY - radius <= 0)
	//{
	//	posY = radius;
	//	velY *= -1;
	//}



}

//--------------------------------------------------------------
void ofApp::draw(){

	if (isInside) ofSetColor(110, 50, 80);
	else ofSetHexColor(0x98d9c2);
	ofDrawCircle(posX, posY, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 's' || key == 'S') {

        // 현재 날짜 및 시간 문자열 (예: "2024-12-27-15-30-45")
        std::string timestamp = ofGetTimestampString("%Y-%m-%d-%H-%M-%S");

        // 파일 이름에 타임스탬프 추가
        std::string filename = "screenshot-" + timestamp + ".png";

        // 화면 저장
        ofSaveScreen(filename);

        ofLog() << "Screenshot saved as " << filename;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

	float rr = radius * radius;
	float dd = ((posX - x) * (posX - x)) + ((posY - y) * (posY - y));

	if (dd < rr)
	{
		isInside = true;
	}
	else
	{
		isInside = false;
	}
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
