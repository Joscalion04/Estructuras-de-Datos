#pragma once
#include<iostream>
using namespace std;

class Persona
{
private:
	string nombre;
	int edad;
	string direccion;

public:
	Persona();
	Persona(string nombre, int edad, string direccion);
	~Persona() {}
	string getNombre();					void setNombre(string nombre);
	int getEdad();						void setEdad(int edad);
	string getDireccion();				void setDireccion(string direccion);
	string toString();

};