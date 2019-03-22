#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    backGroundImage.load("night.jpg");
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    clickCount = 0;
    
    for (int i=0; i<10; i++) {
        colorArray[i].setHsb(ofRandom(0, 30), 100, 250);
        colorArray2[i].setHsb(ofRandom(100, 150), 100, 255);
        colorArray3[i].setHsb(ofRandom(200,255), 100, 255);
    }
//    p.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, ofRandom(-10.10), ofRandom(-10, 10));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<particles.size(); i++) {
        particles[i].resetForce();
        particles[i].addForce(0, 0.4);
        particles[i].addDampingForce();
        particles[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    backGroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    for (int i=0; i<particles.size(); i++) {
//        ofSetColor(colorArray[i % 10]);
//        if (mouseX <= ofGetWidth()/3) {
//                ofSetColor(colorArray[i % 10]);
//        }else if(mouseX > ofGetWidth()/3 && mouseX <= ofGetWidth()/3*2) {
//                ofSetColor(colorArray2[i % 10]);
//        }else if(mouseX > ofGetWidth()/3*2) {
//                ofSetColor(colorArray3[i % 10]);
//        }
        
        if (clickCount%3 == 0) {
            ofSetColor(colorArray[i % 10]);
            
        }else if(clickCount%3 == 1) {
            ofSetColor(colorArray2[i % 10]);
            
        }else if(clickCount%3 == 2) {
            ofSetColor(colorArray3[i % 10]);
            
        }
        
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
    clickCount = clickCount + 1;
    for (int i=0; i<NUM; i++) {
        Particle myParticle;
        float vx = ofRandom(-7, 7);
        float vy = ofRandom(-10, 5);
        myParticle.setInitialCondition(x, y, vx, vy); // setInitialCondition(float px, float py, float vx, float vy)
//        force.x = force.x - velocity.x * damping;
    
        
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
