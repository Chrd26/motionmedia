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
		
		if(cv::waitKey(1) == 27)
		{
			break;
		}
	}
}

Capture::~Capture()
{
}
