#include "Material.h"
#include <string>

using namespace std;

Material:: Material(string name, unsigned int quantity){
    this->name = name;
    this->quantity = quantity;
    this->material_char = 'W';

    this->getChar();
}

string Material:: getName(){
    return this->name;
}

unsigned int Material:: getQuantity(){
    return this->quantity;
}

void Material:: increaseQuantity(){
    this->quantity++;
}

void Material:: increaseQuantity(unsigned int quantity){
    this->quantity = this->quantity + quantity;
}

void Material:: decreaseQuantity(){
    this->quantity--;
}

void Material:: decreaseQuantity(unsigned int quantity){
    this->quantity = this->quantity - quantity;
}

void Material:: getChar(){

    switch(this->name[0]){
        case 'm':

            if(this->name == "Metal"){
                this->material_char = 'I';
            }else{
                this->material_char = 'W';
            }

            break;
        case 'p':
            this->material_char = 'S';
            break;
    }
}


Material:: ~Material(){
    
}