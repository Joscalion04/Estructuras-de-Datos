#include "ListaCircular.h"
#include <sstream>

ListaCircular::ListaCircular()
{
	this->primero = nullptr;
}

ListaCircular::~ListaCircular()
{
	if (!vacia()) {
		Nodo* aux = primero;
		do {
			Nodo* deleter = aux;
			aux = aux->getSiguiente();
			delete deleter->getElemento();
			delete deleter;
		} while (aux!=primero);
	}
}

void ListaCircular::insertar(Persona* nuevo)
{
	Nodo* nuevoNodo = new Nodo(nuevo);
	if (vacia()) {  // LISTA VACIA?
		primero = nuevoNodo;
		primero->setSiguiente(primero);
	}
	else {
		Nodo* aux = primero;
		while (aux->getSiguiente()!=primero) { // Llegar hasta el final
			aux = aux->getSiguiente();
		}
		// Auxiliar en este momento es el ultimo nodo de la lista
		aux->setSiguiente(nuevoNodo); // Vamos a hacer que ahora tenga de siguiente al nuevo nodo
		nuevoNodo->setSiguiente(primero); // Ahora el nuevo nodo tiene de siguiente a primero
		// Con esto nuevo nodo se logro insertar al final
	}
}

Persona* ListaCircular::buscarPersona(string nombre)
{
	if (vacia()) return nullptr; // LISTA VACIA?
	Nodo* aux = primero;
	while (aux->getSiguiente()!=primero) { // Recorre lista
		if (aux->getElemento()->getNombre() == nombre) { // Pregunta si el nodo actual tiene de persona la que se busca
			return aux->getElemento(); // si es asi, se retorna
		}
		aux = aux->getSiguiente();
	}
	return nullptr;
}

bool ListaCircular::eliminarPersona(string nombre)
{
	if (vacia()) return false; // LISTA VACIA?

	Nodo* aux = primero;
	Nodo* anterior = nullptr;  // Para mantener el nodo anterior durante la iteración

	do { // Usamos un `do-while` ya que es una lista circular
		if (aux->getElemento()->getNombre() == nombre) { // Si el nombre coincide
			if (aux == primero) { // Si es el primero
				if (primero->getSiguiente() == primero) { // Si es el único nodo
					delete primero->getElemento(); // Borra el elemento
					delete primero; // Borra el nodo
					primero = nullptr; // La lista queda vacía
				}
				else { // Si hay más de un nodo
					Nodo* deleter = primero; // Guarda el nodo a eliminar
					// Encuentra el último nodo para actualizar su puntero
					Nodo* ultimo = primero;
					while (ultimo->getSiguiente() != primero) {
						ultimo = ultimo->getSiguiente();
					}
					primero = primero->getSiguiente(); // Reasigna el nuevo primero
					ultimo->setSiguiente(primero); // Último apunta al nuevo primero
					delete deleter->getElemento(); // Borra el elemento del nodo anterior
					delete deleter; // Borra el nodo
				}
			}
			else { // Si no es el primero
				anterior->setSiguiente(aux->getSiguiente()); // Conecta el anterior con el siguiente
				delete aux->getElemento(); // Borra el elemento del nodo
				delete aux; // Borra el nodo
			}
			return true; // Eliminación exitosa
		}
		anterior = aux; // Actualiza el anterior
		aux = aux->getSiguiente(); // Avanza al siguiente nodo
	} while (aux != primero); // Recorre toda la lista
	return false; // No se encontró el nodo con el nombre dado
}

string ListaCircular::toString()
{
	stringstream s;
	Nodo* aux = primero;
	do {
		s << aux->getElemento()->toString() << endl;
		aux = aux->getSiguiente();
	} while (aux!=primero);

	return s.str();
}

bool ListaCircular::existe(string nombre)
{
	Nodo* aux = primero;
	do {
		if (aux->getElemento()->getNombre()==nombre) {
			return true;
		}
		aux = aux->getSiguiente();
	} while (aux!=primero);
	return false;
}

bool ListaCircular::vacia()
{
	return primero == nullptr;
}
