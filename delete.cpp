void Andypolis:: deleteBuildingByCoords()
{
    unsigned int row_pos, column_pos;
    int pos;
    string confirm;
    this->map->addCoords(row_pos, column_pos);
    if(!this->map->checkCoords(row_pos, column_pos)){
        cout << "Las coordenadas ingresadas no son válidas" << endl;
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