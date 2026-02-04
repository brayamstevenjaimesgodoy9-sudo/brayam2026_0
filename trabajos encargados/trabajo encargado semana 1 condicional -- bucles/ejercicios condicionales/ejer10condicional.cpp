#include <iostream>
using namespace std;
int main(){
    cout << "que operacion desea hacer: " << endl;
    
    cout << "1: reguistrar dinero: " << endl;
    cout << "2: consultar saldo: " << endl;
    cout << "3: retirar dinero: " << endl;
    cout << "4: salir: " << endl;
    int opcion;
    cin >> opcion;
    switch (opcion){
        case 1:
        cout << "reguistrar dinero: " << endl;
        cout << "feliz lunes y que tengas suerte" << endl;
            break;
        case 2:
        cout << "consultar saldo: " << endl;
        cout << "este dia tendras buen momento" << endl;
            break;
        case 3:
        cout << "retirar dinero: " << endl;
        cout << "gran dia ten voluntad" << endl;
            break;
        case 4:
        cout << "salir: " << endl;
        cout << "un dia bien hermoso y calido" << endl;
            break;
        default:
        cout << "opcion no valida: " << endl;
    }
    return 0;
}