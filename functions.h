#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "Andypolis.h"

// PRE:
// POST: Imprime el menu en pantalla.
void showMenu();

// PRE: La opcion debe haber sido validada.
// POST: Genera alguna de las acciones del menu en base a la opcion elegida.
void selectedOption(Andypolis& City, int answer);

// PRE: 
// POST: Retorna una opcion validada del menu
int get_option();
#endif