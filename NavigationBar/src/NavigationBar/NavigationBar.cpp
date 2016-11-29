
#include "NavigationBar.h"


void NavigationBar::setup() {
	defaultPos_ = ofVec2f(450, 20);
	barPos_ = ofVec2f(0, 0);
	barSize_ = ofVec2f(1, 8);
	textPos_ = ofVec2f(defaultPos_);

	loadFiles();

	ofAddListener(ofEvents().update, this, &NavigationBar::moveText);
}

void NavigationBar::loadFiles() {
	loadXml();
	loadFont();

	mainBarImage_.load(mainBarFilename_);
	sideBarImage_.load(sideBarFilename_);
}

void NavigationBar::loadXml() {
	if (xml_.load("settings.xml")) {
		xml_.pushTag("group");
		int textValue_ = xml_.getNumTags("Navi");
		for (int i = 0; i < textValue_; i++) {
			naviText_[i] = xml_.getValue("Navi", "none", i);
		}
		mainBarFilename_ = xml_.getValue("MainBar", "none");
		sideBarFilename_ = xml_.getValue("SideBar", "none");
		fontSize_ = xml_.getValue("FontSize", 0);
		fontFilename_ = xml_.getValue("Font", "none");
		xml_.popTag();
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

void NavigationBar::draw() {
	drawGUI();

	mainBarImage_.draw(ofVec2f(barPos_), ofGetWindowWidth() / ofVec2f(barSize_).x, ofGetWindowHeight() / ofVec2f(barSize_).y);

	drawSwitchText();

	sideBarImage_.draw(ofVec2f(barPos_), ofGetWindowWidth() / ofVec2f(barSize_).x, ofGetWindowHeight() / ofVec2f(barSize_).y);
}

void NavigationBar::drawGUI() {
	ImGui::Begin("NavigationBar");
	ImGui::DragFloat2("TextStopPos", defaultPos_.getPtr());
	ImGui::DragFloat("FontScale", &fontScale_, 1.0f, 500, 1000);
	ImGui::DragInt("TextWaitTime", &waitTime_, 1.0f, 3, 100);
	ImGui::DragFloat("TextMoveValue", &moveValue_, 1.0f, 15, 100);
	ImGui::DragFloat2("BarPosition", barPos_.getPtr());
	ImGui::DragFloat2("BarSize", barSize_.getPtr());
	if (ImGui::BeginMenuBar()) {
		if (ImGui::BeginMenu("File")) {
			if (ImGui::MenuItem("Save")) {

			}
			if (ImGui::MenuItem("Load")) {

			}
		}
		ImGui::EndMenuBar();
	}
	ImGui::End();
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
