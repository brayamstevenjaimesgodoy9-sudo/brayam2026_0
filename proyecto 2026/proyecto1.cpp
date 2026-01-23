#include <iostream>
using namespace std;

struct Producto {
    int codigo;
    string nombre;
    float precio;
    int stock;
};

// Registrar productos
void registrarProductos(Producto productos[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "\nProducto " << i + 1 << endl;
        cout << "Código: ";
        cin >> productos[i].codigo;
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, productos[i].nombre);
        cout << "Precio: ";
        cin >> productos[i].precio;
        cout << "Stock: ";
        cin >> productos[i].stock;
    }
}

// Mostrar inventario
void mostrarInventario(Producto productos[], int n) {
    cout << "\n INVENTARIO\n";
    for(int i = 0; i < n; i++) {
        cout << "Código: " << productos[i].codigo
             << " | Nombre: " << productos[i].nombre
             << " | Precio: $" << productos[i].precio
             << " | Stock: " << productos[i].stock << endl;
    }
}

// Realizar venta
void realizarVenta(Producto productos[], int n, float &totalVentas) {
    int codigo, cantidad;
    cout << "\n Ingrese código del producto: ";
    cin >> codigo;

    for(int i = 0; i < n; i++) {
        if(productos[i].codigo == codigo) {
            cout << "Cantidad a vender: ";
            cin >> cantidad;

            if(cantidad <= productos[i].stock) {
                float total = cantidad * productos[i].precio;
                productos[i].stock -= cantidad;
                totalVentas += total;

                cout << "Venta realizada. Total: $" << total << endl;
            } else {
                cout << "Stock insuficiente.\n";
            }
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Menú principal
void menu() {
    cout << "\n SISTEMA DE VENTAS E INVENTARIO\n";
    cout << "1. Registrar productos\n";
    cout << "2. Mostrar inventario\n";
    cout << "3. Realizar venta\n";
    cout << "4. Mostrar total de ventas\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    const int MAX = 10;
    Producto productos[MAX];
    int n = 0;
    int opcion;
    float totalVentas = 0;

    do {
        menu();
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Cantidad de productos a registrar (máx 10): ";
                cin >> n;
                registrarProductos(productos, n);
                break;

            case 2:
                mostrarInventario(productos, n);
                break;

            case 3:
                realizarVenta(productos, n, totalVentas);
                break;

            case 4:
                cout << "\n💰 Total de ventas: $" << totalVentas << endl;
                break;

            case 5:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opción inválida.\n";
        }

    } while(opcion != 5);

    return 0;
}


