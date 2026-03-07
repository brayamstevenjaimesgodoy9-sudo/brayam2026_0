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
    laptop(){
        marca ="desconocida";
        ram = 4;
        almacenamiento = 1000;
    }
    laptop(string marca, int ram){
        this -> marca = marca;
        this -> ram = ram;
        almacenamiento = 1000;
    }
    laptop(string marca, int ram, double almacenamiento){
        this -> marca = marca;
        this -> ram = ram;
        if(almacenamiento >= 0 && almacenamiento <= 1000)
            this -> almacenamiento = almacenamiento;
        else
            this -> almacenamiento = 1000;
    }
    void mostrar(){
    cout << "marca: "<< marca << endl;
    cout << "ram: "<< ram << endl;
    cout << "almacenamiento: " << almacenamiento << endl;
    cout << "-----------------------" << endl;
    }
};

int main(){

    laptop lap1("lenovo", 16, 459.12);
    laptop lap2("dell", 32, 523.56);


    lap1.mostrar();
    lap2.mostrar();

    return 0;

}
/* este codigo se reliso con intento tra intento pero se logro ahora este codigo debajo sera el resultado de la ia */

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    // Constructor por defecto
    Celular() {
        marca = "Desconocida";
        modelo = "Generico";
        bateria = 100;
    }

    // Constructor con 2 parametros
    Celular(string marca, string modelo) {
        this->marca = marca;
        this->modelo = modelo;
        bateria = 100;
    }

    // Constructor con 3 parametros
    Celular(string marca, string modelo, int bateria) {
        this->marca = marca;
        this->modelo = modelo;
        if (bateria >= 0 && bateria <= 100)
            this->bateria = bateria;
        else
            this->bateria = 100;
    }

    void mostrarInfo() {
        cout << marca << " - " << modelo << " - " << bateria << "%" << endl;
    }
};
