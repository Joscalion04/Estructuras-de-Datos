#pragma once
#include<iostream>
#include"Persona.h"

using namespace std;

class Nodo
{
private:
	Persona* elemento;
	Nodo* atras;

public:
	Nodo();
	Nodo(Persona* elemento);
	~Nodo();
	Persona* getElemento();
	void setElemento(Persona* NewElemento);
	Nodo* getAtras();
	void setAtras(Nodo* siguiente);
};

