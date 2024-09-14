#include "Nodo.h"

Nodo::Nodo(Persona* element)
{
	izquierda = nullptr;
	derecha = nullptr;
	this->elemento = element;
}
