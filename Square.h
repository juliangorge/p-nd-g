#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <iostream>

using namespace std;

class Square
{
    protected:
        char square_type;
        bool is_it_path;
        bool is_it_terrain;
        char type_of_object;
        string object_name;
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
        virtual void emptySquare();
};

#endif // SQUARE_H
