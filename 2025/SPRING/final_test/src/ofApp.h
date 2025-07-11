#pragma once

#include "ofMain.h"

class Circle {
private:
	int posX, posY, radius;
	ofColor col;
	int sx, sy;

public:
	Circle() { };
	Circle(int x, int y, int r, ofColor c) {
		posX = x;
		posY = y;
		radius = r;
		col = c;
		sx = ofRandom(-2, 2);
		sy = ofRandom(-2, 2);
	}

	void draw() {		
		col.a = 15;
		ofSetColor(col);
		for (int i = 0; i < radius; i++) {
			ofDrawCircle(posX, posY, i);
		}
	}

	
	void update() {
		posX += sx;
		posY += sy;

		if (posX > ofGetWidth() || posX < 0) {
			sx *= -1;
		}
		if (posY > ofGetHeight() || posY < 0) {
			sy *= -1;
		}
	}


};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void exit();

	vector<Circle *> circles;
};
