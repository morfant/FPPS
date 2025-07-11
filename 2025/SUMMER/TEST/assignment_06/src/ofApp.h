#pragma once

#include "ofMain.h"
#include <vector>

class Circle {

private:
	float posX, posY;
	float radius;
	ofColor col;
	bool isFilled;

public:
	Circle() {};
	Circle(float x, float y, float rad)
	{
		posX = x;
		posY = y;
		radius = rad;
		col = ofColor(50, 100, 200);
		isFilled = false;
	}

	void toggleIsFilled()
	{
		if (isFilled == true) { isFilled = false;
		} else { isFilled = true; }

		// isFilled = !isFilled;
	}

	void show()
	{
		ofSetColor(col);
		if (!isFilled) { ofNoFill(); }
		else { ofFill(); }
		ofDrawCircle(posX, posY, radius);
	}

	bool isMouseTouched(float ex, float ey)
	{
		float dist = ofDist(posX, posY, ex, ey);
		if (dist > radius) { return false; }
		return true;
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

		vector<Circle> circles;
		bool isMouseReleased;
		
};
