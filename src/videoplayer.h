#pragma once
#include "detector.h"

class VideoPlayer{
	
public:
	static cv::Mat videoFrame;
	static cv::VideoCapture videoSource;
	static cv::Mat emptyPicture;
	

public:
	VideoPlayer(std::string pathToVideo, std::string pathToBackgroundPicture );
	~VideoPlayer();
	
private:
	static void PlayVideo();
	
};
