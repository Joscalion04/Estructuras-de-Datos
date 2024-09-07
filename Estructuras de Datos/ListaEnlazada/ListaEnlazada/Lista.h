#pragma once
#include"Nodo.h"
using namespace std;

class Lista
{
private:
	Nodo* primero; // {Elemento & Siguiente(Nodo-> {Elemento & Siguiente(Nodo->{Elemento & Siguiente->....})})}

public:
	Lista();
	~Lista();
	void insertar(Persona* nuevo);
	void insertarAlInicio(Persona* nuevo);
	void insertarEspecifico(Persona* nuevo, string personaDeReferencia);
	bool intercambiarNodo(string nombre1, string nombre2);
	string toString();
	Persona* buscarPersonaNombre(string nombre);
	bool eliminarPersonaNombre(string nombre);
	string toStringPersona(string nombre);

};

