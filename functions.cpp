#include "functions.h"
#include <iostream>

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

void selectedOption(Andypolis& City, int answer){
    switch(answer){
        case 1:
            // Se debe verificar si existe, cuente con los materiales y no supere máximo de construcciones
            // Mostrar mensaje si no se puede construir o un mensaje de confirmacion
            // Se solicita unas coordenadas válidas en el mapa
            City.newBuildingByName();
            break;
        case 2:
            // Mostrar edificios CONSTRUIDOS a partir del archivo ubicaciones.txt y sus coordenadas
            City.showBuiltBuildings();
            break;
        case 3:
            // Listar edificios indicando: unidades de materiales, cantidad construida, cantidad permitida para seguir construyendo
            // sin superar el máximo permitido y si me brinda algún tipo de material
            City.showBuildings();
            break;
        case 4:
            // Se solicita las coordenadas y se elimina la construcción + devolver la mitad de los materiales
            City.deleteBuildingByCoords();
            break;
        case 5:
            /* Mostrara el mapa indicando los edificios y materiales que se encuentren en el mismo. También se
            deberá mostrar ya sea con el código de colores sugerido en la sección mapa o imprimiendo con las
            letras indicadas los tipos de terrenos presentes en el mapa.*/
            City.showMap();
            break;
        case 6:
            /*
            Se le pedirá al usuario que ingrese una coordenada y si la misma es válida obtendrá un mensaje con
            información sobre la coordenada seleccionada.
            Si no hay nada en ese casillero se deberá decir que tipo de casillero es y que está vacío. Por ejemplo:
            “Soy un casillero construible y me encuentro vacío.”
            Si hay algo el casillero deberá decir que tipo de casillero es y además se le deberá pedir al objeto que de
            información de si mismo. Por ejemplo, si hay una piedra en un camino se podría mostrar un mensaje
            como el siguiente:
            “Soy un casillero transitable y no me encuentro vacío.
            Soy una piedra y me encuentro en el casillero consultado”
            NOTA: El casillero deberá mostrar su información y pedirle al objeto que contiene que muestre la suya.
            */
            City.checkMap();
            break;
        case 7:
            // Mostrar materiales (Listar materiales de TP1)
            City.showInventory();
            break;
        case 8:
            // Se suman los materiales de los edificios construidos
            // PDF: Se recolectarán todos los materiales que produjeron los edificios que se encuentran construidos. 
            City.colectResources();
            break;
        case 9:
            // ...
            City.rainResources();
            break;
    }
}