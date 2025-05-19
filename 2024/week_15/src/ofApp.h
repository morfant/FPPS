#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
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
    
    ofMesh mesh;
    ofEasyCam cam;
    
    int num_x = 32;
    int num_y = 32;
    float width, height;
    float step_x, step_y;
    
    int gl_mode = 0;
    int prev_gl_mode = -1;
    
    ofPrimitiveMode connectingMode [3] = {
        OF_PRIMITIVE_POINTS,
        OF_PRIMITIVE_LINES,
        OF_PRIMITIVE_TRIANGLES,
    };
    
    string modeNames [3] = {
        "OF_PRIMITIVE_POINTS",
        "OF_PRIMITIVE_LINES",
        "OF_PRIMITIVE_TRIANGLES",
    };
    
};
