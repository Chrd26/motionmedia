#include "capture.h"

Capture::Capture(int deviceID, int apiID, std::string pathToVideo):videoplayer(pathToVideo)
{
	std::cout << "seg test" << std::endl;		
	capture.open(deviceID, apiID);
	hasInitialisedSuccessfully = true;
	
	if (!capture.isOpened())
	{
		std::cout << "Failed to open camera" << std::endl;
		hasInitialisedSuccessfully = false;
	}
}


void Capture::Start()
{
		while(true)
	{
		if (!hasInitialisedSuccessfully)
		{
			break;
		}
		
		capture.read(frame);
		
		if (frame.empty())
		{
			std::cout << "Getting empty frames!" << std::endl;
			break;
		}
		
		cv::imshow("Camera", frame);
		
		// If person found, show video 
		// start video if there are no detections
		videoplayer.videoSource.read(videoplayer.videoFrame);
		
		if (videoplayer.videoFrame.empty())
		{
			std::cout << "Getting empty frames" << std::endl;
		}
		
		cv::imshow("Video", videoplayer.videoFrame);
		
		if(cv::waitKey(1) == 27)
		{
			break;
		}
	}
}

Capture::~Capture()
{
}
