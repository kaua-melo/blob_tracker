
#ifndef _BLOBTRACKER	// if this class has't been defined, then we should define it.
#define _BLOBTRACKER	// Here we define it. This is useful so that you prevent the class to be called more than once, which would confuse the compiler.

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "Blob.h"

class BlobTracker
{
	public:
       	//ofxCvContourFinder 		p_blobs;
       	//ofxCvContourFinder 		blobs;
       	ofxCvContourFinder	contourFinder;

		vector<Blob>	pBlobs; // Previous Blobs
		vector<Blob>	cBlobs; // Current  Blobs

		//vector<ofVec2f>			p_blobs_;
		//vector<ofVec2f>			blobs;
		vector<int>		blobs_ID;

		int currentMaxID;
		int maxDistance;

		bool debug;


		// METHODS ----------------------------------------------------------------------------------------
		BlobTracker(); // Constructor

		// Find the blobs in a gray image
		void findBlobs(ofxCvGrayscaleImage &im, int minArea, int maxArea, int max_n_blobs, bool findHoles);

		// Give IDs to the blobs
		void setIDs();

		// Match the blobs' IDs on the current frame with the blobs' IDS on the previous frame when
		//  the number of blobs in the current frame is greater or equal than the previous frame.
		void matchIDs_more_or_equal_than_previous();

		// Match the blob's IDs on the current frame with the blobs' IDs on the previous frame when
		//	the number of blobs in the current frame is smaller than the previous frame.
		void matchIDs_less_than_previous();

		// 
		void updatePreviousBlobs();

		void draw(int x, int y);
		void name();

	private:	
};
#endif
