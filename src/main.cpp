#include "capture.h"

int main()
{
	Capture cap(0, cv::CAP_ANY);
	cap.Start();
	
	return 0;
}
