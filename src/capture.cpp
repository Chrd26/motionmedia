#include "capture.h"

Capture::Capture(	int deviceID, int apiID, std::string pathToVideo, 
					std::string pathToBackground):videoplayer(pathToVideo, pathToBackground), 
					detector("../Cascade Classifier/haarcascade_frontalface_default.xml")
{	
	capture.open(deviceID, apiID);
	hasInitialisedSuccessfully = true;
	alpha = 1;
	
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
		
		// If person found, show video 
		// start video if there are no detections
		videoplayer.videoSource.read(videoplayer.videoFrame);
		std::vector<cv::Rect> faces = detector.ReturnDetectionInformation(frame);
	
		// Create a purple rectangle
		for (int i = 0; i < faces.size(); i++)
		{
			cv::rectangle(frame, faces[i].tl(), faces[i].br(), cv::Scalar(255, 0, 255), 5);
		}
		
		if (videoplayer.videoFrame.empty())
		{
			std::cout << "Getting empty frames" << std::endl;
		}
		
		//cv::imshow("Camera", frame);
		//cv::imshow("Video", videoplayer.videoFrame);
		
		if (faces.empty())
		{
			noDetection = true;
		}else
		{
			noDetection = false;
		}
		
		if (noDetection && alpha > 0)
		{
			beta += 0.1;
			alpha -= 0.1;
		}
		
		if (!noDetection && alpha < 1)
		{
			beta -= 0.5;
			alpha += 0.5;
		}
		
		
		cv::Mat dest;
		
		cv::addWeighted(videoplayer.videoFrame, alpha, cv::Scalar(0, 0, 0), beta, 0.0, dest);
		cv::namedWindow("Result", cv::WINDOW_NORMAL);
		cv::imshow("Result", dest);
		cv::setWindowProperty("Result", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);
		
		if(cv::waitKey(50) == 27)
		{
			break;
		}
	}
}

Capture::~Capture()
{
}
