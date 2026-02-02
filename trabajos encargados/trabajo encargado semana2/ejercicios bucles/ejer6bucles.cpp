//Validación de número positivo
#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Ingrese un numero positivo: ";
    cin >> num;

    while (num < 0) {
        cout << "Numero invalido. Intente nuevamente: ";
        cin >> num;
    }

    cout << "Numero valido: " << num << endl;
    return 0;
}
