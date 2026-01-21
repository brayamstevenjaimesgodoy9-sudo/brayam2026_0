#include <iostream>
using namespace std;

int main() {
    float num1, num2, resultado;
    char operacion;

    cout << "Introduce el numero 1:  ";
    cin >> num1;

    cout << "Introduce la operacion (+, -, *, /) que deseas: ";
    cin >> operacion;

    cout << "Introduce el numero 2: ";
    cin >> num2;

    if (operacion == '+') {
        resultado = num1 + num2;
        cout << "Resultado: " << resultado << endl;
    }
    else if (operacion == '-') {
        resultado = num1 - num2;
        cout << "Resultado: " << resultado << endl;
    }
    else if (operacion == '*') {
        resultado = num1 * num2;
        cout << "Resultado:  " << resultado << endl;
    }
    else if (operacion == '/') {
        if (num2 != 0) {
            resultado = num1 / num2;
            cout << "Resultado: " << resultado << endl;
        }
        else {
            cout << "Error: No se puede dividir entre cero" << endl;
        }
    }
    else {
        cout << "revise los numeros" << endl;
    }

    return 0;
}