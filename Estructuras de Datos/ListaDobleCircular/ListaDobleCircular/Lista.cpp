#include "Lista.h"
#include <sstream>

Lista::Lista() {
    primero = nullptr;
}

Lista::~Lista() {
    if (primero != nullptr) {
        Nodo* actual = primero;
        do {
            Nodo* aux = actual;
            actual = actual->getSiguiente();
            delete aux->getElemento();
            delete aux;
        } while (actual != primero);
    }
}

void Lista::insertar(Persona* nuevo) { 
    // O(1) Tiempo 
    // O(1) Espacio
    Nodo* newNodo = new Nodo(nuevo);
    if (primero == nullptr) {
        primero = newNodo;
        primero->setSiguiente(primero);
        primero->setAnterior(primero);
    }
    else {
        Nodo* ultimo = primero->getAnterior(); 
        ultimo->setSiguiente(newNodo);
        newNodo->setAnterior(ultimo);
        newNodo->setSiguiente(primero);
        primero->setAnterior(newNodo);
    }
}

void Lista::insertarAlInicio(Persona* nuevo) {
    Nodo* newNodo = new Nodo(nuevo);
    if (primero == nullptr) {
        primero = newNodo;
        primero->setSiguiente(primero);
        primero->setAnterior(primero);
    }
    else {
        Nodo* ultimo = primero->getAnterior();
        newNodo->setSiguiente(primero);
        newNodo->setAnterior(ultimo);
        primero->setAnterior(newNodo);
        ultimo->setSiguiente(newNodo);
        primero = newNodo;
    }
}

void Lista::insertarEspecifico(Persona* nuevo, string personaDeReferencia) {
    Nodo* newNodo = new Nodo(nuevo);
    if (primero == nullptr) {
        primero = newNodo;
        primero->setSiguiente(primero);
        primero->setAnterior(primero);
    }
    else {
        Nodo* actual = primero;
        do {
            if (actual->getElemento()->getNombre() == personaDeReferencia) {
                Nodo* siguiente = actual->getSiguiente();
                newNodo->setSiguiente(siguiente);
                newNodo->setAnterior(actual);
                actual->setSiguiente(newNodo);
                siguiente->setAnterior(newNodo);
                return;
            }
            actual = actual->getSiguiente();
        } while (actual != primero); //
        // Si no se encuentra la referencia, se inserta al final
        insertar(nuevo);
    }
}

bool Lista::intercambiarNodo(string nombre1, string nombre2) {
    if (nombre1 == nombre2) return false;

    Nodo* nodo1 = nullptr;
    Nodo* nodo2 = nullptr;
    Nodo* actual = primero;

    do {
        if (actual->getElemento()->getNombre() == nombre1) {
            nodo1 = actual;
        }
        if (actual->getElemento()->getNombre() == nombre2) {
            nodo2 = actual;
        }
        actual = actual->getSiguiente();
    } while (actual != primero && (nodo1 == nullptr || nodo2 == nullptr));

    if (nodo1 == nullptr || nodo2 == nullptr) return false;

    // Intercambiar conexiones de los nodos
    if (nodo1->getSiguiente() == nodo2) { // Nodos adyacentes
        Nodo* nodo1Prev = nodo1->getAnterior();
        Nodo* nodo2Next = nodo2->getSiguiente();

        nodo1Prev->setSiguiente(nodo2);
        nodo2->setAnterior(nodo1Prev);
        nodo2->setSiguiente(nodo1);
        nodo1->setAnterior(nodo2);
        nodo1->setSiguiente(nodo2Next);
        nodo2Next->setAnterior(nodo1);
    }
    else if (nodo2->getSiguiente() == nodo1) { // Nodos adyacentes (en orden inverso)
        Nodo* nodo2Prev = nodo2->getAnterior();
        Nodo* nodo1Next = nodo1->getSiguiente();

        nodo2Prev->setSiguiente(nodo1);
        nodo1->setAnterior(nodo2Prev);
        nodo1->setSiguiente(nodo2);
        nodo2->setAnterior(nodo1);
        nodo2->setSiguiente(nodo1Next);
        nodo1Next->setAnterior(nodo2);
    }
    else { // Nodos no adyacentes
        Nodo* nodo1Prev = nodo1->getAnterior();
        Nodo* nodo1Next = nodo1->getSiguiente();
        Nodo* nodo2Prev = nodo2->getAnterior();
        Nodo* nodo2Next = nodo2->getSiguiente();

        nodo1Prev->setSiguiente(nodo2);
        nodo2->setAnterior(nodo1Prev);
        nodo2->setSiguiente(nodo1Next);
        nodo1Next->setAnterior(nodo2);

        nodo2Prev->setSiguiente(nodo1);
        nodo1->setAnterior(nodo2Prev);
        nodo1->setSiguiente(nodo2Next);
        nodo2Next->setAnterior(nodo1);
    }

    if (primero == nodo1) {
        primero = nodo2;
    }
    else if (primero == nodo2) {
        primero = nodo1;
    }

    return true;
}

string Lista::toString() {
    stringstream s;
    s << "----------------- LISTA -----------------\n";
    if (primero != nullptr) {
        Nodo* actual = primero;
        do {
            s << actual->getElemento()->toString() << endl;
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    return s.str();
}

Persona* Lista::buscarPersonaNombre(string nombre) {
    if (primero == nullptr) return nullptr;
    Nodo* actual = primero;
    do {
        if (actual->getElemento()->getNombre() == nombre) {
            return actual->getElemento();
        }
        actual = actual->getSiguiente();
    } while (actual != primero);
    return nullptr;
}

bool Lista::eliminarPersonaNombre(string nombre) {
    if (primero == nullptr) return false;

    Nodo* actual = primero;
    do {
        if (actual->getElemento()->getNombre() == nombre) {
            Nodo* nodoAnterior = actual->getAnterior();
            Nodo* nodoSiguiente = actual->getSiguiente();

            if (actual == primero) {
                if (primero->getSiguiente() == primero) {
                    primero = nullptr;
                }
                else {
                    primero = nodoSiguiente;
                }
            }

            nodoAnterior->setSiguiente(nodoSiguiente);
            nodoSiguiente->setAnterior(nodoAnterior);

            delete actual->getElemento();
            delete actual;

            return true;
        }
        actual = actual->getSiguiente();
    } while (actual != primero);

    return false;
}

string Lista::toStringPersona(string nombre) {
    Persona* persona = buscarPersonaNombre(nombre);
    if (persona != nullptr) {
        return persona->toString();
    }
    return "No se pudo encontrar la persona";
}
