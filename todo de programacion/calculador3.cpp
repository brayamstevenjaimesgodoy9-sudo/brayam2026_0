#include <iostream>
using namespace std;

int main() {
    float num1, num2, resultado;
    char operacion;

    cout << "Introduce el numero 1:  ";
    cin >> num1;

    cout << "Introduce la operacion (+, -, *, /): ";
    cin >> operacion;

    cout << "Introduce el numero 2: ";
    cin >> num2;

    switch(operacion) {
        case '+':
            resultado = num1 + num2;
            cout << "Resultado: " << resultado << endl;
            break;

        case '-':
            resultado = num1 - num2;
            cout << "Resultado: " << resultado << endl;
            break;

        case '*':
            resultado = num1 * num2;
            cout << "Resultado:  " << resultado << endl;
            break;

        case '/': 
            if (num2 != 0) {
                resultado = num1 / num2;
                cout << "Resultado: " << resultado << endl;
            }
            else {
                cout << "Error: No se puede dividir entre cero" << endl;
            }
            break;

        default:
            cout << "revise los numeros ingresados" << endl;
            break;
    }

    return 0;
}