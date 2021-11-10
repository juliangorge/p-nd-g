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
    this->building_char = 'B';
    this->provide_materials = true;

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

unsigned int Building:: getMaterialsProvided(){
    return this->materials_provided;
}

char Building:: getBuildingChar(){
    return this->building_char;
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
    switch(this->name[0]){
        case 'm':
            this->building_char = 'M';
            this->provide_materials = true;
            this->materials_provided = 15;
            break;
        case 'a':
            this->building_char = 'A';
            this->provide_materials = true;
            this->materials_provided = 25;
            break;
        case 'f':
            this->building_char = 'F';
            this->provide_materials = true;
            this->materials_provided = 40;
            break;
        case 'e':
            this->building_char = 'E';
            this->provide_materials = false;
            break;
        case 'o':
            this->building_char = 'O';
            this->provide_materials = false;
            break;
        case 'p':
            this->building_char = 'P';
            this->provide_materials = false;
        default:
            this->building_char = 'B';
            this->provide_materials = false;
    }
}

Building:: ~Building(){
    
}