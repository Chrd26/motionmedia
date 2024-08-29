#include "capture.h"

Capture::Capture(int deviceID, int apiID)
{		
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
		
		cv::imshow("live", frame);
		
		if(cv::waitKey(1) == 27)
		{
			break;
		}
	}
}
