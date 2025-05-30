#pragma once

#include "ofMain.h"
#include <vector>
#define NUM_OF_CIRCLE 50

class Shape {
	protected: // move members of Circle to Shape
		ofColor col, col2;

	public:
		Shape() {};

		void hide() { col.a = 0; }
		void unHide() { col.a = 255; }

};

class Circle : public Shape {

	private:
		float posX, posY;
		float radius;

	public:
		Circle() {}; // Default constructor
		Circle(float x, float y, float rad)
		{
			posX = x;
			posY = y;
			radius = rad;
			col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
			col2 = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
		}

		// Setter
		void setRadius(float r) { radius = r; }

		// Getter
		float getRadius() { return radius; }

		void draw()
		{
			// if (isMouseTouched()) { ofSetColor(col2); }
			// else { ofSetColor(col); }

			ofSetColor(col);
			if (isMouseTouched()) { hide(); }
			else { unHide(); }

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
		vector<Circle> circles;

		
};
