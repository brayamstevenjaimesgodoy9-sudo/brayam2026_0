//Nota ≥ 90 "Excelente"
//Nota ≥ 70 "Aprobado"
//Nota < 70 "Reprobado"
#include <iostream>
using namespace std;
int main(){
    cout << "ingrese nota porfavor: "<< endl;
    int nota;
    cin >> nota;
    if (nota > 100 || nota < 0){
        cout << "ingrese notas validas"<< endl;
    }else if (nota >= 90){
        cout << "excelene:"<< endl;
        cout << "tu efuerzo es mas que maximo agradece a DIOS:";
    }else if(nota >= 70){
        cout << "aprobado:" << endl;
        cout << "diste lo mejor pero puedes dar mas y ser mejor:";
    }else if (nota < 70){
        cout << "reprobado:"<< endl;
        cout << "no te desesperes lo lograras si te esfuerzas mas:";
    }
    return 0;
}