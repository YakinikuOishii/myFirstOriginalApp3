#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    backGroundImage.load("night.jpg");
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    
    for (int i=0; i<NUM; i++) {
        colorArray[i].setHsb(ofRandom(0, 255), 200, 255);
    }
//    p.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, ofRandom(-10.10), ofRandom(-10, 10));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<particles.size(); i++) {
        particles[i].resetForce();
        particles[i].addForce(0, 0.6);
        particles[i].addDampingForce();
        particles[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
//    backGroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    for (int i=0; i<particles.size(); i++) {
        ofSetColor(colorArray[i % 10]);
        particles[i].draw();
    }
//    p.draw();
    
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    particles.clear();
    for (int i=0; i<NUM; i++) {
        Particle myParticle;
        float vx = ofRandom(-10, 10);
        float vy = ofRandom(-10, 10);
        myParticle.setInitialCondition(x, y, vx, vy);
        // 配列の末尾に追加
        particles.push_back(myParticle);
//        particles[i].setInitialCondition(x, y, ofRandom(-10, 10), ofRandom(-10, 10));
    }
    
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
