#include "TerrainSquare.h"
TerrainSquare::TerrainSquare()
{
   this->square_type = 'T';

}

char TerrainSquare::getTypeSquare()
{
   return this->square_type;
}

TerrainSquare:: ~TerrainSquare(){
}