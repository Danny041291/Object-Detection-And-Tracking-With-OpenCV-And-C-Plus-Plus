#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>

#include "TrackerFactory.h"

using namespace cv;
using namespace std;

int main()
{
	// Get the tracker
	TrackerFactory trackerFactory(TrackerType::KCF);
	auto tracker = trackerFactory.GetTracker();

	// Activate the camera
	VideoCapture camera(0);
	if (!camera.isOpened()) return 1;

	Mat frame;
	Rect2d bbox(250, 100, 200, 225);
	bool init = false;
	bool photo = false;

	// Frame loop
	while (camera.read(frame))
	{
		if (!photo)
		{
			rectangle(frame, bbox, Scalar(255, 0, 0), 2, 1);
			putText(frame, "PUT THE OBJECT TO RECOGNIZE INSIDE THE BOX", Point(10, 20), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(50, 170, 50), 2);
			putText(frame, "PRESS ENTER TO TAKE THE PHOTO", Point(10, 50), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(50, 170, 50), 2);
		}
		else
		{
			// Init the tracker with the object to recognize
			if (!init)
			{
				tracker->init(frame, bbox);
				init = true;
			}

			// Track the object
			if (tracker->update(frame, bbox))
				rectangle(frame, bbox, Scalar(255, 0, 0), 2, 1);
		}

		// Show the current frame
		imshow("Tracking", frame);

		// Wait for the Enter key or the Escape key
		int key = waitKey(1);
		if (key == 13) photo = true;
		else if (key == 27) break;
	}

	// Close all windows
	destroyAllWindows();

	return 0;
}