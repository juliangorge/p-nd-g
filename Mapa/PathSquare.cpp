#include "PathSquare.h"
PathSquare::PathSquare()
{
    this->square_type = 'C';

}
char PathSquare::getTypeSquare()
{
  return this->square_type;
}

PathSquare:: ~PathSquare(){
}