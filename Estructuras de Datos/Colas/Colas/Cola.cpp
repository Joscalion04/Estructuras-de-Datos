#include "Cola.h"

Cola::Cola() : Head(nullptr), Peek(nullptr) {}

Cola::~Cola()
{
    while (Head != nullptr) {
        Nodo* temp = Head;
        Head = Head->getAtras();
        delete temp;
    }
}

void Cola::enqueue(Persona* nuevo)
{
    Nodo* nuevoNodo = new Nodo(nuevo);
    if (Peek == nullptr) {
        Head = Peek = nuevoNodo;
    }
    else {
        Peek->setAtras(nuevoNodo);
        Peek = nuevoNodo;
    }
}

void Cola::dequeue()
{
    if (estaVacia()) {
        std::cout << "La cola esta vacia" << std::endl;
        return;
    }
    Nodo* temp = Head;
    Head = Head->getAtras();
    if (Head == nullptr) {
        Peek = nullptr;
    }
    delete temp;
}

Persona* Cola::peek()
{
    if (estaVacia()) {
        std::cout << "La cola esta vacia" << std::endl;
        return nullptr;
    }
    return Peek->getElemento(); // Retornar el ultimo elemento de la cola.
}

bool Cola::estaVacia()
{
    return Head == nullptr;
}

Persona* Cola::head()
{
    if (estaVacia()) {
        std::cout << "La cola esta vacia" << std::endl;
        return nullptr;
    }
    return Head->getElemento();
}
