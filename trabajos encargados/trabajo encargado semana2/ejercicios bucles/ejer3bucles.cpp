//Suma de los primeros n números naturales
#include <iostream>
using namespace std;

int main() {
    int n, suma = 0;
    cout << "Ingrese un numero n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        suma += i;
    }

    cout << "La suma es: " << suma << endl;
    return 0;
}
