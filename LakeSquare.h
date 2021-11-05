#ifndef LAKESQUARE
#define LAKESQUARE

#include "Square.h"
class LakeSquare : public Square
{
    public:
        LakeSquare();
        ~LakeSquare();
        char getTypeSquare();
        unsigned int showRow();
		unsigned int showColumn();
		bool checkSquareStatus();
		void changeSquareStatus();
};

#endif //LAKESQUARE_H
