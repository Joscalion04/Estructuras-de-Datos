#include<iostream>
#include "Cola.h"

int main() {
    // Crear una cola como puntero
    Cola* cola = new Cola();

    // Crear algunas personas
    Persona* p1 = new Persona("Alice", 30, "123 Calle A");
    Persona* p2 = new Persona("Bob", 25, "456 Calle B");
    Persona* p3 = new Persona("Charlie", 35, "789 Calle C");

    // Agregar personas a la cola
    cola->enqueue(p1);
    cola->enqueue(p2);
    cola->enqueue(p3);

    // Mostrar el elemento en la cabeza de la cola
    cout << "Primera persona en la cola (head): " << endl;
    cout << cola->head()->toString() << endl;

    // Desencolar un elemento
    cout << "Desencolando una persona..." << endl;
    cola->dequeue();

    // Mostrar el nuevo elemento en la cabeza de la cola
    cout << "Nueva primera persona en la cola (head): " << endl;
    cout << cola->head()->toString() << endl;

    // Mostrar el último elemento en la cola (Peek)
    cout << "Última persona en la cola (peek): " << endl;
    cout << cola->peek()->toString() << endl;

    // Verificar si la cola está vacía
    if (cola->estaVacia()) {
        cout << "La cola está vacía." << endl;
    }
    else {
        cout << "La cola NO está vacía." << endl;
    }

    // Liberar la memoria utilizada
    delete cola;
	return 0;
}