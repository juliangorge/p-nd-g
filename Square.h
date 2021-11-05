#ifndef SQUARE_H
#define SQUARE_H

class Square
{
    protected:
        unsigned int row_pos;
        unsigned int col_pos;
        char square_type;
        bool is_path_taken;
        bool is_buildable;

    public:
        Square(){};
        virtual ~Square() {};
        virtual char getTypeSquare() = 0;
        virtual unsigned int showRow() = 0;
        virtual unsigned int showColumn() = 0;
		virtual bool checkSquareStatus() = 0;
		virtual void changeSquareStatus() = 0;
        virtual bool isBuildable() = 0;
};

#endif // SQUARE_H
