#include <iostream>
using namespace std;
int main (){
    cout << "ingrese horas trabajadas: " << endl;
    int horas, exta, salario;
    float horaextra;
    cin >> horas;
    bool extra=(horas > 40);
    switch (extra){
        case 0 :
        salario =horas * 16 ;
        cout << "tu salario normal es: " << salario << endl;
        break ;

        case 1 :
        float horaextra = horas - 40;
        salario = (horas * 16) + (horaextra * 0.20);
        cout << "tu salario tiene aumento extra: " << salario << endl;
        break ;
    }
    return 0 ;

}