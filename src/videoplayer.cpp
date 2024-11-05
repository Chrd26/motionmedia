#include "videoplayer.h"

cv::Mat VideoPlayer::videoFrame;
cv::VideoCapture VideoPlayer::videoSource;
cv::Mat VideoPlayer::emptyPicture;

VideoPlayer::VideoPlayer(std::string pathToVideo, std::string pathToBackgroundPicture)
{
	videoSource = cv::VideoCapture(pathToVideo);
	emptyPicture = cv::imread(pathToBackgroundPicture);
	
	if (emptyPicture.empty())
	{
		std::cout << "Failed to open picture" << std::endl;
		exit(-1);
	}
	
	if (!videoSource.isOpened())
	{
		std::cout << "Failed to open file" << std::endl;
		exit(-1);
	}
}

void VideoPlayer::PlayVideo()
{
	while(true)
	{
		videoSource.read(videoFrame);
		
		if (videoFrame.empty())
		{
			std::cout << "Receiving empty frames" << std::endl;
			break;
		}
		
		cv::imshow("Video Player", videoFrame);
		
		if(cv::waitKey(1) == 27)
		{
			break;
		}
	}
}


VideoPlayer::~VideoPlayer()
{
	
}
