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
        bool isBuildable();
};

#endif //PATHSQUARE_H