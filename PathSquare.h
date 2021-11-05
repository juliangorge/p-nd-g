#ifndef PATHSQUARE
#define PATHSQUARE

#include "Square.h"
class PathSquare : public Square
{
    public:
        PathSquare();
        ~PathSquare();
        char getTypeSquare();
        unsigned int showRow();
		unsigned int showColumn();
		bool checkSquareStatus();
		void changeSquareStatus();
};

#endif //PATHSQUARE_H
