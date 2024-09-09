#include "Circle.h"

Circle::Circle(Point* centerPoint, double radius)
	: centerPoint{ centerPoint }, radius{ radius }
{
}

Circle::Circle(Point* A, Point* B, Point* C)
	:centerPoint{ nullptr }, radius{}
{
	double denominator{ 2 * ((C->GetX() - B->GetX()) - ((B->GetY() - C->GetY()) / (B->GetY() - A->GetY())) * (A->GetX() - B->GetX())) };
	double centerX{ (pow(C->GetX(), 2) + pow(C->GetY(), 2) - pow(B->GetX(), 2) - pow(B->GetY(), 2) + ((B->GetY() - C->GetY()) / (B->GetY() - A->GetY())) * (pow(B->GetX(), 2) + pow(B->GetY(), 2) - pow(A->GetX(), 2) - pow(A->GetY(), 2))) / denominator };
	double centerY{ ((pow(B->GetX(), 2) + pow(B->GetY(), 2) - pow(A->GetX(), 2) - pow(A->GetY(), 2)) + (2 * A->GetX() - 2 * B->GetX()) * centerX) / (2 * B->GetY() - 2 * A->GetY()) };

	centerPoint = new Point(centerX, centerY);
	radius = sqrt(pow(A->GetX() - centerPoint->GetX(), 2) + pow(A->GetY() - centerPoint->GetY(), 2));
}

string Circle::GetData()
{
	string s{ "" };
	s += "Circle : ";
	s += "x = " + to_string(centerPoint->GetX()) + " y = " + to_string(centerPoint->GetY()) + " z = " + to_string(centerPoint->GetZ()) + ";";
	s += " ";
	s += "radius = " + to_string(radius) + ";";
	return s;
}

//Segment* Circle::GetSegment()
//{
//	return nullptr;
//}

double* Circle::GetStartPoint()
{
	double* coordinates{ nullptr };
	coordinates = new double[3]{ centerPoint->GetX() + radius, centerPoint->GetY(), centerPoint->GetZ() };
	return coordinates;
}

double* Circle::GetEndPoint()
{
	return GetStartPoint();
}

double Circle::CalculateLength()
{
	const double pi{ 3.14159265358979323846 };
	return (2 * pi * this->radius);
}

double* Circle::CalculatePointOnDistance(double radius)
{
	const double pi{ 3.14159265358979323846 };
	double angle{ radius / this->radius };

	double xValue{ this->centerPoint->GetX() + this->radius * cos(angle) };
	double yValue{ this->centerPoint->GetY() + this->radius * sin(angle) };

	return new double[3] {xValue, yValue, centerPoint->GetZ()};
}

double Circle::GetMaxX()
{
	return centerPoint->GetX() + radius * cos(0);
}

double Circle::GetMinX()
{
	const double pi{ 3.14159265358979323846 };
	return centerPoint->GetX() + radius * cos(pi);
}

double Circle::GetMaxY()
{
	const double pi{ 3.14159265358979323846 };
	return centerPoint->GetY() + radius * sin(pi / 2);
}

double Circle::GetMinY()
{
	const double pi{ 3.14159265358979323846 };
	return centerPoint->GetY() + radius * sin(3 * pi / 2);
}

Circle::~Circle()
{
	delete centerPoint;
}
