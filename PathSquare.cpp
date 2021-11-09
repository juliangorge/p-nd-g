#include "PathSquare.h"

#include <string>

using namespace std;

PathSquare::PathSquare()
{
	this->type_square = 'C';
	this->is_it_path = true;
	this->is_it_terrain = false;
	this->square_name = "casillero transitable";
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
	return (this->building == nullptr);
}

Building* PathSquare::getBuilding(){
	return this->building;
}

Material* PathSquare::getMaterial(){
	return this->material;
}

string PathSquare::getSquareName()
{
	return this->square_name;
}

char PathSquare::getTypeSquare(){
	return this->type_square;
}

void PathSquare::changeObject(){
}

void PathSquare::emptySquare()
{
	//this->square_name.clear();
}

PathSquare::~PathSquare(){
}
