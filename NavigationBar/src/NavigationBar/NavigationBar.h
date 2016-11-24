
#pragma once


#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxGui.h"


class NavigationBar {
private:
  ofxXmlSettings xml_;
  ofxPanel gui_;

  //テキスト
  ofTrueTypeFont font_;
  string naviText_[2];
  ofVec2f textPos_;
  ofxVec2Slider defaultPos_;

  //画像
  string mainBarFilename_;
  string sideBarFilename_;
  ofImage mainBarImage_;
  ofImage sideBarImage_;
  ofxVec2Slider barPos_;
  ofxVec2Slider barSize_;

  //フォント
  string fontFilename_;
  ofxFloatSlider fontScale_;
  float fontSize_;

  //
  int count_ = 0;
  ofxIntSlider waitTime_;
  int textSwitch_ = -1;
  int moveSwitch_ = 0;
  ofxFloatSlider moveValue_;

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
  void saveGUI() { gui_.saveToFile("settings.xml"); }
  void loadGUI() { gui_.loadFromFile("settings.xml"); }

  void setTexPos(ofVec2f pos) { textPos_ = pos; }
  ofVec2f getTexPos() { return textPos_; }
  void setDefaultPos(ofVec2f pos) { defaultPos_ = pos; }
  ofVec2f setDefaultPos() { return defaultPos_; }
  void setFontSize(float size) { fontSize_ = size; }
  float getFontSize() { return fontSize_; }
  void setWaitTime(int time) { waitTime_ = time; }
  int getWaitTime() { return waitTime_; }
  void setMoveValue(float value) { moveValue_ = value; }
  float getMoveValue() { return moveValue_; }
};
