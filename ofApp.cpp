#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(32);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	for (float radius = 50; radius <= 250; radius += 100) {

		for (float deg = 0; deg < 360; deg += 3) {

			float noise_value = ofNoise(deg - ofGetFrameNum() * 0.005) + 0.5;
			ofPoint point_1(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			ofPoint point_2(radius * noise_value * cos(deg * DEG_TO_RAD), radius * noise_value * sin(deg * DEG_TO_RAD));

			ofColor line_color;
			line_color.setHsb(deg / 360 * 255, 200, 200);
			ofSetColor(line_color);
			ofDrawLine(point_1, point_2);
		}
	}

}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}