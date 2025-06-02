#include "ofApp.h"


// ofGetWidth()/ofGetHeight() only returns a valid value after the window object has been created.
// However, At this point, the window object may not exist yet,
// so calling them can lead to an error.

// int Circle::width = ofGetWidth();
// int Circle::height = ofGetHeight();

// Because of this, it’s common to initialize static variables with temporal value (like 0),
// and then update them later at an appropriate point
// for example, inside the setup() function:
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
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
