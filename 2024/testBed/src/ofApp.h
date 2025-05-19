#pragma once

#include "ofMain.h"
#include <memory>

class Shape {
private:
    int colors[5] = {0xffbe0b, 0xfb5607, 0xff006e, 0x8338e, 0xa86ff};
    
protected:
    int r = ofRandom(4);
    ofColor col = ofColor::fromHex(colors[r]);

public:
    void changeColor()
    {
        int r = ofRandom(4);
        col = ofColor::fromHex(colors[r]);
    };
};


class Circle : public Shape {
    
private:
    float x, y;
    float velX, velY;
    float radius;
    bool isMouseOn = false;
    
public:
    static int WIDTH, HEIGHT;
    
    Circle(){};
    Circle(float _x, float _y, float _r)
    {
        x = _x;
        y = _y;
        radius = _r;
        velX = ofRandom(-4, 4);
        velY = ofRandom(-4, 4);
    }
    
    void checkMouseOn()
    {
        float distToMouse = ofDist(x, y, ofGetMouseX(), ofGetMouseY());
        if (distToMouse > radius) isMouseOn = false;
        else isMouseOn = true;
    }
     
    void update()
    {
        x = x + velX;
        y = y + velY;
        
        if (x - radius > WIDTH) x = 0;
        else if (x + radius < 0) x = WIDTH;
        
        if (y - radius > HEIGHT) y = 0;
        else if (y + radius < 0) y = HEIGHT;
        
        checkMouseOn();
    }
    
    void draw()
    {
        if (isMouseOn) ofSetColor(ofColor::gray);
        else ofSetColor(col);
        ofDrawCircle(x, y, radius);
    }
    
};



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        const int NUM_CIRCLES = 100;
        vector<unique_ptr<Circle>> circles;
    
        int w, h;

//        Circle c1 = Circle(300, 300, 100); // OK, Copy Initialization
//        Circle c2 = Circle(300, 300, 100); // OK, Copy Initialization
//        Circle c1(300, 100, 100); // ERROR, Cannot use in member variable initialization
    
//        Circle* c2 = new Circle(300, 300, 100);
//        Circle* c3 = new Circle(200, 400, 50);
//
//        unique_ptr<Circle> c4 = make_unique<Circle>(400, 500, 40);
//        unique_ptr<Circle> c5 = make_unique<Circle>(400, 500, 40);

};
