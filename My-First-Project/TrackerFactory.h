#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>

using namespace cv;
using namespace std;

enum class TrackerType {
	BOOSTING,
	MIL,
	KCF,
	TLD,
	MEDIANFLOW,
	GOTURN,
	MOSSE,
	CSRT
};

class TrackerFactory 
{
	public:
		TrackerFactory(TrackerType trackerType);
		Ptr<Tracker> GetTracker();
	private:
		TrackerType trackerType;
};