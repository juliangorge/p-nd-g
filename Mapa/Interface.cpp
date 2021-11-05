#include "Interface.h"

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

void selectedOption(Andypolis& city, int answer){
    switch(answer){
        case 1:
            city.showMaterials();
            break;
        case 2:
            city.newBuilding();
            break;
        case 3:
            city.showBuiltBuildings();
            break;
        case 4:
            city.showBuildings();
            break;
        case 5:
            city.deleteBuilding();
            break;
    }
}

int getOption(){
    string option;

    int answer;

    cout << "Ingrese el número de su acción elegida : ";
    cin >> option;

    bool isValidOption = option[0] >= (int)'1' && option[0] <= (int)'6' && option[1] == '\0';

    while(!isValidOption){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> option;
        isValidOption = option[0] >= (int)'1' && option[0] <= (int)'6' && option[1] == '\0';
    }

    answer = stoi(option);

    return answer;
}