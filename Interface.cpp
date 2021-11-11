#include "Interface.h"

using namespace std;

void showMenu(){
    cout << endl; 
    cout << "1. Construir edificio por nombre." << endl;
    cout << "2. Listar los edificios construidos." << endl;
    cout << "3. Listar todos los edificios." << endl;
    cout << "4. Demoler un edificio por coordenada." << endl;
    cout << "5. Mostrar mapa." << endl;
    cout << "6. Consultar coordenada." << endl;
    cout << "7. Mostrar inventario." << endl;
    cout << "8. Recolectar recursos producidos." << endl;
    cout << "9. Lluvia de recursos." << endl;
    cout << "10. Guardar y salir. " << endl;
    cout << endl;
}

void selectedOption(Andypolis& city, int answer){
    switch(answer){
        case 1:
            city.newBuildingByName();
            break;
        case 2:
            city.showBuiltBuildings();
            break;
        case 3:
            city.showBuildings();
            break;
        case 4:
            city.deleteBuildingByCoords();
            break;
        case 5:
            city.showMap();
            break;
        case 6:
            city.checkCoords();
            break;
        case 7:
            city.showInventory();
            break;
        case 8:
            city.colectResources();
            break;
        case 9:
            city.rainResources();
            break;
        case 10:
            break;
    }
}

int getOption(){
    string option;

    int answer;

    cout << "Ingrese el número de su acción elegida: ";
    cin >> option;

    bool isValidOption = (option[FIRST_POS] >= (int)'1' && option[FIRST_POS] <= (int)'9' && option[SECOND_POS] == '\0') || 
                         (option[FIRST_POS] == (int)'1' && option[SECOND_POS] == (int)'0' && option[THIRD_POS] == '\0');

    while(!isValidOption){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> option;
        isValidOption = (option[FIRST_POS] >= (int)'1' && option[FIRST_POS] <= (int)'9' && option[SECOND_POS] == '\0') || 
                         (option[FIRST_POS] == (int)'1' && option[SECOND_POS] == (int)'0' && option[THIRD_POS] == '\0');
    }

    answer = stoi(option);

    return answer;
}