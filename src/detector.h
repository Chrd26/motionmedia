#pragma once
#include "detectionresults.h"

class Detector
{
public:
	Detector(std::string pathToClassifier);
	~Detector();
	
public:
	static DetectorResults ReturnDetectionInformation(cv::Mat frame);
	
private:
	static cv::CascadeClassifier visionClassifier;
	
};
