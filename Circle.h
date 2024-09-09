#pragma once
#include "IShape.h"
#include "Point.h"
class Circle : public IShape
{
private:
	Point* centerPoint;
	double radius;
public:
	Circle(Point*, double);
	Circle(Point*, Point*, Point*);
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
	~Circle();
};

