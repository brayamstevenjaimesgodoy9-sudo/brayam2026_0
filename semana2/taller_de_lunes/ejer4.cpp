/*El usuario elige una opción:
1.	Sumar
2.	Restar
3.	Multiplicar
4.	Dividir
*/
#include <iostream>
using namespace std;
int main(){
    cout << "ingrese una opcion para suma (1), resta (2), multiplicar(3), dividir(4): "<< endl;
    int opcion;
    cin >> opcion;
    switch (opcion){
        case 1:
        cout << "Sumar";
        break;
        case 2:
        cout <<"resta";
        break;
        case 3:
        cout << "multiplicar";
        break;
        case 4:
        cout << "dividir";
        break;
        default:
        cout << "operacion no valida";
    }

    return 0;
}