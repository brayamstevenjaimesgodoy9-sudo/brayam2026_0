//Suma de dígitos
#include <iostream>
using namespace std;

int main() {
    int num, suma = 0;
    cout << "Ingrese un numero entero: ";
    cin >> num;

    while (num != 0) {
        suma += num % 10;
        num /= 10;
    }

    cout << "La suma de los digitos es: " << suma << endl;
    return 0;
}
