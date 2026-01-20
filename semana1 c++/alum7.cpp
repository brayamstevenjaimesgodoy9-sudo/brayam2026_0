#include <iostream>
using namespace std;
int main(){
    //Convierte metros a centímetros.
    float metros, centimetros;
    cout << "Ingrese metros: ";
    cin >> metros;
    centimetros = metros * 100;
    cout << metros << " metros son " << centimetros << " centimetros" << endl;
}