#include <iostream>
#include "edificios.h"
#include <fstream>

using namespace std;

void cargar_lista_edificios(Lista_de_edificios* lista_edificios){
    lista_edificios -> cantidad_de_edificios = 0;
    fstream archivo_edificios(PATH_EDIFICIOS, ios::in);

    if(!archivo_edificios.is_open()){
        cout << "No se encontro un archivo con nombre \"" << PATH_EDIFICIOS << "\", se va a crear el archivo" << endl << endl;
        archivo_edificios.open(PATH_EDIFICIOS, ios::out);
        archivo_edificios.close();
        archivo_edificios.open(PATH_EDIFICIOS, ios::in);
    }
    string nombre, valor_aux;
    Edificio* edificio;

    while(archivo_edificios >> nombre){
        archivo_edificios >> valor_aux;
        edificio = new Edificio;
        edificio -> nombre_edificio = nombre;
        edificio -> piedra_requerida = stoi(valor_aux);
        archivo_edificios >> valor_aux;
        edificio -> madera_requerida = stoi(valor_aux);
        archivo_edificios >> valor_aux;
        edificio -> metal_requerido = stoi(valor_aux);
        archivo_edificios >> valor_aux;
        edificio -> cantidad_construidos = stoi(valor_aux);
        archivo_edificios >> valor_aux;
        edificio -> cantidad_maxima = stoi(valor_aux);
        agregar_edificio(lista_edificios, edificio);
    }
    archivo_edificios.close();
}

void agregar_edificio(Lista_de_edificios* lista_edificios, Edificio* edificio){
    int tope_viejo = lista_edificios -> cantidad_de_edificios;
    Edificio** nuevo_vector_edificios = new Edificio*[tope_viejo + 1];

    for(int i = 0; i < lista_edificios -> cantidad_de_edificios; i++){
        nuevo_vector_edificios[i] = lista_edificios -> edificios[i];
    }
    nuevo_vector_edificios[tope_viejo] = edificio;

    if(lista_edificios -> cantidad_de_edificios != 0){

        delete[] lista_edificios -> edificios;
    }
    lista_edificios -> edificios = nuevo_vector_edificios;
    lista_edificios -> cantidad_de_edificios++;
}

void imprimir_lista_edificios(Lista_de_edificios* lista_edificios){
    
    if(lista_edificios -> cantidad_de_edificios == 0){
        cout << "No se encuentra ningun edificio para trabajar " << endl << endl;

        return;
    }

    cout << "Edificios disponibles" << endl << endl;

    for (int i = 0; i < lista_edificios -> cantidad_de_edificios; i++){
        cout << "> Edificio: " << lista_edificios -> edificios[i] -> nombre_edificio << endl
        	 << "  Materiales requeridos: " << endl
        	 << '\t' << "- Piedra: " << lista_edificios -> edificios[i] -> piedra_requerida << endl
        	 << '\t' << "- Madera: " << lista_edificios -> edificios[i] -> madera_requerida << endl
        	 << '\t' << "- Metal: "  << lista_edificios -> edificios[i] -> metal_requerido << endl
        	 << "  Cantidad construida: " << lista_edificios -> edificios[i] -> cantidad_construidos << endl
        	 << "  Cantidad posible de construir: " << lista_edificios -> edificios[i] -> cantidad_maxima - lista_edificios -> edificios[i] -> cantidad_construidos << endl
        	 << endl;
    }
}

void imprimir_edificios_contruidos(Lista_de_edificios* lista_edificios){
	int tipos_de_edificios_construidos = 0;
	int cantidad_de_edificios = lista_edificios -> cantidad_de_edificios;
	cout << "Edificios construidos" << endl << endl; 

    for (int i = 0; i < cantidad_de_edificios; i++){

    	if(lista_edificios -> edificios[i] -> cantidad_construidos > 0){
    		cout << "> Edificio: " << lista_edificios -> edificios[i] -> nombre_edificio << endl
    		<< "  Cantidad construida: " << lista_edificios -> edificios[i] -> cantidad_construidos << endl
    		<< endl;
    		tipos_de_edificios_construidos ++;
    	}
    }

    if(tipos_de_edificios_construidos == NO_HAY_EDIFICIOS_CONSTRUIDOS)
    	cout << "No hay edificios construidos por el momento" << endl << endl;
}

string pedir_edificio(){
    string edificio;
    cout << "Ingrese el edificio a trabajar: ";
    cin >> edificio;
    cout << endl;

    return edificio;
}

bool existe_el_edificio(Lista_de_edificios* lista_edificios, string edificio_a_trabajar){
    bool existe_el_edificio = false;

    for (int i = 0; i < lista_edificios -> cantidad_de_edificios; i++){
    	if(edificio_a_trabajar == lista_edificios -> edificios[i] -> nombre_edificio){
    		existe_el_edificio = true;
    	}
    }

    return existe_el_edificio;
}

void corregir_mayusculas(string & edificio_a_trabajar){
    for (size_t i = 0; i < edificio_a_trabajar.length() ; i++)
    {

        if(edificio_a_trabajar[i]>=CARACTER_A_MAYUS && edificio_a_trabajar[i]<=CARACTER_Z_MAYUS){
            edificio_a_trabajar[i] = (char)(edificio_a_trabajar[i] + CORRECTOR_MAYUS_A_MINUS);
        }
    }
}

