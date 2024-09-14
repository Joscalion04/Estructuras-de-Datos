#include "Arbol.h"

Nodo* Arbol::insertar(Nodo* nodo, Persona* valor)
{
    if (nodo == nullptr) {
        return new Nodo(valor);
    }

    if (valor->getEdad() < nodo->elemento->getEdad()) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    }
    else if (valor->getEdad() > nodo->elemento->getEdad()) {
        nodo->derecha = insertar(nodo->derecha, valor);
    }
    // Si valor->getEdad() == nodo->valor->getEdad(), no se realiza ninguna acción (suponiendo que no se permite duplicados)
    return nodo;
}

bool Arbol::buscar(Nodo* nodo, Persona* valor) const
{
    if (nodo == nullptr) {
        return false;
    }

    if (valor->getEdad() == nodo->elemento->getEdad()) {
        return true;
    }
    else if (valor->getEdad() < nodo->elemento->getEdad()) {
        return buscar(nodo->izquierda, valor);
    }
    else {
        return buscar(nodo->derecha, valor);
    }
}

Nodo* Arbol::eliminar(Nodo* nodo, Persona* valor)
{
    if (nodo == nullptr) return nodo;

    if (valor->getEdad() < nodo->elemento->getEdad()) {
        nodo->izquierda = eliminar(nodo->izquierda, valor);
    }
    else if (valor->getEdad() > nodo->elemento->getEdad()) {
        nodo->derecha = eliminar(nodo->derecha, valor);
    }
    else {
        if (nodo->izquierda == nullptr) {
            Nodo* temp = nodo->derecha;
            delete nodo;
            return temp;
        }
        else if (nodo->derecha == nullptr) {
            Nodo* temp = nodo->izquierda;
            delete nodo;
            return temp;
        }

        Nodo* temp = minValorNodo(nodo->derecha);
        *(nodo->elemento) = *(temp->elemento);  // Copiar el contenido del nodo mínimo
        nodo->derecha = eliminar(nodo->derecha, temp->elemento);
    }
    return nodo;
}

Nodo* Arbol::minValorNodo(Nodo* nodo)
{
    Nodo* actual = nodo;
    while (actual && actual->izquierda != nullptr)
        actual = actual->izquierda;
    return actual;
}

void Arbol::toString(Nodo* nodo, std::string& resultado) const
{
    if (nodo == nullptr) return;
    toString(nodo->izquierda, resultado);
    resultado += nodo->elemento->toString();  
    toString(nodo->derecha, resultado);
}

void Arbol::insertar(Persona* valor)
{
    raiz = insertar(raiz, valor);
}

bool Arbol::buscar(Persona* valor) const
{
    return buscar(raiz, valor);
}

void Arbol::eliminar(Persona* valor)
{
    raiz = eliminar(raiz, valor);
}

std::string Arbol::toString() const
{
    std::string resultado;
    toString(raiz, resultado);
    return resultado;
}
