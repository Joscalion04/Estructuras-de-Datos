#include "Nodo.h"

Nodo::Nodo()
{
	this->elemento = new Persona();
	this->siguiente = nullptr;
}

Nodo::Nodo(Persona* elemento)
{
	this->elemento = elemento;
	this->siguiente = nullptr;
}

Nodo::~Nodo()
{
	this->elemento = nullptr;
	this->siguiente = nullptr;
}

Persona* Nodo::getElemento()
{
	return this->elemento;
}

void Nodo::setElemento(Persona* NewElemento)
{
	this->elemento = NewElemento;
}

Nodo* Nodo::getSiguiente()
{
	return this->siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente)
{
	this->siguiente = siguiente;
}