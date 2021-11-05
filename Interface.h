#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "Andypolis.h"

const int FIRST_POS = 0;
const int SECOND_POS = 1;
const int THIRD_POS = 2;
using namespace std;

// PRE:
// POST: 
void showMenu();

// PRE:
// POST: 
int getOption();

// PRE:
// POST: 
void selectedOption(Andypolis& city, int answer);

#endif //INTERFACE_H