#pragma once

#include "ofMain.h"

class Shape {

protected:
	ofColor col, colTouched;

	void hide()
	{
		col.a = 0;
	}

	void unHide()
	{
		col.a = 255;
	}

public:
	Shape() { };
};


class Circle : public Shape {

private:
	// member variables
	float posX, posY, radius;
	float speedX, speedY;

public:
	// constructor
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


	// member functions
	void setRadius(float rad) {
		radius = rad;
	}

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

	int width, height;
	Circle cir1;
};
