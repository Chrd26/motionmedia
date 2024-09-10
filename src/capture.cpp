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
		
		cv::Mat grayscaledImage;
		cv::cvtColor(frame, grayscaledImage, cv::COLOR_BGR2GRAY);
		
		cv::circle(grayscaledImage, cv::Point(640, 360), 100, cv::Scalar(255, 0, 0), 5);
		
		
		if (frame.empty())
		{
			std::cout << "Getting empty frames!" << std::endl;
			break;
		}
		
		cv::imshow("Camera", grayscaledImage);
		
		if(cv::waitKey(1) == 27)
		{
			break;
		}
	}
}
