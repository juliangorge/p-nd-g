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
        bool isFreeSquare();
        Building* getBuilding();
        Material* getMaterial();
        string getSquareName();
        char getTypeSquare();
        void setBuilding(Building* building);
        void setMaterial(Material* material);
        void changeObject();
        void emptySquare();
};

#endif //PATHSQUARE_H
