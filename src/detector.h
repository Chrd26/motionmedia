#pragma once
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <thread>
class Detector
{
public:
	Detector(std::string pathToClassifier);
	
public:
	static std::vector<cv::Rect> ReturnDetectionInformation(cv::Mat frame);
	
private:
	static cv::CascadeClassifier visionClassifier;
};
