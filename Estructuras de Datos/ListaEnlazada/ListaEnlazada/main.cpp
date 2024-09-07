#include <iostream>
#include"Lista.h"
using namespace std;

int main() {

    Lista lista;
    lista.insertar(new Persona("Joseph", 20, "Coronado"));
    lista.insertar(new Persona("Amaya", 23, "Moravia"));
    lista.insertar(new Persona("Johan", 22, "Coronado"));
    lista.insertar(new Persona("Osvaldo", 19, "Heredia"));
    lista.insertar(new Persona("Maria", 19, "Aserri"));

    cout << "\nLista completa:\n" << lista.toString();

    cout << "\nBuscando a Bob:\n" << lista.toStringPersona("Bob") << endl;
    cout << "\nBuscando a Joseph:\n" << lista.toStringPersona("Joseph") << endl;

    lista.eliminarPersonaNombre("Johan");
    cout << "\nLista despu�s de eliminar a Johan:\n" << lista.toString();

    return 0;
}