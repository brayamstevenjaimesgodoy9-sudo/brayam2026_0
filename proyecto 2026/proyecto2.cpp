#include <iostream>
using namespace std;

int main() {
    string nombreProducto;
    int stock;
    float precio;
    int cantidadVenta;

    // Registro de producto
    cout << "REGISTRO DE PRODUCTO" << endl;
    cout << "Ingrese el nombre del producto: ";
    cin >> nombreProducto;

    cout << "Ingrese el precio del producto: ";
    cin >> precio;

    cout << "Ingrese la cantidad en stock: ";
    cin >> stock;

    // Inventario
    cout << endl;
    cout << "INVENTARIO ACTUAL" << endl;
    cout << "Producto: " << nombreProducto << endl;
    cout << "Precio: " << precio << endl;
    cout << "Stock disponible: " << stock << endl;

    // Registro de venta
    cout << endl;
    cout << "REGISTRO DE VENTA" << endl;
    cout << "Ingrese la cantidad a vender: ";
    cin >> cantidadVenta;

    if (cantidadVenta <= stock) {
        stock = stock - cantidadVenta;
        float total = cantidadVenta * precio;

        cout << endl;
        cout << "VENTA REALIZADA" << endl;
        cout << "Total a pagar: " << total << endl;
        cout << "Stock restante: " << stock << endl;
    } else {
        cout << endl;
        cout << "ERROR: No hay suficiente stock" << endl;
    }

    return 0;
}
