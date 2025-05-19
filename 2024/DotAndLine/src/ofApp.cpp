#include "ofApp.h"
#include "Dot.h"



//--------------------------------------------------------------
void ofApp::setup(){

    width = ofGetWidth();
    height = ofGetHeight();
    
    for (int i = 0; i < 10; i++)
    {
        dots.push_back(new Dot(ofRandom(-width/2, width/2), ofRandom(-height/2, height/2), ofRandom(500)));
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);

    cam.begin();
    for (auto & l : lines)
    {
        l.draw();
    }
    cam.end();

}

//--------------------------------------------------------------
void ofApp::exit()
{
    for (auto & d : dots)
    {
        delete d;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ')
    {
        int rb = ofRandom(9);
        int re = ofRandom(9);
        lines.push_back(*dots[rb] + dots[re]);
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
