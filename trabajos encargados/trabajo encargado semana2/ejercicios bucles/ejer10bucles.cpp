//Adivina el número
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int numero, intento;
    srand(time(0));
    numero = rand() % 100 + 1; // número entre 1 y 100

    do {
        cout << "Adivina el numero (1-100): ";
        cin >> intento;

        if (intento > numero)
            cout << "Demasiado alto.\n";
        else if (intento < numero)
            cout << "Demasiado bajo.\n";

    } while (intento != numero);

    cout << "¡Correcto! Adivinaste el numero.\n";
    return 0;
}
