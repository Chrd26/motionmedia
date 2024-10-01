#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include "videoplayer.h"
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>


class Capture{
private:
	cv::Mat frame;
	cv::VideoCapture capture;
	bool hasInitialisedSuccessfully;
	int getCameraID, getAPIID;
	//VideoPlayer videoplayer;
	
public:
	Capture(int deviceID, int apiID);
	static void CaptureOperation(int cameraID, int apiID);
	void Start();
};
