//Menú interactivo
#include <iostream>
using namespace std;

int main() {
    int opcion;

    do {
        cout << "\nMENU\n";
        cout << "1. Opcion 1\n";
        cout << "2. Opcion 2\n";
        cout << "3. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

    } while (opcion != 3);

    cout << "Programa finalizado.\n";
    return 0;
}
