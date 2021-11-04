#ifndef SQUARE_H
#define SQUARE_H

class Square
{
    protected:
        unsigned int row_pos;
        unsigned int col_pos;
        char square_type;


    public:
        Square(){};
        virtual ~Square() {};
        virtual char getTypeSquare() = 0;
};

#endif // SQUARE_H
