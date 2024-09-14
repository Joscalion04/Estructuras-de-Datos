#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

// Clase Nodo, que representa cada nodo del �rbol
class Nodo {
public:
    Persona* elemento;
    Nodo* izquierda;
    Nodo* derecha;

    // Constructor del nodo
    Nodo(Persona* element);
};