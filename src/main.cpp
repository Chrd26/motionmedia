#include "capture.h"

// Use the command line tool to get the path to the videos

int main(int argc, char** argv)
{
	/*
	if (argc > 2)
	{
		std::cout << "Too many arguments!" << std::endl;
		return -1;
	}
	
	std::vector<std::string> videoPaths;
	
	for (int i = 0; i < argc - 1; i++)
	{
		videoPaths.push_back = argv[i];
	}
	*/
	
	Capture cap(0, cv::CAP_ANY);
	cap.Start();
	
	return 0;
}
