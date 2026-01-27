/*Diseña un programa que:
Reciba una hora del día (0–23)
Muestre:
"Buenos días" (6–11)
"Buenas tardes" (12–18)
"Buenas noches" (19–23)
"Hora no válida" (otros casos)
*/
#include <iostream>
using namespace std;
int main(){
    cout << "ingrese la hora: "<< endl;
    int hora;
    cin >> hora;

    if(hora >= 0 && hora <= 5){
        cout << "marugada";
    }else if (hora >= 6 && hora <= 11){
        cout << "buenos dias";
    }else if (hora >= 12 && hora <=18){
        cout << "buenas tardes";
    }else if((hora >= 19 && hora <= 23)){
        cout <<"buenas noches";
    }else{
        cout << "la hora no valida: ";
    }
    

    return 0;
}