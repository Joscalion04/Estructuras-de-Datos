#ifndef NODO_H
#define NODO_H

#include "Persona.h"

class Nodo {
private:
    Persona* elemento;
    Nodo* siguiente;
    Nodo* anterior;

public:
    Nodo();
    Nodo(Persona* elemento);
    ~Nodo();

    Persona* getElemento();
    void setElemento(Persona* elemento);

    Nodo* getSiguiente();
    void setSiguiente(Nodo* siguiente);

    Nodo* getAnterior();
    void setAnterior(Nodo* anterior);
};

#endif
