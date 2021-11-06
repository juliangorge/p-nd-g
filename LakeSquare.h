#ifndef LAKESQUARE
#define LAKESQUARE

#include "Square.h"
class LakeSquare : public Square
{
    public:
        LakeSquare();
        ~LakeSquare();
        char getTypeSquare();
        char getTypeObject();
        string getObjName();
		bool isPath();
        bool isTerrain();
        bool isSquareFree();
        void changeObject(string object_name, char type_of_object);
        string getSquareName();
};

#endif //LAKESQUARE_H
