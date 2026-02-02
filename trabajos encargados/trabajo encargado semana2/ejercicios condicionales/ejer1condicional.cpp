#include <iostream>
using namespace std;
int main(){
    cout << "ingrese numero: ";
    int numero1;
    cin >> numero1;

    if (numero1 < 0){
        cout << "el numero es invalido solo positivos: " << endl;
    }else{
        cout << "el numero es correcto: " << endl;
    }if(numero1 % 2 == 0 ){
        cout << "el numero: " << numero1 << " es par:" << endl;
    }else if(numero1 % 2 == 1){
        cout << "el numero: " << numero1 << " es impar:" << endl;
    }
    return 0 ;
}