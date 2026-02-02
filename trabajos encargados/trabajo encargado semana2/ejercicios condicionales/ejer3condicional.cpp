#include <iostream>
using namespace std;
int main(){
    cout << "ingrese numero: " << endl;
    int numero5;
    cin >> numero5;
    if (numero5 < 0){
        cout << "el numero es negativo: " << numero5 << endl;
    }else if(numero5 > 0){
        cout << "el numero es positivo: " << numero5 << endl;
    }else if(numero5 == 0){
        cout << "el numero es cero: " << numero5 << endl;
    }
    return 0 ;
}