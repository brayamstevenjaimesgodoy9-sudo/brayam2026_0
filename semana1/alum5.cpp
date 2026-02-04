#include <iostream>
using namespace std;
int main(){
    //Calcula el promedio de 3 números.
    int prom1, prom2, prom3;
    float promedio;
    cout << "Ingrese tres numeros: ";
    cin >> prom1 >> prom2 >> prom3;
    promedio = (prom1 + prom2 + prom3) / 3;
    cout << "El promedio es: " << promedio << endl;
    return 0;
}