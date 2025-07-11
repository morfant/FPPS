#pragma once

#include "ofMain.h"

//---------------------------------------------
// Base class for shapes
class Shape {
protected:
	ofColor col, colTouched; // color of the shape and color when touched

	// Make the shape invisible by setting alpha to 0
	void hide()
	{
		col.a = 0;
	}

	// Make the shape visible by setting alpha to 255
	void unhide()
	{
		col.a = 255;
	}

public:
	Shape() {};
};

//---------------------------------------------
// Circle class that inherits from Shape
class Circle : public Shape {

private:
	float posX, posY;      // position of the circle
	float radius;          // radius of the circle
	float speedX, speedY;  // movement speed in X and Y

public:
	// Default constructor
	Circle () {};

	// Constructor with initial position and radius
	Circle (float x, float y, float rad)
	{
		posX = x;
		posY = y;
		radius = rad;

		// Random speed between -5 and 5
		speedX = ofRandom(-5, 5);
		speedY = ofRandom(-5, 5);

		// Random base color
		col = ofColor(100, ofRandom(200), 150);

		// Color when touched (not used directly in current code)
		colTouched = ofColor(0, 100, 200);
	};

	// Setter for radius
	void setRadius(float rad)
	{
		radius = rad;
	}

	// Draw the circle on screen
	void show()
	{
		ofSetColor(col);

		// Hide the circle if mouse is touching it
		// if (isMouseTouched()) { hide(); }
		// else { unhide(); }

		ofDrawCircle(posX, posY, radius);
	}

	// Update the position of the circle
	void move()
	{
		posX += speedX;
		posY += speedY;

		// Bounce off the left/right walls
		if (posX + radius >= ofGetWidth() || posX - radius <= 0)
		{
			speedX *= -1;
		}

		// Bounce off the top/bottom walls
		if (posY + radius >= ofGetHeight() || posY - radius <= 0)
		{
			speedY *= -1;	
		}
	}

	// Check if the mouse is touching the circle
	bool isMouseTouched()
	{
		// Calculate the distance between the mouse and the circle center
		float dist = ofDist(posX, posY, ofGetMouseX(), ofGetMouseY());

		// Return true if distance is less than radius
		return (dist <= radius);
	}
};

//---------------------------------------------
// Main application class
class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		int width, height;     // screen dimensions
		int num;               // number of circles

		vector<Circle> circles;
};