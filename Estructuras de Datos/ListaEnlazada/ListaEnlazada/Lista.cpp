#include "Lista.h"
#include<sstream>

Lista::Lista()
{
	primero = nullptr; // puntero nulo
}

Lista::~Lista()
{
	while (primero!=nullptr) {
		Nodo* aux = primero;
		primero = primero->getSiguiente();
		delete aux->getElemento();
		delete aux;
	}
}

void Lista::insertar(Persona* nuevo) // INSERTAR AL FINAL
{
	Nodo* newNodo = new Nodo(nuevo); // Nuevo nodo a insertar 
	if (primero==nullptr) { // Caso: La lista esta vacia
		primero = newNodo; // O(1) (Complejidad Constante)
	}else { // Caso: La lista ya tiene elementos
		// primero->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente.....
		Nodo* aux = primero; // Copio el primer nodo 
		while (aux->getSiguiente()!=nullptr) { // Mientras que el nodo que tenga enfrente no este vacio
			// Metodos que ocupen recorrer la lista //
			aux = aux->getSiguiente(); // Se mueve al siguiente nodo
		}
		aux->setSiguiente(newNodo); // Se asignaba el nuevo nodo al final
	}
}

void Lista::insertarAlInicio(Persona* nuevo)
{
	Nodo* newNodo = new Nodo(nuevo);
	if (primero == nullptr) { // La lista está vacía
		primero = newNodo;
	}
	else { // La lista ya tiene elementos
		newNodo->setSiguiente(primero);
		primero = newNodo;
	}
}

void Lista::insertarEspecifico(Persona* nuevo, string personaDeReferencia)
{
	Nodo* newNodo = new Nodo(nuevo);
	Nodo* aux = primero;

	// Si la lista está vacía o el nuevo nodo debe insertarse al inicio
	if (primero == nullptr || primero->getElemento()->getNombre() == personaDeReferencia) {
		newNodo->setSiguiente(primero);
		primero = newNodo;
		return;
	}

	// Busca el nodo con el nombre de referencia
	while (aux->getSiguiente() != nullptr && aux->getSiguiente()->getElemento()->getNombre() != personaDeReferencia) {
		aux = aux->getSiguiente();
	}

	// Si se encuentra el nodo de referencia, se inserta después de él
	if (aux->getSiguiente() != nullptr) {
		newNodo->setSiguiente(aux->getSiguiente());
		aux->setSiguiente(newNodo);
	}
	else {
		// Si no se encuentra el nodo de referencia, se inserta al final
		aux->setSiguiente(newNodo);
	}
}

bool Lista::intercambiarNodo(string nombre1, string nombre2)
{
	if (nombre1 == nombre2) return false; // Si los nombres son iguales, no hay nada que intercambiar

	Nodo* prev1 = nullptr, *curr1 = primero;
	Nodo* prev2 = nullptr, *curr2 = primero;

	// Buscar los nodos correspondientes a `nombre1` y `nombre2`
	while (curr1 != nullptr && curr1->getElemento()->getNombre() != nombre1) {
		prev1 = curr1;
		curr1 = curr1->getSiguiente();
	}

	while (curr2 != nullptr && curr2->getElemento()->getNombre() != nombre2) {
		prev2 = curr2;
		curr2 = curr2->getSiguiente();
	}

	// Si alguno de los nodos no se encuentra, se retorna false
	if (curr1 == nullptr || curr2 == nullptr) return false;

	// Si uno de los nodos es el primero en la lista
	if (prev1 != nullptr) prev1->setSiguiente(curr2);
	else primero = curr2;

	if (prev2 != nullptr) prev2->setSiguiente(curr1);
	else primero = curr1;

	// Intercambiar los nodos
	Nodo* temp = curr2->getSiguiente();
	curr2->setSiguiente(curr1->getSiguiente());
	curr1->setSiguiente(temp);

	return true;
}

string Lista::toString()
{
	stringstream s; s << "----------------- LISTA -----------------\n";
	Nodo* aux = primero; // Copiar el primer nodo
	while (aux!=nullptr) { // O(n) Complejidad LINEAL (TIENE UN CICLO)
		s << aux->getElemento()->toString() << endl;
		aux = aux->getSiguiente(); // Se mueve al siguiente nodo
	}
	return s.str();
}

Persona* Lista::buscarPersonaNombre(string nombre)
{
	Nodo* aux = primero; // Copiar el primer nodo
	while (aux != nullptr) { // O(n) Complejidad LINEAL (TIENE UN CICLO)
		if (aux->getElemento()->getNombre()==nombre) {
			return aux->getElemento();
		}
		aux = aux->getSiguiente(); // Se mueve al siguiente nodo
	}
	return nullptr; // NO LO ENCONTRE O NO EXISTE
}

bool Lista::eliminarPersonaNombre(string nombre)
{
	// Caso 1: Lista Vacia
	if (primero == nullptr)return false; 

	// Caso 2: Si el nodo a eliminar es el primero 
	if (primero->getElemento()->getNombre()==nombre) {
		Nodo* aux = primero; // Copio la lista
		primero = primero->getSiguiente();
		delete aux->getElemento();
		delete aux;
		return true;
	}else { // Caso 3: Es cualquier otro nodo 
		Nodo* aux = primero;
		while (aux->getSiguiente()!=nullptr&&aux->getSiguiente()->getElemento()->getNombre()==nombre) {
			aux = aux->getSiguiente(); 
		}
		if (aux->getSiguiente() == nullptr)return false;
		Nodo* aux2 = aux->getSiguiente();
		aux->setSiguiente(aux->getSiguiente()->getSiguiente());
		delete aux2->getElemento();
		delete aux2;
		return true;
	}
}

string Lista::toStringPersona(string nombre)
{
	if (buscarPersonaNombre(nombre) != nullptr)return buscarPersonaNombre(nombre)->toString();
	return "No se puo encontrar la persona";
}
