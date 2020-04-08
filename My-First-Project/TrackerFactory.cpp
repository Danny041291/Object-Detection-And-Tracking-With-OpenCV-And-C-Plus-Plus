#include <iostream>

#include "TrackerFactory.h"

using namespace cv;
using namespace std;

TrackerFactory::TrackerFactory(TrackerType trackerType) 
	: trackerType(trackerType)
{
	
}

Ptr<Tracker> TrackerFactory::GetTracker()
{
	Ptr<Tracker> tracker;
	switch (trackerType)
	{
	case TrackerType::BOOSTING:
		tracker = TrackerBoosting::create();
		break;
	case TrackerType::MIL:
		tracker = TrackerMIL::create();
		break;
	case TrackerType::KCF:
		tracker = TrackerKCF::create();
		break;
	case TrackerType::TLD:
		tracker = TrackerTLD::create();
		break;
	case TrackerType::MEDIANFLOW:
		tracker = TrackerMedianFlow::create();
		break;
	case TrackerType::GOTURN:
		tracker = TrackerGOTURN::create();
		break;
	case TrackerType::MOSSE:
		tracker = TrackerMOSSE::create();
		break;
	case TrackerType::CSRT:
		tracker = TrackerCSRT::create();
		break;
	default:
		break;
	}
	return tracker;
}