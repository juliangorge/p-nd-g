#include "functions.h"
#include <iostream>

using namespace std;

void showMenu(){
    cout << endl; 
    cout << "1. Listar materiales de construcción." << endl;
    cout << "2. Construir edificio por nombre." << endl;
    cout << "3. Listar los edificios construidos." << endl;
    cout << "4. Listar todos los edificios." << endl;
    cout << "5. Demoler un edificio por nombre." << endl;
    cout << "6. Guardar y salir." << endl;
    cout << endl;
}

void selectedOption(Andypolis& City, int answer){
    switch(answer){
        case 1:
            City.showMaterials();
            break;
        case 2:
            City.newBuilding();
            break;
        case 3:
            City.showBuiltBuildings();
            break;
        case 4:
            City.showBuildings();
            break;
        case 5:
            City.deleteBuilding();
            break;
    }
}

int get_option(){
    string option;
    int answer;
    cout << "Ingrese el número de su acción elegida : ";
    cin >> option;
    bool is_valid_option = option[0] >= (int)'1' && option[0] <= (int)'6' && option[1]=='\0';

    while(!is_valid_option){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> option;
        is_valid_option = option[0] >= (int)'1' && option[0] <= (int)'6' && option[1]=='\0';
    }
    answer=stoi(option);

    return answer;
}