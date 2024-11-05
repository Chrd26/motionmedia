#include "capture.h"

Capture::Capture(	int deviceID, int apiID, std::string pathToVideo, 
					std::string pathToBackground):videoplayer(pathToVideo, pathToBackground), 
					detector("../Cascade Classifier/haarcascade_upperbody.xml")
{	
	capture.open(deviceID, apiID);
	hasInitialisedSuccessfully = true;
	isIncreasing = true;
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
	
		//std::cout << "Faces: " << faces.size() << std::endl;
		// Create a purple rectangle  the face.
		for (int i = 0; i < faces.size(); i++)
		{
			std::cout << "Top Left: " << faces[0].tl() << std::endl;
			std::cout << "Bottom Right: " << faces[i].br() << std::endl;
			cv::rectangle(frame, faces[i].tl(), faces[i].br(), cv::Scalar(255, 0, 255), 5);
		}
		
		if (videoplayer.videoFrame.empty())
		{
			std::cout << "Getting empty frames" << std::endl;
		}
		
		cv::imshow("Camera", frame);
		cv::imshow("Video", videoplayer.videoFrame);
		
		if (beta > 1 || beta < 0)
		{
			if (!isIncreasing)
			{
				alpha = 1.0;
			}
			
			isIncreasing = !isIncreasing;
		}
		
		if (isIncreasing)
		{
			beta += 0.05;
			alpha -= 0.05;
		}else
		{
			beta -= 0.05;
			alpha += 0.05;
		}
		
		std::cout << "Beta: " << beta << std::endl;
		std::cout << "Alpha: " << alpha << std::endl;
		
		cv::Mat dest;
		
		cv::addWeighted(videoplayer.videoFrame, alpha, cv::Scalar(0, 0, 0), beta, 0.0, dest);
		cv::imshow("Blended Image", dest);
		
		if(cv::waitKey(1) == 27)
		{
			break;
		}
	}
}

Capture::~Capture()
{
}
