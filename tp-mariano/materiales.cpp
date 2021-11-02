#include <iostream>
#include "materiales.h"
#include <fstream>

using namespace std;

void cargar_lista_materiales(Lista_de_materiales* lista_materiales){
    lista_materiales -> cantidad_de_materiales = 0;
    fstream archivo_materiales(PATH_MATERIALES, ios::in);

    if(!archivo_materiales.is_open()){
        cout << "No se encontro un archivo con nombre \"" << PATH_MATERIALES << "\", se va a crear el archivo" << endl << endl;
        archivo_materiales.open(PATH_MATERIALES, ios::out);
        archivo_materiales.close();
        archivo_materiales.open(PATH_MATERIALES, ios::in);
    }
    string nombre, cantidad;
    Material* material;

    while(archivo_materiales >> nombre){
        archivo_materiales >> cantidad;
        material = new Material;
        material -> nombre_material = nombre;
        material -> cantidad_material = stoi(cantidad);

        agregar_material(lista_materiales, material);
    }
    archivo_materiales.close();
}

void agregar_material(Lista_de_materiales* lista_materiales, Material* material){
    int tope_viejo = lista_materiales -> cantidad_de_materiales;
    Material** nuevo_vector_materiales = new Material*[tope_viejo + 1];

    for(int i = 0; i < lista_materiales -> cantidad_de_materiales; i++){
        nuevo_vector_materiales[i] = lista_materiales -> materiales[i];
    }
    nuevo_vector_materiales[tope_viejo] = material;

    if(lista_materiales -> cantidad_de_materiales != 0){

        delete[] lista_materiales -> materiales;
    }
    lista_materiales -> materiales = nuevo_vector_materiales;
    lista_materiales -> cantidad_de_materiales++;
}

void imprimir_materiales(Lista_de_materiales* lista_materiales){

    if(lista_materiales -> cantidad_de_materiales == 0){
        cout << "No se encuentra ningun material para trabajar " << endl << endl;

        return;
    }

    for (int i = 0; i < lista_materiales -> cantidad_de_materiales; i++){
        cout << "> Material: " << lista_materiales -> materiales[i] -> nombre_material << endl
             << "  Cantidad disponible: " 
             << lista_materiales -> materiales[i] -> cantidad_material << endl << endl;
    }
}

void obtener_posiciones_materiales(Lista_de_materiales* lista_materiales, Posiciones_materiales* posiciones_materiales){
	posiciones_materiales -> posicion_piedra = obtener_posicion_materiales_individual(lista_materiales,NOMBRE_PIEDRA);
	posiciones_materiales -> posicion_madera = obtener_posicion_materiales_individual(lista_materiales,NOMBRE_MADERA);
	posiciones_materiales -> posicion_metal = obtener_posicion_materiales_individual(lista_materiales,NOMBRE_METAL);
}

int obtener_posicion_materiales_individual(Lista_de_materiales* lista_materiales, const string material_buscado){
    int posicion_material;

    for (int i = 0; i < lista_materiales -> cantidad_de_materiales; i++){

        if(lista_materiales -> materiales[i] -> nombre_material == material_buscado)
            posicion_material = i;
    }
    
    return posicion_material;
}

void actualizar_materiales(Lista_de_materiales* lista_materiales){
    ofstream archivo_materiales(PATH_MATERIALES);

    int cantidad_de_materiales = lista_materiales -> cantidad_de_materiales;

    for(int i = 0; i < cantidad_de_materiales; i++){
        archivo_materiales << lista_materiales -> materiales[i] -> nombre_material << ' '
                           << lista_materiales -> materiales[i] -> cantidad_material << '\n';

        delete lista_materiales -> materiales[i];
        lista_materiales -> cantidad_de_materiales--;
    }

    delete[] lista_materiales -> materiales;
    lista_materiales -> materiales = nullptr;
}


