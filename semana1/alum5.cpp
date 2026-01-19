#include <iostream>
#include <string>
using namespace std;
int main(){
    //Pide el nombre del usuario y muéstralo.
    string nombre ;
    cout<<"ingrese tu nombre: "<< endl;
    getline (cin , nombre);
    cout << "el usuario se llama: " << nombre << endl;
    return 0 ;
}