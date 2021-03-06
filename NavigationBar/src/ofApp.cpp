
#include "ofApp.h"


void ofApp::setup() {
	//ofBackground(255, 255, 255);
	ofSetFrameRate(60);

	gui_.setup();

	naviBar_.setup();
}

void ofApp::update() {}

void ofApp::draw() {
	gui_.begin();
  naviBar_.draw();
	naviBar_.drawGui();
	gui_.end();
}

void ofApp::keyPressed(int key) {}

void ofApp::keyReleased(int key) {}

void ofApp::mouseMoved(int x, int y) {}

void ofApp::mouseDragged(int x, int y, int button) {}

void ofApp::mousePressed(int x, int y, int button) {}

void ofApp::mouseReleased(int x, int y, int button) {}

void ofApp::mouseEntered(int x, int y) {}

void ofApp::mouseExited(int x, int y) {}

void ofApp::windowResized(int w, int h) {}

void ofApp::gotMessage(ofMessage msg) {}

void ofApp::dragEvent(ofDragInfo dragInfo) {}
