#include <iostream>
#include <string>
using namespace std;

class laptop{
private:
    string marca;
    int ram;
    double almacenamiento;
//una ves convertido los atributos de publico a privete de la clase laptop para hacer se utilizare el get y el set para poder leer y cambiar
public:
    string getmarca() const { return marca;}
    int getram() const {return ram;}
    double getalmacenamiento() const {return almacenamiento;}
    laptop(string m , int r,double a){
       marca = m ;
       ram = r;
       almacenamiento = a;
    }
    void setmarca(string m){ marca = m;}
    void setram(int r){
    if(r >= 4 && r >=128 ){
               ram = r;
        }else{
                cout << "la ram no es suficiente para la laptop";
        }
    }
    void setalmacenamiento(double a){almacenamiento = a; }
    void mostrar(){
    cout << "marca: "<< marca << endl;
    cout << "ram: "<< ram << endl;
    cout << "almacenamiento: " << almacenamiento << endl;
    cout << "-----------------------" << endl;
    }
};

int main(){
    laptop lap1("lenovo", 16 , 459.12);

    laptop lap2("dell", 32 , 523.56);

    lap1.mostrar();
    lap2.mostrar();

    return 0;

}
/*este ejercicio realizado fue por investigacion y verificacion de errores por ejemplo sobre compilacion y algunos puntos y coma  despues viene un ejercicios que pide pero hecho con la ia el primer ejercicio es otro*/
class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getBateria() const { return bateria; }

    void setMarca(string m) { marca = m; }
    void setModelo(string mo) { modelo = mo; }

    void setBateria(int b) {
        if (b >= 0 && b <= 100) {
            bateria = b;
        } else {
            cout << "Error: bateria invalida" << endl;
        }
    }

    void mostrarInfo() {
        cout << marca << " - " << modelo << " - " << bateria << "%" << endl;
    }
};
