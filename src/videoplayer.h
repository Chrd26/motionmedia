#pragma once
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <thread>

class VideoPlayer{
	
private:
	static cv::Mat videoFrame;
	static cv::VideoCapture videoSource;
	

public:
	VideoPlayer(std::string pathToVideo);
	~VideoPlayer();
	
private:
	static void PlayVideo();
	
};
