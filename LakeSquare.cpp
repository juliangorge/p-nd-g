#include "LakeSquare.h"
LakeSquare::LakeSquare()
{
    this->square_type = 'L';
    this->is_path_taken = true;
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

}

LakeSquare:: ~LakeSquare(){
}