
#include "NavigationBar.h"


void NavigationBar::setup() {
  setupGUI();

  textPos_ = ofVec2f(defaultPos_);

  loadFile();

  ofAddListener(ofEvents().update, this, &NavigationBar::moveText);
  ofAddListener(ofEvents().draw, this, &NavigationBar::drawNavigationBar);
}

void NavigationBar::setupGUI(){
  ofVec2f minPos_ = ofVec2f(0, 0);
  ofVec2f maxPos_ = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight());

  gui_.setup();
  gui_.add(defaultPos_.setup("TextStopPos", ofVec2f(100, 70), minPos_, maxPos_));
  gui_.add(fontScale_.setup("FontSize", 500, 1, 10000));
  gui_.add(waitTime_.setup("TextWaitTime", 10, 1, 100));
  gui_.add(moveValue_.setup("TextMoveValue", 15, 1, 100));
  gui_.add(barPos_.setup("BarPosition", ofVec2f(0, 0), minPos_, maxPos_));
  gui_.add(barSize_.setup("BarSize", ofVec2f(1, 8), ofVec2f(1, 1), ofVec2f(10, 10)));
}

void NavigationBar::loadFile() {
  xml_.load("settings.xml");
  naviText1_ = xml_.getValue("group:Navi1", "none");
  naviText2_ = xml_.getValue("group:Navi2", "none");
  mainBarFilename_ = xml_.getValue("group:MainBar", "none");
  sideBarFilename_ = xml_.getValue("group:SideBar", "none");
  fontFilename_ = xml_.getValue("group:Font", "none");

  font_.loadFont(fontFilename_, fontScale_);

  mainBarImage_.load(mainBarFilename_);
  sideBarImage_.load(sideBarFilename_);
}

void NavigationBar::moveText(ofEventArgs &args) {
  switch (moveSwitch_) {
  case 0:
    frameOutTextStart();
    break;

  case 1:
    frameInTextStart();
    break;
  }
}

void NavigationBar::frameOutTextStart() {
  count_ += 60 / ofGetFrameRate();
  if (count_ >= waitTime_ * 60) {
    textPos_.x -= float(moveValue_)* 60 / ofGetFrameRate();
    if (textPos_.x <= -ofGetWindowWidth()) {
      frameOutTextEnd();
    }
  }
}

void NavigationBar::frameOutTextEnd() {
  textPos_.x = ofGetWindowWidth();
  count_ = 0;
  moveSwitch_ = 1;
  textSwitch_ = textSwitch_*-1;
}

void NavigationBar::frameInTextStart() {
  textPos_.x -= float(moveValue_)* 60 / ofGetFrameRate();
  if (textPos_.x <= ofVec2f(defaultPos_).x) {
    frameInTextEnd();
  }
}

void NavigationBar::frameInTextEnd(){
  textPos_ = ofVec2f(defaultPos_);
  moveSwitch_ = 0;
}

void NavigationBar::drawNavigationBar(ofEventArgs &args) {
  mainBarImage_.draw(ofVec2f(barPos_), ofGetWindowWidth() / ofVec2f(barSize_).x, ofGetWindowHeight() / ofVec2f(barSize_).y);

  drawSwitchText();

  sideBarImage_.draw(ofVec2f(barPos_), ofGetWindowWidth() / ofVec2f(barSize_).x, ofGetWindowHeight() / ofVec2f(barSize_).y);

  gui_.draw();
}

void NavigationBar::drawSwitchText() {
  switch (textSwitch_)
  {
  case -1:
    ofSetColor(255, 255, 255);

    drawText(naviText1_);
    break;

  case 1:
    ofSetColor(255, 255, 255);

    drawText(naviText2_);
    break;
  }
}

void NavigationBar::drawText(string& text) {
  ofPushMatrix();

  ofTranslate(textPos_);
  ofScale((ofGetWindowWidth() / fontScale_), (ofGetWindowHeight() / fontScale_), 1);
  font_.drawString(text, 0, 0);

  ofPopMatrix();
}
