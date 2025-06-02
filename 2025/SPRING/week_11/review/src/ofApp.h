#pragma once

#include "ofMain.h"
#define NUM_OF_CCS 50

class ConcentricCircle {
	private:
		float posX, posY;
		float radius;
		ofColor col;
		int numOfCircles;
		int fillMode;

	public:
		ConcentricCircle() {};
		ConcentricCircle(float x, float y, float r)
		{
			posX = x;
			posY = y;
			radius = r;
			col = ofColor(
				ofRandom(255),
				ofRandom(255),
				ofRandom(255)
			);

			numOfCircles = radius / 8;
		};

		// Setter
		void setFillMode(int m)
		{
			fillMode = m;
		}

		void draw()
		{
			if (fillMode)
			{
				ofFill();
				col.a = 40;
				ofSetColor(col);
			}
			else 
			{
				ofNoFill();
				col.a = 255;
				ofSetColor(col);
			}

			float step = radius / numOfCircles;
			for (int i = 0; i < numOfCircles; i++)
			{
				ofDrawCircle(posX, posY, (i + 1) * step);
			}
		}

}; // Don't forget this!


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

		// ConcentricCircle cc;
		int width, height;

		ConcentricCircle ccs[NUM_OF_CCS];
		
};
