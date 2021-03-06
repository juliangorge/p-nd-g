#include "Andypolis.h"
#include <string>
#include <fstream>
#include <ctype.h>


using namespace std;

Andypolis:: Andypolis(){
    this->building_quantity = 0;
    this->building_quantity_total = 0;
    this->material_quantity = 0;
    this->map = new Map();
}

void Andypolis:: showBuiltBuildings(){
    cout << endl << "======================" << endl << endl;
    cout << "Edificios construidos: " << endl;

    if(!this->building_quantity) cout << "No hay edificios construidos :(" << endl;

    for(int i = 0; i < this->building_quantity; i++){
        if(this->buildings[i]->getQuantity() > 0) cout << "# " << this->buildings[i]->getName() << " (Construidos: " << this->buildings[i]->getQuantity() << ")" << endl;
    }

    cout << endl << "======================" << endl << endl;
}

void Andypolis:: showBuildings(){
    cout << endl << "======================" << endl << endl;
    //cout << "    Edificios | Piedra | Madera | Metal | Construidos | Cant. permitida" << endl;

    for(int i = 0; i < this->building_quantity; i++){
        cout << "-> " << (i+1) << ": " << this->buildings[i]->getName() << endl;
        cout << " | Piedra req = " <<this->buildings[i]->getStone() << " | Madera req = " << this->buildings[i]->getWood() << " | Metal req = " 
             << this->buildings[i]->getIron() << " | Construidos= " << this->buildings[i]->getQuantity() << " | Construcciones posibles = " 
             << this->buildings[i]->getMax() - this->buildings[i]->getQuantity()<< endl;
         
        //cout << "Construidos: " << this->buildings[i]->getQuantity() << " (" << (this->buildings[i]->getMax() - this->buildings[i]->getQuantity()) << " para el maximo permitido) " << endl;
    cout << endl;
    }
    cout << "======================" << endl << endl;
}



int Andypolis:: checkIfBuildingExistsByName(string name){
    bool exists = false;
    int pos = -1, i = 0;

    while(!exists && i < this->building_quantity){
        exists = (this->buildings[i]->getName() == name);

        if(exists) pos = i;
        i++;
    }

    if(pos == -1) cout << "ATENCION: Se ingreso un tipo de edificio invalido" << endl;
    return pos;
}

bool Andypolis:: checkByMaterials(int pos){
    bool stockStone = false, stockWood = false, stockIron = false;
    int i = 0;

    while((!stockStone || !stockWood || !stockIron) && i < this->material_quantity){
        if(this->materials[i]->getName() == "piedra") stockStone = (this->materials[i]->getQuantity() >= this->buildings[pos]->getStone());

        if(this->materials[i]->getName() == "madera") stockWood = (this->materials[i]->getQuantity() >= this->buildings[pos]->getWood());

        if(this->materials[i]->getName() == "metal") stockIron = (this->materials[i]->getQuantity() >= this->buildings[pos]->getIron());

        i++;
    }

    if(!(stockStone && stockWood && stockIron)){
        cout << "ATENCION: No hay suficiente material para esta construccion" << endl;
    }

    return (stockStone && stockWood && stockIron);
}

bool Andypolis:: checkByMax(int pos){
    bool condition = (this->buildings[pos]->getQuantity() < this->buildings[pos]->getMax());

    if(!condition) cout << "ATENCION: Se alcanzo el maximo para esta construccion" << endl;
    return condition;
}

bool Andypolis:: checkByMin(int pos){
    bool condition = (this->buildings[pos]->getQuantity()!=0);

    if(!condition) cout << "ATENCION: No hay edificios construidos de este tipo" << endl;
    return condition;
}

void Andypolis:: decreaseMaterials(int pos){
    for(int i = 0; i < this->material_quantity; i++){
        if(this->materials[i]->getName() == "piedra") this->materials[i]->decreaseQuantity(this->buildings[pos]->getStone());

        if(this->materials[i]->getName() == "madera") this->materials[i]->decreaseQuantity(this->buildings[pos]->getWood());

        if(this->materials[i]->getName() == "metal") this->materials[i]->decreaseQuantity(this->buildings[pos]->getIron());
    }
}

void Andypolis:: increaseMaterials(int pos){
    for(int i = 0; i < this->material_quantity; i++){
        if(this->materials[i]->getName() == "piedra") this->materials[i]->increaseQuantity(this->buildings[pos]->getStone()/2);

        if(this->materials[i]->getName() == "madera") this->materials[i]->increaseQuantity(this->buildings[pos]->getWood()/2);

        if(this->materials[i]->getName() == "metal") this->materials[i]->increaseQuantity(this->buildings[pos]->getIron()/2);
    }
}


