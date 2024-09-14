#pragma once
#include "Nodo.h"
#include "Persona.h"
#include <string>

class Arbol
{
private:
    // Atributos
    Nodo* raiz;

    // Método auxiliar para insertar un nuevo nodo en el árbol
    Nodo* insertar(Nodo* nodo, Persona* valor);

    // Método auxiliar para buscar un valor en el árbol
    bool buscar(Nodo* nodo, Persona* valor) const;

    // Método auxiliar para eliminar un nodo del árbol
    Nodo* eliminar(Nodo* nodo, Persona* valor);

    // Método auxiliar para encontrar el nodo con el valor mínimo
    Nodo* minValorNodo(Nodo* nodo);

    // Método auxiliar para generar el string in-order (izquierda, nodo, derecha)
    void toString(Nodo* nodo, std::string& resultado) const;

public:
    // Constructor
    Arbol() : raiz(nullptr) {}

    // Método para insertar un valor en el árbol
    void insertar(Persona* valor);

    // Método para buscar un valor en el árbol
    bool buscar(Persona* valor) const;

    // Método para eliminar un valor del árbol
    void eliminar(Persona* valor);

    // Método para obtener una representación del árbol en forma de string
    std::string toString() const;
};
