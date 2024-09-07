#include<iostream>
#include<iomanip> // Para usar setw y mejorar la est�tica de la consola

using namespace std;

// Funci�n para imprimir el arreglo
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

// Ordenamiento por Selecci�n
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Encontramos el �ndice del menor elemento en el arreglo no ordenado
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Intercambiamos el menor elemento encontrado con el primer elemento
        std::swap(arr[min_idx], arr[i]);
    }
}

// Ordenamiento por Inserci�n
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Movemos los elementos del arreglo que son mayores que el "key" una posici�n adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insertamos el "key" en la posici�n correcta
        arr[j + 1] = key;
    }
}

// Ordenamiento R�pido (Quick Sort)
void quickSort(int arr[], int low, int high) {
    if (low >= high) return; // Condici�n de salida para evitar recursi�n infinita

    int i = low; int j = high; int pivote = arr[(low + high) / 2]; // Corregir el c�lculo del pivote

    do {
        // Mover el �ndice 'i' hacia la derecha hasta que encontremos un elemento mayor o igual al pivote
        while (arr[i] < pivote) {
            i++;
        }
        // Mover el �ndice 'j' hacia la izquierda hasta que encontremos un elemento menor o igual al pivote
        while (arr[j] > pivote) {
            j--;
        }
        // Si los �ndices no se cruzan, intercambiamos los elementos
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j); // Continuar mientras los �ndices no se crucen

    // Recursi�n para las dos sublistas
    if (low < j)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}



// Funci�n auxiliar para mezclar dos subarreglos en Merge Sort
void merge(int arreglo[], int inicio, int medio, int fin) {
    // Tama�os de los subarreglos a fusionar
    int tamIzq = medio - inicio + 1; // Tama�o del subarreglo izquierdo
    int tamDer = fin - medio;        // Tama�o del subarreglo derecho

    // Creaci�n de arreglos temporales para izquierda y derecha
    int* izq = new int[tamIzq];      // Subarreglo izquierdo
    int* der = new int[tamDer];      // Subarreglo derecho

    // Copiamos los datos del arreglo original a los subarreglos temporales
    for (int i = 0; i < tamIzq; i++)
        izq[i] = arreglo[inicio + i]; // Copiamos el lado izquierdo
    for (int j = 0; j < tamDer; j++)
        der[j] = arreglo[medio + 1 + j]; // Copiamos el lado derecho

    // Inicializamos los �ndices de los subarreglos y el �ndice del arreglo original
    int i = 0, j = 0, k = inicio;

    // Comparamos y mezclamos los elementos de los subarreglos izq[] y der[]
    while (i < tamIzq && j < tamDer) {
        if (izq[i] <= der[j]) {
            arreglo[k] = izq[i];  // Si el elemento de la izquierda es menor o igual, lo colocamos en el arreglo
            i++;                  // Avanzamos el �ndice del subarreglo izquierdo
        }
        else {
            arreglo[k] = der[j];  // Si el elemento de la derecha es menor, lo colocamos en el arreglo
            j++;                  // Avanzamos el �ndice del subarreglo derecho
        }
        k++;  // Avanzamos el �ndice del arreglo original
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

    // Liberamos la memoria din�mica utilizada por los arreglos temporales
    delete[] izq;
    delete[] der;
}

// Funci�n recursiva de Ordenamiento por Mezcla (Merge Sort)
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



 // Funci�n auxiliar para el algoritmo Counting Sort utilizado por Radix Sort
 void countingSort(int arreglo[], int tamano, int exp) {
     int* salida = new int[tamano];  // Arreglo temporal para almacenar los resultados
     int conteo[10] = { 0 };         // Arreglo para almacenar la cuenta de cada d�gito (0-9)

     // Contamos la ocurrencia de cada d�gito basado en la posici�n actual (exp)
     for (int i = 0; i < tamano; i++) {
         int digito = (arreglo[i] / exp) % 10;  // Extraemos el d�gito actual
         conteo[digito]++;  // Incrementamos el conteo para ese d�gito
     }

     // Ajustamos conteo para que ahora contenga las posiciones de los d�gitos en el arreglo de salida
     for (int i = 1; i < 10; i++) {
         conteo[i] += conteo[i - 1];  // Actualizamos las posiciones acumuladas
     }

     // Construimos el arreglo de salida
     for (int i = tamano - 1; i >= 0; i--) {
         int digito = (arreglo[i] / exp) % 10;  // Extraemos el d�gito actual
         salida[conteo[digito] - 1] = arreglo[i];  // Colocamos el n�mero en su posici�n correspondiente
         conteo[digito]--;  // Reducimos la cuenta de ese d�gito
     }

     // Copiamos los elementos del arreglo de salida de vuelta al arreglo original
     for (int i = 0; i < tamano; i++) {
         arreglo[i] = salida[i];
     }

     delete[] salida;  // Liberamos la memoria din�mica
 }

 // Funci�n auxiliar para obtener el valor m�ximo en el arreglo
 int getMax(int arreglo[], int tamano) {
     int maximo = arreglo[0];  // Asumimos que el primer elemento es el m�ximo
     for (int i = 1; i < tamano; i++) {
         if (arreglo[i] > maximo) {
             maximo = arreglo[i];  // Actualizamos el m�ximo si encontramos uno mayor
         }
     }
     return maximo;  // Devolvemos el valor m�ximo
 }

 // Funci�n principal del algoritmo Radix Sort
 void radixSort(int arreglo[], int tamano) {
     // Obtenemos el n�mero m�ximo para saber cu�ntos d�gitos tiene
     int maximo = getMax(arreglo, tamano);

     // Aplicamos el algoritmo de ordenamiento por conteo (Counting Sort) para cada d�gito
     // exp es 10^i, donde i es el d�gito actual (1 para unidades, 10 para decenas, 100 para centenas, etc.)
     for (int exp = 1; maximo / exp > 0; exp *= 10) {
         countingSort(arreglo, tamano, exp);  // Ordenamos por cada d�gito
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

    // Prueba del ordenamiento Selecci�n
    int arr2[] = { 7,2,1,6,4,5,3,8 };
    selectionSort(arr2, n);
    cout << "\nArreglo Ordenado con Selecci�n: " << endl;
    printArray(arr2, n);


    // Prueba del ordenamiento Inserci�n
    int arr3[] = { 7,2,1,6,4,5,3,8 };
    insertionSort(arr3, n);
    cout << "\nArreglo Ordenado con Inserci�n: " << endl;
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
