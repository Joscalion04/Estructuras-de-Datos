#pragma once
#include<iostream>
#include"Persona.h"

using namespace std;

class Nodo
{
private:
	Persona* elemento;
	Nodo* siguiente;

public:
	Nodo();
	Nodo(Persona* elemento);
	~Nodo();
	Persona* getElemento();
	void setElemento(Persona* NewElemento);
	Nodo* getSiguiente();
	void setSiguiente(Nodo* siguiente);
};

