#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

//	Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLFWWindowSettings settings;
    settings.doubleBuffering = false; // 더블 버퍼링 비활성화

	settings.setSize(800, 800);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

}
