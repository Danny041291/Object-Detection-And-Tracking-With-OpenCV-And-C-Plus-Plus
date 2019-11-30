#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>

#include "enums.h"
#include "tracker-factory.h"

using namespace cv;
using namespace std;

TrackerFactory::TrackerFactory(TrackerType trackerType) {
	_trackerType = trackerType;
}

TrackerFactory::~TrackerFactory() {

}

Ptr<Tracker> TrackerFactory::GetTracker()
{
	Ptr<Tracker> tracker;
	switch (_trackerType)
	{
		case BOOSTING:
			tracker = TrackerBoosting::create();
			break;
		case MIL:
			tracker = TrackerMIL::create();
			break;
		case KCF:
			tracker = TrackerKCF::create();
			break;
		case TLD:
			tracker = TrackerTLD::create();
			break;
		case MEDIANFLOW:
			tracker = TrackerMedianFlow::create();
			break;
		case GOTURN:
			tracker = TrackerGOTURN::create();
			break;
		case MOSSE:
			tracker = TrackerMOSSE::create();
			break;
		case CSRT:
			tracker = TrackerCSRT::create();
			break;
		default:
			break;
	}
	return tracker;
}