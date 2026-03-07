#include <iostream>
#include <string>
using namespace std;

class laptop{
public:
    string marca;
    string ram;
    double almacenamiento;
    laptop(string m , string r,double a){
       marca = m ;
       ram = r;
       almacenamiento = a;
    }
    void mostrar(){
    cout << "marca: "<< marca << endl;
    cout << "ram: "<< ram << endl;
    cout << "almacenamiento: " << almacenamiento << endl;
    cout << "-----------------------" << endl;
    }
};

int main(){
    laptop lap1("lenovo", "16 gb", 459.12);

    laptop lap2("dell", "32gb", 523.56);
    lap1.mostrar();
    lap2.mostrar();

    return 0;

}
/*despues vien el ejerciccio del la actividad pero resuelto con la ia
la cual el primer codigo que esta se resolvio manualmente personlmente con sugerencia del profesor */

#include <iostream>
using namespace std;

class Celular {
public:
    string marca;
    string modelo;
    int bateria;

    void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Bateria: " << bateria << "%" << endl;
        cout << "-------------------" << endl;
    }
};

int main() {
    Celular cel1;
    cel1.marca = "Samsung";
    cel1.modelo = "S23";
    cel1.bateria = 85;

    Celular cel2;
    cel2.marca = "Apple";
    cel2.modelo = "iPhone 14";
    cel2.bateria = 60;

    cel1.mostrarInfo();
    cel2.mostrarInfo();

    return 0;
}
