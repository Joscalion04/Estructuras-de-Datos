#pragma once
#include<iostream>
#include"Persona.h"

using namespace std;

class Nodo
{
private:
	Persona* elemento;
	Nodo* abajo; 

public:
	Nodo();
	Nodo(Persona* elemento);
	~Nodo();
	Persona* getElemento();
	void setElemento(Persona* NewElemento);
	Nodo* getAbajo(); //GETABAJO
	void setAbajo(Nodo* siguiente);
};

