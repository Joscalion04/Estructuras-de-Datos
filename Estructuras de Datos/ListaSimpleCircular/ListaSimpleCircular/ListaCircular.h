#pragma once
#include "Nodo.h"
using namespace std;

class ListaCircular
{
private:
	Nodo* primero;

public:
	ListaCircular();
	~ListaCircular();
	void insertar(Persona* nuevo);
	Persona* buscarPersona(string );
	bool eliminarPersona(string );
	string toString();
	bool existe(string);
	bool vacia();
};

