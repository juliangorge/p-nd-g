#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <iostream>

using namespace std;

class Square
{
    protected:
        // Es un camino transitable
        bool is_it_path;

        // Es un terreno
        bool is_it_terrain;

        // Caracter del edificio/material en ese casillero (si está vacío es igual a square_type)
        char type_of_object;

        // Nombre del edificio/material contenido en el casillero (si está vacio no hay nombre)
        string object_name;

        // Caracter del casillero (fijo)
        char square_type;

        // Nombre del casillero (fijo)
        string square_name;

    public:
        Square(){};
        virtual ~Square() {};
        virtual char getTypeSquare() = 0;
        virtual char getTypeObject() = 0;
        virtual string getObjName() = 0;
		virtual bool isPath() = 0;
        virtual bool isTerrain() = 0;
        virtual bool isSquareFree() = 0;
        virtual void changeObject(string object_name, char type_of_object) = 0;
        virtual string getSquareName() = 0;
        virtual void emptySquare() = 0;
};

#endif // SQUARE_H
