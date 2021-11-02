#ifndef MATERIALES
#define MATERIALES_H
#include <string>

using namespace std;

// Nombre del archivo de materiales
const string PATH_MATERIALES="materiales.txt";

// Constantes utlizadas para ubicar los materiales con los cuales se construyen los edificios
const string NOMBRE_PIEDRA="piedra";
const string NOMBRE_MADERA="madera";
const string NOMBRE_METAL="metal";

// Estructura que contiene un material del archivo de materiales procesado con su nombre y su cantidad
struct Material{
    string nombre_material;
    int cantidad_material;
};

// Estructura que contiene todas las estructuras de los materiales cargados
struct Lista_de_materiales{
    Material** materiales;
    int cantidad_de_materiales;
};

// Estructura que contiene las posiciones en la lista de materiales, los materiales a utilizar en los edificios 
struct Posiciones_materiales{
	int posicion_piedra;
	int posicion_madera;
	int posicion_metal;
};

//Precondiciones: -
//Postcondiciones: Carga los materiales del archivo con sus cantidades, en caso de no existir el archivo, se crea uno para que se pueda ejecutar el archivo
void cargar_lista_materiales(Lista_de_materiales* lista_materiales);

//Precondiciones: El material debe estar bien cargado
//Postcondiciones: Añade el material a la lista de materiales
void agregar_material(Lista_de_materiales* lista_materiales, Material* material);

//Precondiciones: Debe haber al menos un material cargado
//Postcondiciones: Imprime por pantalla todos los materiales cargados del archivo con sus cantidades
void imprimir_materiales(Lista_de_materiales* lista_materiales);

//Precondiciones: Los materiales debe existir
//Postcondiciones: Devuelve las posiciones de los materiales utilizados para la construccion (piedra, madera, metal)
void obtener_posiciones_materiales(Lista_de_materiales* lista_materiales, Posiciones_materiales* posiciones_materiales);

//Precondiciones: El material debe existir
//Postcondiciones: Devuelve la posicion del material para la construccion 
int obtener_posicion_materiales_individual(Lista_de_materiales* lista_materiales, const string material_buscado);

//Precondiciones: -
//Postcondiciones: Actualiza el archivo PATH_MATERIALES reescribiendo los valores de los materiales que fueron modificados durante la ejecución del programa
void actualizar_materiales(Lista_de_materiales* lista_materiales);

#endif //MATERIALES_H