

#include "Blob.h"
//#include <string>     // so we can use to_string


Blob::Blob(){
    //cout<<"created a BLOB! "<<endl;
    ID = -1;
    
    vel.set(0, 0);
}

Blob::Blob(ofxCvBlob b){
    blob = b;
    ID = -1;

    vel.set(0, 0);
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

}





