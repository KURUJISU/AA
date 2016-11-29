
#pragma once


#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxImGui.h"


class NavigationBar {
private:
  ofxXmlSettings xml_;

  //テキスト
  ofTrueTypeFont font_;
  string naviText_[2];
  ofVec2f textPos_;
  ofVec2f defaultPos_;

  //画像
  string mainBarFilename_;
  string sideBarFilename_;
  ofImage mainBarImage_;
  ofImage sideBarImage_;
  ofVec2f barPos_;
  ofVec2f barSize_;

  //フォント
  string fontFilename_;
  float fontScale_;
  float fontSize_;

  //
  int count_ = 0;
  int waitTime_;
  int textSwitch_ = -1;
  int moveSwitch_ = 0;
  float moveValue_;

  void loadFiles();
  void loadXml();
  void loadFont();
  void moveText(ofEventArgs &args);
  void frameOutTextStart();
  void frameOutTextEnd();
  void frameInTextStart();
  void frameInTextEnd();
  void moveTextPos();
  void drawSwitchText();
  void drawText(string& text);

public:
  void setup();
  void drawNavigationBar();
  void setupGUI();

  void setTexPos(ofVec2f& pos) { textPos_ = pos; }
  ofVec2f getTexPos() { return textPos_; }
  void setDefaultPos(ofVec2f& pos) { defaultPos_ = pos; }
  ofVec2f setDefaultPos() { return defaultPos_; }
  void setFontSize(float size) { fontSize_ = size; }
  float getFontSize() { return fontSize_; }
  void setWaitTime(int time) { waitTime_ = time; }
  int getWaitTime() { return waitTime_; }
  void setMoveValue(float value) { moveValue_ = value; }
  float getMoveValue() { return moveValue_; }
};
