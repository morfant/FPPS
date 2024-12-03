#include "ofApp.h"

float Circle::TOP_SPEED = 20.f;

//--------------------------------------------------------------
void ofApp::setup(){
    // 원을 몇개의 직선으로 그릴 것인가
    ofSetCircleResolution(40);
    
    // 초당 몇 프레임씩 그릴 것인가
    ofSetFrameRate(60);

    ofBackground(255);
	ofSetBackgroundAuto(false);
    
    // 윈도우의 가로, 세로 길이
    w = ofGetWidth();
    h = ofGetHeight();
    
    // 원의 중심 좌표
    pos_x = w / 2;
    pos_y = h / 2;
    
    radius = 100;
    
    // x, y 축 방향 속도
    speed_x = 3.0;
    speed_y = 3.0;
    
    // 마우스 포인터가 원 안에 위치했는가?
    isOn = false;


    gravity.set(0, 1.0);
    
    // 10개의 Circle 객체를 생성
    for (int i = 0; i < CIRCLE_MAX; i++)
    {
        ofVec2f p = ofVec2f(w/2, h/2);
        Circle* c = new Circle(p, ofRandom(1, 1));
        circles.push_back(c);
    }
}


//--------------------------------------------------------------
void ofApp::update(){

    
    // 원의 중심점으로부터 마우스 포인터까지의 거리
    float d = ofDist(pos_x, pos_y, ofGetMouseX(), ofGetMouseY());
    
    // 마우스 포인터가 원 안에 들어왔는지 판별
    if (d < radius) isOn = true;
    else isOn = false;

    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
    for (auto & c : circles)
    {
        if (isClickedR)
        {
            //c->applyForce(wind);
            c->pulled(ofVec2f(ofGetMouseX(), ofGetMouseY()));
        }

        if (isOn)
        {
            //c->pulled(ofVec2f(w/2, h/2));
            c->repelled(ofVec2f(w/2, h/2));
        }
        //c->applyForce(gravity);
        c->update();
    }
 
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // 움직이는 원
    ofSetColor(0, 0, 255);
    if (isOn) ofSetColor(200, 100, 50, 50);
    ofDrawCircle(pos_x, pos_y, radius);
    
    
    for (auto & c : circles)
    {
        c->draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    cout << "The app is shuting down.." << endl;
    
    for (auto it = circles.begin(); it != circles.end(); it++)
    {
        auto c = *it;
        delete c;
    }
    
    cout << "Dynamic memory is released." << endl;

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
    if (button == 2)
    {
        isClickedR = true;
        wind = ofVec2f(ofRandomf(), ofRandomf());
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
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
