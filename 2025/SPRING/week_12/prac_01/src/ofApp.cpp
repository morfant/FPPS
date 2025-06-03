#include "ofApp.h"

int Circle::width = 0;
int Circle::height = 0;

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(30);
    ofSetCircleResolution(32);

    width = ofGetWidth();
    height = ofGetHeight();

	Circle::width = width;
	Circle::height = height;



	elapsed = startTime = 0.f;
	timeStarted = false;

}

//--------------------------------------------------------------
void ofApp::update(){


	for (int i = 0; i < circles.size(); )
	{
		if (circles[i]->isMouseTouched() && ofGetMousePressed())
		{
			delete circles[i];
			circles[i] = circles.back();
			circles.pop_back();
		}
		else
		{
			circles[i]->update();
			++i;
		}
	}


}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);

    for (int i = 0; i < circles.size(); i++)
    {
        circles[i]->draw();
    }


	ofDrawBitmapStringHighlight("Number of circles: " + ofToString(circles.size()), 10, 20);
	ofDrawBitmapStringHighlight("FPS: " + ofToString(ofGetFrameRate(), 2), 10, 40);

	if (circles.size() <= 0) timeStarted = false;

	if (timeStarted)
	{
		elapsed = ofGetElapsedTimef() - startTime;
		ofDrawBitmapStringHighlight("Timer: " + ofToString(elapsed, 2), 10, 60);
	}
	else
	{
		ofDrawBitmapStringHighlight("Timer: " + ofToString(elapsed, 2), 10, 60);
		ofDrawBitmapStringHighlight("Press Spacebar to start timer!", 10, 80);
	}

}

//--------------------------------------------------------------
void ofApp::exit(){

	for (int i = 0; i < circles.size(); i++)
	{
		delete circles[i];
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == ' ')
	{
		startTime = ofGetElapsedTimef();
		timeStarted = true;

		for (int i = 0; i < NUM; i++)
		{
			Circle* c = new Circle(
				ofRandom(width), ofRandom(height), // posX, posY
				ofRandom(-3, 3), ofRandom(-3, 3), // speedX, speedY,
				ofRandom(30, 100) // radius
			);

			circles.push_back(c);
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
