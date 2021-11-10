#ifndef MAP_H
#define MAP_H

#include "Square.h"

#include "PathSquare.h"
#include "TerrainSquare.h"
#include "LakeSquare.h"
#include "Building.h"
#include <string>

using namespace std;

class Map
{
    private:
        unsigned int rows;
        unsigned int columns;
        unsigned int path_square_quantity;
        Square*** squares;

    public:
        Map();
        ~Map();
        void readMap();
        void loadMap(unsigned int rows, unsigned int columns, char square_type);
        void addCoords(unsigned int & row_pos, unsigned int & column_pos);
        bool checkCoords(unsigned int row_pos, unsigned int column_pos);
        bool checkTerrainSquare(unsigned int row_pos, unsigned int column_pos);
        bool checkTerrainBuilding(unsigned int row_pos, unsigned int column_pos);
        void showMap();
        string printCoordsByName(string name);
        void showCoord(unsigned int row_pos, unsigned int column_pos);
        unsigned int getPathSquareQuantity();
        void addMaterialToRandomPathSquares(Square** path_squares, Material* material, int material_quantity);
        void saveChanges(string filename_locations, int building_quantity_total);
        void setObject(unsigned int row_pos, unsigned int column_pos, Building* building);
        void getEmptySquare(unsigned int row_pos, unsigned int column_pos);
        void getSquareData(unsigned int row_pos, unsigned int column_pos);
        void emptySquare(unsigned int row_pos, unsigned int column_pos);
        string getNamefromCoords(unsigned int row_pos, unsigned int column_pos);
};


#endif // MAP_H
