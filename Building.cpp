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
        case 'M':
            this->building_char = 'M';
            this->provide_materials = true;
            break;
        case 'A':
            this->building_char = 'A';
            this->provide_materials = true;
            break;
        case 'P':
            this->building_char = 'P';
            this->provide_materials = true;
            break;
        case 'E':
            this->building_char = 'E';
            this->provide_materials = false;
            break;
        case 'O':
            this->building_char = 'O';
            this->provide_materials = false;
            break;
        default:
            this->building_char = 'F';
            this->provide_materials = true;
    }
}

Building:: ~Building(){
    
}