# Carga de archivos TIENE QUE SER CON MEMORIA DINÁMICA

+ Herencia para Materiales.
+ Polimorfismo para Edificios.

//

void Andypolis::cargarTerrenos(fila, columna, terreno)
{
    switch(terreno)
    {
        case 'C':
            this->mapa[fila][columna] = new Camino();
            break;

        case 'T':
            this->mapa[fila][columna] = new Terreno();
            break;

        default:
            this->mapa[fila][columna] = new Lago();
    }
}
