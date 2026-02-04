#include <iostream>
using namespace std;
int main (){
cout << "ingrese los numeros: " << endl;
int numero7 , numero8;
cin >> numero7 >> numero8;
cout << "ingrese el operador deseado +, -, *, /" << endl;
char operador;
cin >> operador;

switch (operador){
    case '+':
    cout << "la suma es: " << numero7 + numero8 << endl;
        break;

    case '-':
    cout << "la resta es: " << numero7 - numero8 << endl;
        break;

    case '*':
    cout << "la multiplicacion es: " << numero7 * numero8 << endl;
        break;

    case '/':
    if (numero8 != 0)
    cout << "la divicion es: " << numero7 / numero8 << endl;
    else
        cout << "el numero no pued ser cero: " << endl;
        break; 

    default:
        cout << "opercion no valida: " << endl;
}
return 0 ;
}