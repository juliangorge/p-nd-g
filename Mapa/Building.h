#ifndef Building_INCLUDED
#define Building_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Building {

    // Attributes
    private:
        string name;
        int stone;
        int wood;
        int iron;
        int quantity;
        int max;
        char building_char;
        bool provide_materials;

    // Methods
    public:
    
        // PRE: Los parametros deben ser validos.
	    // POST: Crea un objeto Building.
        Building(string name, int stone, int wood, int iron, int max);
        
        // PRE:
        // POST: Destruye un objeto Building.
        ~Building();

        // PRE:
        // POST: Retorna el nombre.
        string getName();

        // PRE:
        // POST: Retorna la cantidad de piedra.
        int getStone();

        // PRE:
        // POST: Retorna la cantidad de madera.
        int getWood();

        // PRE:
        // POST: Retorna la cantidad de metal.
        int getIron();

        // PRE:
        // POST: Retorna la cantidad de edificios construidos.
        int getQuantity();

        // PRE:
        // POST: Suma una unidad a la cantidad
        void increaseQuantity();
    
        // PRE: Recibe un valor entero
        // POST: Suma el valor ingresado a la cantidad previa
        void increaseQuantity(int quantity);
        
        // PRE:
        // POST: Resta una unidad a la cantidad
        void decreaseQuantity();

        // PRE: Recibe un valor entero
        // POST: Resta el valor ingresado a la cantidad previa
        void decreaseQuantity(int quantity);

        // PRE:
        // POST: Retorna la cantidad maxima de edificios.
        int getMax();

        // PRE: 
        // POST: Retorna el valor valido
        void getChar();
};

#endif