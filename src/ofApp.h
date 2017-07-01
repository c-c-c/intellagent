#pragma once

#include "ofMain.h"

class Compass {
    
    public:
    
//    Basically here we are creating a kind of compass by attributing a direction to any whole number between 0 and 7. We will see why in the draw() section.
    
    int north = 0;
    int northEast = 1;
    int east = 2;
    int southEast = 3;
    int south = 4;
    int southWest = 5;
    int west = 6;
    int northWest = 7;
    
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		    
        bool savingPDF;
    
		
};
