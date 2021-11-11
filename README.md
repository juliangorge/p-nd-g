# p-nd-g
P&amp;G

P&G

- Se le asigna un caracter al objeto edificio o material en base al primer caracter de su nombre, por lo tanto, si se tiene por ejemplo los edificios Mina y Monasterios, ambos se veran representados en el mapa con una M

- En el ingreso del nombre del edificio por consola del edificio a construir, se utilizo el comando getlina(cin, name) 2 VECES ya que por alguna razon, al colocar una vez el comando, name tenia asignado el \n de la opcion anterior.

- Tanto para construcción, demolición y consulta de casillero, el número a ingresar para fila y columna se hace en base al número de fila y número de columna; NO A LA POSICIÓN ALMACENADA EN SQUARE (row_pos, column_pos).
 Ej: si en la opción del menu nº6, se ingresa Fila: 1 - Columna: 1, mostrará el Square de coordenadas (0,0).