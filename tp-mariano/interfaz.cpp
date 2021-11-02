#include <iostream>
#include "interfaz.h"
#include <fstream>

using namespace std;

const int LISTAR_MATERIALES = 1;
const int CONSTRUIR_EDIFICIO = 2;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 3;
const int LISTAR_TODOS_LOS_EDIFICIOS = 4;
const int DEMOLER_EDIFICIO = 5;

const int ERROR_POSICION = -1;

const int POSICION_PRIMER_CARACTER = 0;
const int POSICION_SEGUNDO_CARACTER = 1;

void mostrar_menu(){
    cout << endl;
    cout << "MENU" << endl
    << '\t' << "1_ Listar materiales de construcción " << endl
    << '\t' << "2_ Construir edificio por nombre " << endl
    << '\t' << "3_ Listar edificios construidos " << endl
    << '\t' << "4_ Listar todos los edificios " << endl
    << '\t' << "5_ Demoler un edificio por nombre " << endl
    << '\t' << "6_ Guardar y salir " << endl << endl;
}

string pedir_opcion(){
    string opcion_elegida;
    cout << "Ingrese el número de su acción elegida : ";
    cin >> opcion_elegida;
    cout << endl;

    return opcion_elegida;
}

int validar_opcion_elegida(string opcion_elegida){
    int valor_opcion;
    bool es_opcion_valida = opcion_elegida[POSICION_PRIMER_CARACTER] >= CARACTER_UNO 
        && opcion_elegida[POSICION_PRIMER_CARACTER] <= CARACTER_SEIS && opcion_elegida[POSICION_SEGUNDO_CARACTER]=='\0';

    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> opcion_elegida;
        es_opcion_valida = opcion_elegida[POSICION_PRIMER_CARACTER] >= CARACTER_UNO 
        && opcion_elegida[POSICION_PRIMER_CARACTER] <= CARACTER_SEIS && opcion_elegida[POSICION_SEGUNDO_CARACTER]=='\0';
    }
    valor_opcion=stoi(opcion_elegida);

    return valor_opcion;
}

void procesar_opcion(Lista_de_materiales* lista_materiales, Lista_de_edificios* lista_edificios, int opcion ,Posiciones_materiales* posiciones_materiales){
	int condiciones_para_construccion = CONDICIONES_CUMPLIDAS;
	int edificios_construidos = NO_HAY_EDIFICIOS_CONSTRUIDOS;
    int posicion_del_edificio = ERROR_POSICION;
    string operacion;
    string edificio_a_trabajar;
    char confirmacion;
	obtener_posiciones_materiales(lista_materiales, posiciones_materiales);

    switch (opcion) {

        case LISTAR_MATERIALES:
            imprimir_materiales(lista_materiales);
            break;

        case CONSTRUIR_EDIFICIO:    

            if(lista_materiales -> cantidad_de_materiales == 0){
                cout << "No hay materiales disponibles para trabajar" << endl;
                break;
            }
            
        	edificio_a_trabajar = pedir_edificio();
            corregir_mayusculas(edificio_a_trabajar);

        	if(!existe_el_edificio(lista_edificios, edificio_a_trabajar)){
        		cout << "No existe edificio cuyo nombre sea " << edificio_a_trabajar << endl;
            } 

            else {
                posicion_del_edificio = obtener_posicion_del_edificio(lista_edificios, edificio_a_trabajar);
                condiciones_para_construccion = verificar_condiciones_construccion(lista_edificios, lista_materiales, posicion_del_edificio, posiciones_materiales);

                if(condiciones_para_construccion != CONDICIONES_CUMPLIDAS){
                	imprimir_error_construccion(condiciones_para_construccion,lista_edificios, lista_materiales, posicion_del_edificio, posiciones_materiales);
                }

                else{
                    operacion = confirmar_operacion();
                    confirmacion = validar_confirmacion_elegida(operacion);

                    if(confirmacion == CARACTER_S_MINUS || confirmacion == CARACTER_S_MAYUS){
                	construir_edificio(lista_edificios, lista_materiales, posicion_del_edificio, posiciones_materiales);
                	cout << "Se ha construido un " << lista_edificios -> edificios[posicion_del_edificio] -> nombre_edificio << endl
                	 	 << "Cantidad construida: " << lista_edificios -> edificios[posicion_del_edificio] -> cantidad_construidos << endl;
                    }

                    else if(confirmacion == CARACTER_N_MINUS || confirmacion == CARACTER_N_MAYUS){
                        cout << "Accion cancelada" << endl;
                    }
                }      
            }
            break;

        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            imprimir_edificios_contruidos(lista_edificios);
            break;

        case LISTAR_TODOS_LOS_EDIFICIOS:
            imprimir_lista_edificios(lista_edificios);
            break;

        case DEMOLER_EDIFICIO:

            if(lista_materiales -> cantidad_de_materiales == 0){
                cout << "No hay materiales disponibles para trabajar" << endl;
                break;
            }

        	edificio_a_trabajar = pedir_edificio();
            corregir_mayusculas(edificio_a_trabajar);

        	if(!existe_el_edificio(lista_edificios, edificio_a_trabajar)){
        		cout << "No existe edificio cuyo nombre sea " << edificio_a_trabajar << endl;
            } 
            else {
                posicion_del_edificio = obtener_posicion_del_edificio(lista_edificios, edificio_a_trabajar);
                edificios_construidos = verificar_edificios_construidos(lista_edificios, posicion_del_edificio);

                if(edificios_construidos == NO_HAY_EDIFICIOS_CONSTRUIDOS){
                	imprimir_error_demolicion(lista_edificios, posicion_del_edificio);
                }

                else{
                    operacion = confirmar_operacion();
                    confirmacion = validar_confirmacion_elegida(operacion);

                    if(confirmacion == CARACTER_S_MINUS || confirmacion == CARACTER_S_MAYUS){
                        demoler_edificio(lista_edificios, lista_materiales, posicion_del_edificio, posiciones_materiales);
                        agregar_materiales_sobrantes(lista_edificios, lista_materiales, posicion_del_edificio, posiciones_materiales);
                        cout << "Se ha demolido un " << lista_edificios -> edificios[posicion_del_edificio] -> nombre_edificio << endl
                             << "Edificios del mismo tipo restantes: " << lista_edificios -> edificios[posicion_del_edificio] -> cantidad_construidos << endl;
                    }

                    else if(confirmacion == CARACTER_N_MINUS || confirmacion == CARACTER_N_MAYUS){
                        cout << "Accion cancelada" << endl;
                    }
                	
                }
                
            }
            break;
    }
}

