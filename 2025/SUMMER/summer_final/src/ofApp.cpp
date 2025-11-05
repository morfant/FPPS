#include "ofApp.h"


Circle::Circle(float x, float y, float r, ofColor c) {
	posX = x;
	posY = y;
	radius = r;
	col = c;
}

void Circle::draw() {
	ofSetColor(col);
	ofDrawCircle(posX, posY, radius);
}

void Circle::update() {
	posY -= 0.3;
}


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto& c : circles) {
		c.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (auto& c : circles) {
		c.draw();
	}
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		for (auto& c : circles) {
			c.col.set(ofRandom(255), ofRandom(255), ofRandom(255));
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
	float radius = ofRandom(20, 60);
	ofColor color;
	color.set(ofRandom(255), ofRandom(255), ofRandom(255));
	circles.push_back(Circle(x, y, radius, color));
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
