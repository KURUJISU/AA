
#include "NavigationBar.h"


void NavigationBar::setup() {
  setupGUI();
  loadFiles();

  textPos_ = ofVec2f(defaultPos_);

  ofAddListener(ofEvents().update, this, &NavigationBar::moveText);
}

void NavigationBar::setupGUI() {
  ofVec2f minPos_ = ofVec2f(0, 0);
  ofVec2f maxPos_ = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight());

  gui_.setup();
  gui_.add(defaultPos_.setup("TextStopPos", ofVec2f(450, 20), minPos_, maxPos_));
  gui_.add(fontScale_.setup("FontScale", 500, 1, 1000));
  gui_.add(waitTime_.setup("TextWaitTime", 3, 1, 100));
  gui_.add(moveValue_.setup("TextMoveValue", 15, 1, 100));
  gui_.add(barPos_.setup("BarPosition", ofVec2f(0, 0), minPos_, maxPos_));
  gui_.add(barSize_.setup("BarSize", ofVec2f(1, 8), ofVec2f(1, 1), ofVec2f(10, 10)));
}

void NavigationBar::loadFiles() {
  loadXml();
  loadFont();

  mainBarImage_.load(mainBarFilename_);
  sideBarImage_.load(sideBarFilename_);
}

void NavigationBar::loadXml() {
  if (xml_.load("settings.xml")) {
    int textValue_ = xml_.getNumTags("group:Navi");
    for (int i = 0; i < textValue_; i++) {
      naviText_[i] = xml_.getValue("group:Navi", "none", i);
    }
    mainBarFilename_ = xml_.getValue("group:MainBar", "none");
    sideBarFilename_ = xml_.getValue("group:SideBar", "none");
    fontSize_ = xml_.getValue("group:FontSize", 0);
    fontFilename_ = xml_.getValue("group:Font", "none");
  }
}

void NavigationBar::loadFont() {
  font_.loadFont(fontFilename_, fontSize_);
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
  count_ += ofGetLastFrameTime() * 100;
  if (count_ >= waitTime_ * 60) {
    moveTextPos();
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
  moveTextPos();
  if (textPos_.x <= ofVec2f(defaultPos_).x) {
    frameInTextEnd();
  }
}

void NavigationBar::frameInTextEnd() {
  textPos_ = ofVec2f(defaultPos_);
  moveSwitch_ = 0;
}

void NavigationBar::moveTextPos() {
  textPos_.x -= float(moveValue_)* (ofGetLastFrameTime() * 100);
}

void NavigationBar::drawNavigationBar() {
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

    drawText(naviText_[0]);
    break;

  case 1:
    ofSetColor(255, 255, 255);

    drawText(naviText_[1]);
    break;
  }
}

void NavigationBar::drawText(string& text) {
  ofPushMatrix();

  float fontWidth = font_.stringWidth(text);
  float fontHeight = font_.stringHeight(text);

  ofTranslate(textPos_);
  ofScale((ofGetWindowWidth() / (fontScale_)),
    (ofGetWindowHeight() / fontScale_), 1);
  font_.drawString(text, -fontWidth / 2, fontHeight);

  ofPopMatrix();
}
