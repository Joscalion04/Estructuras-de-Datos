#include<iostream>
#include<iomanip> // Para usar setw y mejorar la estética de la consola

using namespace std;

// Función para imprimir el arreglo
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(3) << arr[i] << " ";
    }
    cout << endl;
}

// Ordenamiento de Burbuja
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Si el elemento actual es mayor que el siguiente, los intercambiamos
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Ordenamiento por Selección
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Encontramos el índice del menor elemento en el arreglo no ordenado
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Intercambiamos el menor elemento encontrado con el primer elemento
        std::swap(arr[min_idx], arr[i]);
    }
}

// Ordenamiento por Inserción
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Movemos los elementos del arreglo que son mayores que el "key" una posición adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insertamos el "key" en la posición correcta
        arr[j + 1] = key;
    }
}

// Ordenamiento Rápido (Quick Sort)
void quickSort(int arr[], int low, int high) {
    if (low >= high) return; // Condición de salida para evitar recursión infinita

    int i = low; int j = high; int pivote = arr[(low + high) / 2]; // Corregir el cálculo del pivote

    do {
        // Mover el índice 'i' hacia la derecha hasta que encontremos un elemento mayor o igual al pivote
        while (arr[i] < pivote) {
            i++;
        }
        // Mover el índice 'j' hacia la izquierda hasta que encontremos un elemento menor o igual al pivote
        while (arr[j] > pivote) {
            j--;
        }
        // Si los índices no se cruzan, intercambiamos los elementos
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j); // Continuar mientras los índices no se crucen

    // Recursión para las dos sublistas
    if (low < j)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}



// Función auxiliar para mezclar dos subarreglos en Merge Sort
void merge(int arreglo[], int inicio, int medio, int fin) {
    // Tamaños de los subarreglos a fusionar
    int tamIzq = medio - inicio + 1; // Tamaño del subarreglo izquierdo
    int tamDer = fin - medio;        // Tamaño del subarreglo derecho

    // Creación de arreglos temporales para izquierda y derecha
    int* izq = new int[tamIzq];      // Subarreglo izquierdo
    int* der = new int[tamDer];      // Subarreglo derecho

    // Copiamos los datos del arreglo original a los subarreglos temporales
    for (int i = 0; i < tamIzq; i++)
        izq[i] = arreglo[inicio + i]; // Copiamos el lado izquierdo
    for (int j = 0; j < tamDer; j++)
        der[j] = arreglo[medio + 1 + j]; // Copiamos el lado derecho

    // Inicializamos los índices de los subarreglos y el índice del arreglo original
    int i = 0, j = 0, k = inicio;

    // Comparamos y mezclamos los elementos de los subarreglos izq[] y der[]
    while (i < tamIzq && j < tamDer) {
        if (izq[i] <= der[j]) {
            arreglo[k] = izq[i];  // Si el elemento de la izquierda es menor o igual, lo colocamos en el arreglo
            i++;                  // Avanzamos el índice del subarreglo izquierdo
        }
        else {
            arreglo[k] = der[j];  // Si el elemento de la derecha es menor, lo colocamos en el arreglo
            j++;                  // Avanzamos el índice del subarreglo derecho
        }
        k++;  // Avanzamos el índice del arreglo original
    }

    // Copiamos los elementos restantes de izq[], si es que quedan
    while (i < tamIzq) {
        arreglo[k] = izq[i];  // Colocamos el resto del subarreglo izquierdo en el arreglo
        i++;
        k++;
    }

    // Copiamos los elementos restantes de der[], si es que quedan
    while (j < tamDer) {
        arreglo[k] = der[j];  // Colocamos el resto del subarreglo derecho en el arreglo
        j++;
        k++;
    }

    // Liberamos la memoria dinámica utilizada por los arreglos temporales
    delete[] izq;
    delete[] der;
}

