#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
//    ofSetBackgroundAuto(false);
    ofSetCircleResolution(30);
    ofSetFrameRate(60);
    
    w = ofGetWidth();
    h = ofGetHeight();
    
    g = ofVec2f(0, 1.f);
    
//    ofColor col = ofColor(ofRandom(50, 100), ofRandom(100, 170), ofRandom(255), ofRandom(50, 255));
//    c1 = new Circle(ofVec2f(ofGetWidth()/2, ofGetHeight()/2), 100, ofColor(255, 0, 0));
//    c1 = new Circle(ofVec2f(200, 200), 40, ofColor(255, 0, 0));
//    c2 = new Circle(ofVec2f(ofGetWidth()/2, ofGetHeight()/2), 50, ofColor(0, 0, 255));
    
    for (int i = 0; i < 1200; i++)
    {
        
        float rr = ofRandom(2, 12);
        ofColor col = ofColor(ofRandom(50, 100), ofRandom(100, 170), ofRandom(255), ofRandom(50, 255));
        circles.push_back(new Circle(ofVec2f(
                                             ofRandom(10, ofGetWidth() - 10),
                                             ofRandom(10, ofGetHeight() - 10)), rr, col));
    }
 

}

//--------------------------------------------------------------
void ofApp::update(){
    
    float gMult = ofMap(ofGetMouseY(), 0, h, 0, 3.0f);
    g.set(0, gMult);

    ofColor cb = ofColor(
                         ofMap(ofClamp(ofGetMouseX(), 0, w), 0, w, 0, 255),
                         0, 0);
    int rx = ofRandom(w*0.2, w*0.8);
    int ry = ofRandom(h*0.2, h*0.8);
    float rr = ofRandom(2, 6);
    
    ofColor col = ofColor(ofRandom(50, 100), ofRandom(100, 170), ofRandom(255), ofRandom(50, 255));
        
    if (circles.size() < MAX_NUM_POINT && isClicked == true) {
        if (count % 1 == 0) {
            circles.push_back(new Circle(ofVec2f(ofGetMouseX(), ofGetMouseY()), rr, col));
        }
    }
    
   
    for (auto it = circles.begin(); it != circles.end();)
    {
        Circle * c = *it;
        for (auto jt = std::next(it); jt != circles.end(); ++jt)
        {
            Circle * c2 = *jt;
            c2->attract(c);
        }
//        c->applyForce(g);
        
        if (isClickedR) {
          ofVec2f wind(0.5, 0);
          c->applyForce(wind);
        }

        c->setColorBase(cb);
        c->update();
        c->checkEdge();
        
        
        if (c->getAge() > AGE_LIMIT)
        {
            delete c;
            it = circles.erase(it);
        }
        else
        {
            it++;
        }
    }
     
//    
//    c1->setColorBase(cb);
////    c1->applyForce(g);
//    c1->attract(c2);
//    c1->update();
//    c1->checkEdge();
//    
//    c2->setColorBase(cb);
////    c2->applyForce(g);
//    c2->attract(c1);
//    c2->update();
//    c2->checkEdge();
//    
    count++;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofSetColor(255);
//    ofDrawCircle(w/2, h/2, 100);
//    
//    ofSetColor(100);
//    ofDrawRectangle(w/2, h/2, 200, 200);
//    
//    ofSetColor(255, 100, 60);
//    ofDrawTriangle(w/2, h/2, 400, 400, 100, 700);
//    
//    ofSetLineWidth(10);
//    ofSetColor(0, 120, 200);
//    ofDrawLine(0, 0, w/2, h/2);
//    
//    ofSetColor(200, 100, 150, 50);
//    ofDrawEllipse(w/2, h/2, 200, 50);
    
    
    
//    ofSetColor(0);
    for (auto& c : circles)
    {
        c->draw();
    }
    
    
    ofSetColor(255, 0, 0);
    ofDrawBitmapString(circles.size(), w * 0.9, h * 0.1);

    ofSetColor(255, 0, 0);
    ofDrawBitmapString("gravity: " + ofToString(g.y), w * 0.8, h * 0.2);
    
    ofSetColor(0, 0, 255);
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), w * 0.8, h * 0.3);

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
    if (button == 0) isClicked = true;
    if (button == 2) isClickedR = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == 0) isClicked = false;
    if (button == 2) isClickedR = false;

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
