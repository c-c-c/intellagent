float posX;
float posY;

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    bool savingPDF = false;
    posX = ofGetWidth()/2;
    posY = ofGetHeight()/2;

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
    
    float step_size = 1;
    int direction;
    
    for (int i=0; i<=ofGetMouseX(); i++) {
        
        // the random method returns a float so we need to convert it into a int number between 0 and 7 in order to obtain a single 'direction' point on our compass.
        direction = (int) ofRandom(0, 8);
        
        if (direction == 0) {
            posY -= step_size;
            
        }
        else if (direction == 1) {
            posX += step_size;
            posY -= step_size;
        }
        else if (direction == 2) {
            posX += step_size;
        }
        else if (direction == 3) {
            posX += step_size;
            posY += step_size;
        }
        else if (direction == 4) {
            posY += step_size;
        }
        else if (direction == 5) {
            posX -=  step_size;
            posY += step_size;
        }
        else if (direction == 6) {
            posX -= step_size;
        }
        else if (direction == 7) {
            posX -= step_size;
            posY -= step_size;
        }
        
        if (posX > ofGetWidth()) posX = 0;
        if (posX < 0) posX = ofGetWidth();
        if (posY < 0) posY = ofGetHeight();
        if (posY > ofGetHeight()) posY = 0;
        
        // palette 
        ofColor army(75,83,32,30);
        ofSetColor(army);
        
        ofDrawEllipse(posX+step_size/2, posY+step_size/2, 1, 1);

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
        cout << "PDF screenshot saved" << endl;
    }
    if (key == 'c') { // export as PNG, for quick reference
        ofImage screenshot;
        screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screenshot.save("savePNG_"+ofGetTimestampString()+".png");
        cout << "PNG screenshot saved" << endl;
    }
    if (key == ' ') { // pressing the space bar clears the screen
        ofBackground(255, 255, 255);
    }
    
}

