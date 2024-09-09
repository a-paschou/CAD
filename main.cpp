#include "Drawing.h"
#include "Line.h"
#include "Circle.h"
#include "IShape.h"
#include <vector>
#include "Surface.h"
#include <iostream>

void main()
{
	IShape* A = new Point(0, 0);
	IShape* B = new Point(10, 0);
	IShape* C = new Point(10, 10);
	IShape* D = new Point(0, 10);

	IShape* AB = new Line((Point*)A, (Point*)B);
	IShape* BC = new Line((Point*)B, (Point*)C);
	IShape* CD = new Line((Point*)C, (Point*)D);
	IShape* DA = new Line((Point*)D, (Point*)A);
	
	Surface surface{ std::vector<IShape*> { AB, BC, CD, DA } };
	
	IShape* circle = new Circle(new Point(5, 5), 2);

	surface.Cut(std::vector<IShape*> {circle});

	std::cout<<"End"<<std::endl;
}