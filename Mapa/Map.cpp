#include "Map.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const string PATH = "mapa.txt";

Map::Map()
{
    this->rows = 0;
    this->columns = 0;
    this->readMap();
}

void Map::readMap()
{
    ifstream file;
    file.open(PATH.c_str());
    char square_type;

    if(!file)
    {
        cout << "No se pudo leer el archivo: " << PATH << endl;
        exit(1);
    }

    file >> this->rows >> this->columns;

    this->squares = new Square**[this->rows];

    for (unsigned int row_pos = 0; row_pos < this->rows; row_pos++)
    {

        this->squares[row_pos] = new Square*[this->columns];

        for (unsigned int col_pos = 0; col_pos < this->columns; col_pos++)
        {

            file >> square_type;
            this->loadMap(row_pos,col_pos,square_type);

        }
    }

    file.close();

}

void Map::loadMap(unsigned int row_pos, unsigned int col_pos, char square_type)
{
    switch(square_type)
    {
        case 'T':
            this->squares[row_pos][col_pos] = new TerrainSquare();
            break;

        case 'C':
            this->squares[row_pos][col_pos] = new PathSquare();
            break;

        case 'L':
            this->squares[row_pos][col_pos] = new LakeSquare();
            break;
    }
}

void Map::showMap()
{
    cout << "Filas: " << this->rows << endl;
    cout << "Columnas: " << this->columns << endl;
    for (unsigned int i = 0; i < this->rows; i++)
    {
        for (unsigned int j = 0; j < this->columns; j++)
        {
            cout << this->squares[i][j]->getTypeSquare() << " ";
        }
        cout << endl;
    }
}

void Map::showCoord(unsigned int row_pos, unsigned int col_pos)
{
    cout <<"Ese casillero es: "<< this->squares[row_pos][col_pos]->getTypeSquare() << endl;
    cout << "El casillero esta: "<<this->squares[row_pos][col_pos]->checkSquareStatus() << endl;
}