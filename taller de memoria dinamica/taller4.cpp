#include <iostream>
using namespace std;

int main() {

    int capacidad = 2;     // tamaño inicial
    int cantidad = 0;      // cuántos elementos reales hay
    int copias = 0;       // contar cuántas veces redimensionamos

    int* arreglo = new int[capacidad];

    int num;

    while (true) {
        cout << "Ingrese un numero (-1 para terminar): ";
        cin >> num;

        if (num == -1) {
            break;
        }

        // si se llena el arreglo
        if (cantidad == capacidad) {

            int nuevaCapacidad = capacidad * 2;

            // crear arreglo nuevo
            int* nuevo = new int[nuevaCapacidad];

            // copiar elementos
            for (int i = 0; i < cantidad; i++) {
                nuevo[i] = arreglo[i];
            }

            // borrar el viejo
            delete[] arreglo;

            // apuntar al nuevo
            arreglo = nuevo;
            capacidad = nuevaCapacidad;
            copias++;
        }

        arreglo[cantidad] = num;
        cantidad++;
    }

    // imprimir elementos
    cout << "\nNumeros guardados:\n";
    for (int i = 0; i < cantidad; i++) {
        cout << arreglo[i] << " ";
    }

    cout << "\n\nEl arreglo se copio " << copias << " veces.\n";

    delete[] arreglo;

    return 0;
}
