#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetCircleResolution(32);

    width = ofGetWidth();
    height = ofGetHeight();

    for (int i = 0; i < MAX_NUM; i++)
    {
        dots[i] = new Dot(ofRandom(width), ofRandom(height), ofRandom(1, 3));
    } 
    // d1 = new Dot(100, 100, 10);
    // d2 = new Dot(400, 200, 50);
    // d3 = (*d2) + (*d1);


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);

    // d1.draw();
    // d2.draw();

    // float dist = d1 - d2;
    // ofDrawBitmapStringHighlight("Distance from d1 to d2: " + ofToString(dist, 2), 10, 20);

    ofDrawBitmapStringHighlight("FPS: " + ofToString(ofGetFrameRate(), 2), 10, 20);

    // d1 + d2;
    // d1 + 0.1;
    // d3.draw();


    for (int i = 0; i < MAX_NUM; i++)
    {
        dots[i]->draw();
    }


}

//--------------------------------------------------------------
void ofApp::exit(){

    for (int i = 0; i < MAX_NUM; i++)
    {
        delete dots[i];
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
