#ifndef TERRAINSQUARE
#define TERRAINSQUARE

#include "Square.h"
class TerrainSquare : public Square
{
    public:
        TerrainSquare();
        ~TerrainSquare();
        char getTypeSquare();
        char getTypeObject();
        string getObjName();
		bool isPath();
		bool isTerrain();
        bool isSquareFree();
        void changeObject(string object_name, char type_of_object);
        string getSquareName();
        void emptySquare();
};

#endif //TERRAINSQUARE_H
