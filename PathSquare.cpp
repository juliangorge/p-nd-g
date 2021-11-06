#include "PathSquare.h"

#include <string>

using namespace std;

PathSquare::PathSquare()
{
	this->square_type = 'C';
	this->is_it_path = true;
	this->is_it_terrain = false;
	this->type_of_object = this->square_type;
	this->square_name = "casillero transitable";
}

char PathSquare::getTypeSquare()
{
  return this->square_type;
}

char PathSquare::getTypeObject()
{
	return this->type_of_object;
}

string PathSquare::getObjName()
{
	return this->object_name;
}

bool PathSquare::isPath()
{
	return this->is_it_path;
}

bool PathSquare::isTerrain()
{
	return this->is_it_terrain;
}

bool PathSquare::isSquareFree()
{
	return this->square_type == this->type_of_object;
}
void PathSquare::changeObject(string object_name, char type_of_object)
{
	this->object_name = object_name;
	this->type_of_object = type_of_object;
	return;
}

string PathSquare::getSquareName()
{
	return this->square_name;
}

PathSquare::~PathSquare(){
}
