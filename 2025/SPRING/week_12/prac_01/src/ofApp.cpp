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

    for (int i = 0; i < NUM; i++)
    {
		Circle* c = new Circle(
			ofRandom(width), ofRandom(height), // posX, posY
			ofRandom(-3, 3), ofRandom(-3, 3), // speedX, speedY,
			ofRandom(10, 10) // radius
		);

		circles.push_back(c);
    }

}

//--------------------------------------------------------------
void ofApp::update(){

	if (ofGetMousePressed())
	{
		for (int i = 0; i < 10; i++)
		{
			Circle* c = new Circle(
				ofGetMouseX(), ofGetMouseY(), // posX, posY
				ofRandom(-3, 3), ofRandom(-3, 3), // speedX, speedY,
				ofRandom(10, 10) // radius
			);
			circles.push_back(c);
		}

	}


	// Method 1
    for (auto it = circles.begin(); it != circles.end(); )
    {
		auto c = *it;

		if (c->toDie())
		{
			delete c;
			it = circles.erase(it);
		}
		else
		{
			c->update();
			++it;
		}
    }



	// Method 2
	// for (int i = 0; i < circles.size(); )
	// {
	// 	if (circles[i]->toDie())
	// 	{
	// 		delete circles[i];
	// 		circles[i] = circles.back();
	// 		circles.pop_back();
	// 	}
	// 	else
	// 	{
	// 		circles[i]->update();
	// 		++i;
	// 	}
	// }


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
