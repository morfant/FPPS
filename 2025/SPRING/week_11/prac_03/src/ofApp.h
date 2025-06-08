#pragma once

#include "ofMain.h"
#define NUM_OF_CIRCLE 50

class Shape {
	protected:
		ofColor col, col2;

	public:
		Shape() {};

		void hide() { col.a = 0; }
		void unHide() { col.a = 255; }

};

class Circle : public Shape {

	private:
		// member variables
		float posX, posY;
		float radius;
		float speedX, speedY;

	public:
		// static member variables in public area
		// You should define them outside of the class.
		static int width;
		static int height;

		// Default constructor
		Circle() {};

		// Constructor 2
		// Constructor overloading
		Circle(float x, float y, float rad)
		{
			posX = x;
			posY = y;
			radius = rad;
			col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
			col2 = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
		}

		// Constructor 3
		// Constructor overloading
		Circle(float x, float y, float rad, float spdX, float spdY)
		{
			posX = x;
			posY = y;
			radius = rad;
			speedX = spdX;
			speedY = spdY;
			col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
			col2 = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
		}

		// Setter
		void setRadius(float r) { radius = r; }

		// Getter
		float getRadius() { return radius; }


		// member functions
		void update()
		{
			// This will make the object move
			posX += speedX;
			posY += speedY;


			// Reset the circle's position

			// when it goes beyond the right edge of the canvas. (➡️)
			if (posX - radius >= width) { posX = 0 - radius; }

			// when it goes beyond the left edge of the canvas. (⬅️)
			else if (posX <= 0 - radius) { posX = width + radius; }

			// when it goes beyond the bottom edge of the canvas. (⬇️)
			if (posY - radius >= height) { posY = 0 - radius; }

			// when it goes beyond the top edge of the canvas. (⬆️)
			else if (posY <= 0 - radius) { posY = height + radius; }

		}

		void draw()
		{
			ofSetColor(col);
			ofDrawCircle(posX, posY, radius);
		}

		int isMouseTouched()
		{
			float dist = ofDist(posX, posY, ofGetMouseX(), ofGetMouseY());
			if (dist < radius) { return 1; }
			else { return 0; }
		}

};


class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;
		void keyPressed(int key) override;

		int width_, height_;
		// Circle* circles[NUM_OF_CIRCLE]; // Static array

		vector<Circle*> circles;


		// variables for timer
		float startTime, elapsed;
		bool timeStarted;

};
