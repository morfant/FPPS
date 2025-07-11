#pragma once

#include "ofMain.h"
#include <vector>


class Rectt {

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
		ofSetColor(100, 100, 200);
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

		std::vector<Rectt> rectts;

		
};
