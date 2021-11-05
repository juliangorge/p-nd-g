#include <iostream>
#include "Interface.h"
#include "Map.h"

using namespace std;

const string PATH_MATERIALS = "materiales.txt";
const string PATH_BUILDINGS = "edificios.txt";
const string PATH_MAP = "mapa.txt";
const string PATH_LOCATIONS = "ubicaciones.txt";

const int EXIT_OPTION = 6;

int main()
{
    // Inicializacion
    Andypolis city;

	// Lectura de archivo
    city.processBuildingsFile(PATH_BUILDINGS);
    city.processMaterialsFile(PATH_MATERIALS);
    city.processMapFile(PATH_MAP);
    city.processLocationsFile(PATH_LOCATIONS);

    // Mostrar menu
    showMenu();
    int answer = getOption();
    do{

        selectedOption(city, answer);
        showMenu();
        answer = getOption();


    }while(answer != EXIT_OPTION);

    
    // Liberar memoria
    City.flushMemory();

    // Guardar cambio
    City.saveChanges();

    return 0;
}
