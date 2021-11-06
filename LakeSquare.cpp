#include "LakeSquare.h"

#include <string>

using namespace std;

LakeSquare::LakeSquare()
{
	this->square_type = 'L';
    this->is_it_path = false;
    this->is_it_terrain = false;
    this->type_of_object = this->square_type;
    this->square_name = "casillero con agua";
}

char LakeSquare::getTypeSquare()
{
	return this->square_type;
}

char LakeSquare::getTypeObject()
{
	return this->type_of_object;
}

string LakeSquare::getObjName()
{
	return this->object_name;
}

bool LakeSquare::isPath()
{
	return this->is_it_path;
}

bool LakeSquare::isTerrain()
{
	return this->is_it_terrain;
}

bool LakeSquare::isSquareFree()
{
	return this->square_type == this->type_of_object;
}
void LakeSquare::changeObject(string object_name, char type_of_object)
{
	this->object_name = object_name;
	this->type_of_object = type_of_object;
	return;
}

string LakeSquare::getSquareName()
{
	return this->square_name;
}

void LakeSquare::emptySquare()
{
	this->square_name=s.clear();
	this->type_of_object=this->square_type;
}


LakeSquare:: ~LakeSquare(){
}