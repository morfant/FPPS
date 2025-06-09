// ofApp.cpp
#include "ofApp.h"

// define static member variables with temporal value.
int Circle::width = 0;
int Circle::height = 0;

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetCircleResolution(32);
    ofSetFrameRate(30);

    width_ = ofGetWidth();
    height_ = ofGetHeight();

	// Set the values as we need.
    Circle::width = width_;
    Circle::height = height_;

    for (int i = 0; i < 10; i++)
    {
        Circle* c = new Circle(
            ofRandom(width_), ofRandom(height_),
            ofRandom(50, 80),
            ofRandom(-5, 5), ofRandom(-5, 5)
        );

        circles.push_back(c);
    }


}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < circles.size(); )
    {
        if (circles.at(i)->isMouseTouched() && ofGetMousePressed())
        {
            delete circles.at(i);

            circles.at(i) = circles.back();
            circles.pop_back();
        }
        else
        {
            // circles[i]->update();
            circles.at(i)->update();
            i++;
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);

    for (int i = 0; i < circles.size(); i++)
    {
        // circles[i]->draw();
        circles.at(i)->draw();
    }

}


//--------------------------------------------------------------
void ofApp::exit(){

    for (int i = 0; i < circles.size(); i++)
    {
        // delete circles[i];
        delete circles.at(i);
    }

    circles.clear();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}