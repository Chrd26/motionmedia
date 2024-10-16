#include "detector.h"
Detector::visionClassifier;

Detector::Detector(std::string pathToClassifier)
{
	visionClassifier.load(pathToClassifier);
	
	if (cascadeClassifier.empty())
	{
		std::cout << "Haar cascade classifier was not loaded" << std::endl;
		exit(-1);
	}
	
	
}


Detector::ReturnDetectionInformation(cv::Mat frame)
{
	DetectorResults results;
	
	visionClassifier.detectMultiscale(frame, results.faces, 1.1, 10);
	
	return results;
}
