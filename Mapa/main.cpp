#include <iostream>
#include "Map.h"

using namespace std;

int main()
{
	unsigned int row_pos;
	unsigned int col_pos;
    Map map;
    map.showMap();
    cout<<"Ingrese coordenada: ";
    cin>>row_pos;
    cin>>col_pos;
    map.showCoord(row_pos, col_pos);
    return 0;
}
