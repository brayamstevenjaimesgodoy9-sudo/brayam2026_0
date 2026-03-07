#include <iostream>
using namespace std;

int main() {

    int gastos[7] = {120, 80, 100, 60, 140, 90, 110};
    int total = 0;
    int diasMayor = 0;
    float promedio;

    // Calcular total
    for(int i = 0; i < 7; i++){
        total = total + gastos[i];
    }

    // Calcular promedio
    promedio = total / 7.0;

    // Contar días mayores al promedio
    for(int i = 0; i < 7; i++){
        if(gastos[i] > promedio){
            diasMayor++;
        }
    }

    cout << "Total: " << total << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Dias con gasto mayor al promedio: " << diasMayor << endl;

    return 0;
}
