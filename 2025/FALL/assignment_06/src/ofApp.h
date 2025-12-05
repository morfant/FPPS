#pragma once

#include "ofMain.h"

class Shape {

protected:
	ofColor col, colTouched;

	// Make alpha 0 to hide
	void hide() {
		col.a = 0;
	}

	// Restore alpha to show
	void unHide() {
		col.a = 180;
	}

public:
	Shape() { };
};

class Circle : public Shape {

private:
	// Circle position and size
	float posX, posY, radius;
	// Movement speed
	float speedX, speedY;
	float radiusSpeed;

public:
	// Create circle with position and radius
	Circle(float x, float y, float rad) {
		posX = x;
		posY = y;
		radius = rad;

		col = ofColor(0, 100, 120, 100);
		colTouched = ofColor(0, 100, 120, 255);

		speedX = ofRandom(-5, 5);
		speedY = ofRandom(-5, 5);
		radiusSpeed = ofRandom(0.2, 1.0);
	};

	Circle() { };

	// Change radius
	void setRadius(float rad) {
		radius = rad;
	}

	// Change color
	void setColor(int r, int g, int b) {
		col = ofColor(r, g, b);
	}

	void move() {
		posX += speedX;
		posY += speedY;

		checkEdge();
	}

	// Separate into independent functions
	void checkEdge() {
		int width = ofGetWidth();
		int height = ofGetHeight();

		if (posX + radius >= width) // Circle hit the RIGHT edge
		{
			posX = width - radius; // Reset position first
			speedX *= -1; // Bounce back
		}

		if (posX - radius <= 0) // Circle hit the LEFT edge
		{
			posX = radius;
			speedX *= -1;
		}

		if (posY + radius >= height) // Circle hit the BOTTOM edge
		{
			posY = height - radius;
			speedY *= -1;
		}

		if (posY - radius <= 0) // Circle hit the TOP edge
		{
			posY = radius;
			speedY *= -1;
		}
	}

	// Draw circle on screen
	void show() {
		ofFill();

		ofSetColor(col);
		if (isMouseTouched() == true) {
			// ofSetColor(colTouched);
			hide();
		} else {
			unHide();
		}

		ofDrawCircle(posX, posY, radius);
	}

	// Check if mouse is inside circle
	bool isMouseTouched() {
		float dist = ofDist(posX, posY, ofGetMouseX(), ofGetMouseY());

		if (dist <= radius) {
			return true;
		} else {
			return false;
		}
	}

	void breath() {
		radius += radiusSpeed;
		if (radius >= 40 || radius <= 10) radiusSpeed *= -1;
	}
};

class ofApp : public ofBaseApp {

public:
	void setup() override;
	void update() override;
	void draw() override;
	void exit() override;

	int width, height;
	int numCircles, numX, numY;
	Circle * circles;
};
