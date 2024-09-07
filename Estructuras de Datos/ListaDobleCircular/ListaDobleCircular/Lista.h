#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
private:
    Nodo* primero; // primero->anterior == Ultimo //primero->getAnterior(); O(1)

public:
    Lista();
    ~Lista();

    void insertar(Persona* nuevo);
    void insertarAlInicio(Persona* nuevo);
    void insertarEspecifico(Persona* nuevo, string personaDeReferencia);
    bool intercambiarNodo(string nombre1, string nombre2);
    string toString();
    Persona* buscarPersonaNombre(string nombre);
    bool eliminarPersonaNombre(string nombre);
    string toStringPersona(string nombre);
};

#endif
