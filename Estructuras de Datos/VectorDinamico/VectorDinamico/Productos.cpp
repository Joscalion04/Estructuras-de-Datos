#include "Productos.h"
Productos::Productos(int can)
{
    vec = new Producto * [can];
    tam = can;
    cant = 0;

    for (int i = 0; i < tam; i++) {
        vec[i] = nullptr; // Inicializa el vector con punteros a nullptr
    }
}

Productos::~Productos()
{
    for (int i = 0; i < cant; i++) {
        delete vec[i]; // Borra los objetos dinámicos
    }
    delete[] vec; // Borra el vector
}

void Productos::setCant(int can)
{
    cant = can;
}

void Productos::setTam(int tama)
{
    tam = tama;
}

bool Productos::ingresar(Producto* produc)
{
    if (cant < tam) {
        vec[cant++] = produc; // Agrega el producto y luego incrementa cant
        return true;
    }
    return false;
}

string Productos::toString()
{
    stringstream s;
    s << "----Lista de Productos----" << endl;
    for (int i = 0; i < cant; i++) {
        s << "Producto " << i + 1 << endl;
        s << vec[i]->toString() << endl; // Llama a toString de Producto
        s << "---------------------------" << endl;
    }
    s << "---------Fin de Lista---------" << endl;
    return s.str();
}

bool Productos::existeProducto(const string& cod)
{
    for (int i = 0; i < cant; i++) {
        if (vec[i]->getCode() == cod) {
            return true;
        }
    }
    return false;
}

string Productos::mostrarProductoCod(const string& cod)
{
    if (existeProducto(cod)) {
        for (int i = 0; i < cant; i++) {
            if (vec[i]->getCode() == cod) {
                return vec[i]->toString();
            }
        }
    }
    else {
        return "No hay productos registrados con el código proporcionado.";
    }
}

string Productos::prodExistMin()
{
    stringstream s;
    for (int i = 0; i < cant; i++) {
        if (vec[i]->getExis() < 10) {
            s << vec[i]->toString() << endl;
        }
    }
    return s.str();
}

bool Productos::buscarProducto(const string& cod)
{
    return existeProducto(cod);
}

Producto* Productos::retornaProducto(const string& cod)
{
    for (int i = 0; i < cant; i++) {
        if (vec[i]->getCode() == cod) {
            return vec[i];
        }
    }
    return nullptr;
}

int Productos::posDelProduc(const string& cod)
{
    for (int i = 0; i < cant; i++) {
        if (vec[i]->getCode() == cod) {
            return i;
        }
    }
    return -1;
}

void Productos::EliminarProducto(const string& cod)
{
    int posEliminar = posDelProduc(cod); // Obtiene la posición del producto
    if (posEliminar != -1) {
        delete vec[posEliminar]; // Borra el producto en esa posición
        for (int i = posEliminar; i < cant - 1; i++) {
            vec[i] = vec[i + 1]; // Desplaza los elementos hacia la izquierda
        }
        cant--; // Reduce la cantidad de productos
    }
}
