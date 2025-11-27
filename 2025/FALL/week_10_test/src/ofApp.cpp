#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

    width = ofGetWidth();
    height = ofGetHeight();

    ofSetCircleResolution(32);

    ofBackground(255);

    mx = -1;
    my = -1;

    for (int i = 0; i < 50; i++)
    {
        circles[i] = Circle(width * 0.5, height * 0.5, 100);
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (int i = 0; i < 50; i++)
    {
        if (ofGetMousePressed())
        {
            circles[i].setRadius(ofRandom(40, 120));
        }
        circles[i].move();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{

    for (int i = 0; i < 50; i++)
    {
        circles[i].show();
    }

    ofDrawBitmapStringHighlight("FPS: " + ofToString(ofGetFrameRate(), 2), 10, 20);
}

//--------------------------------------------------------------
void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
