#ifndef LAKESQUARE
#define LAKESQUARE

#include "Square.h"
class LakeSquare : public Square
{
    public:
        LakeSquare();
        ~LakeSquare();
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

#endif //LAKESQUARE_H
