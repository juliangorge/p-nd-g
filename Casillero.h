#ifndef CASILLERO_H
#define CASILLERO_H

class Casillero {

    // Attributes
    protected:
    	char[1] terreno;
    	unsigned int fila;
    	unsigned int columna;

	public: 
		Casillero();
		virtual void mostrar() = 0;
};

class CasilleroTransitable : public Casillero  /* Sintaxis para indicar que CasilleroTransitable hereda de Casillero */
{
	// Attributes
	// protected:
	//

    public:
    	void mostrar();
};


class CasilleroConstruible : public Casillero  /* Sintaxis para indicar que CasilleroConstruible hereda de Casillero */
{
	// Attributes
	private:
		Edificio* edificio;

    public:
    	void mostrar();
};

class CasilleroInaccesible : public Casillero  /* Sintaxis para indicar que CasilleroInaccesible hereda de Casillero */
{
	// Attributes
	// protected:
	//

    public:
    	void mostrar();
};

#endif // CASILLERO_H