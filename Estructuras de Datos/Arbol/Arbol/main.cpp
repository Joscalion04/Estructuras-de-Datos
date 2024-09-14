#include <iostream>
#include "Arbol.h"
#include "Persona.h"

using namespace std;

int main() {
    // Crear instancias de Persona
    Persona* p1 = new Persona("Juan", 25, "Calle A");
    Persona* p2 = new Persona("Ana", 30, "Calle B");
    Persona* p3 = new Persona("Luis", 20, "Calle C");
    Persona* p4 = new Persona("Maria", 28, "Calle D");
    Persona* p5 = new Persona("Carlos", 35, "Calle E");

    // Crear un �rbol binario de b�squeda
    Arbol arbol;

    // Insertar personas en el �rbol
    arbol.insertar(p1);
    arbol.insertar(p2);
    arbol.insertar(p3);
    arbol.insertar(p4);
    arbol.insertar(p5);

    // Mostrar el contenido del �rbol en orden
    cout << "Contenido del �rbol en orden:" << endl;
    cout << arbol.toString() << endl;

    // Buscar personas en el �rbol
    cout << "Buscar persona con edad 25: "
        << (arbol.buscar(p1) ? "Encontrado" : "No encontrado")
        << endl;

    cout << "Buscar persona con edad 40: "
        << (arbol.buscar(new Persona("", 40, "")) ? "Encontrado" : "No encontrado")
        << endl;

    // Eliminar una persona del �rbol
    arbol.eliminar(p3);
    cout << "Contenido del �rbol despu�s de eliminar a la persona con edad 20:" << endl;
    cout << arbol.toString() << endl;

    // Limpiar memoria
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    return 0;
}
