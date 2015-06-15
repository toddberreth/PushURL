#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxButton       enterIPAddress;
        ofxLabel        currentIPAddress;
        ofxButton       enterPort;
        ofxLabel        currentPort;
        ofxButton       enterURL;
        ofxLabel        currentURL;
        ofxButton       push;
        ofxPanel        gui;
    
        ofxOscSender    sender;
    
        int             pushTimer;
        bool            bPushURL;
};
