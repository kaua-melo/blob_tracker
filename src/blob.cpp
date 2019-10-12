
#include "Blob.h"

Blob::Blob(){
    ID = -1;
    
    vel.set(0, 0);

    //p_pos.set( blob.centroid.x, 
    //           blob.centroid.y);

    font.loadFont("verdana.ttf", 15); //(you need verdana.ttf inside your bin/data/  folder)
}


Blob::Blob(ofxCvBlob b):Blob(){ // We are calling the Blob() constructor here too, so we set its ID, vel, etc...
                                // It first executes Blob(), then it executes Blob(ofxCvBlob b)

    blob = b;

    // It's important to set the previous position of the blob to its current poisition so it 
    //  calculates the velocity for the first frame properly.
    p_pos.set( blob.centroid.x, 
               blob.centroid.y);
}


void Blob::drawContainer(int x, int y)
{
    ofSetColor(255, 0, 94);
    ofNoFill();
    ofSetLineWidth(4);

    // Draw rectangle around the blob
    ofDrawRectangle( blob.boundingRect.getLeft() + x,
                     blob.boundingRect.getTop()  + y,
                     blob.boundingRect.getWidth(),
                     blob.boundingRect.getHeight()
    );    

    // Writing the Blob's ID with Big font size (you need verdana.ttf inside your data/  folder)
    font.drawString(to_string(ID), blob.boundingRect.getLeft() + x , 
                                   blob.boundingRect.getTop()  + y - 5); 

    // Writing the blob's ID with small font size
    //ofDrawBitmapString(to_string(ID), blob.boundingRect.getLeft() + x , 
    //                                  blob.boundingRect.getTop()  + y - 5); 
          
}

void Blob::drawVelocity(int x, int y)
{
    // Drawing velocities
    //ofSetColor(20, 100, 200);
    ofDrawLine( blob.centroid.x + x,           blob.centroid.y + y,
                blob.centroid.x + x + vel.x*7, blob.centroid.y + y + vel.y*7 );  
}

void Blob::calcVel(){
    
    vel.set( blob.centroid.x - p_pos.x, 
             blob.centroid.y - p_pos.y );
}





