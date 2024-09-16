#include "Nodo.h"

Nodo::Nodo()
{
	this->elemento = new Persona();
	this->atras = nullptr;
}

Nodo::Nodo(Persona* elemento)
{
	this->elemento = elemento;
	this->atras = nullptr;
}

Nodo::~Nodo()
{
	this->elemento = nullptr;
	this->atras = nullptr;
}

Persona* Nodo::getElemento()
{
	return this->elemento;
}

void Nodo::setElemento(Persona* NewElemento)
{
	this->elemento = NewElemento;
}

Nodo* Nodo::getAtras()
{
	return this->atras;
}

void Nodo::setAtras(Nodo* siguiente)
{
	this->atras = siguiente;
}