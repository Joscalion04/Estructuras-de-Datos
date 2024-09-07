#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Funci�n de b�squeda lineal
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;  // Element found
        }
    }
    return -1;  // Element not found
}

// Funci�n de b�squeda binaria
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid; // Element found
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Element not found
}

// Funci�n de ordenamiento por burbuja
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Si no hubo intercambios, el arreglo est� ordenado
        if (!swapped)
            break;
    }
}

int main() {
    // Ejemplo de b�squeda lineal
    std::vector<int> arr1 = { 10, 23, 45, 70, 11, 15 };
    int target = 70;

    auto start = std::chrono::high_resolution_clock::now();
    int result = linearSearch(arr1, target);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "B�squeda Lineal:" << std::endl;
    if (result != -1)
        std::cout << "Elemento encontrado en el �ndice " << result << std::endl;
    else
        std::cout << "Elemento no encontrado" << std::endl;
    std::cout << "Tiempo de ejecuci�n: " << duration.count() << " ms\n" << std::endl;

    // Ejemplo de b�squeda binaria
    std::vector<int> arr2 = { 10, 15, 23, 45, 70, 100 };

    start = std::chrono::high_resolution_clock::now();
    result = binarySearch(arr2, target);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    std::cout << "B�squeda Binaria:" << std::endl;
    if (result != -1)
        std::cout << "Elemento encontrado en el �ndice " << result << std::endl;
    else
        std::cout << "Elemento no encontrado" << std::endl;
    std::cout << "Tiempo de ejecuci�n: " << duration.count() << " ms\n" << std::endl;

    // Ejemplo de ordenamiento por burbuja
    std::vector<int> arr3 = { 64, 34, 25, 12, 22, 11, 90 };

    start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr3);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    std::cout << "Ordenamiento por Burbuja:" << std::endl;
    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < arr3.size(); ++i)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;
    std::cout << "Tiempo de ejecuci�n: " << duration.count() << " ms\n" << std::endl;

    return 0;
}
