#include <iostream>
using namespace std;
int main(){
    cout << "restaurante la casa tropical" << endl;
   
    cout << "1: Pescado entero frito con arroz." << endl;
   cout << "2: Filete de Paiche envuelto en hoja." << endl;
   cout << "3: Arroz marinero aromatizado con cilantro.." << endl;
   cout << "4: Lomo de res en salsa de tamarindo." << endl;
   cout << "5: Curry de garbanzos y leche de coco con trozos de piña." << endl;
   
   cout << "ingrese su opcion de menu: " << endl;
   int opcion;
   cin >> opcion;
switch(opcion) {
    case 1:
        // primera opcion
        cout << "Pescado entero frito con arroz." << endl;
        break;
    case 2:
        // segunda opcion
        cout << "Filete de Paiche envuelto en hoja." << endl;
        break;
    case 3:
        // tercera opcion
        cout << "Arroz marinero aromatizado con cilantro.." << endl;
        break;
    case 4:
        // cuarta opcion
        cout << "Lomo de res en salsa de tamarindo." << endl;
        break;
    case 5:
        // quinta opcion
        cout << "Curry de garbanzos y leche de coco con trozos de piña." << endl;
        break;
    default:
        cout << "gracias por su preferencia" << endl;
        break;
}
}