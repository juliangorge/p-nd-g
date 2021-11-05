#include "LakeSquare.h"
LakeSquare::LakeSquare()
{
	this->square_type = 'L';
    this->is_path_taken = false;
    this->is_buildable = false;
}

char LakeSquare::getTypeSquare()
{
	return this->square_type;
}

unsigned int LakeSquare:: showRow()
{
	return this->row_pos;
}

unsigned int LakeSquare:: showColumn()
{
	return this->col_pos;
}

bool LakeSquare::checkSquareStatus()
{
	return this->is_path_taken;
}

void LakeSquare::changeSquareStatus()
{
	this->is_path_taken =! this->is_path_taken;
}

bool LakeSquare::isBuildable(){
	return this->is_buildable;
}

LakeSquare:: ~LakeSquare(){
}