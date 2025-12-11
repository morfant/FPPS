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
	std::cout << "How many green circles? ";
	std::cin >> numCirclesGreen;

	std::cout << "How many blue circles? ";
	std::cin >> numCirclesBlue;

	total = numCirclesGreen + numCirclesBlue;

	// Allocate circle array
	circles = new Circle[total];

	for (int i = 0; i < numCirclesGreen; i++)
	{
		circles[i] = Circle(width * 0.5, height * 0.5, 100);
		circles[i].setColor(10, 180, 50);
	}

	for (int i = numCirclesGreen; i < total; i++)
	{
		circles[i] = Circle(width * 0.5, height * 0.5, 100);
		circles[i].setColor(10, 50, 200);
	}

	for (int i = 0; i < total; i++) {
		int a = (int)ofRandom(total) % total;
		int b = (int)ofRandom(total) % total;
		Circle tmp = circles[a];
		circles[a] = circles[b];
		circles[b] = tmp;
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	// On mouse press, randomize radius
	if (ofGetMousePressed()) {
		for (int i = 0; i < total; i++) {
			circles[i].setRadius(ofRandom(50, 100));
		}

		// for (int i = 0; i < numCirclesBlue; i++) {
		// 	circlesBlue[i].setRadius(ofRandom(50, 100));
		// }
	}

	// Move every circle
	// for (int i = 0; i < numCirclesGreen; i++) {
	// 	circlesGreen[i].move();
	// }

	for (int i = 0; i < total; i++) {
		circles[i].move();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	// Fill background white
	ofBackground(255, 255, 255);

	// Draw all circles
	for (int i = 0; i < total; i++) {
		circles[i].show();
	}

	// for (int i = 0; i < numCirclesBlue; i++) {
	// 	circlesBlue[i].show();
	// }



	ofDrawBitmapStringHighlight(
		"FPS: " + ofToString(ofGetFrameRate(), 2), 10, 20);
}

//--------------------------------------------------------------
void ofApp::exit() {
	// Free allocated memory
	delete[] circles;
	// delete[] circlesGreen;
	// delete[] circlesBlue;
}
