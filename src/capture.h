#pragma once
#include "videoplayer.h"


class Capture{
private:
	cv::Mat frame;
	cv::VideoCapture capture;
	bool hasInitialisedSuccessfully;
	int getCameraID, getAPIID;
	VideoPlayer videoplayer;
	
public:
	Capture(int deviceID, int apiID, std::string pathToVideo);
	~Capture();
	static void CaptureOperation(int cameraID, int apiID);
	void Start();
};
