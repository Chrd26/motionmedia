#include "videoplayer.h"

cv::Mat VideoPlayer::videoFrame;
cv::VideoCapture VideoPlayer::videoSource;

VideoPlayer::VideoPlayer(std::string pathToVideo)
{
	std::cout << "Path: " << pathToVideo << std::endl;
	videoSource = cv::VideoCapture(pathToVideo);
	
	if (!videoSource.isOpened())
	{
		std::cout << "Failed to open file" << std::endl;
		exit(-1);
	}
	
	PlayVideo();
	
	//std::thread t1(PlayVideo);
	
	//if (t1.joinable())
	//{
	//	t1.detach();
	//}	
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
