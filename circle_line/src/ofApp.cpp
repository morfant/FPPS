#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (isClicked == true)
    {
        Circle* c = new Circle(ofVec2f(ofGetMouseX(), ofGetMouseY()));
        circles.push_back(c);
        isClicked = false;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    Circle * pc = nullptr;
    for (auto & c : circles)
    {
        c->draw();
        if (pc) {
            ofSetColor(0);
            ofDrawLine(pc->getPos(), c->getPos());
        }
        pc = c;
    }

}

//--------------------------------------------------------------
void ofApp::exit(){
    
    for (auto it = circles.begin(); it != circles.end(); ++it)
    {
        auto & c = *it;
        delete c;
    }

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
    if (button == 0) {isClicked = true;}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == 0) {isClicked = false;}
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
