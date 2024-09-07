#include "ListaDoble.h"
#include "Persona.h"

int main() {
    // Crear una lista doblemente enlazada
    ListaDoble* lista = new ListaDoble();

    // Crear algunas personas
    Persona* p1 = new Persona("Alice", 30, "123 Calle A");
    Persona* p2 = new Persona("Bob", 25, "456 Calle B");
    Persona* p3 = new Persona("Charlie", 35, "789 Calle C");

    // Insertar personas en la lista
    lista->insertarInicio(p1);
    lista->insertarFinal(p2);
    lista->insertarFinal(p3);

    // Mostrar lista
    std::cout << "Lista de personas:" << std::endl;
    lista->mostrarLista();

    // Eliminar una persona
    std::cout << "Eliminando a Bob..." << std::endl;
    lista->eliminar(p2);

    // Mostrar lista después de la eliminación
    std::cout << "Lista de personas después de eliminar a Bob:" << std::endl;
    lista->mostrarLista();

    // Verificar si la lista está vacía
    if (lista->estaVacia()) {
        std::cout << "La lista está vacía." << std::endl;
    }
    else {
        std::cout << "La lista NO está vacía." << std::endl;
    }

    // Liberar la memoria utilizada
    delete lista;

    return 0;
}
