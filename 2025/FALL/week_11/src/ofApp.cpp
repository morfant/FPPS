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

	// Allocate circle array

	for (int i = 0; i < 10; i++)
	{
		Circle c = Circle(width * 0.5, height * 0.5, 100);
		circles.push_back(c);
	}


	// circles = new Circle[total];

	// for (int i = 0; i < numCirclesGreen; i++)
	// {
	// 	circles[i] = Circle(width * 0.5, height * 0.5, 100);
	// 	circles[i].setColor(10, 180, 50);
	// }

	// for (int i = numCirclesGreen; i < total; i++)
	// {
	// 	circles[i] = Circle(width * 0.5, height * 0.5, 100);
	// 	circles[i].setColor(10, 50, 200);
	// }

	// for (int i = 0; i < total; i++) {
	// 	int a = (int)ofRandom(total) % total;
	// 	int b = (int)ofRandom(total) % total;
	// 	Circle tmp = circles[a];
	// 	circles[a] = circles[b];
	// 	circles[b] = tmp;
	// }
}

//--------------------------------------------------------------
void ofApp::update() {

	// On mouse press, randomize radius
	// if (ofGetMousePressed()) {
	// 	for (int i = 0; i < circles.size(); i++) {
	// 		circles.at(i).setRadius(ofRandom(50, 100));
	// 	}

	// 	// for (int i = 0; i < numCirclesBlue; i++) {
	// 	// 	circlesBlue[i].setRadius(ofRandom(50, 100));
	// 	// }
	// }

	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT))
	{
		bool isAnyCircleTouched = false;
		for (int i = 0; i < circles.size(); i++)
		{
			if (circles.at(i).isMouseTouched() == true)
			{
				isAnyCircleTouched = true;
				break;
			}
		}

		if (isAnyCircleTouched == false)
		{
			Circle c = Circle(ofGetMouseX(), ofGetMouseY(), 100);
			circles.push_back(c);
		}
	}

	if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) 
	{
		for (int i = 0; i < circles.size();)
		{
			if (circles.at(i).isMouseTouched() == true)
			{
				circles.at(i) = circles.back();
				circles.pop_back();
			} else {
				i++;
			}
		}
	}

	for (int i = 0; i < circles.size(); i++) {
		circles.at(i).move();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	// Fill background white
	ofBackground(255, 255, 255);

	// Draw all circles
	for (int i = 0; i < circles.size(); i++) {
		circles.at(i).show();
	}

	// for (int i = 0; i < numCirclesBlue; i++) {
	// 	circlesBlue[i].show();
	// }



	ofDrawBitmapStringHighlight(
		"FPS: " + ofToString(ofGetFrameRate(), 2), 10, 20);

	ofDrawBitmapStringHighlight(
		"The number of circles: " + ofToString(circles.size()), 10, 40);
}

//--------------------------------------------------------------
void ofApp::exit() {
	// Free allocated memory
	// delete[] circles;
	// delete[] circlesGreen;
	// delete[] circlesBlue;
}
