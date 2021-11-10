#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "Andypolis.h"

const int FIRST_POS = 0;
const int SECOND_POS = 1;
const int THIRD_POS = 2;
using namespace std;

// PRE:
// POST: Muestra las opciones de menu
void showMenu();

// PRE:
// POST: Se solicita el ingreso de la opcion
int getOption();

// PRE: Recibe city y la respuesta
// POST: Se ejecuta la opcion seleccionada
void selectedOption(Andypolis& city, int answer);

#endif //INTERFACE_H