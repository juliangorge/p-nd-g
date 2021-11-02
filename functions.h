#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "Andypolis.h"

// PRE:
// POST: Imprime el menu en pantalla.
void showMenu();

// PRE: Recibe la Ciudad y el valor ingresado por consola.
// POST: Retorna TRUE si la opcion fue valida y llama a la funcion acorde a la opcion seleccionada.
void selectedOption(Andypolis& City, int answer);

#endif