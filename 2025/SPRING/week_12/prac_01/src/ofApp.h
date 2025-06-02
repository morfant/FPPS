#pragma once

#include "ofMain.h"
#define NUM 100


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
		float speedX, speedY;
		float posX, posY;
		float radius;
		int lifeSpan;
		float age;


	public:
		static int width;
		static int height;

		Circle() {}

		Circle(float x, float y, float rad)
		{
			posX = x;
			posY = y;
			speedX = 1;
			speedY = 1;
			radius = rad;
			col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
			colChanged = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
		}

		Circle(float x, float y, float vx, float vy, float rad)
		{
			posX = x;
			posY = y;
			speedX = vx;
			speedY = vy;
			radius = rad;
			lifeSpan = radius;
			age = 0;

			col = ofColor(ofRandom(100, 120), ofRandom(180, 200), ofRandom(200, 240), 50);
			colChanged = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
		}


		void update()
		{

			// if (isMouseTouched())
			// {
			// 	hide();
			// } else {
			// 	unHide();
			// }

			// make move
			posX += speedX;
			posY += speedY;

			age += 0.1;
			radius = lifeSpan - age;

			// reappear from the opposite side
			if (posX - radius >= width) { posX = 0 - radius; }
			else if (posX + radius <= 0) { posX = width + radius; }

			if (posY - radius >= height) { posY = 0 - radius; }
			else if (posY + radius <= 0) { posY = height + radius; }

		}

		int toDie()
		{
			if (age > lifeSpan) { return 1; }
			else { return 0; }
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
		vector<Circle*> circles;

};
