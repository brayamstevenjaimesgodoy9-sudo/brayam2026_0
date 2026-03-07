#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Producto {
    int codigo;
    string nombre;
    float precio;
    int stock;
};

int main() {
    int N;
    cout << "Ingrese el numero de productos a registrar (minimo 5): ";
    cin >> N;
    if (N < 5) {
        cout << "Debe ser al menos 5. Se usara 5." << endl;
        N = 5;
    }
    Producto productos[100];  // Arreglo de max 100, pero usamos N
    int numProductos = 0;     // Contador de productos registrados

    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Registrar productos\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto por codigo\n";
        cout << "4. Buscar producto por nombre\n";
        cout << "5. Mostrar producto con mayor stock\n";
        cout << "6. Mostrar producto mas caro\n";
        cout << "7. Calcular valor total del inventario\n";
        cout << "8. Salir\n";
        cout << "9. Ordenar productos por precio (mayor a menor)\n";  // Reto
        cout << "10. Ordenar productos por nombre (A-Z)\n";           // Reto
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {  // Registrar productos
                cout << "Ingrese los " << N << " productos:\n";
                for (int i = 0; i < N; i++) {
                    cout << "Producto " << (i + 1) << ":\n";
                    cout << "Codigo: ";
                    cin >> productos[i].codigo;
                    cin.ignore();  // Limpiar buffer para getline
                    cout << "Nombre: ";
                    getline(cin, productos[i].nombre);
                    do {
                        cout << "Precio: ";
                        cin >> productos[i].precio;
                        if (productos[i].precio <= 0) {
                            cout << "Precio debe ser mayor a 0. Intente de nuevo.\n";
                        }
                    } while (productos[i].precio <= 0);
                    do {
                        cout << "Stock: ";
                        cin >> productos[i].stock;
                        if (productos[i].stock < 0) {
                            cout << "Stock no puede ser negativo. Intente de nuevo.\n";
                        }
                    } while (productos[i].stock < 0);
                }
                numProductos = N;
                break;
            }
            case 2: {  // Mostrar productos
                if (numProductos == 0) {
                    cout << "No hay productos registrados.\n";
                    break;
                }
                cout << left << setw(10) << "Codigo" 
                     << setw(20) << "Nombre" 
                     << setw(10) << "Precio" 
                     << setw(10) << "Stock" << endl;
                for (int i = 0; i < numProductos; i++) {
                    cout << left << setw(10) << productos[i].codigo 
                         << setw(20) << productos[i].nombre 
                         << setw(10) << productos[i].precio 
                         << setw(10) << productos[i].stock << endl;
                }
                break;
            }
            case 3: {  // Buscar por codigo
                int cod;
                cout << "Ingrese codigo a buscar: ";
                cin >> cod;
                bool encontrado = false;
                for (int i = 0; i < numProductos; i++) {
                    if (productos[i].codigo == cod) {
                        cout << "Codigo: " << productos[i].codigo << "\n";
                        cout << "Nombre: " << productos[i].nombre << "\n";
                        cout << "Precio: " << productos[i].precio << "\n";
                        cout << "Stock: " << productos[i].stock << "\n";
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) cout << "No encontrado\n";
                break;
            }
            case 4: {  // Buscar por nombre
                string nom;
                cin.ignore();
                cout << "Ingrese nombre a buscar: ";
                getline(cin, nom);
                bool encontrado = false;
                for (int i = 0; i < numProductos; i++) {
                    if (productos[i].nombre == nom) {
                        cout << "Codigo: " << productos[i].codigo << "\n";
                        cout << "Nombre: " << productos[i].nombre << "\n";
                        cout << "Precio: " << productos[i].precio << "\n";
                        cout << "Stock: " << productos[i].stock << "\n";
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) cout << "No encontrado\n";
                break;
            }
            case 5: {  // Producto con mayor stock
                if (numProductos == 0) {
                    cout << "No hay productos.\n";
                    break;
                }
                int maxStock = productos[0].stock;
                int idx = 0;
                for (int i = 1; i < numProductos; i++) {
                    if (productos[i].stock > maxStock) {
                        maxStock = productos[i].stock;
                        idx = i;
                    }
                }
                cout << "Producto con mayor stock:\n";
                cout << "Codigo: " << productos[idx].codigo << "\n";
                cout << "Nombre: " << productos[idx].nombre << "\n";
                cout << "Precio: " << productos[idx].precio << "\n";
                cout << "Stock: " << productos[idx].stock << "\n";
                break;
            }
            case 6: {  // Producto mas caro
                if (numProductos == 0) {
                    cout << "No hay productos.\n";
                    break;
                }
                float maxPrecio = productos[0].precio;
                int idx = 0;
                for (int i = 1; i < numProductos; i++) {
                    if (productos[i].precio > maxPrecio) {
                        maxPrecio = productos[i].precio;
                        idx = i;
                    }
                }
                cout << "Producto mas caro:\n";
                cout << "Codigo: " << productos[idx].codigo << "\n";
                cout << "Nombre: " << productos[idx].nombre << "\n";
                cout << "Precio: " << productos[idx].precio << "\n";
                cout << "Stock: " << productos[idx].stock << "\n";
                break;
            }
            case 7: {  // Valor total del inventario
                if (numProductos == 0) {
                    cout << "No hay productos.\n";
                    break;
                }
                float total = 0;
                for (int i = 0; i < numProductos; i++) {
                    total += productos[i].precio * productos[i].stock;
                }
                cout << "Valor total del inventario: " << total << endl;
                break;
            }
            case 9: {  // Reto: Ordenar por precio (mayor a menor)
                for (int i = 0; i < numProductos - 1; i++) {
                    for (int j = 0; j < numProductos - i - 1; j++) {
                        if (productos[j].precio < productos[j + 1].precio) {
                            Producto temp = productos[j];
                            productos[j] = productos[j + 1];
                            productos[j + 1] = temp;
                        }
                    }
                }
                cout << "Productos ordenados por precio (mayor a menor).\n";
                break;
            }
            case 10: {  // Reto: Ordenar por nombre (A-Z)
                for (int i = 0; i < numProductos - 1; i++) {
                    for (int j = 0; j < numProductos - i - 1; j++) {
                        if (productos[j].nombre > productos[j + 1].nombre) {
                            Producto temp = productos[j];
                            productos[j] = productos[j + 1];
                            productos[j + 1] = temp;
                        }
                    }
                }
                cout << "Productos ordenados por nombre (A-Z).\n";
                break;
            }
            case 8:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 8);

    return 0;
}