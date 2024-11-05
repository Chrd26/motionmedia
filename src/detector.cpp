#include "detector.h"
cv::CascadeClassifier Detector::visionClassifier;

Detector::Detector(std::string pathToClassifier)
{
	visionClassifier.load(pathToClassifier);
	
	if (visionClassifier.empty())
	{
		std::cout << "Haar cascade classifier was not loaded" << std::endl;
		exit(-1);
	}
}

std::vector<cv::Rect> Detector::ReturnDetectionInformation(cv::Mat frame)
{
	std::vector<cv::Rect> faces;
	
	visionClassifier.detectMultiScale(frame, faces, 1.1, 9);
	
	return faces;
}
