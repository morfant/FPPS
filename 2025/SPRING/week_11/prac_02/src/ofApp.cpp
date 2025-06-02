#include "ofApp.h"

int Circle::width = 0;
int Circle::height = 0;

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetCircleResolution(32);
    ofSetFrameRate(30);

    width_ = ofGetWidth();
    height_ = ofGetHeight();

    Circle::width = width_;
    Circle::height = height_;

    for (int i = 0; i < NUM_OF_CIRCLE; i++)
    {
        circles[i] = Circle(
            ofRandom(width_),
            ofRandom(height_),
            ofRandom(50, 80),
            ofRandom(-5, 5),
            ofRandom(-5, 5)
        );
    }


}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM_OF_CIRCLE; i++)
    {
        circles[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);

    for (int i = 0; i < NUM_OF_CIRCLE; i++)
    {
        circles[i].draw();
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
<<<<<<< HEAD
void ofApp::dragEvent(ofDragInfo dragInfo){ 
=======
void ofApp::dragEvent(ofDragInfo dragInfo){
>>>>>>> 98a19388c68a9bbd8257f49d27e55d54e263438a

}
