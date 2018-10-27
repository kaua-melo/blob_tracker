
#ifndef _BLOB	// if this class has't been defined, then we should define it.
#define _BLOB	// Here we define it. This is useful so that you prevent the class to be called more than once, which would confuse the compiler.

#include "ofMain.h"
#include "ofxOpenCv.h"

class Blob
{
	public:

		// VARIABLES -------------------------------------------------------------
		ofxCvBlob	blob;
		int 		ID;

		ofVec2f		p_pos; // Previous position. Used to calculate velocity.
		ofVec2f		vel;   // Velocity.

		ofTrueTypeFont font;	// Font to be used when writing blob's ID on screen.
		// -----------------------------------------------------------------------



		// METHODS ---------------------------------------------------------------
		Blob(); 			// Constructor
		Blob(ofxCvBlob b);  // Constructor

		void drawContainer(int x, int y);
		void drawVelocity(int x, int y);

		void calcVel();		// Calculate the blob's velocity vector
		// -----------------------------------------------------------------------

	private:	
};

#endif
