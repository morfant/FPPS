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
	std::cout << "How many circles? (column row) ";
	std::cin >> numX >> numY;

	// Allocate circle array
	numCircles = numX * numY;
	circles = new Circle[numCircles];

	int index = 0;
	for (int y = 0; y < numY; y++) {
		for (int x = 0; x < numX; x++) {
			float posX = x * 80; // horizontal interval
			float posY = y * 80; // vertical interval
			circles[index] = Circle(posX, posY, ofRandom(10, 40));
			index++;
		}
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	for (int i = 0; i < numCircles; i++) {
		if (ofGetMousePressed()) {
			circles[i].move();
		} else {
			circles[i].breath();
		}
	}

	// Move every circle
	// for (int i = 0; i < numCircles; i++) {
	// circles[i].move();
	// }
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
