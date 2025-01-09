#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	sh1 = new Circle(500, 500, 20);
	sh2 = new Rect(0, 0, 100, 100);

}

//--------------------------------------------------------------
void ofApp::update(){
	sh1->update();
	sh2->update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	sh1->draw();
	sh2->draw();
}


//--------------------------------------------------------------
void ofApp::exit()
{
	delete sh1;
	delete sh2;
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