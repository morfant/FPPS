#include "ofApp.h"

int Shape::WIDTH = 0;
int Shape::HEIGHT = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(42);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    Shape::WIDTH = width;
    Shape::HEIGHT = height;
    
    shape1 = new CircleShape(100, 100, 100);
    shape2 = new RectShape(100, 100, 100, 200);
    
    shape1->setup();
    shape2->setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    shape1->update();
    shape2->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    shape1->draw();
    shape2->draw();

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
