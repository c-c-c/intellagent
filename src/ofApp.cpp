#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    bool savingPDF = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    if (savingPDF) {
        ofBeginSaveScreenAsPDF("savePDF_"+ofGetTimestampString()+".pdf");
    }
    // begin actual code
    
    // we call this method to make sure the bg is not being redrawn, if that was the case we wouldn't see much drawing. Also we want a nice transparent look in the outcome, so we'll enable the alpha blending method.
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    int direction;
    int stepSize = 1;
    float posX = ofGetMouseX();
    float posY = ofGetMouseY();
    
    
    for (int i=0; i<ofGetMouseX(); i++) {
        
        // of ofRandom method returns a float so we need to caste it to
        direction = (int) ofRandom(0,8);
        
//        cout << direction << endl;
        
        // rule for moving north
        if (direction == 0) {
            posX += stepSize;
        } else
        // .. northEast
        if (direction == 1) {
            posX += stepSize;
            posY += stepSize;
        } else
        // .. east
        if (direction == 2) {
            posY += stepSize;
        } else
        // .. southEast
        if (direction == 3) {
            posX += stepSize;
            posY -= stepSize;
        } else
        // .. south
        if (direction == 4) {
            posY -= stepSize;
        } else
        // .. southWest
        if (direction == 5) {
            posX -= stepSize;
            posY -= stepSize;
        } else
        // .. west
        if (direction == 6) {
            posY -= stepSize;
        } else
        // .. and finally northWest
        if (direction == 7) {
            posY -= stepSize;
            posX += stepSize;
        }
    
//        if (posX > ofGetMouseX()) posX = 0;
//        if (posX < 0) posX = ofGetMouseX();
//        if (posY < 0) posY = ofGetMouseY();
//        if (posY > ofGetMouseY()) posY = 0;
        
        
        ofSetColor(0, 0, 0, 30);
        
        ofDrawEllipse(posX, posY, 1, 1);
    
    }
    
    
    // end of code, below is for PDF export
    if (savingPDF) {
        ofEndSaveScreenAsPDF();
        savingPDF = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 's') { // export as PDF, good to keep a vector format
        savingPDF = true;
    }
    if (key == 'c') { // export as PNG, for quick reference 
        ofImage screenshot;
        screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screenshot.save("savePNG_"+ofGetTimestampString()+".png");
    }
    if (key == ' ') { // pressing the space bar clears the screen
        ofBackground(255, 255, 255);
    }
    
}

