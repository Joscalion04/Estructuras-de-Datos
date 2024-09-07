#include <iostream>
#include"Persona.h"
using namespace std;

int main() {


	int* a = new int(10); // Crea un entero en el heap que tiene de valor a
	cout << "Direccion de Memoria de 'a' en el Heap\n";
	cout << a  << endl; // Direccion del Heap -> Es decir el 'new'

	cout << "\nDireccion de Memoria de 'a' en el Stack\n ";
	cout << &a << endl; // Direccion del Stack del valor de a

	cout << "\nValor de 'a'\n";
	cout << *a << endl; // Valor del entero = 10

    // Crear un objeto Persona en el heap
    Persona* personaHeap = new Persona("Jose", 30, "123 Calle Principal");
    Persona* personaAux2;
    Persona* personaAux3 = new Persona("Cesar", 19, "Puriscal");

   

    // Crear un objeto Persona en el stack
    Persona personaStack("Ana", 25, "456 Calle Secundaria");

    // Imprimir la dirección de memoria del objeto en el heap
    cout << "Direccion de Memoria del objeto 'personaHeap' en el Heap\n";
    cout << personaHeap << endl; // Direccion del Heap -> Es decir el 'new'

    // Imprimir la dirección de memoria del puntero en el stack
    cout << "\nDireccion de Memoria del puntero 'personaHeap' en el Stack\n";
    cout << &personaHeap << endl; // Direccion del Stack del puntero a 'personaHeap'

    // Imprimir el contenido del objeto en el heap
    cout << "\nContenido del objeto 'personaHeap'\n";
    cout << personaHeap->toString() << endl;

    // Imprimir la dirección de memoria del objeto en el stack
    cout << "\nDireccion de Memoria del objeto 'personaStack' en el Stack\n";
    cout << &personaStack << endl; // Direccion del Stack del objeto 'personaStack'

    // Imprimir el contenido del objeto en el stack
    cout << "\nContenido del objeto 'personaStack'\n";
    cout << personaStack.toString() << endl;

    // Liberar la memoria del objeto en el heap
    delete personaHeap;


	return 0;
}