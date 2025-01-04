#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	first = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	for (ofVec3f &c : circles) {
		c.z += ofRandom(-5, 5);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	int i = 0;
	for (ofVec3f c : circles) {
		ofSetColor(colors[i].x, colors[i].y, colors[i].z);
		ofDrawCircle(c.x, c.y, c.z);
		i++;
		if (first) {
			lastPoint = ofVec2f(c.x, c.y);
			first = false;
		}
		else {
			ofDrawLine(lastPoint.x, lastPoint.y, c.x, c.y);
			lastPoint = ofVec2f(c.x, c.y);
		}
	}
	first = true;
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
	if (button == 0) {
		radius = ofRandom(10, 100);
		colors.push_back(ofVec3f(ofRandom(255), ofRandom(255),ofRandom(255)));
		circle = ofVec3f(x, y, radius);
		circles.push_back(circle);
	}
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

void ofApp::exit() {
	
}