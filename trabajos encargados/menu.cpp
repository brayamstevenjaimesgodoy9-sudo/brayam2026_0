#include <iostream>
using namespace std;
int main(){
   cout << "restaurante la casa tropical" << endl;
   
   cout << "1: Pescado entero frito con arroz." << endl;
   cout << "2: Filete de Paiche envuelto en hoja." << endl;
   cout << "3: Arroz marinero aromatizado con cilantro.." << endl;
   cout << "4: Lomo de res en salsa de tamarindo." << endl;
   cout << "5: Curry de garbanzos y leche de coco con trozos de piña." << endl;
   
   cout << "ingrese su opcion deseas: "; 
   int opcion;
   cin >> opcion;
   if (opcion == 1) {
    // Aquí va el código para elegir las primera opcion
    
    cout << "Pescado entero frito con arroz." << endl;
}
else if (opcion == 2) {
    // Aquí va el código para la segunda opcion
    cout << "Filete de Paiche envuelto en hoja." << endl;
}
else if (opcion == 3) {
    // Aquí va el código para la tercera opcion
     cout << "Arroz marinero aromatizado con cilantro.." << endl;
}
else if (opcion == 4) {
    // Aquí va el código para la cuarta opcion
     cout << "Lomo de res en salsa de tamarindo." << endl;
}
else if (opcion == 5) {
    // Aquí va el código para la quinta opcion
     cout << "Curry de garbanzos y leche de coco con trozos de piña." << endl;
}
else {
    cout << "gracias por su preferencia" << endl;
}
}
