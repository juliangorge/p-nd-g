#include "Building.h"
#include <string>

using namespace std;

Building:: Building(string name, int stone, int wood, int iron, int quantity, int max){
    this->name = name;
    this->stone = stone;
    this->wood = wood;
    this->iron = iron;
    this->quantity = quantity;
    this->max = max;
}

string Building:: getName(){
    return this->name;
}

int Building:: getStone(){
    return this->stone;
}

int Building:: getWood(){
    return this->wood;
}

int Building:: getIron(){
    return this->iron;
}

int Building:: getQuantity(){
    return this->quantity;
}

void Building:: increaseQuantity(){
    this->quantity++;
}

void Building:: increaseQuantity(int quantity){
    this->quantity = this->quantity + quantity;
}

void Building:: decreaseQuantity(){
    this->quantity--;
}

void Building:: decreaseQuantity(int quantity){
    this->quantity = this->quantity - quantity;
}

int Building:: getMax(){
    return this->max;
}

Building:: ~Building(){
    
}