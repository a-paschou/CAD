#include "Surface.h"
#include <numeric>
#include <stdexcept>
#include "Point.h"

Surface::Surface(std::vector<IShape*> shapes)
{
	bool checkLoop{ CheckClosedLoop(&shapes, &this->outerBoundary) };
	if (!checkLoop)
	{
		throw std::invalid_argument("The segments do not create a closed loop");
	}
	else
	{
		AddBoundaryVertices(&this->outerBoundary, &this->outerBoundaryVertices);
	}
	CalculateMaxValues();
}

void Surface::Cut(std::vector<IShape*> shapes)
{
	std::vector<IShape*>* newInnerBoundary = new std::vector<IShape*>();
	bool checkLoop{ CheckClosedLoop(&shapes, newInnerBoundary) };
	if (!checkLoop)
	{
		throw std::invalid_argument("The segments do not create a closed loop");
	}
	else
	{
		innerBoundary.push_back(newInnerBoundary);
		AddBoundaryVertices(this->innerBoundary.at(innerBoundary.size() - 1), &this->innerBoundaryVertices);
	}
}

bool Surface::CheckClosedLoop(std::vector<IShape*>* inputShapes, std::vector<IShape*>* newShapes)
{
	(*newShapes).push_back((*inputShapes).at(0));
	double* firstPoint{ ((*newShapes).at(0))->GetStartPoint() };
	double* secondPoint{ ((*newShapes).at(0))->GetEndPoint() };

	std::vector<int> remainingShapes((*inputShapes).size() - 1);
	std::iota(std::begin(remainingShapes), std::end(remainingShapes), 1);
	while ((*newShapes).size() != (*inputShapes).size())
	{
		bool shapePlaced{ false };
		for (size_t i = 0; i < remainingShapes.size(); i++)
		{
			if ((((*inputShapes).at(remainingShapes.at(i)))->GetStartPoint()[0] == secondPoint[0] && ((*inputShapes).at(remainingShapes.at(i)))->GetStartPoint()[1] == secondPoint[1] && ((*inputShapes).at(remainingShapes.at(i)))->GetStartPoint()[2] == secondPoint[2])
				|| (((*inputShapes).at(remainingShapes.at(i)))->GetEndPoint()[0] == secondPoint[0] && ((*inputShapes).at(remainingShapes.at(i)))->GetEndPoint()[1] == secondPoint[1] && ((*inputShapes).at(remainingShapes.at(i)))->GetEndPoint()[2] == secondPoint[2]))
			{
				firstPoint = ((*inputShapes).at(remainingShapes.at(i)))->GetStartPoint();
				secondPoint = ((*inputShapes).at(remainingShapes.at(i)))->GetEndPoint();
				(*newShapes).push_back((*inputShapes).at(remainingShapes.at(i)));
				remainingShapes.erase(remainingShapes.begin() + i);
				shapePlaced = true;
				break;
			}
		}
		if (!shapePlaced)
		{
			newShapes->clear();
			return false;
		}
	}
	if (((*newShapes).at(0)->GetStartPoint()[0] != (*newShapes).at((*newShapes).size() - 1)->GetStartPoint()[0] || (*newShapes).at(0)->GetStartPoint()[1] != (*newShapes).at((*newShapes).size() - 1)->GetStartPoint()[1] || (*newShapes).at(0)->GetStartPoint()[2] != (*newShapes).at((*newShapes).size() - 1)->GetStartPoint()[2])
		&& ((*newShapes).at(0)->GetStartPoint()[0] != (*newShapes).at((*newShapes).size() - 1)->GetEndPoint()[0] || (*newShapes).at(0)->GetStartPoint()[1] != (*newShapes).at((*newShapes).size() - 1)->GetEndPoint()[1] || (*newShapes).at(0)->GetStartPoint()[2] != (*newShapes).at((*newShapes).size() - 1)->GetEndPoint()[2]))
	{
		newShapes->clear();
		return false;
	}
	return true;
	delete firstPoint;
	delete secondPoint;
}

