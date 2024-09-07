#include <iostream>

// Ejemplo 1: Factorial de un número (Recursión simple)
int factorial(int n) {
    if (n == 0) {  // Caso base
        return 1;
    }
    return n * factorial(n - 1);  // Llamada recursiva
}

// Ejemplo 2: Secuencia de Fibonacci (Recursión intermedia)
int fibonacci(int n) {
    if (n == 0) {  // Caso base 1
        return 0;
    }
    if (n == 1) {  // Caso base 2
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // Llamadas recursivas
}

int main() {
    // Ejemplo 1: Factorial
    int numFactorial = 5;
    std::cout << "Factorial de " << numFactorial << " es: " << factorial(numFactorial) << std::endl;

    // Ejemplo 2: Fibonacci
    int numFibonacci = 10;
    std::cout << "\nFibonacci de " << numFibonacci << " es: " << fibonacci(numFibonacci) << std::endl;

    return 0;
}
