#ifndef Material_INCLUDED
#define Material_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Material {

    // Attributes
    private:
        string name;
        unsigned int quantity;
        char material_char;

    // Methods
    public:

        // PRE: Los parametros deben ser validos.
	    // POST: Crea un objeto Material.
        Material(string name, unsigned int quantity);

        // PRE:
        // POST: Destruye un objeto Material.
        ~Material();

        // PRE:
        // POST: Retorna el nombre
        string getName();

        // PRE:
        // POST: Retorna la cantidad
        unsigned int getQuantity();
        
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
        // POST: Retorna el valor valido
        void getChar();
};

#endif