#pragma once
#include "Persona.h"

class Nodo
{
private:
	Nodo* Siguiente;
	Persona* Elemento;

public:
	Nodo();
	Nodo(Persona* Elemento);
	Nodo* getSiguiente();
	void setSiguiente(Nodo* siguiente);
	Persona* getElemento();
	void setElemento(Persona* elemento);

};

