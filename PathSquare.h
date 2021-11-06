#ifndef PATHSQUARE
#define PATHSQUARE

#include "Square.h"
class PathSquare : public Square
{
    public:
        PathSquare();
        ~PathSquare();
        char getTypeSquare();
        char getTypeObject();
        string getObjName();
		bool isPath();
        bool isTerrain();
        bool isSquareFree();
        void changeObject(string object_name, char type_of_object);
        string getSquareName();
};

#endif //PATHSQUARE_H
