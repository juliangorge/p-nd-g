#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include <string>
#include "materiales.h"

using namespace std;

// Nombre del archivo de edificios
const string PATH_EDIFICIOS="edificios.txt";

// Constantes para verificar las condiciones de construcción
const int CONDICIONES_CUMPLIDAS = 0;
const int FALTA_PIEDRA = 1;
const int FALTA_MADERA = 2;
const int FALTA_METAL = 4;
const int EDIFICIOS_MAXIMOS_CONSTRUIDOS = -1;

// Constantes para verificar las condiciones de demolición
const int NO_HAY_EDIFICIOS_CONSTRUIDOS = 0;
const int HAY_EDIFICIOS_CONSTRUIDOS = 1;

// Constantes para hacer la convertir los caracteres en MAYUSCULA escritos por el usuarios en minuscula
const int CARACTER_A_MAYUS = 65;
const int CARACTER_Z_MAYUS = 90;
const int CORRECTOR_MAYUS_A_MINUS = 32;

// Estructura que contiene un edificio del archivo de edificios procesado con su nombre y sus parametros 
struct Edificio{
    string nombre_edificio;
    int piedra_requerida;
    int madera_requerida;
    int metal_requerido;
    int cantidad_construidos;
    int cantidad_maxima;
};

// Estructura que contiene todas las estructuras de los edificios cargados
struct Lista_de_edificios{
    Edificio** edificios;
    int cantidad_de_edificios;
};

//Precondiciones: -
//Postcondiciones: Carga los edificios del archivo con sus parametros, en caso de no existir el archivo, se crea uno para que se pueda ejecutar el archivo
void cargar_lista_edificios(Lista_de_edificios* lista_edificios);

//Precondiciones: El edificio debe estar bien cargado
//Postcondiciones: Añade el edificio a la lista de edificios
void agregar_edificio(Lista_de_edificios* lista_edificios, Edificio* edificio);

//Precondiciones: Debe haber al menos un edificio cargado
//Postcondiciones: Imprime por pantalla todos los edificios cargados del archivo con sus parametros
void imprimir_lista_edificios(Lista_de_edificios* lista_edificios);

//Precondiciones: Debe haber al menos un edificio cargado
//Postcondiciones: Imprime por pantalla la cantidad y tipo de edificios construidos hasta el momento  
void imprimir_edificios_contruidos(Lista_de_edificios* lista_edificios);

//Precondiciones: -
//Postcondiciones: Solicita al usuario el edificio hasta que sea valido
string pedir_edificio();

//Precondiciones: -
//Postcondiciones: Devuelve true si el edificio buscado esta en la lista de edificios y false en caso contrario
bool existe_el_edificio(Lista_de_edificios* lista_edificios, string edificio_a_trabajar);

//Precondiciones: SE debe haber ingresado un string por consola
//Postcondiciones: Reemplaza los caracteres en MAYUSCULA por minuscula del string ingresado por consola
void corregir_mayusculas(string & edificio_a_trabajar);

//Precondiciones: El edificio debe existir
//Postcondiciones: Devuelve la posicion en la que se encuentra el edificio recibido
int obtener_posicion_del_edificio(Lista_de_edificios* lista_edificios, string edificio_a_trabajar);

//Precondiciones: -
//Postcondiciones: Verifica si se tienen disponibles los materiales para la construccion, y si se alcanzó la cantidad maxima permitida del edificio
int verificar_condiciones_construccion(Lista_de_edificios* lista_edificios, Lista_de_materiales* lista_materiales, int posicion_del_edificio, Posiciones_materiales* posiciones_materiales);

//Precondiciones: -
//Postcondiciones: Compara el material disponible con el material necesario para la construccion del edificio
bool verificar_material(int materiales_disponibles, int materiales_necesarios);

//Precondiciones: Se deben cumplir los requisitos de materiales disponibles, y que se haya exedido la cantidad maxima permitida del edificio a construir
//Postcondiciones: Construye un edificio y sustrae los materiales que requiere el mismo de la lista de materiales
void construir_edificio(Lista_de_edificios*  lista_edificios, Lista_de_materiales*  lista_materiales, int posicion_del_edificio, Posiciones_materiales* posiciones_materiales);

//Precondiciones: La cantidad disponible de material debe ser mayor a la cantidad requerida
//Postcondiciones: Sustrae de la cantidad disponible de material la cantidad requerida para el edificio
void restar_material(int & materiales_disponibles, int materiales_a_sustraer);

//Precondiciones: Debe haber al menos un edificio construido del tipo de edificio que se quiere demoler
//Postcondiciones: Disminuye en una unidad la cantidad construida del tipo de edificio elegido
void demoler_edificio(Lista_de_edificios*  lista_edificios, Lista_de_materiales*  lista_materiales, int posicion_del_edificio, Posiciones_materiales* posiciones_materiales);

//Precondiciones: Se debe habar demolido un edificio
//Postcondiciones: Añade la mitad de los materiales requeridos para la construccion del edificio demolido a los materiales disponibles
void agregar_materiales_sobrantes(Lista_de_edificios*  lista_edificios, Lista_de_materiales*  lista_materiales, int posicion_del_edificio, Posiciones_materiales* posiciones_materiales);

//Precondiciones: -
//Postcondiciones: Añade la mitad de un material requerido para la construccion del edificio demolido a los materiales disponibles
void agregar_material(int & materiales_disponibles, int materiales_a_agregar);

//Precondiciones: El edificio debe estar bien cargado
//Postcondiciones: Indica la cantidad de edificios construidos presentes de un mismo tipo de edificio 
int verificar_edificios_construidos(Lista_de_edificios* lista_edificios, int posicion_del_edificio);

//Precondiciones: -
//Postcondiciones: Actualiza el archivo PATH_EDIFICIOS reescribiendo las cantidades construidas de edificios que fueron modificados durante la ejecución del programa
void actualizar_edificios(Lista_de_edificios* lista_edificios);

#endif //EDIFICIOS_H
