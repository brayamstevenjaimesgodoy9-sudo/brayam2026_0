#include <iostream>
using namespace std;
int main(){
    cout << "ingrese su edad correcta porfavor: " << endl;
    int numero6;
    cin >> numero6 ;
    if (numero6 >=18){
        cout << "el usuario es mayor de edad bienvenido: " << numero6 ;
    }else{
        cout << "el usuario es menor de edad no ingrese: " << numero6 ;
    }
    return 0 ;
}