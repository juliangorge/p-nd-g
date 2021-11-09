#ifndef PATHSQUARE
#define PATHSQUARE

#include "Square.h"
class PathSquare : public Square
{
    public:
        PathSquare();
        ~PathSquare();
		bool isPath();
        bool isTerrain();
        bool isSquareFree();
        Building* getBuilding();
        Material* getMaterial();
        string getSquareName();
        char getTypeSquare();
        void changeObject();
        void emptySquare();
};

#endif //PATHSQUARE_H
