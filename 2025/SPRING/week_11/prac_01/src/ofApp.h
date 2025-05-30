#pragma once

#include "ofMain.h"
#define MAX_NUM 20000 

class Dot{

	private:
		float posX, posY;
		float radius;

	public:
		Dot() {};
		Dot(float x, float y, float r)
		{
			posX = x;
			posY = y;
			radius = r;
		}

		void draw()
		{
			ofNoFill();
			ofSetColor(255, 255, 255);
			ofDrawCircle(posX, posY, radius);
		}

		float operator-(Dot other)
		{
			return ofDist(posX, posY, other.posX, other.posY);
		}

		// void operator+ (Dot other)
		// {
		// 	radius = radius + other.radius;
		// }

		Dot operator+ (Dot other)
		{
			return Dot(other.posX + posX, other.posY + posY, radius + other.radius);
		}

		void operator+ (float f)
		{
			radius = radius + f;
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

		Dot* d1;
		Dot* d2;
		Dot d3;

		Dot* dots[MAX_NUM];
		
};
