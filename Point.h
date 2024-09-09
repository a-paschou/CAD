#pragma once
#include <string>
#include "IShape.h"

using namespace std;

class Point : public IShape
{
private:
	double X;
	double Y;
	double Z;
public:
	Point(double x = 0, double y = 0, double z = 0);
	virtual string GetData() override final;
	virtual double* GetStartPoint() override final;
	virtual double* GetEndPoint() override final;
	virtual double CalculateLength() override final;
	virtual double* CalculatePointOnDistance(double) override final;
	virtual double GetMaxX() override final;
	virtual double GetMinX() override final;
	virtual double GetMaxY() override final;
	virtual double GetMinY() override final;
	double GetX();
	double GetY();
	double GetZ();
	~Point();
};