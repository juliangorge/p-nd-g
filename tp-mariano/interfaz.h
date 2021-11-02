#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <string>
#include "edificios.h"

using namespace std;

// Constantes para las opciones a seleccionar del menu
const int CARACTER_UNO = 49;
const int CARACTER_SEIS = 54;

// Constantes para la validación o no de la acción a realizar
const int CARACTER_S_MINUS = 83;
const int CARACTER_N_MINUS = 78;
const int CARACTER_S_MAYUS = 115;
const int CARACTER_N_MAYUS = 110;
const int OPCION_SALIR = 6;

//Precondiciones: -
//Postcondiciones: imprime por pantalla el menu
void mostrar_menu();

//Precondiciones: -
//Postcondiciones: Le solicita al usuario que ingrese el numero de la opcion que desea seleccionar
string pedir_opcion();

//Precondiciones: recibe la opcion elegida precargada
//Postcondiciones: Verifica que la opcion sea un numero entre 1 y 6, y si no lo es vuelve a solicitar los datos
int validar_opcion_elegida(string opcion_elegida);

//Precondiciones: La opcion es valida.
//Postcondiciones: Realiza la opcion indicada.
void procesar_opcion(Lista_de_materiales* lista_materiales, Lista_de_edificios* lista_edificios ,int opcion, Posiciones_materiales* posiciones_materiales);

//Precondiciones: No se cumple algunas de las condiciones necesarias para la construccion, ya sea por falta de materiales o tener la cantidad maxima construida
//Postcondiciones: Imprime por pantalla el error correspondiente al parametro que no se cumple
void imprimir_error_construccion(int materiales_necesarios, Lista_de_edificios* lista_edificios, Lista_de_materiales* lista_materiales, int posicion_del_edificio, Posiciones_materiales* posiciones_materiales);

//Precondiciones: La cantidad de materias requerido es mayor a la cantidad disponible
//Postcondiciones: Imprime por pantalla el tipo y cantidad de material que falta para la construccion
void imprimir_material_faltante(string nombre_material, int cantidad_material_requerida, int cantidad_material_disponible);

//Precondiciones: La cantidad de edificios construidos del tipo solicitado es igual a la maxima permitida
//Postcondiciones: Imprime por pantalla el error de que se ya se tiene la cantidad maxima de edificios construidos del mismo tipo
void imprimir_error_maxima_cantidad(int cantidad_maxima);

//Precondiciones: No debe hacer edificios construidos del tipo solicitado a demoler
//Postcondiciones: Imprime por pantalla el error de que no se tienen edificios de ese tipo construidos
void imprimir_error_demolicion(Lista_de_edificios* lista_edificios, int posicion_del_edificio);

//Precondiciones: -
//Postcondiciones: Le solicita al usuario que confirme o no la acción a realizar
string confirmar_operacion();

//Precondiciones: recibe la opcion elegida precargada
//Postcondiciones: Verifica que la opcion sea algunos de los posibles caracteres: 's','S','n' o 'N', y si no lo es vuelve a solicitar los datos
char validar_confirmacion_elegida(string operacion);

#endif //INTERFAZ_H
