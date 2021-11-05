#ifndef Andypolis_INCLUDED
#define Andypolis_INCLUDED

#include "Map.h"
#include "Material.h"
#include "Building.h"
#include <string>

using namespace std;

class Andypolis {

    // Attributes
    private:
        Building** buildings;
        Material** materials;
        Map* map;

        int building_quantity;
        int material_quantity;
    
    // Methods
    public:

        // PRE: Los parametros deben ser validos.
	    // POST: Crea un objeto Andypolis.
        Andypolis();

        // PRE:
        // POST: Destruye un objeto Andypolis.
        ~Andypolis();

        // PRE:
        // POST: Imprime una lista de Edificios construidos en pantalla.
        void showBuiltBuildings();

        // PRE:
        // POST: Imprime una lista de Edificios en pantalla.
        void showBuildings();

        // PRE: Recibe fila y columna
        // POST: Retorna true si esta disponible.
        bool isPathTaken(unsigned int & row_pos, unsigned int & column_pos);

        // PRE:
        // POST: Consulta el edificio por nombre y incrementa en 1 unidad.
        void newBuilding();

        // PRE:
        // POST: Consulta el edificio por nombre y disminuye en 1 unidad.
        void deleteBuilding();

        // PRE:
        // POST: Consulta por pantalla el nombre del Edificio y si existe retorna su posicion, de lo contrario -1.
        int checkIfBuildingExistsByName();

        // PRE: Recibe una posicion valida.
        // POST: Retorna TRUE si el Edificio puede construirse en base a la cantidad de material.
        bool checkByMaterials(int pos);
    
        // PRE: Recibe una posicion valida.
        // POST: Retorna TRUE si el Edificio puede construirse en base al maximo permitido.
        bool checkByMax(int pos);

        // PRE: Recibe una posicion valida.
        // POST: Retorna TRUE si hay al menos un Edificio construido
        bool checkByMin(int pos);

        // PRE: Recibe una posicion valida.
        // POST: Disminuye la cantidad de materiales en base a los materiales del Edificio de la posicion ingresada.
        void decreaseMaterials(int pos);

        // PRE: Recibe una posicion valida.
        // POST: Incrementa la cantidad de materiales en base a los materiales del Edificio de la posicion ingresada.
        void increaseMaterials(int pos);

        // PRE:
        // POST:
        void newBuildingByName();

        // PRE:
        // POST:
        void deleteBuildingByCoords();

        // PRE:
        // POST:
        void showMap();

        // PRE:
        // POST:
        void checkMap();

        // PRE:
        // POST: Imprime una lista de Materiales en pantalla.
        void showInventory();

        // PRE:
        // POST:
        void colectResources();

        // PRE:
        // POST:
        void rainResources();


        // PRE: Recibe un objeto Material.
        // POST: Ingresa el objeto en un array dinámico.
        void addBuilding(Building* building);

        // PRE: Recibe un objeto Material.
        // POST: Ingresa el objeto en un array dinámico.
        void addMaterial(Material* material);

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda cada linea en un objeto Building.
        void processBuildingsFile(string filename);

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda cada linea en un objeto Material.
        void processMaterialsFile(string filename);

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda cada linea en un objeto Map.
        void processMapFile(string filename);

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda cada linea en un objeto Location.
        void processLocationsFile(string filename);

        // PRE:
        // POST: Retorna la cantidad de Edificios.
        int getBuildingQuantity();

        // PRE:
        // POST: Retorna la cantidad de Materiales.
        int getMaterialQuantity();

        // PRE: Recibe una posicion valida.
        // POST: Retorna un objeto Building segun su posicion.
        Building* getBuildingByPos(int pos);

        // PRE: Recibe una posicion valida.
        // POST: Retorna un objeto Material segun su posicion.
        Material* getMaterialByPos(int pos);

        void flushMemory();
        void saveChanges(string path_materials, string path_buildings, string path_map, string path_locations);

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda en dicho archivo todos los cambios producidos en el objeto Building,
        // Siguiendo el formato:
        // nombre_edificio piedra madera metal cantidad_construidos máxima_cantidad_permitidos.
        void saveBuildingsChanges(string filename);

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda en dicho archivo todos los cambios producidos en el objeto Material,
        // Siguiendo el formato:
        // nombre_material cantidad_material.
        void saveMaterialsChanges(string filename);

        void saveMapChanges(string filename_map, string filename_locations);

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda en dicho archivo todos los cambios producidos en el objeto Location,
        // Siguiendo el formato:
        // nombre_edificio (fila, columna)
        void saveLocationsChanges(string filename);

};

#endif