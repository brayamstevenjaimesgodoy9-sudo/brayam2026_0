//Contador de dígitos
#include <iostream>
using namespace std;

int main() {
    int num, contador = 0;
    cout << "Ingrese un numero entero positivo: ";
    cin >> num;

    while (num > 0) {
        num /= 10;
        contador++;
    }

    cout << "Cantidad de digitos: " << contador << endl;
    return 0;
}
