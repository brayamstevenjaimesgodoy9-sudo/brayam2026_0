#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setEdad(int edad) {
        if (edad >= 0)
            this->edad = edad;
    }

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};
/*parte b*/

class Estudiante : public Persona {
private:
    string carrera;

public:
    void setCarrera(string carrera) {
        this->carrera = carrera;
    }

    void estudiar() {
        cout << "Estoy estudiando..." << endl;
    }
};

class Profesor : public Persona {
private:
    string materia;

public:
    void setMateria(string materia) {
        this->materia = materia;
    }

    void ensenar() {
        cout << "Estoy educando..." << endl;
    }
};
/*parte c*/

int main() {
    Estudiante e;
    e.setNombre("Carlos");
    e.setEdad(20);
    e.setCarrera("Ingenieria");
    e.mostrar();
    e.estudiar();

    Profesor p;
    p.setNombre("Ana");
    p.setEdad(40);
    p.setMateria("Matematicas");
    p.mostrar();
    p.ensenar();

    return 0;
}

