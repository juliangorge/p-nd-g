#include "LakeSquare.h"

#include <string>

using namespace std;

LakeSquare::LakeSquare()
{
	this->type_square = 'L';
	this->is_it_path = false;
    this->is_it_terrain = false;
    this->square_name = "casillero con agua";
	this->building = nullptr;
	this->material = nullptr;
}

bool LakeSquare::isPath()
{
	return this->is_it_path;
}

bool LakeSquare::isTerrain()
{
	return this->is_it_terrain;
}

bool LakeSquare::isFreeSquare()
{
	return (this->building == nullptr);
}

Building* LakeSquare::getBuilding(){
	return this->building;
}

Material* LakeSquare::getMaterial(){
	return this->material;
}

string LakeSquare::getSquareName()
{
	return this->square_name;
}

char LakeSquare::getTypeSquare(){
	return this->type_square;
}

void LakeSquare::setBuilding(Building* building){
}

void LakeSquare::setMaterial(Material* material){
}

void LakeSquare::changeObject(){
}

void LakeSquare::emptySquare(){
	this->building = nullptr;
	changeObject();
}

LakeSquare:: ~LakeSquare(){
}