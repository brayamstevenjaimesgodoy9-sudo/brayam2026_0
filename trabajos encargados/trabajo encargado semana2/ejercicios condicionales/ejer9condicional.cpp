#include <iostream>
using namespace std;
int main(){
    cout << "ingrese un dia para una frese del dia" << endl;
    cout << "1: lunes" << endl;
    cout << "2: martes" << endl;
    cout << "3: miercoles" << endl;
    cout << "4: jueves" << endl;
    cout << "5: viernes" << endl;
    cout << "6: sabado" << endl;
    cout << "7: domingo" << endl;
    int opcion;
    cin >> opcion;
    switch (opcion){
        case 1:
        cout << "lunes: " << endl;
        cout << "feliz lunes y que tengas suerte" << endl;
            break;
        case 2:
        cout << "martes: " << endl;
        cout << "este dia tendras buen momento" << endl;
            break;
        case 3:
        cout << "miercoles: " << endl;
        cout << "gran dia ten voluntad" << endl;
            break;
        case 4:
        cout << "jueves: " << endl;
        cout << "un dia bien hermoso y calido" << endl;
            break;
        case 5:
        cout << "viernes: " << endl;
        cout << "este dia tendras mayor calidad de vida" << endl;
            break;
        case 6:
        cout << "sabado: " << endl;
        cout << "este dia es un buen descanso" << endl;
            break;
        case 7:
        cout << "domingo: " << endl;
        cout << "este dia es un buen dia de capacitacion" << endl;
            break;
            default:
        cout << "dia no valida: " << endl;
    }
    return 0;
}