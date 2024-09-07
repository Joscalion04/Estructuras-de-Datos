#pragma once
#include<iostream>
#include"Persona.h"

using namespace std;

class Nodo
{
private:
	Persona* elemento;
	Nodo* siguiente; // ABAJO

public:
	Nodo();
	Nodo(Persona* elemento);
	~Nodo();
	Persona* getElemento();
	void setElemento(Persona* NewElemento);
	Nodo* getSiguiente(); //GETABAJO
	void setSiguiente(Nodo* siguiente);
};

