#include "ofApp.h"


int Particle::WIDTH = 0;
int Particle::HEIGHT = 0;



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    Particle::WIDTH = width;
    Particle::HEIGHT = height;
    
    for (int i = 0; i < MAX_NUM; i++)
    {
        auto p = make_shared<Particle>(glm::vec2(ofRandom(width), ofRandom(height)));
        particles.push_back(p);
    }

}

//--------------------------------------------------------------
void ofApp::update(){

   
    if (isMouseClicked)
    {
        auto p = make_shared<Particle>(glm::vec2(mX, mY));
        particles.push_back(p);
    }
    
    for (auto & p : particles)
    {
        p->update();
        p->checkEdge();
        p->grow();
    }
    
    for (auto it = particles.begin(); it != particles.end();)
    {
        auto p = *it;
        if (p->hasToDie())
        {
            it = particles.erase(it);
        }
        else
        {
            ++it;
        }
    }
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0, 0, 0);
    
    for (auto & p : particles)
    {
        p->draw();
    }
    
    ofSetColor(255);
    string str = "Number of particles: " + ofToString(particles.size());
    ofDrawBitmapString(str, width * 0.75, height * 0.1);

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
    mX = x;
    mY = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (button == 0)
    {
        isMouseClicked = true;
        mX = x;
        mY = y;
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == 0) { isMouseClicked = false; }

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
