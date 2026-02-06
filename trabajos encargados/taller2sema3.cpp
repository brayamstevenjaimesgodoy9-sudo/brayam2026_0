#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct producto{
    int codigo;
    string=nombre;
    float precio;
    int stock;
};

int main(){
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
    
}