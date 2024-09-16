#include "Nodo.h"

Nodo::Nodo()
{
	this->elemento = new Persona();
	this->abajo = nullptr;
}

Nodo::Nodo(Persona* elemento)
{
	this->elemento = elemento;
	this->abajo = nullptr;
}

Nodo::~Nodo()
{
	this->elemento = nullptr;
	this->abajo = nullptr;
}

Persona* Nodo::getElemento()
{
	return this->elemento;
}

void Nodo::setElemento(Persona* NewElemento)
{
	this->elemento = NewElemento;
}

Nodo* Nodo::getAbajo()
{
	return this->abajo;
}

void Nodo::setAbajo(Nodo* siguiente)
{
	this->abajo = siguiente;
}