#include <iostream>
using namespace std;

// Función que crea el arreglo
int* crearArreglo(int n) {
    int* arreglo = new int[n]; // reservar memoria

    // llenar con números pares
    for (int i = 0; i < n; i++) {
        arreglo[i] = (i + 1) * 2; // 2,4,6,8...
    }

    return arreglo; // devolver el puntero
}

int main() {
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    int* arreglo = crearArreglo(n); // llamar función

    // imprimir elementos
    cout << "Arreglo de numeros pares:\n";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }

    // liberar memoria
    delete[] arreglo;

    return 0;
}
