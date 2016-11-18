
#include "NavigationBar.h"


void NavigationBar::LoadFile() {
	xml_.load("settings.xml");
	naviText1_ = xml_.getValue("Navi1", "none");
	naviText2_ = xml_.getValue("Navi2", "none");
	mainBarFilename_ = xml_.getValue("MainBar", "none");
	sideBarFilename_ = xml_.getValue("SideBar", "none");
	fontFilename_ = xml_.getValue("Font", "none");

	font_.loadFont(fontFilename_, fontSize_);

	mainBarImage_.load(mainBarFilename_);
	sideBarImage_.load(sideBarFilename_);
}

void NavigationBar::MoveText() {
	switch (moveSwitch_)
	{
	case 0:
		count_ += 1;
		if (count_ >= waitTime_) {
			textPos_.x += moveValue_;
			if (textPos_.x <= endPos_.x) {
				textPos_.x = startPos_.x;
				count_ = 0;
				moveSwitch_ = 1;
				textSwitch_ = textSwitch_*-1;
			}
		}
		break;

	case 1:
		textPos_.x += moveValue_;
		if (textPos_.x <= defaultPos_.x) {
			moveSwitch_ = 0;
		}
		break;
	}
}

void NavigationBar::DrawBarImage() {
	mainBarImage_.draw(ofVec2f(0, 0), ofGetWindowWidth(), ofGetWindowHeight() / 8);

	DrawSwitchText();

	sideBarImage_.draw(ofVec2f(0, 0), ofGetWindowWidth(), ofGetWindowHeight() / 8);
}

void NavigationBar::DrawSwitchText() {
	switch (textSwitch_)
	{
	case -1:
		ofSetColor(255, 255, 255);
		font_.drawString(naviText1_, textPos_.x, textPos_.y);
		break;

	case 1:
		ofSetColor(255, 255, 255);
		font_.drawString(naviText2_, textPos_.x, textPos_.y);
		break;
	}
}