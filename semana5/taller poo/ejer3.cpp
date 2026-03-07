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

    void setmarca(string marca){ this -> marca = marca;}
    void setram(int ram){
    if(ram >= 4 && ram <= 128 ){
               this -> ram = ram;
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
     laptop lap1;
    lap1.setmarca("lenovo");
    lap1.setram(16);
    lap1.setalmacenamiento(459.12);

    laptop lap2;
    lap2.setmarca("dell");
    lap2.setram(32);
    lap2.setalmacenamiento(523.56);


    lap1.mostrar();
    lap2.mostrar();

    return 0;

}
/*el ejercicio de primero se iso y me salio algunas dudas pero entendibles la cuales si se pone el this ya no seria necesario utilizar el contructor es mi entender asi se vio
y este ejercicios lo hice con la ayuda de la ia lo que pide la actividad*/
void setMarca(string marca) {
    this->marca = marca;
}

void setBateria(int bateria) {
    if (bateria >= 0 && bateria <= 100) {
        this->bateria = bateria;
    }
}
