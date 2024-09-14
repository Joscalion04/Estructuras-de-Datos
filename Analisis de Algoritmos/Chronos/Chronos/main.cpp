#include <iostream>
#include <vector>
#include <algorithm> // Para std::swap
#include <chrono>    // Para medir el tiempo

// Implementación de Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Si no hubo intercambios en la pasada, el arreglo está ordenado
        if (!swapped)
            break;
    }
}

int main() {
    // Crear un vector con números aleatorios
    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };

    // Mostrar el arreglo original
    std::cout << "Arreglo original: ";
    for (const auto& num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    // Iniciar el cronómetro
    auto start = std::chrono::high_resolution_clock::now();
    // Ejecutar Bubble Sort
    bubbleSort(arr);
    // Detener el cronómetro
    auto end = std::chrono::high_resolution_clock::now();
    // Calcular la duración en nanosegundos
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    // Mostrar el arreglo ordenado
    std::cout << "Arreglo ordenado: ";
    for (const auto& num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    // Mostrar el tiempo tomado por Bubble Sort en nanosegundos
    std::cout << "Tiempo tomado por Bubble Sort: " << duration.count() << " nanosegundos." << std::endl;

    return 0;
}
