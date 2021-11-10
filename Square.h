#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <iostream>
#include "Building.h"
#include "Material.h"

using namespace std;

class Square
{
    protected:
        // Es un camino transitable
        bool is_it_path;

        // Es un terreno
        bool is_it_terrain;

        // Nombre del casillero (fijo)
        string square_name;

        char type_square;

        Building* building;

        Material* material;

    public:
        Square(){};
        virtual ~Square() {};
        virtual bool isPath() = 0;
        virtual bool isTerrain() = 0;
        virtual bool isSquareFree() = 0;
        virtual Building* getBuilding() = 0;
        virtual Material* getMaterial() = 0;
        virtual string getSquareName() = 0;
        virtual char getTypeSquare() = 0;
        virtual void setBuilding(Building* building) = 0;
        virtual void changeObject() = 0;
        virtual void emptySquare() = 0;
};

#endif // SQUARE_H
