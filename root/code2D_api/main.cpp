/*
 Project:		Two_Dimension Code Recognition & Location
 Author:		Jerry Peng
 Created on:	Mar 19,2014

 2014-7-5 Modify: set Y Perpendicular to 2D code surface
*/

#include "codeRecog2D.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

CodeRecog2D codeRecog2D(0.025);

/*
double t= 0;
double fps;
char str[5];
*/
  int main(int argc, const char** argv)
 {
	VideoCapture capture(0);
	Mat frame;
	vector<aruco::Marker> markers;

	//-- 1. Read the video stream
	if( !capture.isOpened() ){
		cout << "Could not initialize capturing...\n";
        return -1;
    }

	//namedWindow("result",1);

	//-- 2. Markers Detection
	while(1){
		//t = (double)getTickCount();
		capture>>frame;

		codeRecog2D.detectAndDraw(frame);
		markers = codeRecog2D.getMarkers();

		// Print Markers Info
		for (unsigned int i=0;i<markers.size();i++) {
            cout<<markers[i].id<<endl;
        }

		//-- FPS
/*		t = ((double)getTickCount() - t) / getTickFrequency();
		fps = 1.0 / t;
		sprintf(str, "%3.2f", fps);
		string fpsStr("FPS:");
		fpsStr += str;
		putText(frame, fpsStr, Point(0,30), CV_FONT_HERSHEY_DUPLEX, 1.0, Scalar(0,255,0));
*/
		// show 
		//imshow("result", frame);
		if(waitKey(33)==27) break;
	}
	
	//-- 3. Release
	capture.release();
	frame.release();
	return 0;
}

