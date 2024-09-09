#pragma once
#include "Point.h"
class Segment
{
private:
	Point* startPoint;
	Point* endPoint;
public:
	Segment(Point*, Point*);
	Point* GetStartPoint();
	Point* GetEndPoint();
	~Segment();
};

