

#include "Blob.h"
//#include <string>     // so we can use to_string


Blob::Blob(){
    //cout<<"created a BLOB! "<<endl;
    ID = -1;
    
    vel.set(0, 0);
    p_pos.set( blob.centroid.x, 
               blob.centroid.y);
}

Blob::Blob(ofxCvBlob b){
    blob = b;
    ID = -1;

    vel.set(0, 0);
    p_pos.set( blob.centroid.x, 
               blob.centroid.y);    
}



void Blob::draw(int x, int y)
{
    ofSetColor(200, 0, 200);
    ofNoFill();
    ofSetLineWidth(2);

    ofDrawRectangle( blob.boundingRect.getLeft() + x,
                     blob.boundingRect.getTop()  + y,
                     blob.boundingRect.getWidth(),
                     blob.boundingRect.getHeight()
    );    

    ofDrawBitmapString(to_string(ID), blob.boundingRect.getLeft() + x , 
                                      blob.boundingRect.getTop()  + y - 5); 

    // Drawing velocities
    ofSetColor(20, 100, 200);
    ofDrawLine( blob.centroid.x + x,           blob.centroid.y + y,
                blob.centroid.x + x + vel.x*10, blob.centroid.y + y + vel.y*10 );
}

void Blob::calcVel(){
    
    vel.set( blob.centroid.x - p_pos.x, 
             blob.centroid.y - p_pos.y );
}





