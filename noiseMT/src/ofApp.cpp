#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    stepX = width / num_x;
    stepY = height / num_y;

    float offsetX = -width / 2;
    float offsetY = -height / 2;

    
    for (int x = 0; x < num_x; ++x) {
        for (int y = 0; y < num_y; ++y) {
            mesh.addVertex(ofPoint(x * stepX + offsetX, y * stepY + offsetY, 0));
            mesh.addColor(ofColor(255, 255, 255));
        }
    }
   
    
}

//--------------------------------------------------------------
void ofApp::update(){
   
    // mode 선택
    if (prev_gl_mode != gl_mode) {
        mesh.setMode(connectingMode[gl_mode]);
        
		/*
		왼쪽 상단: x + (y * num_x)
		오른쪽 상단: (x + 1) + (y * num_x)
		왼쪽 하단: x + (num_x * (y + 1))
		오른쪽 하단: (x + 1) + (num_x * (y + 1))
		*/

        for (int x = 0; x < num_x - 1; ++x) {
            for (int y = 0; y < num_y - 1; ++y) {
                mesh.addIndex(x + (y * num_x));
                mesh.addIndex((x + 1) + (y * num_x));
                mesh.addIndex(x + (num_x * (y + 1)));
                
                mesh.addIndex((x + 1) + (y * num_x));
                mesh.addIndex((x + 1) + (num_x * (y + 1)));
                mesh.addIndex(x + (num_x * (y + 1)));
            }
        }
        prev_gl_mode = gl_mode;
    }
   
    
    // z 값에 변화 주기
    for (int x = 0; x < num_x; ++x) {
        for (int y = 0; y < num_y; ++y) {
            
            int idx = num_x * y + x;
            ofPoint v = mesh.getVertex(idx);
            
			//float noiseValue = ofNoise(xOffset + x * 0.1, y * 0.1, ofGetElapsedTimef() * 0.1); // 3D
			float noiseValue = ofNoise(xOffset + x * 0.08, y * 0.08); // 2D
			v.z = noiseValue * 200.0f;  // z 값 스케일 조정 (0~1 범위를 0~200으로 확대)


            mesh.setVertex(idx, v);
            ofColor c(v.z, 100, 120);
            //ofColor c(noiseValue * 200.0f, 100, 120);
            mesh.setColor(idx, c);

        }
    }

    xOffset += 0.1;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0, 0, 0);
    
    cam.begin();
    //mesh.draw();

    ofSetLineWidth(20);
    for (int i = 0; i < mesh.getNumVertices(); i++)
    {
        ofPoint v = mesh.getVertex(i);
        ofColor c = mesh.getColor(i);

        ofVec3f v1(v.x, v.y, 0);
        ofSetColor(c);
        ofDrawLine(v1, v);
        //ofDrawCircle(v, 3);
    }
    cam.end();
    
    
    ofColor(255);
    ofDrawBitmapString("Select 1 ~ 7", 100, 100);
    
    string currentModeName = modeNames[gl_mode];
    ofDrawBitmapString(currentModeName, 100, 130);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    int n = key - 48;
    
    if (0 < n && n < 8) {
        cout << n << endl;
        gl_mode = n - 1;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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
