#include <iostream>
using namespace std;
int main (){
    cout << "ingresar el monto de las compras: "<< endl;
    int compra , resul ;
    cin >> compra;
    if (compra >= 1000){
        resul= compra * 0.20;
        cout << "la compra tiene descuento de 20 porcieto solo pagaras: "<< resul << endl;
    }else{
        cout << "la compra no tiene descuento: " << compra << " no es suficiente para el descuento " << endl;
    }
    return 0 ;
}