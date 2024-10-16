#include "capture.h"

// Use the command line tool to get the path to the videos

int main(int argc, char** argv)
{
	
	if (argc > 2 || argc < 2)
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		return -1;
	}
	
	std::string videoPath = argv[1];
	
	Capture cap(0, cv::CAP_ANY, videoPath);
	cap.Start();
	
	return 0;
}
