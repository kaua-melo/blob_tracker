
#ifndef _BLOBTRACKER	// if this class has't been defined, then we should define it.
#define _BLOBTRACKER	// Here we define it. This is useful so that you prevent the class to be called more than once, which would confuse the compiler.

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "Blob.h"

class BlobTracker
{
	public:

		// VARIABLES --------------------------------------------------------------------------------------
       	ofxCvContourFinder	contourFinder;

		vector<Blob>	pBlobs;  // Blobs from previous frame
		vector<Blob>	cBlobs;  // Blobs on the current frame

		vector<int>		blobs_ID;

		// The IDS can be [0, 1, 2, 7, 8, 30]. 
		//  currentMaxID == 30 so we know that the next blob should have ID 31
		int currentMaxID;	

		// If the distance between blob A to blob A' (from previous frame) is 
		//	smaller than maxDistance, then A and A' are considere the same blob.
		int maxDistance; 

		bool debug;   // If true -> we print some messages showing what's going on on the program...
		bool calcVel; // If true -> we calculate the velocities
		// ------------------------------------------------------------------------------------------------



		// METHODS ----------------------------------------------------------------------------------------
		BlobTracker(int mxD, bool calculateVel, bool d); // Constructor -> (maxDistance, calculateVel?, debug?)

		// Find the blobs in a gray image
		void findBlobs(ofxCvGrayscaleImage &im, int minArea, int maxArea, int max_n_blobs, bool findHoles);

		// Give IDs to the blobs
		void setIDs();

		// Match and set the blobs' IDs on the current frame with the blobs' IDS on the previous frame when
		//  the number of blobs in the current frame is greater or equal than the previous frame.
		void matchIDs_more_or_equal_than_previous();

		// Match and set the blob's IDs on the current frame with the blobs' IDs on the previous frame when
		//	the number of blobs in the current frame is smaller than the previous frame.
		void matchIDs_less_than_previous();

		// Set the vector of previous blobs to the vector with blobs detected so our function can work fine 
		//	the next iteration.
		void updatePreviousBlobs();

		// Calculate blobs' velocities
		void calcVelocities();

		// Sets the maxDistance variable
		void setMaxDistance(int md);

		void drawContainers(int x, int y);
		void drawVelocities(int x, int y);

		void name();
		// ------------------------------------------------------------------------------------------------

	private:	
};
#endif
