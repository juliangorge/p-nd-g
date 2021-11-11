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
    this->squares = nullptr;
    this->path_square_quantity = 0;
    this->readMap();
}

Map::~Map(){
    
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
            this->path_square_quantity++;
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
    if(!this->squares[row_pos][column_pos]->isFreeSquare()){
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
    if(this->squares[row_pos][column_pos]->isFreeSquare()){
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

string Map::printCoordsByName(string name){
    string aux;
    for (unsigned int i = 0; i < this->rows; i++)
    {
        for (unsigned int j = 0; j < this->columns; j++)
        {
            if(!this->squares[i][j]->isFreeSquare()){
                if(this->squares[i][j]->getBuilding()->getName() == name){
                    aux += "(" + to_string(i) + "," + to_string(j) + ") ";
                }
            }
        }
    }

    return aux;
}
        

void Map::showCoord(unsigned int row_pos, unsigned int column_pos)
{
    cout << "Ese casillero es: " << this->squares[row_pos][column_pos]->getTypeSquare() << endl;
}

unsigned int Map:: getPathSquareQuantity(){
    return this->path_square_quantity;
}

Square** Map:: getPathSquaresPos()
{
	Square** path_squares = new Square*[this->getPathSquareQuantity()];
    int path_square_pos = 0;
    
    for (unsigned int i = 0; i < this->rows; i++){
        for (unsigned int j = 0; j < this->columns; j++){
            if(this->squares[i][j]->isPath()){
                path_squares[path_square_pos] = this->squares[i][j];
                path_square_pos++;
            }
        }
    }
    return path_squares;
}

void Map:: addMaterialToRandomPathSquares(Square** path_squares, Material* material, int material_quantity){
   
    for (int i = 0; i < material_quantity; i++){
        int random_path_square = rand() % (int) (this->path_square_quantity);
        if(path_squares[random_path_square]->isFreeSquare()){
            path_squares[random_path_square]->setMaterial(material);
        }
    }

}

void Map::saveChanges(string filename_locations, int building_quantity_total){
    ofstream file_locations(filename_locations);

    int building_quantity_aux = 0;
    for (unsigned int i = 0; i < this->rows; i++)
    {
        for (unsigned int j = 0; j < this->columns; j++)
        {
            if(!this->squares[i][j]->isFreeSquare()){
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

void Map::getEmptySquare(unsigned int row_pos, unsigned int column_pos){
    this->squares[row_pos][column_pos]->emptySquare();
}

void Map::getSquareData(unsigned int row_pos, unsigned int column_pos)
{
    if(this->squares[row_pos][column_pos]->isFreeSquare()){
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

string Map::getNamefromCoords(unsigned int row_pos, unsigned int column_pos){
    return this->squares[row_pos][column_pos]->getBuilding()->getName();
}