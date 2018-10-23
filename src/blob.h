
#ifndef _BLOB	// if this class has't been defined, then we should define it.
#define _BLOB	// Here we define it. This is useful so that you prevent the class to be called more than once, which would confuse the compiler.

#include "ofMain.h"
#include "ofxOpenCv.h"

class Blob
{
	public:

		// VARIABLES
		ofxCvBlob	blob;
		int 		ID;

		ofVec2f		p_pos;
		//ofVec2f		c_pos;
		ofVec2f		vel;


		// METHODS
		Blob(); 			// Constructor
		Blob(ofxCvBlob b); // Constructor

		void draw(int x, int y);
		void calcVel();

	private:	
};

#endif
