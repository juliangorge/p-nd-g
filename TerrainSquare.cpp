#include "TerrainSquare.h"

#include <string>

using namespace std;

TerrainSquare::TerrainSquare()
{
   this->square_type = 'T';
   this->is_it_path = false;
   this->is_it_terrain = true;
   this->type_of_object = this->square_type;
   this->square_name = "casillero construible";
}

char TerrainSquare::getTypeSquare()
{
   return this->square_type;
}

char TerrainSquare::getTypeObject()
{
	return this->type_of_object;
}

string TerrainSquare::getObjName()
{
	return this->object_name;
}

bool TerrainSquare::isPath()
{
	return this->is_it_path;
}

bool TerrainSquare::isTerrain()
{
	return this->is_it_terrain;
}

bool TerrainSquare::isSquareFree()
{
	return (this->square_type == this->type_of_object);
}
void TerrainSquare::changeObject(string object_name, char type_of_object)
{
	this->object_name = object_name;
	this->type_of_object = type_of_object;
	return;
}

string TerrainSquare::getSquareName()
{
	return this->square_name;
}

void TerrainSquare::emptySquare()
{
	this->object_name.clear();
	this->type_of_object=this->square_type;
}

TerrainSquare:: ~TerrainSquare(){
}