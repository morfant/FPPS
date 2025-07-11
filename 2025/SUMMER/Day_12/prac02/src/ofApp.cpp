#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // Set the resolution of the circles (how smooth the edge is)
    ofSetCircleResolution(42);

    // Set the frame rate to 30 frames per second
    ofSetFrameRate(30);

    // Get the screen width and height
    width = ofGetWidth();
    height = ofGetHeight();

    for (int i = 0; i < 10; i++)
    {
        circles.push_back(
            Circle(width * 0.5, height * 0.5, ofRandom(10, 60))
        );
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    // Adding
    if(ofGetMousePressed(OF_MOUSE_BUTTON_LEFT))
    {
        bool isAnythingTouched = false;
        for (int i = 0; i < circles.size(); i++)
        {
            if (circles[i].isMouseTouched() == true)
            {
                isAnythingTouched = true;
                break;
            }
        }

        if (isAnythingTouched == false)
        {
            circles.push_back(Circle(ofGetMouseX(), ofGetMouseY(), ofRandom(10, 60)));
        }

    }

    // Removing
    for (int i = 0; i < circles.size();)
    {
        if (circles[i].isMouseTouched() && ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT))
        {
            circles[i] = circles.back();
            circles.pop_back();
        }
        else 
        {
            circles[i].move();
            i++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    // Set background color to black
    ofBackground(0);

    // Draw all the circles
    for (int i = 0; i < circles.size(); i++)
    {
        circles[i].show();
    }

    ofDrawBitmapString("circles: " + to_string(circles.size()), 30, 30);
}

//--------------------------------------------------------------
void ofApp::exit()
{

}