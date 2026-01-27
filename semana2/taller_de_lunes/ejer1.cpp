//Si la temperatura es mayor a 30, encender el ventilador.
//Si es menor o igual a 30, apagarlo.”
#include <iostream>
using namespace std;
int main(){
    cout << "ingrese en numero para encender el ventilador"
    int mayor;
    cin >> mayor;
    if (mayor >= 30){
    cout << "el ventilador se encendio"<< endl;
    }else if (mayor < 30){
        cout << "el ventilador no encendera por negatividad"<< endl;
    }else{
        cout << "el numero que ingresastes no es valido"<< endl;
    }
    return 0;
}
