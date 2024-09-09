#include "Drawing.h"

Drawing::Drawing(string fileName)
	: fileName{ fileName }
{
}

void Drawing::Add(IShape* newShape)
{
	shapes.push_back(newShape);
}

void Drawing::Save()
{
	ofstream file;
	file.open(fileName);

	for (IShape* shape : shapes)
	{
		string s = shape->GetData();
		file << s << endl;
	}

	file.close();
}

Drawing::~Drawing()
{
	for (auto shape : shapes)
	{
		delete shape;
	}
	shapes.clear();

}
