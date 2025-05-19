#include "ofApp.h"

int Particle::width = 0;
int Particle::height = 0;

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
	ofSetCircleResolution(40);
	ofSetFrameRate(60);

	WIDTH = ofGetWidth();
	HEIGHT = ofGetHeight();

	Particle::width = WIDTH;
	Particle::height = HEIGHT;

	for (int i = 0; i < 15000; i++)
	{
		int rx = ofRandom(WIDTH);
		int ry = ofRandom(HEIGHT);
		float rr = ofRandom(1, 5);
		auto pat = make_shared<Particle>(rx, ry, rr);
		particles.push_back(pat);
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	//for (shared_ptr<Particle> p : particles)
	//{
	//	p->update();
	//}

	//for (vector<shared_ptr<Particle>>::iterator it = particles.begin();)
	/*for (auto it = particles.begin(); it != particles.end();)
	{
		if ((*it)->toDie())
		{
			it = particles.erase(it);
		}
		else
		{
			(*it)->update();
			it++;
		}
	}*/

	for (int i = 0; i < particles.size();)
	{
		auto p = particles[i];
		if (p->toDie())
		{
			particles[i] = particles.back();
			particles.pop_back();
		}
		else
		{
			p->update();
			++i;
		}
	}


}

//--------------------------------------------------------------
void ofApp::draw(){

	for (auto p : particles)
	{
		p->draw();
	}

	string str = "Number of particles: " + to_string(particles.size());
	ofSetColor(255, 0, 100);
	ofDrawBitmapString(str, 100, 100);

}

//--------------------------------------------------------------
void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (button == 0)
	{
		float rr = ofRandom(2, 10);
		shared_ptr<Particle> pat = make_shared<Particle>(x, y, rr);
		particles.push_back(pat);
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 0)
	{
		float rr = ofRandom(2, 10);
		shared_ptr<Particle> pat = make_shared<Particle>(x, y, rr);
		particles.push_back(pat);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
