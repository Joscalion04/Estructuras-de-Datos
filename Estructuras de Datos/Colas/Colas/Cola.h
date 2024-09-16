#pragma once
#include <iostream>
#include<sstream>

#include "Nodo.h"
class Cola
{
private:
	Nodo* Head;
	Nodo* Peek;

public:
	Cola();
	~Cola();
	// Operaciones de la Cola
	void enqueue(Persona* nuevo); // Inserta frente al ultimo elemento 
	void dequeue(); // Elimina el ultimo elemento 
	Persona* peek(); // Devuelve el ultimo elemento
	bool estaVacia(); // Pregunta si esta vacia 
	Persona* head();
};

