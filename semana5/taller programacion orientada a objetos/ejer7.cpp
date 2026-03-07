#include <iostream>
using namespace std;
/*clase base d vehiculo*/
class Vehiculo {
private:
    string marca;
    int velocidadMax;

public:
    // Constructor
    Vehiculo(string marca, int velocidadMax) {
        this->marca = marca;
        
        if (velocidadMax > 0)
            this->velocidadMax = velocidadMax;
        else
            this->velocidadMax = 0;
    }

    // Getters
    string getMarca() const {
        return marca;
    }

    int getVelocidadMax() const {
        return velocidadMax;
    }

    // Setters
    void setMarca(string marca) {
        this->marca = marca;
    }

    void setVelocidadMax(int velocidadMax) {
        if (velocidadMax > 0)
            this->velocidadMax = velocidadMax;
        else
            cout << "Velocidad invalida" << endl;
    }

    // Metodo mostrarInfo
    void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Velocidad Maxima: " << velocidadMax << " km/h" << endl;
    }
};

/*clase derivada carro*/
class Carro : public Vehiculo {
private:
    int puertas;

public:
    // Constructor
    Carro(string marca, int velocidadMax, int puertas)
        : Vehiculo(marca, velocidadMax) {
        
        if (puertas > 0)
            this->puertas = puertas;
        else
            this->puertas = 4;
    }

    // Getter
    int getPuertas() const {
        return puertas;
    }

    // Setter
    void setPuertas(int puertas) {
        if (puertas > 0)
            this->puertas = puertas;
        else
            cout << "Numero de puertas invalido" << endl;
    }

    // Mostrar info
    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << "Puertas: " << puertas << endl;
        cout << "---------------------" << endl;
    }
};
/*clase derivada moto*/

class Moto : public Vehiculo {
private:
    int cilindraje;

public:
    // Constructor
    Moto(string marca, int velocidadMax, int cilindraje)
        : Vehiculo(marca, velocidadMax) {
        
        if (cilindraje > 0)
            this->cilindraje = cilindraje;
        else
            this->cilindraje = 125;
    }

    // Getter
    int getCilindraje() const {
        return cilindraje;
    }

    // Setter
    void setCilindraje(int cilindraje) {
        if (cilindraje > 0)
            this->cilindraje = cilindraje;
        else
            cout << "Cilindraje invalido" << endl;
    }

    // Mostrar info
    void mostrarInfo() {
        Vehiculo::mostrarInfo();
        cout << "Cilindraje: " << cilindraje << " cc" << endl;
        cout << "---------------------" << endl;
    }
};
/*pruebas en main*/

int main() {

    Carro carro1("Toyota", 180, 4);
    Moto moto1("Yamaha", 200, 600);

    carro1.mostrarInfo();
    moto1.mostrarInfo();

    return 0;
}

