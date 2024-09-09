#include "Line.h"


Line::Line(Point* startPoint, Point* endPoint)
	:startPoint{ startPoint }, endPoint{ endPoint }
{
	//segment = new Segment(this->startPoint, this->endPoint);
}

string Line::GetData()
{
	string s{ "" };
	s += "Line : ";
	s += "x1 = " + to_string(startPoint->GetX()) + " y1 = " + to_string(startPoint->GetY()) + " z1 = " + to_string(startPoint->GetZ()) + ";";
	s += " ";
	s += "x2 = " + to_string(endPoint->GetX()) + " y2 = " + to_string(endPoint->GetY()) + " z2 = " + to_string(endPoint->GetZ()) + ";";
	return s;
}

//Segment* Line::GetSegment()
//{
//	return segment;
//}

double* Line::GetStartPoint()
{
	double* coordinates{ nullptr };
	coordinates = new double[3] { this->startPoint->GetX(), this->startPoint->GetY(), this->startPoint->GetZ() };
	return coordinates;
}

double* Line::GetEndPoint()
{
	double* coordinates{ nullptr };
	coordinates =  new double[3]{ this->endPoint->GetX(), this->endPoint->GetY(), this->endPoint->GetZ() };
	return coordinates;
}

double Line::CalculateLength()
{
	
	return sqrt(pow(startPoint->GetX() - endPoint->GetX(), 2) + pow(startPoint->GetY() - endPoint->GetY(), 2) + pow(startPoint->GetZ() - endPoint->GetZ(), 2));
}

double* Line::CalculatePointOnDistance(double radius)
{
	double vector[]{ this->endPoint->GetX() - this->startPoint->GetX(),this->endPoint->GetY() - this->startPoint->GetY(), this->endPoint->GetZ() - this->startPoint->GetZ() };
	double distance{ CalculateLength() };
	double unitVector[]{ vector[0] / distance, vector[1] / distance, vector[2] / distance };

	double* point{ nullptr };
	point = new double[3] {this->startPoint->GetX() + radius * unitVector[0], this->startPoint->GetY() + radius * unitVector[1], this->startPoint->GetZ() + radius * unitVector[2]};
	return point;
}

double Line::GetMaxX()
{
	if (startPoint->GetX() > endPoint->GetX())
	{
		return startPoint->GetX();
	}
	else
	{
		return endPoint->GetX();
	}
}

double Line::GetMinX()
{
	if (startPoint->GetX() < endPoint->GetX())
	{
		return startPoint->GetX();
	}
	else
	{
		return endPoint->GetX();
	}
}

double Line::GetMaxY()
{
	if (startPoint->GetY() > endPoint->GetY())
	{
		return startPoint->GetY();
	}
	else
	{
		return endPoint->GetY();
	}
}

double Line::GetMinY()
{
	if (startPoint->GetY() < endPoint->GetY())
	{
		return startPoint->GetY();
	}
	else
	{
		return endPoint->GetY();
	}
}

Line::~Line()
{
	delete startPoint;
	delete endPoint;
}