void Andypolis:: newBuildingByName(){
    string name, building_char, confirm;
    int pos;
    unsigned int row_pos, column_pos;
    cout << "Ingrese el nombre: ";
    cin >> name;
    if((pos = checkIfBuildingExistsByName(name)) == -1){
        cout << "No se puede construir" << endl;
        return;
    }

    if(!checkByMaterials(pos) || !checkByMax(pos)){
        cout << "No se puede construir" << endl;
        return;
    }

    // Pedir coordenadas y verificar si se puede construir;
    this->map->addCoords(row_pos, column_pos);
    if(!this->map->checkCoords(row_pos, column_pos)){
        cout << "Las coordenadas ingresadas no son v??lidas" << endl;
        return;
    }
    if(!this->map->checkTerrainSquare(row_pos, column_pos)){
        cout << "No se puede construir en las coordenadas ingresadas" << endl;
        return;
    }

    cout << "Escribe `Y` para confirmar: ";
    cin >> confirm;

    if(confirm == "Y" || confirm == "y"){
        this->map->setSquareName(row_pos, column_pos, name, this->buildings[pos]->getBuildingChar());
        this->buildings[pos]->increaseQuantity();
        decreaseMaterials(pos);
        cout << "Confirmado" << endl;
    }else{
        cout << "Cancelado" << endl;
    }
}

void Andypolis:: deleteBuildingByCoords()
{
    unsigned int row_pos, column_pos;
    int pos;
    string confirm;
    this->map->addCoords(row_pos, column_pos);
    if(!this->map->checkCoords(row_pos, column_pos)){
        cout << "Las coordenadas ingresadas no son v??lidas" << endl;
        return;
    }
    if(!this->map->checkTerrainBuilding(row_pos, column_pos)){
        cout << "No se puede destruir el edificio de las coordenadas ingresadas" << endl;
        return;
    }
    cout << "Escribe `Y` para confirmar: ";
    cin >> confirm;
    if(confirm == "Y" || confirm == "y"){
        pos = checkIfBuildingExistsByName(this->map->getNamefromCoods(row_pos, column_pos));
        this->buildings[pos]->decreaseQuantity();
        increaseMaterials(pos);
        this->map->emptySquare(row_pos, column_pos);
        cout << "Confirmado" << endl;        
    }else{
        cout << "Cancelado" << endl;
    }
}

void Andypolis:: showMap(){
    this->map->showMap();
}

void Andypolis:: checkMap()
{
    unsigned int row_pos, column_pos;
    this->map->addCoords(row_pos, column_pos);
    if(!this->map->checkCoords(row_pos, column_pos)){
        cout << "Las coordenadas ingresadas no son v??lidas" << endl;
        return;
    }
    this->map->getSquareData(row_pos, column_pos);
    return;
    
}

void Andypolis:: showInventory(){
    cout << endl << "======================" << endl << endl;
    cout << "Materiales de construccion: " << endl;
    for(int i = 0; i < this->material_quantity; i++){
        cout << "# " << this->materials[i]->getName() << " - " << this->materials[i]->getQuantity() << endl;
    }
    cout << endl << "======================" << endl << endl;
}

void Andypolis:: colectResources(){
    for(int j = 0; j < this->building_quantity; j++){
        switch(this->buildings[j]->getName()[0])
        {
            case 'm':
                for(int i = 0; i < this->material_quantity; i++){
                    if(this->materials[i]->getName() == "piedra"){
                        for (unsigned int k = 0; k < buildings[j]->getQuantity(); k++)
                        {
                            this->materials[i]->increaseQuantity(buildings[j]->getMaterialsProvided());
                        }
                    }

                        
                }
                break;
            case 'a':
                for(int i = 0; i < this->material_quantity; i++){
                    if(this->materials[i]->getName() == "madera"){
                        for (unsigned int k = 0; k < buildings[j]->getQuantity(); k++)
                        {
                            this->materials[i]->increaseQuantity(buildings[j]->getMaterialsProvided());
                        }
                    }
                }
                break;
            case 'f':
                for(int i = 0; i < this->material_quantity; i++){
                    if(this->materials[i]->getName() == "metal"){
                        for (unsigned int k = 0; k < buildings[j]->getQuantity(); k++)
                        {
                            this->materials[i]->increaseQuantity(buildings[j]->getMaterialsProvided());
                        }
                    } 
                }
                break;

        }

    }
    cout << "Recoleccion de recursos realizada " << endl;
}

void Andypolis:: rainResources(){
    //
}

