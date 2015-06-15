#include "ofApp.h"

#define PUSH_FREQUENCY_LIMIT  300       //every x # of frames

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    ofSetWindowTitle("Push URL to PushBrowser");

    gui.setup();
    gui.setDefaultWidth(480);
    gui.add(enterIPAddress.setup(" <-- update remote IP address (to send OSC message)"));
    gui.add(currentIPAddress.setup("remote_ip", ""));
    gui.add(enterPort.setup(" <-- update remote port number"));
    gui.add(currentPort.setup("remote_port", ""));
    gui.add(enterURL.setup(" <-- update URL to push"));
    gui.add(currentURL.setup("url_to_push", ""));
    gui.add(push.setup(" <-- Push URL to remote PushBrowser"));

    pushTimer = PUSH_FREQUENCY_LIMIT;
    bPushURL = false;
}

//--------------------------------------------------------------
void ofApp::update(){

    if(enterIPAddress) currentIPAddress = ofSystemTextBoxDialog("enter remote IP address and port number", (string)currentIPAddress);
    if(enterPort) currentPort = ofSystemTextBoxDialog("enter remote port number", (string)currentPort);
    if(enterURL) currentURL = ofSystemTextBoxDialog("enter URL to push", (string)currentURL);

    if ((push)&&(pushTimer >= PUSH_FREQUENCY_LIMIT)){bPushURL = true; pushTimer = 0;}

    pushTimer++;
    if (bPushURL){
        bPushURL = false;
        if (((string)currentIPAddress != "") && ((string)currentPort != "") && ((string)currentURL != "")){
            
            sender.setup((string)currentIPAddress, ofToInt((string)currentPort));
            ofxOscMessage m;
            m.setAddress("/pushURL");
            m.addStringArg((string)currentURL);
            sender.sendMessage(m);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor::white, ofColor::gray);
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 's') gui.saveToFile("settings.xml");
    if(key == 'l') gui.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
