#include "Andypolis.h"
#include <string>
#include <fstream>

using namespace std;

Andypolis:: Andypolis(){
    this->building_quantity = 0;
    this->material_quantity = 0;
}

void Andypolis:: showMaterials(){
    cout << endl << "======================" << endl << endl;
    cout << "Materiales de construccion: " << endl;
    for(int i = 0; i < this->material_quantity; i++){
        cout << "# " << this->materials[i]->getName() << " - " << this->materials[i]->getQuantity() << endl;
    }
    cout << endl << "======================" << endl << endl;
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
    cout << "Edificios: " << endl;

    for(int i = 0; i < this->building_quantity; i++){
        cout << "-> " << (i+1) << ": " << this->buildings[i]->getName() << endl;
        cout << "Construidos: " << this->buildings[i]->getQuantity() << " (" << (this->buildings[i]->getMax() - this->buildings[i]->getQuantity()) << " para el maximo permitido) " << endl;
        cout << endl;
    }
    cout << "======================" << endl << endl;
}

void Andypolis:: newBuilding(){
    string name, confirm;
    int pos;

    if((pos = checkIfBuildingExistsByName()) == -1) return;

    if(!checkByMaterials(pos) || !checkByMax(pos)) return;

    cout << "Escribe `Y` para confirmar: ";
    cin >> confirm;

    if(confirm == "Y" || confirm == "y"){
        this->buildings[pos]->increaseQuantity();
        decreaseMaterials(pos);
        cout << "Confirmado" << endl;
    }else{
        cout << "Cancelado" << endl;
    }
}

void Andypolis:: deleteBuilding(){
    string name, confirm;
    int pos;

    if((pos = checkIfBuildingExistsByName()) == -1) return;

    if(!checkByMin(pos)) return;

    cout << "Escribe `Y` para confirmar: ";
    cin >> confirm;

    if(confirm == "Y" || confirm == "y"){
        this->buildings[pos]->decreaseQuantity();
        increaseMaterials(pos);
        cout << "Confirmado" << endl;        
    }else{
        cout << "Cancelado" << endl;
    }
}

int Andypolis:: checkIfBuildingExistsByName(){
    string name;
    bool exists = false;
    int pos = -1, i = 0;

    cout << "Ingrese el nombre: ";
    cin >> name;

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

// Andypolis:: Crea un Array dinámico temporal para dimensionar el actual, reemplazandolo y borrandolo.
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
    string name;
    int stone, wood, iron, max;

    while(file >> name >> stone >> wood >> iron >> max){
        addBuilding(new Building(name, stone, wood, iron, max));
   }

	file.close();
}

void Andypolis:: processMaterialsFile(string filename){
    ifstream file(filename);
    string name;
    int quantity;

    while(file >> name >> quantity){
        addMaterial(new Material(name, quantity));
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

void Andypolis:: saveBuildingsChanges(string filename){
    ofstream file(filename);

    for (int i = 0; i < this->building_quantity; i++){
        file << this->buildings[i]->getName() << " " <<
            this->buildings[i]->getStone() << " " << 
            this->buildings[i]->getWood() << " " <<
            this->buildings[i]->getIron() << " " <<
            this->buildings[i]->getQuantity() << " " <<
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

Andypolis:: ~Andypolis(){
}