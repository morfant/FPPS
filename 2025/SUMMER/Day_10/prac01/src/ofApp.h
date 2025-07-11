#pragma once

#include "ofMain.h"

class Shape {
protected:
	ofColor col, colTouched;

	void hide()
	{
		col.a = 0;
	}

	void unhide()
	{
		col.a = 255;
	}

public:
	Shape() {};

};



class Circle : public Shape {

private:
	float posX, posY;
	float radius;	
	float speedX, speedY;

public:
	Circle () {};
	Circle (float x, float y, float rad)
	{
		posX = x;
		posY = y;
		radius = rad;
		speedX = ofRandom(-5, 5);
		speedY = ofRandom(-5, 5);
		col = ofColor(100, ofRandom(200), 150);
		colTouched = ofColor(0, 100, 200);
	};

	// Setter
	void setRadius(float rad)
	{
		radius = rad;
	}

	// member function
	void show()
	{
		ofSetColor(col);
		if (isMouseTouched()) { hide(); }
		else { unhide(); }
		ofDrawCircle(posX, posY, radius);
	}

	void move()
	{
		posX = posX + speedX;
		posY = posY + speedY;

		// along x-axis
		if (posX + radius >= ofGetWidth())
		{
			speedX = speedX * -1;
		}

		if (posX - radius <= 0)
		{
			speedX = speedX * -1;
		}

		// along y-axis
		if (posY + radius >= ofGetHeight())
		{
			speedY = speedY * -1;
		}

		if (posY - radius <= 0)
		{
			speedY = speedY * -1;	
		}
	}

	bool isMouseTouched()
	{
		float dist = ofDist(
			posX, posY,
			ofGetMouseX(), ofGetMouseY()
		);

		if (dist > radius) { return false; }
		else { return true; }
	}

};



class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
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
		int num;
		Circle* circles;
		
};





