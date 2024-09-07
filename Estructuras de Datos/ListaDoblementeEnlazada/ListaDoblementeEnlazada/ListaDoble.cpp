#include "ListaDoble.h"

ListaDoble::~ListaDoble()
{
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}

void ListaDoble::insertarInicio(Persona* nuevo) // O(1)
{
    Nodo* nuevoNodo = new Nodo(nuevo);
    if (estaVacia()) {
        cabeza = nuevoNodo;
    }
    else {
        nuevoNodo->setSiguiente(cabeza);
        cabeza->setAnterior(nuevoNodo);
        cabeza = nuevoNodo;
    }
}

void ListaDoble::insertarFinal(Persona* nuevo) // O(n)
{
    Nodo* nuevoNodo = new Nodo(nuevo);
    if (estaVacia()) {
        cabeza = nuevoNodo;
    }
    else {
        Nodo* aux = cabeza;
        while (aux->getSiguiente() != nullptr) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(aux);
    }
}

void ListaDoble::eliminar(Persona* persona) // O(n)
{
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->getElemento() == persona) {
            if (actual == cabeza) { // Si es el primero
                cabeza = cabeza->getSiguiente(); // Ajusta el primero al que le sigue
                if (cabeza != nullptr) {
                    cabeza->setAnterior(nullptr);
                }
            }
            else {
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
                if (actual->getSiguiente() != nullptr) {
                    actual->getSiguiente()->setAnterior(actual->getAnterior());
                }
            }
            delete actual;
            return;
        }
        actual = actual->getSiguiente();
    }
}

void ListaDoble::mostrarLista()
{
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->getElemento()->toString() << std::endl;
        actual = actual->getSiguiente();
    }
}

bool ListaDoble::estaVacia() const
{
    return cabeza == nullptr;
}
