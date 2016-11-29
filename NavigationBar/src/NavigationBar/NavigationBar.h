
#pragma once


#include "ofMain.h"
#include "ofxXmlSettings.h"
<<<<<<< HEAD
#include "ofxImGui.h"
=======
#include "ofxGui.h"
>>>>>>> master


class NavigationBar {
private:
  ofxXmlSettings xml_;
<<<<<<< HEAD
=======
  ofxPanel gui_;
>>>>>>> master

  //テキスト
  ofTrueTypeFont font_;
  string naviText_[2];
  ofVec2f textPos_;
<<<<<<< HEAD
  ofVec2f defaultPos_;
=======
  ofxVec2Slider defaultPos_;
>>>>>>> master

  //画像
  string mainBarFilename_;
  string sideBarFilename_;
  ofImage mainBarImage_;
  ofImage sideBarImage_;
<<<<<<< HEAD
  ofVec2f barPos_;
  ofVec2f barSize_;

  //フォント
  string fontFilename_;
  float fontScale_;
=======
  ofxVec2Slider barPos_;
  ofxVec2Slider barSize_;

  //フォント
  string fontFilename_;
  ofxFloatSlider fontScale_;
>>>>>>> master
  float fontSize_;

  //
  int count_ = 0;
<<<<<<< HEAD
  int waitTime_;
  int textSwitch_ = -1;
  int moveSwitch_ = 0;
  float moveValue_;
=======
  ofxIntSlider waitTime_;
  int textSwitch_ = -1;
  int moveSwitch_ = 0;
  ofxFloatSlider moveValue_;
>>>>>>> master

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
<<<<<<< HEAD
  void draw();
  void drawGUI();

  void setTexPos(ofVec2f& pos) { textPos_ = pos; }
  ofVec2f getTexPos() { return textPos_; }
  void setDefaultPos(ofVec2f& pos) { defaultPos_ = pos; }
=======
  void drawNavigationBar();
  void setupGUI();
  void saveGUI() { gui_.saveToFile("settings.xml"); }
  void loadGUI() { gui_.loadFromFile("settings.xml"); }

  void setTexPos(ofVec2f pos) { textPos_ = pos; }
  ofVec2f getTexPos() { return textPos_; }
  void setDefaultPos(ofVec2f pos) { defaultPos_ = pos; }
>>>>>>> master
  ofVec2f setDefaultPos() { return defaultPos_; }
  void setFontSize(float size) { fontSize_ = size; }
  float getFontSize() { return fontSize_; }
  void setWaitTime(int time) { waitTime_ = time; }
  int getWaitTime() { return waitTime_; }
  void setMoveValue(float value) { moveValue_ = value; }
  float getMoveValue() { return moveValue_; }
};
