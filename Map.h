#ifndef MAP_H
#define MAP_H

#include "Square.h"

#include "PathSquare.h"
#include "TerrainSquare.h"
#include "LakeSquare.h"
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
        bool canItBeBuildable(unsigned int & row_pos, unsigned int & column_pos);
        void showMap();
        void showCoord(unsigned int row_pos, unsigned int col_pos);
        void saveChanges(string filename_map, string filename_locations);
};


#endif // MAP_H
