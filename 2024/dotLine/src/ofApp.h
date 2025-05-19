#pragma once

#include "ofMain.h"
#include "Line.h"
#define MAX_LINE_NUM 2000

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

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

		//Line lines[MAX_LINE_NUM];
		unique_ptr<Line[]> lines = make_unique<Line[]>(MAX_LINE_NUM); // �迭 ��ü�� ����Ʈ ������
		//unique_ptr<Line>[] lines; // ����Ʈ �����͵��� ä���� �迭 ����
		int WIDTH, HEIGHT;
		
};
