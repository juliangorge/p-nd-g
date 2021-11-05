#include "TerrainSquare.h"
TerrainSquare::TerrainSquare()
{
   this->square_type = 'T';
   this->is_path_taken = false;
   this->is_buildable = true;
}

char TerrainSquare::getTypeSquare()
{
   return this->square_type;
}

unsigned int TerrainSquare:: showRow()
{
	return this->row_pos;
}
unsigned int TerrainSquare:: showColumn()
{
	return this->col_pos;
}

bool TerrainSquare::checkSquareStatus()
{
	return this->is_path_taken;
}

void TerrainSquare::changeSquareStatus()
{
	this->is_path_taken =! this->is_path_taken;
}

bool TerrainSquare::isBuildable(){
	return this->is_buildable;
}

TerrainSquare:: ~TerrainSquare(){
}