#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofSetCircleResolution(42);
    width = ofGetWidth();
    height = ofGetHeight();

    isObjectCreated = false;

    for (int i = 0; i < 10; i++)
    {
        Circle c = Circle(width * 0.5, height * 0.5, ofRandom(10, 60));
        circles.push_back(c);
    }


}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT))
    {
        bool isAnythingTouched = false;
        for (int i = 0; i < circles.size(); i++)
        {
            if (circles.at(i).isMouseTouched() == true)
            {
                isAnythingTouched = true;
                break;
            }
        }

        if (isAnythingTouched == false)
        {
            circles.push_back(
                Circle(ofGetMouseX(), ofGetMouseY(), ofRandom(10, 60))
            );
        }

    }

    
    for (int i = 0; i < circles.size();)
    {
        if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT) &&
            circles.at(i).isMouseTouched())
        {
            circles.at(i) = circles.back();
            circles.pop_back();
        }
        else
        {
            circles.at(i).move();
            i++;
        }
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    for (int i = 0; i < circles.size(); i++)
    {
        circles.at(i).show();
    }

    ofDrawBitmapStringHighlight("circles: " + to_string(circles.size()), 30, 30);

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
