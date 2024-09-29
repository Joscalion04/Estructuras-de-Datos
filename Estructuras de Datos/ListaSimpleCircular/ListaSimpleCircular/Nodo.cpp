#include "Nodo.h"

Nodo::Nodo()
{
	this->Elemento = nullptr;
	this->Siguiente = nullptr;
}

Nodo::Nodo(Persona* Elemento)
{
	this->Elemento = Elemento;
	this->Siguiente = nullptr;
}

Nodo* Nodo::getSiguiente()
{
	return this->Siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente)
{
	this->Siguiente = siguiente;
}

Persona* Nodo::getElemento()
{
	return Elemento;
}

void Nodo::setElemento(Persona* elemento)
{
	this->Elemento = elemento;
}
