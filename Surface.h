#pragma once
#include "IShape.h"
#include <vector>

class Surface
{
private:
	std::vector<IShape*> outerBoundary;
	std::vector<std::vector<IShape*>*> innerBoundary;
	std::vector<IShape*> outerBoundaryVertices;
	std::vector<IShape*> innerBoundaryVertices;
	double maxX{ 0 };
	double minX{ 0 };
	double maxY{ 0 };
	double minY{ 0 };

	bool CheckClosedLoop(std::vector<IShape*>*, std::vector<IShape*>*);
	void AddBoundaryVertices(std::vector<IShape*>*,std::vector<IShape*>*);
	void CalculateMaxX();
	void CalculateMinX();
	void CalculateMaxY();
	void CalculateMinY();
	void CalculateMaxValues();
public:
	Surface(std::vector<IShape*>);
	void Cut(std::vector<IShape*>);
	std::vector<IShape*>* GetOuterBoundary();
	std::vector<std::vector<IShape*>*>* GetInnerBoundary();
	std::vector<IShape*>* GetBoundaryVertices();
	std::vector<IShape*>* GetOuterBoundaryVertices();
	std::vector<IShape*>* GetInnerBoundaryVertices();
	double GetMaxX();
	double GetMinX();
	double GetMaxY();
	double GetMinY();
};

