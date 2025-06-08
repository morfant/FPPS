// ofApp.cpp
#include "ofApp.h"

// define static member variables with temporal value.
int Circle::width = 0;
int Circle::height = 0;

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetCircleResolution(32);
    ofSetFrameRate(30);

    width_ = ofGetWidth();
    height_ = ofGetHeight();

		// Set the values as we need.
    Circle::width = width_;
    Circle::height = height_;

    // for (int i = 0; i < 10; i++)
    // {
	// 	Circle* c = new Circle(
    //         ofRandom(width_),
    //         ofRandom(height_),
    //         ofRandom(50, 80),
    //         ofRandom(-5, 5),
    //         ofRandom(-5, 5)
    //     );

	// 	circles.push_back(c);
    // }

	// initialize the variables
	elapsed = startTime = 0.f;
	timeStarted = false;

}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < circles.size(); )
    {
		if (circles.at(i)->isMouseTouched() && ofGetMousePressed())
		{
			delete circles.at(i);
			circles.at(i) = circles.back();
			circles.pop_back();
		}
		else
		{
			circles.at(i)->update();
			i++;
		}
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);

    for (int i = 0; i < circles.size(); i++)
    {
        circles.at(i)->draw();
    }


	ofSetColor(0);
	ofDrawBitmapString("Current number of circles: " + ofToString(circles.size()), 10, 20);

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


	circles.clear();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	// Handle Spacebar press
	if (key == ' ')
	{
		startTime = ofGetElapsedTimef();
		timeStarted = true;

		// This code was moved from setup()
		for (int i = 0; i < 10; i++)
		{
			Circle* c = new Circle(
				ofRandom(width_), ofRandom(height_), // posX, posY
				ofRandom(30, 100), // radius
				ofRandom(-3, 3), ofRandom(-3, 3) // speedX, speedY,
			);

			circles.push_back(c);
		}


	}

}

