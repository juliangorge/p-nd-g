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

        for (unsigned int column_pos = 0; column_pos < this->columns; column_pos++)
        {

            file >> square_type;
            this->loadMap(row_pos,column_pos,square_type);

        }
    }

    file.close();

}

void Map::loadMap(unsigned int row_pos, unsigned int column_pos, char square_type)
{
    switch(square_type)
    {
        case 'T':
            this->squares[row_pos][column_pos] = new TerrainSquare();
            break;

        case 'C':
            this->squares[row_pos][column_pos] = new PathSquare();
            break;

        case 'L':
            this->squares[row_pos][column_pos] = new LakeSquare();
            break;
    }
}

void Map::addCoords(unsigned int & row_pos, unsigned int & column_pos)
{
    cout << "Escribe la fila: ";
    cin >> row_pos;

    row_pos--;

    cout << "Escribe la columna: ";
    cin >> column_pos;

    column_pos--;
}

bool Map::checkCoords(unsigned int row_pos, unsigned int column_pos)
{
	return (row_pos < this->rows &&  column_pos < this->columns);
}

bool Map::checkTerrainSquare(unsigned int row_pos, unsigned int column_pos)
{  
    if(!this->squares[row_pos][column_pos]->isTerrain()){
    	cout << "El casillero elegido no es terreno construible" << endl;
    	return false;
    }
    if(!this->squares[row_pos][column_pos]->isSquareFree()){
    	cout << "El casillero elegido está ocupado" << endl;
    	return false;
    } 
    return true;
}

bool Map::checkTerrainBuilding(unsigned int row_pos, unsigned int column_pos)
{  
    if(!this->squares[row_pos][column_pos]->isTerrain()){
        cout << "El casillero elegido no es terreno construible" << endl;
        return false;
    }
    if(this->squares[row_pos][column_pos]->isSquareFree()){
        cout << "El casillero esta vacío" << endl;
        return false;
    } 
    return true;
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

void Map::showCoord(unsigned int row_pos, unsigned int column_pos)
{
    cout << "Ese casillero es: " << this->squares[row_pos][column_pos]->getTypeSquare() << endl;
}

void Map::saveChanges(string filename_locations, int building_quantity_total){
    ofstream file_locations(filename_locations);

    int building_quantity_aux = 0;

    for (unsigned int i = 0; i < this->rows; i++)
    {
        for (unsigned int j = 0; j < this->columns; j++)
        {

            if(!this->squares[i][j]->isSquareFree()){
                file_locations << this->squares[i][j]->getBuilding()->getName() << " (" << i << ", " << j << ")";

                building_quantity_aux++;
                if(building_quantity_aux < building_quantity_total) file_locations << '\n';
            }

            delete this->squares[i][j];
        }

        delete [] this->squares[i];
    }

    delete [] this->squares;
    file_locations.close();
}

void Map::setObject(unsigned row_pos, unsigned column_pos, Building* building){
    this->squares[row_pos][column_pos]->setBuilding(building);
}

void Map::getSquareData(unsigned int row_pos, unsigned int column_pos)
{
    if(this->squares[row_pos][column_pos]->isSquareFree()){
        cout << "Soy un " << squares[row_pos][column_pos]->getSquareName() << " y me encuentro vacio" << endl;
        return;
    }
    cout << "Soy " << squares[row_pos][column_pos]->getBuilding()->getName() << " y estoy en las coordenadas " << "(" << row_pos << "," << column_pos << ")" << endl;
    return;

}

void Map::emptySquare(unsigned int row_pos, unsigned int column_pos)
{
    this->squares[row_pos][column_pos]->emptySquare();
    return;
}

string Map::getNamefromCoods(unsigned int row_pos, unsigned int column_pos){
    return this->squares[row_pos][column_pos]->getBuilding()->getName();
}