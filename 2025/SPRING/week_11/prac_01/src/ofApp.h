#pragma once

#include "ofMain.h"

class Dot {
	private:
		float posX, posY;
		float radius;

	public:
		Dot() {}

		Dot(float x, float y, float rad)
		{
			posX = x;
			posY = y;
			radius = rad;
		}

		void draw()
		{
			ofFill();
			ofSetColor(255);
			ofDrawCircle(posX, posY, radius);
		}

		// d1 + d2
		Dot operator+ (Dot other)
		{
			return Dot(
				(posX + other.posX) / 2,
				(posY + other.posY) / 2,
				radius + other.radius
			);
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

		Dot d1;
		Dot d2;
};
