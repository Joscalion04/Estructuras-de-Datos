#include "Pila.h"
/*
    stack<Persona*> pila = new stack<Persona*>;
*/
Pila::Pila()
{
    Top = nullptr;
}

Pila::~Pila() 
{
    while (!estaVacia()) {
        Nodo* temp = Top; // GUARDO LA DIRECCION A ELIMINAR
        Top = Top->getAbajo();  // CAMBIO LA DIRECCION DEL DE ARRIBA
        delete temp; // BORRO LA DIRECCION 
    }
}

void Pila::push(Persona* persona) //INMEDIATAMENTE O(1) PARA EL MEJOR DE LOS CASOS
{
    Nodo* nuevoNodo = new Nodo(persona);
    nuevoNodo->setAbajo(Top); //nuevoNodo->setAbajo(Top)
    Top = nuevoNodo; // TOP PASA A SER EL NUEVO NODO A INSERTAR
}

void Pila::pop() //INMEDIATAMENTE O(1) PARA EL MEJOR DE LOS CASOS
{
    if (estaVacia()) {
        std::cout << "La pila está vacía" << std::endl;
        return;
    }
    Nodo* temp = Top; // GUARDA LA DIRECCION DEL TOP (LA CUAL VA A BORRAR)
    Top = Top->getAbajo(); // REASIGNA EL TOP AL QUE ESTA ABAJO DEL TOP
    delete temp; // BORRA LA DIRECCION DE TOP ANTIGUO (EL QUE SE GUARDO)
}

Persona* Pila::top() // O(1) 
{
    if (estaVacia()) {
        std::cout << "La pila está vacía" << std::endl;
        return nullptr;
    }
    return Top->getElemento();
}

bool Pila::estaVacia()
{
    return Top == nullptr;
}
