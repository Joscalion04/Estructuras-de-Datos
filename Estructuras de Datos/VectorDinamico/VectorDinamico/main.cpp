#include "Productos.h"
using namespace std;

int main() {
    // Variables de Paso
    string nom, codig;
    int op, exis;
    float pB;

    // Objeto Dinamico de Paso
    Producto* producto = nullptr;

    // Creación de la Contenedora
    Productos* Contenedora = new Productos(100);

    do {
        cout << "--------- Bienvenido al Supermercado ---------" << endl;
        cout << " " << endl;
        cout << "-------------- Menu de Acciones --------------" << endl;
        cout << "1- Registrar Producto" << endl;
        cout << "2- Eliminar Producto" << endl;
        cout << "3- Mostrar Productos" << endl;
        cout << "4- Mostrar Producto por Código" << endl;
        cout << "5- Verificar Existencia de Producto" << endl;
        cout << "6- Mostrar Productos con Existencias Mínimas" << endl;
        cout << "7- Salir" << endl;
        cout << "Ingrese una opción: "; cin >> op;

        switch (op) {
        case 1: {
            // Registrar un Producto
            cout << "Ingrese los datos del nuevo producto" << endl;
            cout << "Nombre: "; cin >> nom;
            cout << "Código: "; cin >> codig;
            cout << "Precio Base: "; cin >> pB;
            cout << "Existencias: "; cin >> exis;

            // Crear el objeto Producto
            producto = new Producto(nom, codig, pB, exis);

            // Asignamos el Objeto a la Contenedora
            if (Contenedora->ingresar(producto)) {
                cout << "Producto Registrado" << endl;
            }
            else {
                cout << "Producto No Registrado (Espacio insuficiente)" << endl;
            }
            break;
        }

        case 2: {
            // Eliminar un Producto
            cout << "Eliminar Producto" << endl;
            cout << "Ingrese el código del producto: "; cin >> codig;

            if (Contenedora->buscarProducto(codig)) {
                cout << "Producto Existente. Eliminando..." << endl;
                Contenedora->EliminarProducto(codig);
                cout << "Producto Eliminado" << endl;
            }
            else {
                cout << "Producto No Existente" << endl;
            }
            break;
        }

        case 3: {
            // Mostrar todos los Productos
            cout << Contenedora->toString() << endl;
            break;
        }

        case 4: {
            // Mostrar Producto por Código
            cout << "Ingrese el código del producto: "; cin >> codig;
            cout << Contenedora->mostrarProductoCod(codig) << endl;
            break;
        }

        case 5: {
            // Verificar si un Producto Existe
            cout << "Ingrese el código del producto: "; cin >> codig;

            if (Contenedora->existeProducto(codig)) {
                cout << "El Producto Existe" << endl;
            }
            else {
                cout << "El Producto No Existe" << endl;
            }
            break;
        }

        case 6: {
            // Mostrar Productos con Existencias Menores a 10
            cout << Contenedora->prodExistMin() << endl;
            break;
        }

        case 7: {
            cout << " ---- M U C H A S G R A C I A S ----" << endl;
            break;
        }

        default: {
            cout << "Opción no válida. Por favor, ingrese una opción entre 1 y 7." << endl;
        }
        }

    } while (op != 7);

    delete Contenedora; // Liberar memoria
    return 0;
}
