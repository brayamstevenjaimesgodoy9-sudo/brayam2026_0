#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    vector<int> arreglo(n); // crea el vector con tamaño n

    // llenar el vector
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    // mostrar el vector
    cout << "\nValores:\n";
    int suma = 0;

    for (int i = 0; i < arreglo.size(); i++) {
        cout << arreglo[i] << " ";
        suma += arreglo[i];
    }

    double promedio = (double)suma / n;
    cout << "\nPromedio: " << promedio << endl;

    return 0;
}
