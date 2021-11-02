#include <iostream>
#include "interfaz.h"

int main() {
	Lista_de_materiales* lista_materiales = new Lista_de_materiales;
	Lista_de_edificios* lista_edificios = new Lista_de_edificios;
    Posiciones_materiales* posiciones_materiales = new Posiciones_materiales;
	string opcion_elegida;
    int opcion_del_menu;
	cargar_lista_materiales(lista_materiales);
	cargar_lista_edificios(lista_edificios);
	
	mostrar_menu();
    opcion_elegida = pedir_opcion();
    opcion_del_menu=validar_opcion_elegida(opcion_elegida);
    while(opcion_del_menu != OPCION_SALIR){
        procesar_opcion(lista_materiales, lista_edificios, opcion_del_menu, posiciones_materiales);
        mostrar_menu();
        opcion_elegida = pedir_opcion();
        opcion_del_menu=validar_opcion_elegida(opcion_elegida);
    }
    actualizar_materiales(lista_materiales);
    actualizar_edificios(lista_edificios);
    delete lista_materiales;
    delete lista_edificios;
    delete posiciones_materiales;
    return 0;
}