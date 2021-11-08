#include <iostream>
#include "Andypolis.h"
#include "Interface.h"
#include "Map.h"

using namespace std;

const string PATH_MATERIALS = "materiales.txt";
const string PATH_BUILDINGS = "edificios.txt";
const string PATH_MAP = "mapa.txt";
const string PATH_LOCATIONS = "ubicaciones.txt";

const int EXIT_OPTION = 10;

int main()
{
    // Inicializacion
    Andypolis city;

	// Lectura de archivo
    city.processBuildingsFile(PATH_BUILDINGS);
    city.processMaterialsFile(PATH_MATERIALS);
    city.processLocationsFile(PATH_LOCATIONS);

    // Mostrar menu
    showMenu();
    int answer = getOption();

    while(answer != EXIT_OPTION){
        selectedOption(city, answer);
        showMenu();
        answer = getOption();
    }

    // Guardar cambio
    city.saveChanges(PATH_MATERIALS, PATH_BUILDINGS, PATH_LOCATIONS);

    return 0;
}
