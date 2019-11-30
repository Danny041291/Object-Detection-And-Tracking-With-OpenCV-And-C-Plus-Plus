#pragma once

#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>

#include "enums.h"

using namespace cv;
using namespace std;

class TrackerFactory {
private:
	TrackerType _trackerType;
public:
	TrackerFactory(TrackerType trackerType);
	~TrackerFactory();
	Ptr<Tracker> GetTracker();
};