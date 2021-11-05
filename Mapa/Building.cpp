#include "Building.h"
#include <string>

using namespace std;

Building:: Building(string name, unsigned int stone, unsigned int wood, unsigned int iron, unsigned int max){
    this->name = name;
    this->stone = stone;
    this->wood = wood;
    this->iron = iron;
    this->quantity = 0;
    this->max = max;
    this->building_char = 'F';

    this->getChar();
}

string Building:: getName(){
    return this->name;
}

unsigned int Building:: getStone(){
    return this->stone;
}

unsigned int Building:: getWood(){
    return this->wood;
}

unsigned int Building:: getIron(){
    return this->iron;
}

unsigned int Building:: getQuantity(){
    return this->quantity;
}

void Building:: increaseQuantity(){
    this->quantity++;
}

void Building:: increaseQuantity(unsigned int quantity){
    this->quantity = this->quantity + quantity;
}

void Building:: decreaseQuantity(){
    this->quantity--;
}

void Building:: decreaseQuantity(unsigned int quantity){
    this->quantity = this->quantity - quantity;
}

unsigned int Building:: getMax(){
    return this->max;
}

void Building:: getChar(){
    switch(this->name){
        case 'Mina':
            this->building_quantity = 'M';
            break;
        case 'Aserradero':
            this->building_quantity = 'A';
            break;
        case 'Planta eléctrica':
            this->building_quantity = 'P';
            break;
        case 'Escuela':
            this->building_quantity = 'E';
            break;
        case 'Obelisco':
            this->building_quantity = 'O';
            break;
        default:
            this->building_quantity = 'F';
    }
}

Building:: ~Building(){
    
}