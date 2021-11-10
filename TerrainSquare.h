#ifndef TERRAINSQUARE
#define TERRAINSQUARE

#include "Square.h"
class TerrainSquare : public Square
{
    public:
        TerrainSquare();
        ~TerrainSquare();
        bool isPath();
		bool isTerrain();
        bool isFreeSquare();
        Building* getBuilding();
        Material* getMaterial();
        string getSquareName();
        char getTypeSquare();
        void setBuilding(Building* building);
        void changeObject();
        void emptySquare();
};

#endif //TERRAINSQUARE_H