void Surface::AddBoundaryVertices(std::vector<IShape*>* shapes, std::vector<IShape*>* boundaryVertices)
{
	shapes->at(0)->GetEndPoint();
	for (IShape* shape : *shapes)
	{
		double* vertexStart = new double[3];
		double* vertexEnd = new double[3];
		vertexStart = shape->GetStartPoint();
		vertexEnd = shape->GetEndPoint();

		bool startPointFlag{ false };
		bool endPointFlag{ false };
		for (IShape* boundaryvertex : *boundaryVertices)
		{
			if (!startPointFlag)
			{
				if (vertexStart[0] == boundaryvertex->GetStartPoint()[0] && vertexStart[1] == boundaryvertex->GetStartPoint()[1] && vertexStart[2] == boundaryvertex->GetStartPoint()[2])
				{
					startPointFlag = true;
				}
			}
			if (!endPointFlag)
			{
				if (vertexEnd[0] == boundaryvertex->GetStartPoint()[0] && vertexEnd[1] == boundaryvertex->GetStartPoint()[1] && vertexEnd[2] == boundaryvertex->GetStartPoint()[2])
				{
					endPointFlag = true;
				}
			}
			if (startPointFlag && endPointFlag)
			{
				break;
			}
		}
		if (!startPointFlag || !endPointFlag)
		{
			(*boundaryVertices).push_back(new Point(vertexStart[0], vertexStart[1], vertexStart[2]));
		}

		delete[] vertexStart;
		delete[] vertexEnd;
	}
}

std::vector<IShape*>* Surface::GetOuterBoundary()
{
	return &this->outerBoundary;
}

std::vector<std::vector<IShape*>*>* Surface::GetInnerBoundary()
{
	return &this->innerBoundary;
}

std::vector<IShape*>* Surface::GetBoundaryVertices()
{
	std::vector<IShape*> boundaryVertices;
	boundaryVertices.reserve(outerBoundaryVertices.size() + innerBoundaryVertices.size());
	boundaryVertices.insert(boundaryVertices.end(), outerBoundaryVertices.begin(), outerBoundaryVertices.end());
	boundaryVertices.insert(boundaryVertices.end(), innerBoundaryVertices.begin(), innerBoundaryVertices.end());
	return &boundaryVertices;
}

std::vector<IShape*>* Surface::GetOuterBoundaryVertices()
{
	return &innerBoundaryVertices;
}

std::vector<IShape*>* Surface::GetInnerBoundaryVertices()
{
	return &outerBoundaryVertices;
}

double Surface::GetMaxX()
{
	return maxX;
}

double Surface::GetMinX()
{
	return minX;
}

double Surface::GetMaxY()
{
	return maxY;
}

double Surface::GetMinY()
{
	return minY;
}

void Surface::CalculateMaxX()
{
	double value{ outerBoundary.at(0)->GetMaxX() };
	for (size_t i = 1; i < outerBoundary.size(); i++)
	{
		if (outerBoundary.at(i)->GetMaxX() > value)
		{
			value = outerBoundary.at(i)->GetMaxX();
		}
	}
	maxX = value;
}

void Surface::CalculateMinX()
{
	double value{ outerBoundary.at(0)->GetMinX() };
	for (size_t i = 1; i < outerBoundary.size(); i++)
	{
		if (outerBoundary.at(i)->GetMinX() < value)
		{
			value = outerBoundary.at(i)->GetMinX();
		}
	}
	minX = value;
}

void Surface::CalculateMaxY()
{
	double value{ outerBoundary.at(0)->GetMaxY() };
	for (size_t i = 1; i < outerBoundary.size(); i++)
	{
		if (outerBoundary.at(i)->GetMaxY() > value)
		{
			value = outerBoundary.at(i)->GetMaxY();
		}
	}
	maxY = value;
}

void Surface::CalculateMinY()
{
	double value{ outerBoundary.at(0)->GetMinY() };
	for (size_t i = 1; i < outerBoundary.size(); i++)
	{
		if (outerBoundary.at(i)->GetMinY() < value)
		{
			value = outerBoundary.at(i)->GetMinY();
		}
	}
	minY = value;
}

void Surface::CalculateMaxValues()
{
	CalculateMaxX();
	CalculateMinX();
	CalculateMaxY();
	CalculateMinY();
}
