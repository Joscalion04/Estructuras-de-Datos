#include "Persona.h"
#include<sstream>

Persona::Persona()
{
	this->nombre = "indefinido";
	this->edad = 0;
	this->direccion = "indefinido";
}

Persona::Persona(string nombre, int edad, string direccion)
{
	this->nombre = nombre;
	this->edad = edad;
	this->direccion = direccion;
}

string Persona::getNombre()
{
	return nombre;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Persona::getDireccion()
{
	return direccion;
}

void Persona::setDireccion(string direccion)
{
	this->direccion = direccion;
}


int Persona::getEdad()
{
	return edad;
}

void Persona::setEdad(int edad)
{
	this->edad = edad;
}


string Persona::toString()
{
	stringstream s;
	s << "----------------------------" << endl;
	s << "Nombre: " << nombre << endl;
	s << "Edad: " << edad << endl;
	s << "Direccion: " << direccion << endl;
	s << "----------------------------" << endl;

	return s.str();
}