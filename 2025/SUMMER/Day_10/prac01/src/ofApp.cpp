#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

    ofSetCircleResolution(42);
    ofSetFrameRate(30);

    width = ofGetWidth();
    height = ofGetHeight();

    std::cout << "How many circles? ";
    std::cin >> num;
    circles = new Circle[num];

    for (int i = 0; i < num; i++)
    {
        circles[i] =
            Circle(width * 0.5, height * 0.5, ofRandom(50, 100));
    }
}

//--------------------------------------------------------------
void ofApp::update()
{

    for (int i = 0; i < num; i++)
    {
        circles[i].move();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);

    for (int i = 0; i < num; i++)
    {
        circles[i].show();
    }
}

//--------------------------------------------------------------
void ofApp::exit()
{
    delete[] circles;
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
