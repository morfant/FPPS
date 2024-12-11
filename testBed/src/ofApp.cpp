#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetDepthTest(true);
//    glShadeModel(GL_FLAT);
    width = ofGetWidth();
    height = ofGetHeight();
    step_x = width / num_x;
    step_y = height / num_y;
    
    float offsetX = width / 2;
    float offsetY = height / 2;
    
//    float offsetX = 0;
//    float offsetY = 0;

    // ofMesh가 사용하는 좌표계의 원점은 left-bottom
    // y값이 증가하면 좌표계 상 위치가 아래에서 위로 이동한다
    // 가로축을 모두 채웠을 때 세로축으로 한 줄 이동
    for (int y = 0; y < num_y; y++) {
        for (int x = 0; x < num_x; x++) {
            mesh.addVertex(
                ofVec3f(
                        (x * step_x) - offsetX,
                        (y * step_y) - offsetY,
                        0
                        )
            );
            mesh.addColor(ofColor((255)));
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
   
    // mode 선택
    if (prev_gl_mode != gl_mode) {
        mesh.setMode(connectingMode[gl_mode]);
        
        // index를 이용해 점들을 연결한다
		/*
		왼쪽 상단: x + (y * num_x)
		오른쪽 상단: (x + 1) + (y * num_x)
		왼쪽 하단: x + (num_x * (y + 1))
		오른쪽 하단: (x + 1) + (num_x * (y + 1))
		*/

        // 두 개의 삼각형을 위한 인덱스 추가
        for (int x = 0; x < num_x - 1; ++x) {
            for (int y = 0; y < num_y - 1; ++y) {
                mesh.addIndex(x + (y * num_x)); // top-left
                mesh.addIndex((x + 1) + (y * num_x)); // top-right
                mesh.addIndex(x + (num_x * (y + 1))); // bottom-left

                mesh.addIndex((x + 1) + (y * num_x)); // top-right
                mesh.addIndex((x + 1) + (num_x * (y + 1))); // bottom-right
                mesh.addIndex(x + (num_x * (y + 1))); // bottom-left
            }
        }
        
        prev_gl_mode = gl_mode;
    }
    
    // [실습] noise 값 사용하기
    for (int x = 0; x < num_x; x++)
    {
        for (int y = 0; y < num_y; y++)
        {
            int idx = x + (num_x * y);
            float noiseValue = ofNoise(x * 0.1, offset_x + y * 0.1);
            ofVec3f p = mesh.getVertex(idx);
            
            p.z = noiseValue * 200.f;
            ofColor c = ofColor(noiseValue * 255, 100, 100);
            mesh.setColor(idx, c);
            mesh.setVertex(idx, p);
        }
    }
    
    offset_x += step;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    cam.begin();
    mesh.draw();
     
    // Temporary drawing
    // vertex들의 순서 및 위치 표시
//    for (int x = 0; x < num_x; x++) {
//        for (int y = 0; y < num_y; y++) {
//            size_t index = x + (num_x * y);
//            ofPoint p = mesh.getVertex(index);
//            
//            ofFill();
//            ofSetColor(index % 255);
//            ofDrawCircle(p.x, p.y, 15);
//            
//            ofSetColor(255, 255, 0);
//            ofDrawBitmapString(index, p.x, p.y);
//        }
//    }
    
    
    // 원 둘 삼각형 하나
//    ofSetColor(255, 0, 0);
//    ofDrawCircle(100, 100, 20);
//    
//    ofSetColor(0, 255, 0);
//    ofDrawCircle(100, 200, 20);
//    
//    ofSetColor(0, 0, 255);
//    ofDrawTriangle(width * 0.2, 100, width * 0.2 + 100, 200, width * 0.2 - 100, 200);
//    
    
    // box
//    ofNoFill();
//    ofSetLineWidth(6);
//    ofSetColor(255, 100, 100);
//    ofDrawBox(0, 0, 0, 100, 100, 100);

    
    cam.end();

    
    ofColor(255);
    ofDrawBitmapString("Select 1 ~ 3", 100, 100);
    
    string currentModeName = modeNames[gl_mode];
    ofDrawBitmapString(currentModeName, 100, 130);
    
}

void ofApp::exit()
{
    cout << "Bye.." << endl;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    int n = key - 48;
    
    if (0 < n && n < 4) {
        cout << n << endl;
        gl_mode = n - 1;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    step = ofMap(y, 0, height, 0.01, 0.2);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//    if (button == 0) change_step = 0.1;
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    if (button == 0) change_step = 0.001;

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
