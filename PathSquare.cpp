#include "PathSquare.h"
PathSquare::PathSquare()
{
	this->square_type = 'C';
	this->is_path_taken = false;
	this->is_buildable = false;
}

char PathSquare::getTypeSquare()
{
  return this->square_type;
}

unsigned int PathSquare::showRow()
{
	return this->row_pos;
}
unsigned int PathSquare::showColumn()
{
	return this->col_pos;
}

bool PathSquare::checkSquareStatus()
{
	return this->is_path_taken;
}

void PathSquare::changeSquareStatus()
{
	this->is_path_taken =! this->is_path_taken;
}

bool PathSquare::isBuildable(){
	return this->is_buildable;
}

PathSquare::~PathSquare(){
}