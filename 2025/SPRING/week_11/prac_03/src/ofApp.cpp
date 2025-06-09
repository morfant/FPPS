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

    for (int i = 0; i < NUM_OF_CIRCLE; i++)
    {
		circles[i] = new Circle(
            ofRandom(width_), ofRandom(height_),
            ofRandom(50, 80),
            ofRandom(-5, 5), ofRandom(-5, 5)
        );
    }

}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < NUM_OF_CIRCLE; i++)
    {
		circles[i]->update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);

    for (int i = 0; i < NUM_OF_CIRCLE; i++)
    {
        circles[i]->draw();
    }

}

//--------------------------------------------------------------
void ofApp::exit(){


    for (int i = 0; i < NUM_OF_CIRCLE; i++)
    {
		delete circles[i];
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){



}

