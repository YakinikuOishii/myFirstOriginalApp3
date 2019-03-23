#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    backGroundImage.load("night.jpg");
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    clickCount = 0;
    
    for (int i=0; i<NUM; i++) {
        colorArray[i].setHsb(ofRandom(0, 30), 100, 250);
        colorArray2[i].setHsb(ofRandom(100, 150), 100, 255);
        colorArray3[i].setHsb(ofRandom(200,255), 100, 255);
    }
//    p.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, ofRandom(-10.10), ofRandom(-10, 10));
    particleCount = 0;
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
    ofSetColor(255, 255, 255);
    backGroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i=0; i<particles.size(); i++) {
        ofSetColor(particles[i].color);
    
//    for (int i=0; i<particles.size(); i++) { // 余りで色を切り替える
//        if (particles[i].count%3 == 0) {
//            ofSetColor(particles[i].color);
//
//        }else if(particles[i].count%3 == 1) {
//            ofSetColor(particles[i].color2);
//
//        }else if(particles[i].count%3 == 2) {
//            ofSetColor(particles[i].color3);
//
//        }
    
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
    
//    for (int i=0; i<particles.size(); i++) { // 全てのパーティクルを見る
//        for(int i=0; i<particleCount; i++){ // 全てのグループを見る
//            if(particles[i].particleNum == i){ // グループを確認する
//                particles[i].count++; // そのグループのマウスクリック数を増やす
//            }
//        }
//    }

//    particles.clear();®
    clickCount = clickCount + 1;
    
    for (int i=0; i<NUM; i++) {
        Particle myParticle;
        float vx = ofRandom(-10, 10);
        float vy = ofRandom(-10, 5);
        
        ofColor c = colorArray[i];
        
        if (particleCount%3 == 0) {
            c = colorArray[i];
        }else if(particleCount%3 == 1) {
            c = colorArray2[i];
        }else if(particleCount%3 == 2){
            c = colorArray3[i];
        }else{
            c = colorArray[i];
        }
//        ofColor c = colorArray[i];
//        ofColor c2 = colorArray2[i];
//        ofColor c3 = colorArray3[i];
        myParticle.setInitialCondition(x, y, vx, vy, c, particleCount); // setInitialCondition(float px, float py, float vx, float vy)
        // 配列の末尾に追加
        particles.push_back(myParticle);
//        particles[i].setInitialCondition(x, y, ofRandom(-10, 10), ofRandom(-10, 10));
    }
    
    particleCount++;
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
