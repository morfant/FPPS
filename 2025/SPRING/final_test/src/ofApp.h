#pragma once

#include "ofMain.h"

class Circle {
	private:
		float posX, posY;
		float radius;
		ofColor col;

	public:
		Circle() {};
		Circle(float x, float y, float rad)
		{
			posX = x;
			posY = y;
			radius = rad;
			col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
		}

		void draw()
		{
			ofSetColor(col);
			ofDrawCircle(posX, posY, radius);
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


		vector<Circle*> circles;

};
