#include "Andypolis.h"
#include "functions.h"
#include <iostream>

using namespace std;

const string PATH_MATERIALS = "materiales.txt";
const string PATH_BUILDINGS = "edificios.txt";
const int EXIT_OPTION = 6;

int main() {

    // Inicializo variables
    Andypolis City;
    // Leo los archivos txt y los proceso dentro de la clase Andypolis
    City.processBuildingsFile(PATH_BUILDINGS);
    City.processMaterialsFile(PATH_MATERIALS);

    cout << "Bienvenido!" << endl;
    cout << "Elige una opcion:" << endl;

    // Ingresar una opcion valida
    int answer;
    do{
        showMenu();
        cout << "Opcion: ";
        cin >> answer;

        selectedOption(City, answer);

    }while(answer != EXIT_OPTION);

    // Guardo los cambios en los archivos txt
    City.saveBuildingsChanges(PATH_BUILDINGS);
    City.saveMaterialsChanges(PATH_MATERIALS);

    return 0;
}