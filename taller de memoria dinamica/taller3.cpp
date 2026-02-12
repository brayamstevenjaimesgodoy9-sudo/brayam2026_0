#include <iostream>
#include <vector>
using namespace std;

int main() {
    int f, c;

    cout << "Ingrese la cantidad de filas: ";
    cin >> f;

    cout << "Ingrese la cantidad de columnas: ";
    cin >> c;

    // crear matriz dinámica
    vector<vector<int>> matriz(f, vector<int>(c));

    // llenar la matriz
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Ingrese el valor [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // imprimir matriz en forma de tabla
    cout << "\nMatriz:\n";
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    // reto extra: suma de cada fila
    cout << "\nSuma de cada fila:\n";
    for (int i = 0; i < f; i++) {
        int suma = 0;
        for (int j = 0; j < c; j++) {
            suma += matriz[i][j];
        }
        cout << "Fila " << i << ": " << suma << endl;
    }

    return 0;
}
