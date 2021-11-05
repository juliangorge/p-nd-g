#ifndef TERRAINSQUARE
#define TERRAINSQUARE

#include "Square.h"
class TerrainSquare : public Square
{
    public:
        TerrainSquare();
        ~TerrainSquare();
        char getTypeSquare();
        unsigned int showRow();
		unsigned int showColumn();
		bool checkSquareStatus();
		void changeSquareStatus();
        bool isBuildable();

};

#endif //TERRAINSQUARE_H
