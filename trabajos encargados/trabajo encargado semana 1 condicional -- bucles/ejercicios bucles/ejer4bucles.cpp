//Factorial de un número
#include <iostream>
using namespace std;

int main() {
    int n;
    long long factorial = 1;

    cout << "Ingrese un numero positivo: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    cout << "El factorial es: " << factorial << endl;
    return 0;
}
