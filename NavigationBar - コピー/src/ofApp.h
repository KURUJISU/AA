
#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"


class ofApp : public ofBaseApp {
private:
  ofxXmlSettings xml_;

  //テキスト
  ofTrueTypeFont font_;
  string naviText1_;
  string naviText2_;
  ofVec2f textPos_ = ofVec2f(100, 70);
  ofVec2f defaultPos_= ofVec2f(100, 70);
  ofVec2f startPos_ = ofVec2f(ofGetWindowWidth(), 70);
  ofVec2f endPos_ = ofVec2f(-ofGetWindowWidth(), 70);

  //画像
  string mainBarFilename_;
  string sideBarFilename_;
  ofImage mainBarImage_;
  ofImage sideBarImage_;

  //フォント
  string fontFilename_;
  float fontSize_ = 50;

  //
  int count_ = 0;
  int waitTime_ = 60 * 10;
  int textSwitch_ = -1;
  int moveSwitch_ = 0;
  float moveValue_ = -15;

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

};
