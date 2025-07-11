#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofSetCircleResolution(42);

    isMouseReleased = true;

}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetMousePressed() == false) isMouseReleased = true;

    if (ofGetMousePressed() && isMouseReleased)
    {
        bool isTouchedAnyCircle = false;
        for (int i = 0; i < circles.size(); i++)
        {
            if(circles.at(i).isMouseTouched(ofGetMouseX(), ofGetMouseY()))
            {
                circles.at(i).toggleIsFilled();
                isTouchedAnyCircle = true;
            } 
        }

        if (isTouchedAnyCircle == false)
        {
            Circle c = Circle(ofGetMouseX(), ofGetMouseY(), 60);
            circles.push_back(c);
        }

        isMouseReleased = false;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);

    for (int i = 0; i < circles.size(); i++)
    {
        circles.at(i).show();
    }

    ofDrawBitmapStringHighlight(
        "number of circles: " + to_string(circles.size()), 30, 30);

    ofDrawBitmapStringHighlight(
        "Press spacebar to clear circles!", 30, 60);

}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ')
    {
        circles.clear();
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
