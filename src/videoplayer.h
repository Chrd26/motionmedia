#pragma once
#include "detector.h"

class VideoPlayer{
	
public:
	static cv::Mat videoFrame;
	static cv::VideoCapture videoSource;
	

public:
	VideoPlayer(std::string pathToVideo);
	~VideoPlayer();
	
private:
	static void PlayVideo();
	
};
