#include "ofApp.h"

int Circle::WIDTH = 0;
int Circle::HEIGHT = 0;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
    ofSetFrameRate(60);
    ofSetCircleResolution(46);
    
    
    w = ofGetWidth();
    h = ofGetHeight();
    
    Circle::WIDTH = w;
    Circle::HEIGHT = h;
    
    for (int i = 0; i < NUM_CIRCLES; i++)
    {
        int x = ofRandom(ofGetWidth());
        int y = ofRandom(ofGetHeight());
        float r = ofRandom(2, 10);
        circles.push_back(make_unique<Circle>(x, y, r));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < circles.size(); i++)
    {
        circles.at(i)->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < circles.size(); i++)
    {
        circles.at(i)->draw();
    }
    
    
    ofSetColor(0);
    string str = "Number of circles: " + to_string(circles.size());
    ofDrawBitmapString(str, w * 0.8, h * 0.1);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ')
    {
        for (int i = 0; i < circles.size(); i++)
        {
            circles.at(i)->changeColor();
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
    if (button == 0)
    {
        circles.push_back(make_unique<Circle>(x, y, ofRandom(2, 10)));
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (button == 0)
    {
        circles.push_back(make_unique<Circle>(x, y, ofRandom(2, 10)));
    }
}

//--------------------------------------------------------------
void ofApp::exit() {
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
