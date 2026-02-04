#include <iostream>
using namespace std;
int main(){
    cout << "ingrese los dos numeros: "<< endl;
    int numero3 , numero4;
    cin >> numero3 >> numero4;
    if (numero3 < 0 || numero4 < 0){
        cout << "los numeros es invalido solo numero positivo: "<< endl;
    }else if (numero3 > numero4){
        cout << "el primer numero: "<< numero3 << " es mayor: "<< endl;
    }else if(numero4 > numero3){
        cout << "el segundo numero: "<< numero4 << " es mayor: "<< endl;
    }else if (numero3 == numero4){
        cout << "los dos numeros son iguales: "<< numero3 << " "<< numero4 << endl;
    }
    return 0 ;
}