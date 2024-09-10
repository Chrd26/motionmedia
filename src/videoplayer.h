#pragma once
#include <iostream>
#include <vector>
#include <opencv2/core.hpp>

class VideoPlayer{
	static std::vector<std::string> videoFiles;
	
public:
	VideoPlayer(int videoAmount, std::vector<std::string> filePaths);
	~VideoPlayer()
};
