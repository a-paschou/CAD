#pragma once
#include <string>

using namespace std;

class IShape
{
public:
	virtual string GetData() = 0;
	virtual double* GetStartPoint() = 0;
	virtual double* GetEndPoint() = 0;
	virtual double CalculateLength() = 0;
	virtual double* CalculatePointOnDistance(double) = 0;
	virtual double GetMaxX() = 0;
	virtual double GetMinX() = 0;
	virtual double GetMaxY() = 0;
	virtual double GetMinY() = 0;
	virtual ~IShape() = 0;
};

