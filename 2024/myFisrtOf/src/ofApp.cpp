#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    ofBackground(255, 255, 255);
    ofSetCircleResolution(32);
    ofSetLineWidth(1);
    ofSetBackgroundAuto(false);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    count = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetMousePressed())
    {
        ofBackground(255, 255, 255);
        count = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (ofGetFrameNum() > 30 && count < 5)
    {
//        ofNoFill();
        ofFill();
        ofSetLineWidth(0);
        ofSetColor(0, 50);
        float rad = ofRandom(50, 100);
        float px = ofRandom(100, width - 100);
        float py = ofRandom(100, height - 100);
        
        for (int i = 0; i < rad / 2; i++)
        {
            ofDrawCircle(px, py, i * 2);
        }
        
        count++;
        
    }
    
   
//    if (ofGetFrameNum() > 30 && count < 5)
//    {
//        float curX = ofRandom(50, width - 50);
//        float curY = ofRandom(50, height - 50);
//        float rad = ofRandom(20, 60);
//
//        ofSetColor(ofRandom(80), 60);
////        ofFill();
//        ofNoFill();
//        ofSetLineWidth(1);
//        
//        for (int i = 0; i < rad / 4; i++)
//        {
//            ofDrawCircle(curX, curY, 4 * (i + 1));
//        }
//        
//        count++;
        
//    }
  
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 32)
    {
        ofBackground(255);
        count = 0;
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
