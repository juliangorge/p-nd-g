#include "Material.h"
#include <string>

using namespace std;

Material:: Material(string name, int quantity){
    this->name = name;
    this->quantity = quantity;
    this->material_char = 'W';

    this->getChar();
}

string Material:: getName(){
    return this->name;
}

int Material:: getQuantity(){
    return this->quantity;
}

void Material:: increaseQuantity(){
    this->quantity++;
}

void Material:: increaseQuantity(int quantity){
    this->quantity = this->quantity + quantity;
}

void Material:: decreaseQuantity(){
    this->quantity--;
}

void Material:: decreaseQuantity(int quantity){
    this->quantity = this->quantity - quantity;
}

void Material:: getChar(){
    switch(this->name){
        case 'Metal':
            this->material_char = 'I';
            break;
        case 'Piedra':
            this->material_char = 'S';
            break;
        default:
            this->material_char = 'W';
    }
}


Material:: ~Material(){
    
}