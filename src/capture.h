#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>


class Capture{
private:
	cv::Mat frame;
	cv::VideoCapture capture;
	bool hasInitialisedSuccessfully;
	int getCameraID, getAPIID;
	
public:
	Capture(int deviceID, int apiID);
	static void CaptureOperation(int cameraID, int apiID);
	void Start();
};
