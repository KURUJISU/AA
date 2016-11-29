
#include "ofApp.h"


void ofApp::setup() {
	//ofBackground(255, 255, 255);
	ofSetFrameRate(60);

<<<<<<< HEAD
	gui_.setup();

=======
>>>>>>> master
	naviBar_.setup();
}

void ofApp::update() {}

void ofApp::draw() {
<<<<<<< HEAD
	gui_.begin();
  naviBar_.draw();
	gui_.end();
}

void ofApp::keyPressed(int key) {}
=======
  naviBar_.drawNavigationBar();
}

void ofApp::keyPressed(int key) {
	if (key == 's') {
		naviBar_.saveGUI();
	}
	if (key == 'l') {
		naviBar_.loadGUI();
	}
}
>>>>>>> master

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
