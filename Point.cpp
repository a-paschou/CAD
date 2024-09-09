#include "Point.h"
#include "Segment.h"

Point::Point(double x, double y, double z)
	:X{ x }, Y{ y }, Z{ z }
{
}

string Point::GetData()
{
	string s{ "" };
	s += "Point : x = " + to_string(X) + " y = " + to_string(Y) + " z = " + to_string(Z) + ";";
	return s;
}

double* Point::GetStartPoint()
{
	double* coordinates{ nullptr };
	coordinates = new double[3]{ this->GetX(), this->GetY(), this->GetZ() };
	return coordinates;
}

double* Point::GetEndPoint()
{
	return GetStartPoint();
}

double Point::CalculateLength()
{
	return 0.0;
}

double* Point::CalculatePointOnDistance(double radius)
{
	return new double[3] {GetX(), GetY(), GetZ()};
}

double Point::GetMaxX()
{
	return X;
}

double Point::GetMinX()
{
	return X;
}

double Point::GetMaxY()
{
	return Y;
}

double Point::GetMinY()
{
	return Y;
}

double Point::GetX()
{
	return X;
}

double Point::GetY()
{
	return Y;
}

double Point::GetZ()
{
	return Z;
}

Point::~Point()
{
}
