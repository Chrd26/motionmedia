#pragma once
#include "videoplayer.h"


class Capture{
private:
	cv::Mat frame;
	cv::VideoCapture capture;
	bool hasInitialisedSuccessfully;
	int getCameraID, getAPIID;
	VideoPlayer videoplayer;
	Detector detector;
	float alpha, beta;
	bool noDetection;
	
public:
	Capture(int deviceID, int apiID, std::string pathToVideo, std::string pathToBackground);
	~Capture();
	static void CaptureOperation(int cameraID, int apiID);
	void Start();
};
