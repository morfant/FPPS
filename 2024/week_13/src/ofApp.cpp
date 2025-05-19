#include "ofApp.h"

// Circle의 static 멤버 함수 초기화
float Circle::TOP_SPEED = 20.f;

//--------------------------------------------------------------
void ofApp::setup(){
    // 원을 몇개의 직선으로 그릴 것인가
    ofSetCircleResolution(40);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    
    // 초당 몇 프레임씩 그릴 것인가
    ofSetFrameRate(60);
    
    // 윈도우의 가로, 세로 길이
    w = ofGetWidth();
    h = ofGetHeight();
    
    // 원의 중심 좌표
    pos_x = w / 2;
    pos_y = h / 2;
    
    // 중앙의 동그라미의 반지름
    radius = 100;
    
    // 중력
    gravity = ofVec2f(0, 2);
    
    // 마우스 포인터가 원 안에 위치했는가?
    isOn = false;
    
    // 10개의 Circle 객체를 생성
    for (int i = 0; i < 10; i++)
    {
        ofColor col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofVec2f p = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
        Circle* c = new Circle(p, ofRandom(30, 100), col);
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
    
//    if (isClickedL == true)
//    {
//        ofColor col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
//        ofVec2f p = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
//        Circle* c = new Circle(p, ofRandom(30, 100), col);
//        circles.push_back(c);
//        isClickedL = false;
//    }
    
    // 마우스 포인터의 위치를 2차원 벡터로 만들기
    ofVec2f mv = ofVec2f(ofGetMouseX(), ofGetMouseY());
    
    for (auto it = circles.begin(); it != circles.end();)
    {
        auto c = *it;
        
        if (c->getAge() > 200)
        {
            delete c;
            it = circles.erase(it);
        }
        else
        {
            c->pulled(mv);
            c->applyForce(gravity);
            c->update();
            it++;
        }
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 180);
    ofDrawRectangle(0, 0, w, h);
    
    float rbx, rby, rex, rey;
    
    // 랜덤한 시작점 (rbx, rby)
    rbx = ofRandom(w);
    rby = ofRandom(h);
    
    // 랜덤한 끝점 (rex, rey)
    rex = ofRandom(w);
    rey = ofRandom(h);
    
    // 선 그리기
    ofSetColor(0);
    ofSetLineWidth(2);
    ofDrawLine(rbx, rby, rex, rey);
    
    // 화면 가운데 동그라미
    ofSetColor(0, 0, 255);
    if (isOn) ofSetColor(200, 100, 50, 50);
    ofDrawCircle(pos_x, pos_y, radius);
    
    // circles의 객체들 그리기
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
        delete *it;
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
    if (button == 0) {
        ofColor col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofVec2f p = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
        Circle* c = new Circle(p, ofRandom(30, 100), col);
        circles.push_back(c);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    if (button == 0) {isClickedL = false;}
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
