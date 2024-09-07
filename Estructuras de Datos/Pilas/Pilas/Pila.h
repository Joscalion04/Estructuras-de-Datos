#pragma once
#include <iostream>
#include "Nodo.h"

class Pila {
private:
    Nodo* Top; 

public:
    Pila();
    ~Pila();
    void push(Persona* persona);
    void pop();
    Persona* top();
    bool estaVacia();
};