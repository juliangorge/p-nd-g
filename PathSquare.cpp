#include "PathSquare.h"

#include <string>

using namespace std;

PathSquare::PathSquare()
{
	this->type_square = 'C';
	this->is_it_path = true;
	this->is_it_terrain = false;
	this->square_name = "casillero transitable";
	this->building = nullptr;
	this->material = nullptr;
}

bool PathSquare::isPath()
{
	return this->is_it_path;
}

bool PathSquare::isTerrain()
{
	return this->is_it_terrain;
}

bool PathSquare::isFreeSquare()
{
	return (this->material == nullptr);
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

void PathSquare::setBuilding(Building* building){
}

void PathSquare::setMaterial(Material* material){
	this->material = material;
	changeObject();
}

void PathSquare::changeObject(){
	if(isFreeSquare()){
		this->type_square = 'C';
	}else{
		this->type_square = this->material->getMaterialChar();
	}
}

void PathSquare::emptySquare(){
	this->building = nullptr;
	changeObject();
}

PathSquare::~PathSquare(){
}