// Función recursiva de Ordenamiento por Mezcla (Merge Sort)
void mergeSort(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        // Encontramos el punto medio del arreglo
        int medio = inicio + (fin - inicio) / 2;

        // Ordenamos la primera mitad de manera recursiva
        mergeSort(arreglo, inicio, medio);

        // Ordenamos la segunda mitad de manera recursiva
        mergeSort(arreglo, medio + 1, fin);

        // Mezclamos las dos mitades ordenadas
        merge(arreglo, inicio, medio, fin);
    }
}



 // Función auxiliar para el algoritmo Counting Sort utilizado por Radix Sort
 void countingSort(int arreglo[], int tamano, int exp) {
     int* salida = new int[tamano];  // Arreglo temporal para almacenar los resultados
     int conteo[10] = { 0 };         // Arreglo para almacenar la cuenta de cada dígito (0-9)

     // Contamos la ocurrencia de cada dígito basado en la posición actual (exp)
     for (int i = 0; i < tamano; i++) {
         int digito = (arreglo[i] / exp) % 10;  // Extraemos el dígito actual
         conteo[digito]++;  // Incrementamos el conteo para ese dígito
     }

     // Ajustamos conteo para que ahora contenga las posiciones de los dígitos en el arreglo de salida
     for (int i = 1; i < 10; i++) {
         conteo[i] += conteo[i - 1];  // Actualizamos las posiciones acumuladas
     }

     // Construimos el arreglo de salida
     for (int i = tamano - 1; i >= 0; i--) {
         int digito = (arreglo[i] / exp) % 10;  // Extraemos el dígito actual
         salida[conteo[digito] - 1] = arreglo[i];  // Colocamos el número en su posición correspondiente
         conteo[digito]--;  // Reducimos la cuenta de ese dígito
     }

     // Copiamos los elementos del arreglo de salida de vuelta al arreglo original
     for (int i = 0; i < tamano; i++) {
         arreglo[i] = salida[i];
     }

     delete[] salida;  // Liberamos la memoria dinámica
 }

 // Función auxiliar para obtener el valor máximo en el arreglo
 int getMax(int arreglo[], int tamano) {
     int maximo = arreglo[0];  // Asumimos que el primer elemento es el máximo
     for (int i = 1; i < tamano; i++) {
         if (arreglo[i] > maximo) {
             maximo = arreglo[i];  // Actualizamos el máximo si encontramos uno mayor
         }
     }
     return maximo;  // Devolvemos el valor máximo
 }

 // Función principal del algoritmo Radix Sort
 void radixSort(int arreglo[], int tamano) {
     // Obtenemos el número máximo para saber cuántos dígitos tiene
     int maximo = getMax(arreglo, tamano);

     // Aplicamos el algoritmo de ordenamiento por conteo (Counting Sort) para cada dígito
     // exp es 10^i, donde i es el dígito actual (1 para unidades, 10 para decenas, 100 para centenas, etc.)
     for (int exp = 1; maximo / exp > 0; exp *= 10) {
         countingSort(arreglo, tamano, exp);  // Ordenamos por cada dígito
     }
 }

int main() {
    int arr[] = { 7,2,1,6,4,5,3,8 };
    int n = sizeof(arr) / sizeof(arr[0]);  // Longitud del arreglo

    cout << "Arreglo Original: " << endl;
    printArray(arr, n);

    // Prueba del ordenamiento Burbuja
    bubbleSort(arr, n);
    cout << "\nArreglo Ordenado con Burbuja: " << endl;
    printArray(arr, n);

    // Prueba del ordenamiento Selección
    int arr2[] = { 7,2,1,6,4,5,3,8 };
    selectionSort(arr2, n);
    cout << "\nArreglo Ordenado con Selección: " << endl;
    printArray(arr2, n);


    // Prueba del ordenamiento Inserción
    int arr3[] = { 7,2,1,6,4,5,3,8 };
    insertionSort(arr3, n);
    cout << "\nArreglo Ordenado con Inserción: " << endl;
    printArray(arr3, n);

    //Prueba ordenamiento rapido
    int arr6[] = { 7,2,1,6,4,5,3,8 };
    quickSort(arr6, 0,n-1);
    cout << "\nArreglo Ordenado con QuickSort: " << endl;
    printArray(arr6, n);

    //Prueba ordenamiento Merge
    int arr5[] = { 7,2,1,6,4,5,3,8 };
    mergeSort(arr5, 0, n - 1);
    cout << "\nArreglo Ordenado con Merge: " << endl;
    printArray(arr5, n);

    //Prueba ordenamiento Radix
    int arr7[] = { 7,2,1,6,4,5,3,8 };
    radixSort(arr7, n);
    cout << "\nArreglo Ordenado con RadixSort: " << endl;
    printArray(arr7, n);

    return 0;
}
