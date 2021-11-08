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
        void showCoord(unsigned int row_pos, unsigned int col_pos);
        void saveChanges(string filename_map, string filename_locations, int building_quantity_total);
        void setSquareName(unsigned int row_pos, unsigned int col_pos, string name, char building_char);
        void getSquareData(unsigned int row_pos, unsigned int col_pos);
        void emptySquare(unsigned int row_pos, unsigned int col_pos);
        string getNamefromCoods(unsigned int row_pos, unsigned int col_pos);
};


#endif // MAP_H
