#ifndef MAP_H
#define MAP_H

#include "Square.h"

#include "PathSquare.h"
#include "TerrainSquare.h"
#include "LakeSquare.h"

class Map
{
    private:
        unsigned int rows;
        unsigned int columns;
        Square*** squares;

    public:
        Map();
        void readMap();
        void loadMap(unsigned int rows, unsigned int columns, char square_type);
        bool canItBeBuildable(unsigned int & row_pos, unsigned int & column_pos);
        void showMap();
        void showCoord(unsigned int row_pos, unsigned int col_pos);
        void flushMemory();
};


#endif // MAP_H
