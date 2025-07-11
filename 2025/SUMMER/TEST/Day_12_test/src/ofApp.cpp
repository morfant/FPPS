#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetCircleResolution(42);
    ofSetFrameRate(30);
    width = ofGetWidth();
    height = ofGetHeight();

    // cout << "How many circles do you want? ";
    // cin >> num;
    // circles = new Circle[num];
    // for (int i = 0; i < num; i++)
    // {
    //     circles[i] = Circle(width * 0.5, height * 0.5, ofRandom(30, 60));
    // }

    cout << "How many circles? (x y) ";
    cin >> numX >> numY;

    len = numX * numY;
    circles = new Circle[len];

    int index = 0;
    for (int y = 0; y < numY; y++)
    {
        for (int x = 0; x < numX; x++)
        {
            circles[index] = Circle(x * 40, y * 40, ofRandom(10, 30));
            index++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (int i = 0; i < len; i++)
    {
        if (ofGetMousePressed()) circles[i].move();
        circles[i].breath();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);

    for (int i = 0; i < len; i++)
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
