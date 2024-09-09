#include "Segment.h"

Segment::Segment(Point* startPoint, Point* endPoint)
	: startPoint{ startPoint }, endPoint{ endPoint }
{
}

Point* Segment::GetStartPoint()
{
	return startPoint;
}

Point* Segment::GetEndPoint()
{
	return endPoint;
}

Segment::~Segment()
{
	delete startPoint;
	delete endPoint;
}
