#include "ofApp.h"
#include "blobTracker.h"


//--------------------------------------------------------------
void ofApp::setup(){
	// The dimensions of the camera images to be displayed.
    width  = 320; // 640;
    height = 240; // 360; 

    bTracker = new BlobTracker(1000, true, false); 
    //lobTracker(int mxD, bool calculateVel, bool d); -> (maxDistance, calculateVel?, debug?)

    // Sets the verbosity - this can be useful for debugging the video grabber interface. you can set the verbosity and then try initGrabber();
    #ifdef _USE_LIVE_VIDEO
        camera.setVerbose(true);

        // There may be cases where it helps to not use a texture in order to save memory or for better performance. 
        camera.setUseTexture(false);

        // The default webcam dimensions are: 640x480.
        // If you set it up for something smaller than 640x480, it will be automatically set to 640x480. 
        // You can set it to 1280x960 though.
        camera.setup(640, 480);

        // Check what are the camera dimensions:
        //cout<< "WIDTH: "  << camera.getWidth()  << endl;
        //cout<< "HEIGHT: " << camera.getHeight() << endl;

        colorImg.allocate( camera.getWidth(), camera.getHeight() );

    #else
        video.load("movingShapes.mp4");
        //video.load("velocity.mp4");

        video.play();
        video.setLoopState(OF_LOOP_NORMAL);

        colorImg.allocate( video.getWidth(), video.getHeight() );

        // Keeping the video aspect ratio
        width  = 320; 
        height = 320/( video.getWidth() / video.getHeight() );  

	#endif

	threshold = 76;
    saveBackground = true;    
}

//--------------------------------------------------------------
void ofApp::update(){

	ofBackground(30);

    bool newFrame = false;

	#ifdef _USE_LIVE_VIDEO
        camera.update();

        // newFrame = false  ->  we don't have a new frame.
        newFrame = camera.isFrameNew(); 
    #else
        video.update();
        newFrame = video.isFrameNew();
	#endif
    

    if(newFrame){
        // Getting the current frame of the video.
		#ifdef _USE_LIVE_VIDEO
            colorImg.setFromPixels(camera.getPixels());
	    #else
            colorImg.setFromPixels(video.getPixels());
        #endif        


        // The line below outputs the following message on the console: "[notice ] ofxCvColorImage: setFromPixels(): reallocating to match dimensions: 320 240"
        // Not sure how to remove it :/  Someone had the same issue in the forum: https://forum.openframeworks.cc/t/ofxcvcolorimage-resize-reallocation/16870
        // *An idea: Try using ofxCvIamge instead of ofxCvColorImage
        colorImg.resize( width, height );  

        // grayImg gets the gray scale of the camera's frame.
        grayImg = colorImg;

        
        // If we press ' ', we save the current background that will be used to compare with the current camera frame.
        if(saveBackground == true){
            cout<<"SAVING BACKGROUND !"<<endl;
            grayBackground = grayImg;
            saveBackground = false;
        }

        // Gets the difference between the 2 images.
        grayDiff.absDiff(grayBackground, grayImg);

        // Sets the contrast of the image.
        grayDiff.threshold(threshold);


        // Find the blobs in the grayDiff image
        bTracker->findBlobs(grayDiff, 10, (width*height)/3, 5, false);
        // (ofxCvGrayscaleImage &input, 
        //  int minArea, 
        //  int maxArea, 
        //  int nConsidered, -> maximum number of blobs to be considered
        //  bool bFindHoles       
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetHexColor(0xffffff);

	#ifdef _USE_LIVE_VIDEO
        //colorImg.resize(320, 240);
	#else
        //colorImg.resize(427, 240);
        colorImg.resize(width, height);

    #endif          
    
	colorImg.draw(20, 20);
    //colorImg.draw(20, 20 + 360 + 218); 
    grayImg.draw(360,20);
 	grayBackground.draw(20,280);
	grayDiff.draw(360,280);   

    colorImg_crop.draw(700, 400);

    // Draw blobs
    bTracker->drawContainers(360, 20); //20, 20 + 360 + 218); // 360,20);
    bTracker->drawVelocities(360, 20); //20, 20 + 360 + 218); // 360,20);


	// Report:
	ofSetHexColor(0xffffff);
	stringstream reportStr;
	reportStr << "press ' ' to save Background" << endl
			  << "threshold " << threshold << " (press: arrow up/down)" << endl
			  << "num blobs found " << contourFinder.nBlobs << ", fps: " << ofGetFrameRate();
	ofDrawBitmapString(reportStr.str(), 20, 600); 
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    //cout<<key<<endl;;

	switch (key){
		case ' ':
			saveBackground = true;
			break;
		case 357:
			threshold ++;
			if (threshold > 255) threshold = 255;
			break;
		case 359:
			threshold --;
			if (threshold < 0) threshold = 0;
			break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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