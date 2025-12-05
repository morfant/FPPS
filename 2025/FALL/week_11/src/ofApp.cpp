#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	// Number of segments for smoother circles
	ofSetCircleResolution(32);
	// Fix the frame rate
	ofSetFrameRate(30);

	// Store current window size
	width = ofGetWidth();
	height = ofGetHeight();

	// Ask console for number of circles
	std::cout << "How many circles? ";
	std::cin >> numCircles;

	// Allocate circle array
	circles = new Circle[numCircles];

	// Place all circles at screen center
	for (int i = 0; i < numCircles; i++) {
		circles[i] = Circle(width * 0.5, height * 0.5, 100);
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	// On mouse press, randomize radius
	if (ofGetMousePressed()) {
		for (int i = 0; i < numCircles; i++) {
			circles[i].setRadius(ofRandom(50, 100));
		}
	}

	// Move every circle
	for (int i = 0; i < numCircles; i++) {
		circles[i].move();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	// Fill background white
	ofBackground(255, 255, 255);

	// Draw all circles
	for (int i = 0; i < numCircles; i++) {
		circles[i].show();
	}

	ofDrawBitmapStringHighlight(
		"FPS: " + ofToString(ofGetFrameRate(), 2), 10, 20);
}


//--------------------------------------------------------------
void ofApp::exit() {
	// Free allocated memory
	delete[] circles;
}