void imprimir_error_construccion(int condiciones_para_construccion, Lista_de_edificios* lista_edificios, Lista_de_materiales* lista_materiales, int posicion_del_edificio, Posiciones_materiales* posiciones_materiales){
	
    switch(condiciones_para_construccion){
		
        case FALTA_PIEDRA:
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> piedra_requerida, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> cantidad_material);
			break;
		
        case FALTA_MADERA:
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> madera_requerida, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> cantidad_material);
			break;
		
        case FALTA_METAL:
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> metal_requerido, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> cantidad_material);
			break;
		
        case FALTA_PIEDRA + FALTA_MADERA:
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> piedra_requerida, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> cantidad_material);
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> madera_requerida, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> cantidad_material);
			break;
		
        case FALTA_PIEDRA + FALTA_METAL:
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> piedra_requerida, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> cantidad_material);
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> metal_requerido, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> cantidad_material);
			break;

		case FALTA_MADERA + FALTA_METAL:
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> madera_requerida, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> cantidad_material);
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> metal_requerido, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> cantidad_material);
			break;

		case FALTA_PIEDRA + FALTA_MADERA + FALTA_METAL:
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> piedra_requerida, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_piedra] -> cantidad_material);
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> madera_requerida, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_madera] -> cantidad_material);
			imprimir_material_faltante( lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> nombre_material, 
										lista_edificios -> edificios[posicion_del_edificio] -> metal_requerido, 
										lista_materiales -> materiales[posiciones_materiales -> posicion_metal] -> cantidad_material);
			break;

        case EDIFICIOS_MAXIMOS_CONSTRUIDOS:
            imprimir_error_maxima_cantidad(lista_edificios -> edificios[posicion_del_edificio] -> cantidad_maxima);

		case CONDICIONES_CUMPLIDAS:
			break;
	}
}

void imprimir_material_faltante(string nombre_material, int cantidad_material_requerida, int cantidad_material_disponible){
	cout << nombre_material << " insuficiente, se requiere " << cantidad_material_requerida - cantidad_material_disponible  
		 << " "  << nombre_material << " adicional para realizar la construcción" << endl << endl;
}

void imprimir_error_maxima_cantidad(int cantidad_maxima){
    cout << "No se pueden construir mas de " << cantidad_maxima << " unidades" << endl;
}

void imprimir_error_demolicion(Lista_de_edificios* lista_edificios, int posicion_del_edificio){
	cout << "No puede demoler el edificio porque no hay ningun/a " << lista_edificios -> edificios[posicion_del_edificio] -> nombre_edificio 
		 << " construido" << endl << endl;
}

string confirmar_operacion(){
    string operacion;
    cout << "¿Desea realizar la acción seleccionada? [S/N] ";
    cin >> operacion;
    cout << endl;

    return operacion;
}

char validar_confirmacion_elegida(string operacion){
    bool es_opcion_valida = (operacion[POSICION_PRIMER_CARACTER] == CARACTER_S_MINUS || operacion[POSICION_PRIMER_CARACTER] == CARACTER_S_MAYUS 
        || operacion[POSICION_PRIMER_CARACTER] == CARACTER_N_MINUS || operacion[POSICION_PRIMER_CARACTER] == CARACTER_N_MAYUS)
        && operacion[POSICION_SEGUNDO_CARACTER]=='\0';

    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> operacion;
        es_opcion_valida = (operacion[POSICION_PRIMER_CARACTER] == CARACTER_S_MINUS || operacion[POSICION_PRIMER_CARACTER] == CARACTER_S_MAYUS 
        || operacion[POSICION_PRIMER_CARACTER] == CARACTER_N_MINUS || operacion[POSICION_PRIMER_CARACTER] == CARACTER_N_MAYUS)
        && operacion[POSICION_SEGUNDO_CARACTER]=='\0';
    }
    
    return operacion[POSICION_PRIMER_CARACTER];
}
