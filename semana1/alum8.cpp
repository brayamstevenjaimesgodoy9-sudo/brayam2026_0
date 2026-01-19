#include <iostream>
using namespace std;
int main(){
    //Compara dos números e imprime el resultado.
    int nume , nume2;
    cout << "ingrese el primer numero y el segundo numero: ";
    cin >> nume >> nume2;
    if (nume > nume2) {
    cout << "el numero es mayor: " << nume << endl;
    } else if (nume2 > nume) {
    cout << "el segundo numero es mayor: " << nume2 << endl;
    } else{
        cout << "los dos numeros son iguales: " << nume << nume2 << endl;
    }
}