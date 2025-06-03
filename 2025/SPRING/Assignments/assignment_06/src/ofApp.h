#pragma once

#include "ofMain.h"

class ConcentricCircle{
	private:
		float posX, posY;
		float radius;
		int numOfCircles;
		ofColor col;

	public:

		ConcentricCircle() {};
		ConcentricCircle(float x, float y, float rad)
		{
			posX = x;
			posY = y;
			radius = rad;
			numOfCircles = radius / 4;
			col = ofColor(0, ofRandom(100, 120), ofRandom(150, 180));
		}

		void draw()
		{
			col.a = 40;
			ofSetColor(col);

			float step = radius / numOfCircles;
			for (int i = 0; i < numOfCircles; i++)
			{
				ofDrawCircle(posX, posY, (i + 1) * step);
			}
		}


		// Setter
		void setPosX(float x)
		{
			posX = x;
		}

		void setPosY(float y)
		{
			posY = y;
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


		ConcentricCircle cc;

};
