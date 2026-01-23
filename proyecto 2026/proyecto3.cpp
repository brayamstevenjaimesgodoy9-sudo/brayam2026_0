#include <iostream>
#include <string>

using namespace std;

struct Producto {
    string nombre;
    float precio;
    int cantidad;
};

int main() {
    Producto lista[10]; 
    int totalRegistrados = 0; 
    string usuario;
    int opcion;

    cout << "Usuario: ";
    getline(cin, usuario);

    do {
        cout << "\n1. Registrar y Guardar\n2. Inventario\n3. Salir\nOpcion: ";
        cin >> opcion;

        if (opcion == 1) {
            if (totalRegistrados < 10) {
                cin.ignore();
                cout << "Nombre: ";
                getline(cin, lista[totalRegistrados].nombre);
                cout << "Precio: ";
                cin >> lista[totalRegistrados].precio;
                cout << "Cantidad: ";
                cin >> lista[totalRegistrados].cantidad;

                // GUARDADO AUTOMÁTICO:
                totalRegistrados++; 
                cout << ">> Producto guardado automaticamente en la lista.\n";
            }
        } 
        else if (opcion == 2) {
            cout << "\n--- INVENTARIO DE " << usuario << " ---" << endl;
            for (int i = 0; i < totalRegistrados; i++) {
                cout << "[" << i + 1 << "] " << lista[i].nombre 
                     << " | S/ " << lista[i].precio << " | Cant: " << lista[i].cantidad << endl;
            }
        }
    } while (opcion != 3);

    return 0;
}