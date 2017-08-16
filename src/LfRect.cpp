//
//  LfRect.cpp
//  lightface_multi_hngt
//
//  Created by Shin Hanagatata on 2017/08/17.
//
//

#include "LfRect.hpp"

LfRect::LfRect(){
    
    
}

void LfRect::setup(ofVec2f _pos, int _size, int _gradationSpeed){
    pos=_pos;
    size=_size;
    gradationSpeed=_gradationSpeed;
}
void LfRect::setStatus(int _status){
    status = _status;
}
void LfRect::update(){
    switch (status) {
        default:
            statusStr = "MIN";
            brightness = 0;
            break;
        case 1:
            statusStr = "DECREASE";
            if(brightness>0)brightness -= gradationSpeed;
            else status=0;
            break;
        case 2:
            statusStr = "INCREASE";
            if(brightness<255)brightness += gradationSpeed;
            else status=3;
            break;
        case 3:
            statusStr = "MAX";
            brightness = 255;
            break;

    }
}
void LfRect::updateGradationSpeed(int val){
    gradationSpeed = val;
}
void LfRect::draw(){
    ofFill();
    ofSetColor(brightness);
    ofDrawRectangle(pos.x, pos.y, size, size);
    
    ofDrawBitmapStringHighlight(statusStr+": "+ofToString(status)+": "+ofToString(brightness), pos.x+10, pos.y+40);
}
