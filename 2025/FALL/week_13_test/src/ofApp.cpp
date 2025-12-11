#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

    ofSetFrameRate(30);

    width = ofGetWidth();
    height = ofGetHeight();
    isReleased = true;

    // rect = Square(width * 0.2, height * 0.2, 100, 100);
}

//--------------------------------------------------------------
void ofApp::update()
{

    if (ofGetMousePressed() && isReleased == true)
    {
        Square sq = Square(ofGetMouseX(), ofGetMouseY(), 100, 100);
        rects.push_back(sq);
        isReleased = false;
    }

    if (!ofGetMousePressed())
    {
        isReleased = true;
    }


}

//--------------------------------------------------------------
void ofApp::draw()
{

    ofBackground(255);

    for (int i = 0; i < rects.size(); i++)
    {
        rects.at(i).show();
    }

    ofDrawBitmapStringHighlight(
        "The number of squares: " + ofToString(rects.size()),
        10, 20);
}

//--------------------------------------------------------------
void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

    if (key == ' ')
    {
        rects.clear();
    }
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
