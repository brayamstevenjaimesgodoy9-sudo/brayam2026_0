#include <iostream>
using namespace std;
int main(){
    cout << "ingrese el menu: " << endl;
    cout << "1: pizza hawuayana: " << endl;
    cout << "2: hamburguesa: " << endl;
    cout << "3: salchipapa: " << endl;
    cout << "4: alitas a la parrilla: " << endl;
    int opcion;
    cin >> opcion;
    switch (opcion){
        case 1:
        cout << "pizza hawuayana: " << endl;
            break;
        case 2:
        cout << "hamburguesa: " << endl;
            break;
        case 3:
        cout << "salchipapa: " << endl;
            break;
        case 4:
        cout << "alitas a la parrila: " << endl;
            break;
        default:
        cout << "opcion no valida: " << endl;
    }
    return 0;
}