#include "capture.h"

// Use the command line tool to get the path to the videos

int main(int argc, char** argv)
{
	std::cout << argc << std::endl;
	if (argc > 2 || argc == 1)
	{
		std::cout << "Wrong amount of arguments!" << std::endl;
		return -1;
	}
	
	std::string videoPath = argv[1];
	
	std::cout << videoPath << std::endl;
	
	/*
	
	Capture cap(0, cv::CAP_ANY);
	cap.Start();
	*/
	
	return 0;
}
