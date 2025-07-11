#pragma once

#include "ofMain.h"

class Shape{
protected:
	ofColor col;
	ofColor colTouched;

	void hide()
	{
		col.a = 0;
		colTouched.a = 0;
	}

	void unhide()
	{
		col.a = 255;
		colTouched.a = 255;
	}

public:
	Shape() {};

};


class Circle : public Shape{

private:
	float posX, posY;
	float radius;
	float radiusSpeed;
	float speedX, speedY;


public:
	Circle() {};
	Circle(float x, float y, float r)
	{
		posX = x;
		posY = y;
		radius = r;
		radiusSpeed = ofRandom(-1, 1);
		speedX = ofRandom(-5, 5);
		speedY = ofRandom(-5, 5);
		col = ofColor(100, ofRandom(150, 200), 200);
		colTouched = ofColor(0, 100, 200);
	}

	// Getter / Setter
	float getRadius()
	{
		return radius;
	}

	void setRadius(float r)
	{
		radius = r;
	}

	// member function
	void show()
	{
		ofSetColor(col);

		// if (isMouseTouched()) 
		// {
		// 	// ofSetColor(colTouched);
		// 	hide();
		// }
		// else
		// {
		// 	unhide();
		// }

		ofDrawCircle(posX, posY, radius);

	}

	void move()
	{
		posX += speedX;
		posY += speedY;

		checkEdge();
	}

	void checkEdge()
	{
		int width = ofGetWidth();
		int height = ofGetHeight();

		if (posX + radius >= width)
		{
			posX = width - radius;
			speedX *= -1;
		}

		if (posX - radius <= 0)
		{
			posX = radius;
			speedX *= -1;
		}

		if (posY + radius >= height)
		{
			posY = height - radius;
			speedY *= -1;
		}


		if (posY - radius <= 0)
		{
			posY = radius;
			speedY *= -1;
		}

	}

	void breath()
	{
		radius += radiusSpeed;
		if (radius >= 60 || radius <= 10) radiusSpeed *= -1;
	}


	bool isMouseTouched()
	{
		float dist = ofDist(posX, posY, ofGetMouseX(), ofGetMouseY());
		if (dist > radius) { return false;
		} else { return true; }
	}


};
class Rectt{
private:
	float posX, posY;
	float width, height;

public:
	Rectt() {};
	Rectt(float x, float y, float w, float h)
	{
		posX = x;
		posY = y;
		width = w;
		height = h;
	}

	void show()
	{
		float dist = ofDist(ofGetMouseX(), ofGetMouseY(), posX, posY);
		ofSetColor(255 * (dist / 1000));
		ofDrawRectangle(posX, posY, width, height);
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
		bool isObjectCreated;

		vector<Circle> circles;
		
};
