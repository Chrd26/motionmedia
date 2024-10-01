#pragma once
#include <iostream>
#include <vector>
#include <opencv2/core.hpp>

class VideoPlayer{
	static std::vector<std::string> videoFiles;
	
public:
	VideoPlayer(std::string pathToVideo);
	~VideoPlayer();
};
