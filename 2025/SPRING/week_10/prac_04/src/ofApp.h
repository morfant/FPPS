#pragma once

#include "ofMain.h"
#define NUM 50


class Shape {

	protected:
		ofColor col;
		ofColor colChanged;

		void hide()
		{
			col.a = 0;
			colChanged.a = 0;
		}

		void unHide()
		{
			col.a = 255;
			colChanged.a = 255;
		}

	public:
		Shape() {};

};

class Circle : public Shape {
	private:
		float posX, posY;
		float radius;

	public:
		Circle() {}

		Circle(float x, float y, float rad)
		{
			posX = x;
			posY = y;
			radius = rad;
			col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
			colChanged = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
		}

		void update()
		{
			if (isMouseTouched())
			{
				hide();
			} else {
				unHide();
			}
		}

		void draw()
		{
			ofFill();

			ofSetColor(col);

			// if (isMouseTouched()) 
			// {
			// 	ofSetColor(colChanged);
			// } else {
			// 	ofSetColor(col);
			// }
			ofDrawCircle(posX, posY, radius);
		}

		int isMouseTouched()
		{
			// cout << "isMouseTouched()" << endl;
			float dist = ofDist(posX, posY, ofGetMouseX(), ofGetMouseY());
			if (dist < radius)
			{
				return 1;
			}
			else
			{
				return 0;
			}
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
		Circle circles[NUM];
		
};
