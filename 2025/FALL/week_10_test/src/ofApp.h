#pragma once

#include "ofMain.h"

class Shape
{
protected:
	ofColor col;
	ofColor colTouched;

public:
	Shape() {};

	void hide()
	{
		col.a = 0;
	}

	void unHide()
	{
		col.a = 100;
	}
};

class Circle : public Shape
{

private:
	// member variables
	float posX, posY;
	float speedX, speedY;
	float radius;

public:
	// Constructor we will use
	Circle(float x, float y, float r)
	{
		posX = x;
		posY = y;
		radius = r;

		speedX = ofRandom(-3, 3);
		speedY = ofRandom(-3, 3);

		col = ofColor(0, 100, ofRandom(120), 100);
		colTouched = ofColor(0, 100, 120, 255);
	}

	// Default constructor
	Circle() {};

	// member functions
	void setRadius(float rad)
	{
		radius = rad;
	}

	void move()
	{
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


	void show()
	{
		if (isMouseTouched() == true)
		{
			// ofSetColor(colTouched);
			hide();
		}
		else
		{
			unHide();
		}

		ofSetColor(col);
		ofFill();
		ofDrawCircle(posX, posY, radius);
	};

	bool isMouseTouched()
	{
		float dist = ofDist(posX, posY, ofGetMouseX(), ofGetMouseY());

		if (dist <= radius)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class ofApp : public ofBaseApp
{

public:
	void setup() override;
	void update() override;
	void draw() override;
	void exit() override;

	void keyPressed(int key) override;
	void keyReleased(int key) override;
	void mouseMoved(int x, int y) override;
	void mouseDragged(int x, int y, int button) override;
	void mousePressed(int x, int y, int button) override;
	void mouseReleased(int x, int y, int button) override;
	void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
	void mouseEntered(int x, int y) override;
	void mouseExited(int x, int y) override;
	void windowResized(int w, int h) override;
	void dragEvent(ofDragInfo dragInfo) override;
	void gotMessage(ofMessage msg) override;

	int width, height;
	int mx, my;

	// Circle cir1;
	Circle circles[50];
};