// Andypolis:: Crea un Array din??mico temporal para dimensionar el actual, reemplazandolo y borrandolo.
void Andypolis:: addBuilding(Building* building){
    int prev_building_quantity = this->building_quantity;

    Building** new_buildings = new Building*[prev_building_quantity + 1];

    for (int i = 0; i < prev_building_quantity; i++){
        new_buildings[i] = this->buildings[i];
    }

    new_buildings[prev_building_quantity] = building;

    if(this->building_quantity != 0) delete[] this->buildings;

    this->buildings = new_buildings;
    this->building_quantity++;

}

char Andypolis:: addBuildingFromLocations(string name){
    int pos = checkIfBuildingExistsByName(name);
    
    this->buildings[pos]->increaseQuantity();

    return this->buildings[pos]->getBuildingChar();
}

void Andypolis:: addMaterial(Material* material){
    int prev_material_quantity = this->material_quantity;

    Material** new_materials = new Material*[prev_material_quantity + 1];

    for (int i = 0; i < prev_material_quantity; i++){
        new_materials[i] = this->materials[i];
    }

    new_materials[prev_material_quantity] = material;

    if(this->material_quantity != 0){
        delete[] this->materials;
    }

    this->materials = new_materials;
    this->material_quantity++;
}

void Andypolis:: processBuildingsFile(string filename){
    ifstream file(filename);

    string aux, name;
    unsigned int stone, wood, iron, max;

    while(file >> name){
        file >> aux;

        // Verifico si es un n??mero
        if(aux[0] >= (int)'0' && aux[0] <= (int)'9'){
            stone = stoi(aux);
        }else{
            name += ' ' + aux;
            file >> stone;
        }

        file >> wood >> iron >> max;
        addBuilding(new Building(name, stone, wood, iron, max));
    }

	file.close();
}

void Andypolis:: processMaterialsFile(string filename){
    ifstream file(filename);

    string name;
    unsigned int quantity;

    while(file >> name >> quantity){
        addMaterial(new Material(name, quantity));
    }

    file.close();
}

void Andypolis:: processLocationsFile(string filename){
    ifstream file(filename);

    string aux_3, aux, coords, row_aux, col_aux, name;
    unsigned int row_pos, col_pos;

    while(file >> name){
        file >> aux;
        if(aux[0] == '('){
            row_aux = aux;
        }else{
            name += ' ' + aux;
            file >> row_aux;
        }

        file >> col_aux;

        aux_3.clear();
        for(unsigned int i = 0; i < row_aux.length(); i++){
            if(isdigit(row_aux[i])){
                aux_3 += row_aux[i];
            }
        }

        col_pos = stoi(col_aux);
        row_pos = stoi(aux_3);
        this->map->setSquareName(row_pos, col_pos, name, addBuildingFromLocations(name));
    }

    file.close();
}

int Andypolis:: getBuildingQuantity(){
    return this->building_quantity;
}

int Andypolis:: getMaterialQuantity(){
    return this->material_quantity;
}

Building* Andypolis:: getBuildingByPos(int pos){
    return this->buildings[pos];
}

Material* Andypolis:: getMaterialByPos(int pos){
    return this->materials[pos];
}

void Andypolis:: saveChanges(string path_materials, string path_buildings, string path_locations){
    saveBuildingsChanges(path_buildings);
    saveMaterialsChanges(path_materials);
    saveMapChanges(path_locations);
}

void Andypolis:: setTotalBuilding(unsigned int quantity){
    this->building_quantity_total += quantity;
}

void Andypolis:: saveBuildingsChanges(string filename){
    ofstream file(filename);


    for (int i = 0; i < this->building_quantity; i++){

        setTotalBuilding(this->buildings[i]->getQuantity());

        file << this->buildings[i]->getName() << " " <<
            this->buildings[i]->getStone() << " " << 
            this->buildings[i]->getWood() << " " <<
            this->buildings[i]->getIron() << " " <<
            this->buildings[i]->getMax() << "\n";

        delete this->buildings[i];
    }

    delete [] this->buildings;
	file.close();
}

void Andypolis:: saveMaterialsChanges(string filename){
    ofstream file(filename);

    for (int i = 0; i < this->material_quantity; i++){
        file << this->materials[i]->getName() << " " << this->materials[i]->getQuantity() << '\n';
        delete this->materials[i];
    }

    delete [] this->materials;
	file.close();
}

void Andypolis:: saveMapChanges(string filename_locations){
    this->map->saveChanges(filename_locations, this->building_quantity_total);
}

Andypolis:: ~Andypolis(){
}