int obtener_posicion_del_edificio(Lista_de_edificios* lista_edificios, string edificio_a_trabajar){
    int posicion_del_edificio;

    for (int i = 0; i < lista_edificios -> cantidad_de_edificios; i++){

        if(lista_edificios -> edificios[i] -> nombre_edificio == edificio_a_trabajar)
            posicion_del_edificio = i;
    }

    return posicion_del_edificio;
}


int verificar_condiciones_construccion(Lista_de_edificios* lista_edificios, Lista_de_materiales* lista_materiales, int posicion_del_edificio, Posiciones_materiales* posiciones_materiales){
	int condiciones_construccion = CONDICIONES_CUMPLIDAS;

    if(lista_edificios -> edificios[posicion_del_edificio] -> cantidad_maxima == lista_edificios -> edificios[posicion_del_edificio] -> cantidad_construidos){
        condiciones_construccion = EDIFICIOS_MAXIMOS_CONSTRUIDOS;

        return condiciones_construccion;
    }

	if(!verificar_material(lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> cantidad_material,
        lista_edificios -> edificios[posicion_del_edificio] -> piedra_requerida))
		condiciones_construccion = condiciones_construccion + FALTA_PIEDRA;
	
    if(!verificar_material(lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> cantidad_material,
        lista_edificios -> edificios[posicion_del_edificio] -> madera_requerida))
		condiciones_construccion = condiciones_construccion + FALTA_MADERA;	
	
    if(!verificar_material(lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> cantidad_material,
        lista_edificios -> edificios[posicion_del_edificio] -> metal_requerido))
		condiciones_construccion = condiciones_construccion + FALTA_METAL;

	return condiciones_construccion;
}

bool verificar_material(int materiales_disponibles, int materiales_necesarios){
    bool alcanza_el_material = false;

    if(materiales_disponibles >= materiales_necesarios){
        alcanza_el_material = true;
    }

    return alcanza_el_material;

}

void construir_edificio(Lista_de_edificios*  lista_edificios, Lista_de_materiales*  lista_materiales, int posicion_del_edificio, Posiciones_materiales* posiciones_materiales){
	restar_material(lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> cantidad_material, 
    lista_edificios -> edificios[posicion_del_edificio] -> piedra_requerida);

    restar_material(lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> cantidad_material, 
    lista_edificios -> edificios[posicion_del_edificio] -> madera_requerida);

    restar_material(lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> cantidad_material, 
    lista_edificios -> edificios[posicion_del_edificio] -> metal_requerido);

	lista_edificios -> edificios[posicion_del_edificio] -> cantidad_construidos ++;
}

void restar_material(int & materiales_disponibles, int materiales_a_sustraer){
    materiales_disponibles = materiales_disponibles - materiales_a_sustraer;
}

void demoler_edificio(Lista_de_edificios*  lista_edificios, Lista_de_materiales*  lista_materiales, int posicion_del_edificio, Posiciones_materiales* posiciones_materiales){
	lista_edificios -> edificios[posicion_del_edificio] -> cantidad_construidos --;
}

void agregar_materiales_sobrantes(Lista_de_edificios*  lista_edificios, Lista_de_materiales*  lista_materiales, int posicion_del_edificio, Posiciones_materiales* posiciones_materiales){
	agregar_material(lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> cantidad_material, 
    lista_edificios -> edificios[posicion_del_edificio] -> piedra_requerida);

    agregar_material(lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> cantidad_material, 
    lista_edificios -> edificios[posicion_del_edificio] -> madera_requerida);

    agregar_material(lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> cantidad_material, 
    lista_edificios -> edificios[posicion_del_edificio] -> metal_requerido);
}

void agregar_material(int & materiales_disponibles, int materiales_a_agregar){
    materiales_disponibles = materiales_disponibles + materiales_a_agregar/2;
}

int verificar_edificios_construidos(Lista_de_edificios* lista_edificios, int posicion_del_edificio){

	if(lista_edificios -> edificios[posicion_del_edificio] -> cantidad_construidos > 0)
		
        return HAY_EDIFICIOS_CONSTRUIDOS;

	return NO_HAY_EDIFICIOS_CONSTRUIDOS;
}

void actualizar_edificios(Lista_de_edificios* lista_edificios){
    ofstream archivo_edificios(PATH_EDIFICIOS);
    int cantidad_de_edificios = lista_edificios -> cantidad_de_edificios;

    for(int i = 0; i < cantidad_de_edificios; i++){
        archivo_edificios << lista_edificios -> edificios[i] -> nombre_edificio << ' '
                          << lista_edificios -> edificios[i] -> piedra_requerida << ' '
                          << lista_edificios -> edificios[i] -> madera_requerida << ' '
                          << lista_edificios -> edificios[i] -> metal_requerido << ' '
                          << lista_edificios -> edificios[i] -> cantidad_construidos << ' '
                          << lista_edificios -> edificios[i] -> cantidad_maxima << '\n';

        delete lista_edificios -> edificios[i];
        lista_edificios -> cantidad_de_edificios--;
    }

    delete[] lista_edificios -> edificios;
    lista_edificios -> edificios = nullptr;
}