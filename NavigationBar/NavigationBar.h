
#pragma once

#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxGui.h"


class NavigationBar{
private:
	ofxXmlSettings xml_;
	ofxPanel gui_;

	//テキスト
	ofTrueTypeFont font_;
	string naviText1_;
	string naviText2_;
	ofVec2f textPos_ = ofVec2f(100, 70);
	ofxVec2Slider defaultPos_;
	float startPos_ = ofGetWindowWidth();
	float endPos_ = -ofGetWindowWidth();

	//画像
	string mainBarFilename_;
	string sideBarFilename_;
	ofImage mainBarImage_;
	ofImage sideBarImage_;
  ofxVec2Slider barPos_;

	//フォント
	string fontFilename_;
	ofxFloatSlider fontScale_;
	float fontWidth_;

	//
	int count_ = 0;
	ofxIntSlider waitTime_;
	int textSwitch_ = -1;
	int moveSwitch_ = 0;
	ofxFloatSlider moveValue_;
  ofxFloatSlider heightValue_;

public:
	void setup();
	void loadFile();
	void moveText(ofEventArgs &args);
	void drawNavigationBar(ofEventArgs &args);
	void drawSwitchText();
	void drawText(string& text);
	void saveGUI() { gui_.saveToFile("settings.xml"); }
	void loadGUI() { gui_.loadFromFile("settings.xml"); }

	void setTexPos(ofVec2f pos) { textPos_ = pos; }
	ofVec2f getTexPos() { return textPos_; }
	void setDefaultPos(ofVec2f pos) { defaultPos_ = pos; }
	ofVec2f setDefaultPos() { return defaultPos_; }
	void setFontSize(float size) { fontScale_ = size; }
	float getFontSize() { return fontScale_; }
	void setWaitTime(int time) { waitTime_ = time; }
	int getWaitTime() { return waitTime_; }
	void setMoveValue(float value) { moveValue_ = value; }
	float getMoveValue() { return moveValue_; }
};
