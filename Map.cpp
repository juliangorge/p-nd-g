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

bool Map::canItBeBuildable(unsigned int & row_pos, unsigned int & column_pos){
    if(this->rows < row_pos && this->columns < column_pos) return false;

    Square* square_aux = this->squares[row_pos][column_pos];
    return (!square_aux->isPathTaken() && square_aux->isBuildable());
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
    cout << "Ese casillero es: " << this->squares[row_pos][col_pos]->getTypeSquare() << endl;
    cout << "El casillero esta: " << this->squares[row_pos][col_pos]->isPathTaken() << endl;
}

void Map::saveChanges(string filename_map, string filename_locations){
    ofstream file_map(filename_map);
    ofstream file_locations(filename_locations);

    for (unsigned int i = 0; i < this->rows; i++)
    {
        for (unsigned int j = 0; j < this->columns; j++)
        {

            string building_name = "falta";
            // En ij -> isBuildable = true (es un terreno) y 
            // ...

            file_locations << building_name << " (" << j << ", " << j << ")" << '\n';
            file_map << this->squares[i][j]->getTypeSquare() << '\n';

            delete this->squares[i][j];
        }
        
        delete [] this->squares[i];
    }

    delete [] this->squares;
    file_locations.close();
    file_map.close();
}
