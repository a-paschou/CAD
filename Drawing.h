#pragma once
#include <string>
#include <list>
#include "IShape.h"
#include <fstream>
using namespace std;

class Drawing
{
private:
	list<IShape*> shapes;
	string fileName;
public:
	Drawing(string);
	void Add(IShape*);
	void Save(); 
	~Drawing();
};