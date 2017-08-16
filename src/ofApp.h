#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"


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
    
    ofVideoGrabber 		vidGrabber;
    
    ofxCvColorImage			colorImg_cam;
    ofxCvColorImage			colorImg;
    
    ofxCvGrayscaleImage 	grayImage;
    vector<ofxCvGrayscaleImage>	grayImgs;
    vector<ofxCvGrayscaleImage>	grayBgs;
    ofxCvGrayscaleImage 	grayDiff;
    
    ofxCvContourFinder 	contourFinder;
    
    int 				threshold;
    bool				bLearnBakground;
    
    ofImage img;
    ofImage img_old;
    ofXml XML;
    
    static const int num_w = 3;
    static const int num_h = 3;
    static const int val_size = num_w * num_h;
    bool isValids[val_size];
    const int cam_coe = 2;
    const int target_whole_base = 200;
    
    int cam_w;
    int cam_h;
    int target_whole_x = 20;
    int target_whole_y = 20;
    int target_whole_w;
    int target_whole_h;
    int target_xs[val_size];
    int target_ys[val_size];
    int target_ws[val_size];
    int target_hs[val_size];
    int target_x;
    int target_y;
    int target_w;
    int target_h;
    int draw_xs[val_size];
    int draw_ys[val_size];
    int values[val_size];
    bool bNewFrame = false;
    bool isPressed = false;
    
    ofSerial mySerial;
    
    bool isBig = false;
    bool isSmall = false;
    int target_id = 0;
    bool isReadSetting = false;

    vector<int> founds;
    
    int target_px_min = 20;
    int found_max = 40;
    int found_min = 0;
    
};

