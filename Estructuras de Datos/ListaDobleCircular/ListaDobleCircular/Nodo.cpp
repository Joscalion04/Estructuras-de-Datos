#include "Nodo.h"

Nodo::Nodo() {
    this->elemento = new Persona();
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

Nodo::Nodo(Persona* elemento) {
    this->elemento = elemento;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

Nodo::~Nodo() {
    this->elemento = nullptr;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

Persona* Nodo::getElemento() {
    return this->elemento;
}

void Nodo::setElemento(Persona* elemento) {
    this->elemento = elemento;
}

Nodo* Nodo::getSiguiente() {
    return this->siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}

Nodo* Nodo::getAnterior() {
    return this->anterior;
}

void Nodo::setAnterior(Nodo* anterior) {
    this->anterior = anterior;
}
