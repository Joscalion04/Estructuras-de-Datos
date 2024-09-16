#include "Pila.h"
#include "Persona.h"

int main() {
    // Crear una pila como puntero
    /*
        stack<Persona*> pila = new stack<Persona*>;
    */
    Pila* pila = new Pila();

    // Crear algunas personas
    Persona* p1 = new Persona("Alice", 30, "123 Calle A");
    Persona* p2 = new Persona("Bob", 25, "456 Calle B");
    Persona* p3 = new Persona("Charlie", 35, "789 Calle C");

    // Apilar personas
    pila->push(p1);
    pila->push(p2);
    pila->push(p3);

    // Mostrar la persona en la cima de la pila
    cout << "Persona en la cima de la pila: " << endl;
    cout << pila->top()->toString() << endl;

    // Desapilar una persona
    cout << "Desapilando una persona..." << endl;
    pila->pop();

    // Mostrar la nueva persona en la cima de la pila
    cout << "Nueva persona en la cima de la pila: " << endl;
    cout << pila->top()->toString() << endl;

    // Verificar si la pila está vacía
    if (pila->estaVacia()) {
        cout << "La pila está vacía." << endl;
    }
    else {
        cout << "La pila NO está vacía." << endl;
    }

    // Liberar la memoria utilizada
    delete pila;

    return 0;
}
