#pragma once
#include <iostream>
#include "Nodo.h"

class ListaDoble { // Nodo (Raiz)
private:
    Nodo* cabeza; // 

public:
    ListaDoble() : cabeza(nullptr){}
    ~ListaDoble();

    void insertarInicio(Persona* nuevo);
    void insertarFinal(Persona* nuevo);
    void eliminar(Persona* persona);
    void mostrarLista();
    bool estaVacia() const;
};
