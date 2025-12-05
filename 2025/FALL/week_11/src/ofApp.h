#pragma once

#include "ofMain.h"
#define NUM_CIRCLE 100

class Shape {

protected:
	ofColor col, colTouched;

	// Make alpha 0 to hide
	void hide()
	{
		col.a = 0;
	}

	// Restore alpha to show
	void unHide()
	{
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

	};

	Circle() { };


	// Change radius
	void setRadius(float rad) {
		radius = rad;
	}

	// Change color
	void setColor(int r, int g, int b)
	{
		col = ofColor(r, g, b);
	}

	// Move using speed
	void move() {
		posX = posX + speedX;
		posY = posY + speedY;

		if (posX - radius <= 0 || posX + radius >= ofGetWidth())
		{
			speedX = speedX * -1;
		}

		if (posY - radius <= 0 || posY + radius >= ofGetHeight())
		{
			speedY = speedY * -1;
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
};

class ofApp : public ofBaseApp {

public:
	void setup() override;
	void update() override;
	void draw() override;
	void exit() override;

	int width, height;
	int numCircles;
	Circle* circles;

};
