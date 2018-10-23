#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "blobTracker.h"


//#define _USE_LIVE_VIDEO		// uncomment this to use a live camera instead of a video file.

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		// The dimensions of the camera images to be displayed
		int width, 
			height;

        #ifdef _USE_LIVE_VIDEO
			ofVideoGrabber 		camera;
		#else
			ofVideoPlayer 		video;
		#endif

        ofxCvColorImage			colorImg;
        ofxCvColorImage			colorImg_crop;

        ofxCvGrayscaleImage 	grayImg, grayBackground, grayDiff;


        ofxCvContourFinder 		previousContourFinder;
        ofxCvContourFinder 		contourFinder;

		BlobTracker				bTracker;

		int	threshold;
		bool saveBackground;		
};
