#ifndef Building_INCLUDED
#define Building_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Building {

    // Attributes
    private:
        string name;
        unsigned int stone;
        unsigned int wood;
        unsigned int iron;
        unsigned int quantity;
        unsigned int max;
        char building_char;
        bool provide_materials;
        unsigned int materials_provided;

    // Methods
    public:
    
        // PRE: Los parametros deben ser validos.
	    // POST: Crea un objeto Building.
        Building(string name, unsigned int stone, unsigned int wood, unsigned int iron, unsigned int max);
        
        // PRE:
        // POST: Destruye un objeto Building.
        ~Building();

        // PRE:
        // POST: Retorna el nombre.
        string getName();

        // PRE:
        // POST: Retorna la cantidad de piedra.
        unsigned int getStone();

        // PRE:
        // POST: Retorna la cantidad de madera.
        unsigned int getWood();

        // PRE:
        // POST: Retorna la cantidad de metal.
        unsigned int getIron();

        // PRE:
        // POST: Retorna la cantidad de edificios construidos.
        unsigned int getQuantity();

        // PRE:
        // POST: Retorna la cantidad de materiales que provee el edificio
        unsigned int getMaterialsProvided();

        // PRE:
        // POST: Retorna el caracter del edificio.
        char getBuildingChar();

        // PRE:
        // POST: Suma una unidad a la cantidad
        void increaseQuantity();
    
        // PRE: Recibe un valor entero
        // POST: Suma el valor ingresado a la cantidad previa
        void increaseQuantity(unsigned int quantity);
        
        // PRE:
        // POST: Resta una unidad a la cantidad
        void decreaseQuantity();

        // PRE: Recibe un valor entero
        // POST: Resta el valor ingresado a la cantidad previa
        void decreaseQuantity(unsigned int quantity);

        // PRE:
        // POST: Retorna la cantidad maxima de edificios.
        unsigned int getMax();

        // PRE: 
        // POST: Retorna el valor valido
        void getChar();
};

#endif