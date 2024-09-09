#pragma once
#include "Point.h"
#include "IShape.h"
#include <string>
using namespace std;

class Line: public IShape
{
private:
	Point* startPoint;
	Point* endPoint;
	//Segment* segment;
public:
	Line(Point*, Point*);
	virtual string GetData() override final;
	//virtual Segment* GetSegment() override final;
	virtual double* GetStartPoint() override final;
	virtual double* GetEndPoint() override final;
	virtual double CalculateLength() override final;
	virtual double* CalculatePointOnDistance(double) override final;
	virtual double GetMaxX() override final;
	virtual double GetMinX() override final;
	virtual double GetMaxY() override final;
	virtual double GetMinY() override final;
	~Line();
};

