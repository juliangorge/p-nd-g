#include "TerrainSquare.h"

#include <string>

using namespace std;

TerrainSquare::TerrainSquare()
{
	this->type_square = 'T';
	this->is_it_path = false;
	this->is_it_terrain = true;
	this->square_name = "casillero construible";
	this->building = nullptr;
}

bool TerrainSquare::isPath()
{
	return this->is_it_path;
}

bool TerrainSquare::isTerrain()
{
	return this->is_it_terrain;
}

bool TerrainSquare::isFreeSquare()
{
	return (this->building == nullptr);
}

Building* TerrainSquare::getBuilding(){
	return this->building;
}

Material* TerrainSquare::getMaterial(){
	return this->material;
}

string TerrainSquare::getSquareName()
{
	return this->square_name;
}

char TerrainSquare::getTypeSquare(){
	return this->type_square;
}

void TerrainSquare::setBuilding(Building* building){
	this->building = building;
	changeObject();
}

void TerrainSquare::changeObject(){
	if(isFreeSquare()){
		this->type_square = 'T';
	}else{
		this->type_square = this->building->getBuildingChar();
	}
}


void TerrainSquare::emptySquare()
{
	this->building = nullptr;
	changeObject();
}

TerrainSquare:: ~TerrainSquare(){
}