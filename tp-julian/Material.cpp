#include "Material.h"
#include <string>

using namespace std;

Material:: Material(string name, int quantity){
    this->name = name;
    this->quantity = quantity;
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

Material:: ~Material(){
    
}