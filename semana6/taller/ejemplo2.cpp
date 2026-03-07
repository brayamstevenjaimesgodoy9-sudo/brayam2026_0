#include <iostream>
#include <vector>
using namespace std;

/* =========================================================
   PASO 4: POLIMORFISMO ESTÁTICO
   ---------------------------------------------------------
   Función template que permite calcular eficiencia
   utilizando cualquier tipo numérico.
   Retorna: distancia / consumo
   ========================================================= */
template <typename T>
T calcularEficiencia(T consumo, T distancia) {
    return distancia / consumo;
}

/* =========================================================
   PASO 1: CLASE ABSTRACTA Vehiculo
   ---------------------------------------------------------
   - Contiene atributos comunes: id y velocidad
   - Método virtual puro moverse()
   - Método virtual mostrarInfo()
   - Destructor virtual
   - Declaración de clase amiga Reporte
   ========================================================= */
class Vehiculo {
protected:
    int id;             // Identificador del vehículo
    double velocidad;   // Velocidad del vehículo

public:
    // Constructor
    Vehiculo(int _id, double _velocidad)
        : id(_id), velocidad(_velocidad) {}

    // Método virtual puro (obliga a las clases hijas a implementarlo)
    virtual void moverse() = 0;

    // Método virtual que puede ser sobrescrito
    virtual void mostrarInfo() {
        cout << "ID: " << id << endl;
        cout << "Velocidad: " << velocidad << endl;
    }

    // Destructor virtual (importante para polimorfismo dinámico)
    virtual ~Vehiculo() {}

    // Declaración de clase amiga
    friend class Reporte;
};

/* =========================================================
   PASO 2: CLASE DERIVADA Auto
   ---------------------------------------------------------
   - Hereda de Vehiculo
   - Agrega atributo específico: puertas
   - Sobrescribe moverse() usando override
   ========================================================= */
class Auto : public Vehiculo {
private:
    int puertas; // Atributo específico

public:
    Auto(int _id, double _velocidad, int _puertas)
        : Vehiculo(_id, _velocidad), puertas(_puertas) {}

    void moverse() override {
        cout << "Auto moviendose en carretera." << endl;
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Puertas: " << puertas << endl;
    }
};

/* =========================================================
   PASO 2: CLASE DERIVADA Drone
   ---------------------------------------------------------
   - Hereda de Vehiculo
   - Agrega atributo específico: altitudMaxima
   - Sobrescribe moverse() usando override
   ========================================================= */
class Drone : public Vehiculo {
private:
    double altitudMaxima; // Atributo específico

public:
    Drone(int _id, double _velocidad, double _altitud)
        : Vehiculo(_id, _velocidad), altitudMaxima(_altitud) {}

    void moverse() override {
        cout << "Drone volando." << endl;
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Altitud Maxima: " << altitudMaxima << endl;
    }
};

/* =========================================================
   PASO 2: CLASE DERIVADA Camion
   ---------------------------------------------------------
   - Hereda de Vehiculo
   - Agrega atributo específico: capacidadCarga
   - Sobrescribe moverse() usando override
   ========================================================= */
class Camion : public Vehiculo {
private:
    double capacidadCarga; // Atributo específico

public:
    Camion(int _id, double _velocidad, double _capacidad)
        : Vehiculo(_id, _velocidad), capacidadCarga(_capacidad) {}

    void moverse() override {
        cout << "Camion transportando carga." << endl;
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Capacidad de Carga: " << capacidadCarga << endl;
    }
};

/* =========================================================
   PASO 5: CLASE AMIGA Reporte
   ---------------------------------------------------------
   - Puede acceder directamente a atributos protegidos
   - Genera un informe del vehículo
   ========================================================= */
class Reporte {
public:
    void generarReporte(Vehiculo* v) {
        cout << "===== REPORTE =====" << endl;
        cout << "ID: " << v->id << endl;          // Acceso directo
        cout << "Velocidad: " << v->velocidad << endl;
        cout << "===================" << endl;
    }
};

/* =========================================================
   PASO 3: POLIMORFISMO DINÁMICO (MAIN)
   ---------------------------------------------------------
   - Vector de punteros a Vehiculo
   - Se almacenan Auto, Drone y Camion
   - Se recorren llamando moverse() y mostrarInfo()
   ========================================================= */
int main() {

    vector<Vehiculo*> flota;

    // Almacenamiento de diferentes tipos en el mismo vector
    flota.push_back(new Auto(1, 120.0, 4));
    flota.push_back(new Drone(2, 80.0, 500.0));
    flota.push_back(new Camion(3, 90.0, 10000.0));

    cout << "=== POLIMORFISMO DINAMICO ===" << endl;

    for (Vehiculo* v : flota) {
        v->moverse();       // Llamada polimórfica
        v->mostrarInfo();   // Llamada polimórfica
        cout << endl;
    }

    /* =====================================================
       PASO 4: Uso del polimorfismo estático
       ===================================================== */
    double eficiencia = calcularEficiencia(10.0, 200.0);
    cout << "Eficiencia: " << eficiencia << endl;

    /* =====================================================
       PASO 5: Uso de la clase amiga
       ===================================================== */
    Reporte r;
    r.generarReporte(flota[0]);

    // Liberación de memoria dinámica
    for (Vehiculo* v : flota) {
        delete v;
    }

    return 0;
}
