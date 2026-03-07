#include <iostream>
using namespace std;

int main() {
    int n;

    // 1) Pedir tamaño
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    // 2) Crear arreglo dinámico
    int* arreglo = new int[n];

    // 3) Llenar el arreglo
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    // 4) Mostrar el arreglo
    cout << "\nValores del arreglo:\n";
    int suma = 0;

    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
        suma += arreglo[i]; // para el promedio
    }

    // Reto extra: promedio
    double promedio = (double)suma / n;
    cout << "\nPromedio: " << promedio << endl;

    // 5) Liberar memoria
    delete[] arreglo;

    return 0;
}