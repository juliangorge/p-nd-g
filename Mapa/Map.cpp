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
    //this->createMap(this->rows,this->columns);

    for (unsigned int row_pos = 0; row_pos < this->rows; row_pos++)
    {
        for (unsigned int col_pos = 0; col_pos < this->columns; col_pos++)
        {
            file >> square_type;
            this->loadMap(row_pos,col_pos,square_type);
        }
    }

    file.close();

}

/*void Map::createMap(unsigned int rows, bool rows)
{
    this->
}*/

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
    }

    //this->vehiculos[cantidadDeVehiculos]->verificarTelepase(telepase); //Aca esta el polimorfismo

}

void Map::showMap()
{
    cout << "Filas: " << this->rows << endl;
    cout << "Columnas: " << this->columns << endl;
    for (unsigned int i = 0; i < this->rows; i++)
    {
        for (unsigned int j = 0; j < this->columns; j++)
        {
            cout<< this->squares[0][j]->getTypeSquare()<< " ";
        }
        cout << endl;
    }
}