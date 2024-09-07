#pragma once
#include "Persona.h"

class Nodo {
private:
    Persona* elemento;
    Nodo* siguiente;
    Nodo* anterior;

public:
    Nodo(Persona* elemento) : elemento(elemento), siguiente(nullptr), anterior(nullptr) {}

    Persona* getElemento() const { return elemento; }
    Nodo* getSiguiente() const { return siguiente; }
    Nodo* getAnterior() const { return anterior; }
    void setSiguiente(Nodo* siguiente) { this->siguiente = siguiente; }
    void setAnterior(Nodo* anterior) { this->anterior = anterior; }
};
