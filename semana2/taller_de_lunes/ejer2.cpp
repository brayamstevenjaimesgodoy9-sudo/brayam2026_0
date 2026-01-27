//Un sistema permite el acceso si la edad es mayor o igual a 18.
#include <iostream>
using namespace std;
int main(){
    cout << "ingrese edad porfavor para ver si eres digno: "<< endl;
    int edad;
    cin >> edad;
    if (edad >= 18){
        cout << "es mayor de edad aceso permitido  al sistema:"<< endl;
        cout << "bienvenido usurio digno del sistema:";
    }else if(edad < 18){
        cout << "es menor de edad no esta permitido al sistema:" << endl;
        cout << "no vuelvas a entrar o seras reportado:";
    }else{
        cout << "la edad que ingresastes no es digno del sistema:";
    }
    return 0;
}