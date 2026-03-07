// ============================================================
// SISTEMA DE CLÍNICA MÉDICA - C++
// ============================================================

#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <map>
#include <regex>
#include <algorithm>

using namespace std;

// ============================================================
// [REQ-5] EXCEPCIÓN PERSONALIZADA (clase propia heredando runtime_error)
// Lanzada cuando no se encuentra Paciente, Doctor o Cita
// ============================================================
class EntidadNoEncontrada : public runtime_error {
public:
    EntidadNoEncontrada(string msg) : runtime_error(msg) {}
};

// ============================================================
// [REQ-6] CLASE BASE Persona (abstracta/concreta con virtual)
// [REQ-7] PUNTERO #1: se usará vector<unique_ptr<Persona>>
//          para demostrar polimorfismo
// ============================================================
class Persona {
protected:
    string nombre;
public:
    // Constructor
    Persona(string n) : nombre(n) {}

    // [MÉTODO 1] getter de nombre
    string getNombre() const { return nombre; }

    // [MÉTODO 2] mostrar() virtual → permite polimorfismo
    virtual void mostrar() const {
        cout << "Nombre: " << nombre << endl;
    }

    // Destructor virtual obligatorio en clases base con virtual
    virtual ~Persona() = default;
};

// ============================================================
// [REQ-6] CLASE EntradaHistoria
// ============================================================
class EntradaHistoria {
public:
    string fecha;
    string nota;
    string diagnostico;

    EntradaHistoria(string f, string n, string d)
        : fecha(f), nota(n), diagnostico(d) {}
};

// ============================================================
// [REQ-6] CLASE HistoriaClinica (composición dentro de Paciente)
// ============================================================
class HistoriaClinica {
    vector<EntradaHistoria> entradas;
public:
    // [MÉTODO 3] agregar entrada a la historia
    void agregarEntrada(EntradaHistoria e) {
        entradas.push_back(e);
    }

    // [MÉTODO 4] mostrar todas las entradas
    void mostrar() const {
        if (entradas.empty()) {
            cout << "  (Sin entradas en historia clinica)" << endl;
            return;
        }
        for (const auto& e : entradas) {
            cout << "  Fecha: " << e.fecha
                 << " | Nota: " << e.nota
                 << " | Diagnostico: " << e.diagnostico << endl;
        }
    }
};

// ============================================================
// [REQ-6] CLASE Paciente : Persona
// [REQ-4] Validaciones: DNI 8 dígitos numéricos, edad 0-120,
//          teléfono 9 dígitos numéricos
// ============================================================
class Paciente : public Persona {
    string dni;
    int    edad;
    string telefono;
    HistoriaClinica historia;   // composición

public:
    Paciente(string n, string d, int e, string t)
        : Persona(n), dni(d), edad(e), telefono(t)
    {
        // [REQ-4] Validación DNI: exactamente 8 dígitos numéricos
        // [REQ-5] std::invalid_argument para datos inválidos
        if (d.length() != 8 || !regex_match(d, regex("\\d{8}")))
            throw invalid_argument("DNI invalido: debe tener exactamente 8 digitos numericos");

        // [REQ-4] Validación edad 0-120
        if (e < 0 || e > 120)
            throw invalid_argument("Edad invalida: debe estar entre 0 y 120");

        // [REQ-4] Validación teléfono: 9 dígitos numéricos
        if (t.length() != 9 || !regex_match(t, regex("\\d{9}")))
            throw invalid_argument("Telefono invalido: debe tener exactamente 9 digitos numericos");
    }

    // [MÉTODO 5] getDni — getter del DNI
    string getDni() const { return dni; }

    // [MÉTODO 6] mostrar() override → polimorfismo
    void mostrar() const override {
        cout << "Paciente -> Nombre: " << nombre
             << " | DNI: " << dni
             << " | Edad: " << edad
             << " | Tel: " << telefono << endl;
    }

    // [MÉTODO 7] agregar entrada a historia clínica
    void agregarHistoria(EntradaHistoria e) {
        historia.agregarEntrada(e);
    }

    // Mostrar historia clínica del paciente
    void mostrarHistoria() const {
        cout << "Historia clinica de " << nombre << ":" << endl;
        historia.mostrar();
    }
};

// ============================================================
// [REQ-6] CLASE Doctor : Persona
// [REQ-4] Validación tarifa > 0
// ============================================================
class Doctor : public Persona {
    string codigo;
    string especialidad;
    double tarifa;

public:
    Doctor(string n, string c, string esp, double t)
        : Persona(n), codigo(c), especialidad(esp), tarifa(t)
    {
        // [REQ-4] Tarifa debe ser positiva
        // [REQ-5] std::invalid_argument
        if (t <= 0)
            throw invalid_argument("Tarifa invalida: debe ser mayor a 0");
    }

    // [MÉTODO 8] getCodigo — getter del código
    string getCodigo() const { return codigo; }

    // [MÉTODO 9] getEspecialidad
    string getEspecialidad() const { return especialidad; }

    // [MÉTODO 10] getTarifa
    double getTarifa() const { return tarifa; }

    // mostrar() override → polimorfismo
    void mostrar() const override {
        cout << "Doctor -> Nombre: " << nombre
             << " | Codigo: " << codigo
             << " | Especialidad: " << especialidad
             << " | Tarifa: S/." << tarifa << endl;
    }
};

// ============================================================
// [REQ-6] CLASE Cita
// [REQ-7] PUNTERO #2: Paciente* y Doctor* como punteros observadores
//          (la propiedad la tiene Clinica con shared_ptr)
// ============================================================
class Cita {
public:
    int       id;
    Paciente* paciente;   // [PUNTERO OBSERVADOR] no posee la memoria
    Doctor*   doctor;     // [PUNTERO OBSERVADOR] no posee la memoria
    string    fecha;
    string    hora;
    string    motivo;
    string    estado;

    Cita(int i, Paciente* p, Doctor* d, string f, string h, string m)
        : id(i), paciente(p), doctor(d), fecha(f), hora(h), motivo(m)
    {
        estado = "ACTIVA";
    }

    // [MÉTODO 11] cancelar cita
    void cancelar() {
        if (estado == "CANCELADA")
            throw runtime_error("La cita ya estaba cancelada");
        estado = "CANCELADA";
    }

    // [MÉTODO 12] mostrar cita
    void mostrar() const {
        cout << "Cita #" << id
             << " | Paciente: " << paciente->getNombre()
             << " | Doctor: "   << doctor->getNombre()
             << " | " << fecha  << " " << hora
             << " | Motivo: "   << motivo
             << " | Estado: "   << estado << endl;
    }
};

// ============================================================
// [REQ-6] CLASE Reporte — genera estadísticas desde Clinica
// ============================================================
class Reporte {
public:
    // [MÉTODO 13] reporte de citas por especialidad
    static void reportePorEspecialidad(const vector<shared_ptr<Cita>>& citas) {
        map<string, int> conteo;
        for (const auto& c : citas) {
            if (c->estado == "ACTIVA")
                conteo[c->doctor->getEspecialidad()]++;
        }
        cout << "\n=== REPORTE POR ESPECIALIDAD (citas activas) ===" << endl;
        if (conteo.empty()) {
            cout << "No hay citas activas." << endl;
            return;
        }
        for (const auto& par : conteo)
            cout << "  " << par.first << ": " << par.second << " cita(s)" << endl;
    }
};

// ============================================================
// [REQ-3] Función auxiliar de validación de formato fecha/hora
// ============================================================

// [REQ-4] Valida formato YYYY-MM-DD
bool validarFecha(const string& f) {
    return regex_match(f, regex("\\d{4}-\\d{2}-\\d{2}"));
}

// [REQ-4] Valida formato HH:MM
bool validarHora(const string& h) {
    return regex_match(h, regex("\\d{2}:\\d{2}"));
}

// ============================================================
// [REQ-6] CLASE Clinica — contenedor principal con CRUD
// [REQ-7] PUNTERO #1 en uso: vector<shared_ptr<Paciente/Doctor>>
//          y vector<unique_ptr<Persona>> para polimorfismo
// ============================================================
class Clinica {

    // Contenedores con smart pointers (ownership)
    vector<shared_ptr<Paciente>> pacientes;
    vector<shared_ptr<Doctor>>   doctores;
    vector<shared_ptr<Cita>>     citas;

    // [PUNTERO POLIMÓRFICO] vector de punteros a clase base Persona
    // Demuestra polimorfismo con unique_ptr<Persona>
    vector<unique_ptr<Persona>> personas; // espejo para demostrar polimorfismo

    int contadorCitas = 1;

public:

    // --------------------------------------------------------
    // [MÉTODO 14] Registrar paciente con todas las validaciones
    // --------------------------------------------------------
    void registrarPaciente() {
        string nombre, dni, telefono;
        int edad;

        cout << "Nombre: ";   cin >> nombre;
        cout << "DNI: ";      cin >> dni;
        cout << "Edad: ";     cin >> edad;
        cout << "Telefono: "; cin >> telefono;

        // El constructor lanza invalid_argument si hay error
        auto p = make_shared<Paciente>(nombre, dni, edad, telefono);
        pacientes.push_back(p);

        // [PUNTERO POLIMÓRFICO] Agrega copia a vector<unique_ptr<Persona>>
        personas.push_back(make_unique<Paciente>(nombre, dni, edad, telefono));

        cout << "Paciente registrado exitosamente." << endl;
    }

    // --------------------------------------------------------
    // [MÉTODO 15] Registrar doctor con validaciones
    // --------------------------------------------------------
    void registrarDoctor() {
        string nombre, codigo, esp;
        double tarifa;

        cout << "Nombre: ";       cin >> nombre;
        cout << "Codigo: ";       cin >> codigo;
        cout << "Especialidad: "; cin >> esp;
        cout << "Tarifa: ";       cin >> tarifa;

        auto d = make_shared<Doctor>(nombre, codigo, esp, tarifa);
        doctores.push_back(d);

        // [PUNTERO POLIMÓRFICO] Agrega al vector polimórfico
        personas.push_back(make_unique<Doctor>(nombre, codigo, esp, tarifa));

        cout << "Doctor registrado exitosamente." << endl;
    }

    // --------------------------------------------------------
    // [MÉTODO 16] Buscar paciente por DNI
    // [REQ-5] Lanza EntidadNoEncontrada (excepción personalizada)
    // --------------------------------------------------------
    Paciente* buscarPaciente(const string& dni) {
        for (auto& p : pacientes)
            if (p->getDni() == dni) return p.get(); // raw pointer observador

        throw EntidadNoEncontrada("Paciente con DNI " + dni + " no encontrado");
    }

    // --------------------------------------------------------
    // [MÉTODO 17] Buscar doctor por índice
    // [REQ-5] Lanza out_of_range si índice inválido
    // --------------------------------------------------------
    Doctor* buscarDoctor(int idx) {
        if (idx < 0 || idx >= (int)doctores.size())
            throw out_of_range("Indice de doctor invalido: " + to_string(idx));
        return doctores[idx].get(); // raw pointer observador
    }

    // --------------------------------------------------------
    // [MÉTODO 18] Agendar cita con todas las validaciones
    // [REQ-4] Valida fecha/hora + no duplicados
    // --------------------------------------------------------
    void agendarCita() {
        string dni, fecha, hora, motivo;
        int doctorIdx;

        cout << "DNI paciente: "; cin >> dni;
        Paciente* p = buscarPaciente(dni); // lanza EntidadNoEncontrada si no existe

        // Mostrar doctores disponibles
        cout << "Doctores disponibles:" << endl;
        for (int i = 0; i < (int)doctores.size(); i++) {
            cout << "  [" << i << "] ";
            doctores[i]->mostrar();
        }

        cout << "Indice doctor: "; cin >> doctorIdx;
        Doctor* d = buscarDoctor(doctorIdx); // lanza out_of_range si inválido

        cout << "Fecha (YYYY-MM-DD): "; cin >> fecha;
        // [REQ-4] Validar formato fecha
        // [REQ-5] invalid_argument si formato incorrecto
        if (!validarFecha(fecha))
            throw invalid_argument("Formato de fecha invalido. Use YYYY-MM-DD");

        cout << "Hora (HH:MM): "; cin >> hora;
        // [REQ-4] Validar formato hora
        if (!validarHora(hora))
            throw invalid_argument("Formato de hora invalido. Use HH:MM");

        cout << "Motivo: "; cin >> motivo;

        // [REQ-4] No permitir cita duplicada (mismo doctor + fecha + hora)
        // [REQ-5] runtime_error para operación inválida
        for (const auto& c : citas)
            if (c->doctor == d && c->fecha == fecha && c->hora == hora && c->estado == "ACTIVA")
                throw runtime_error("Cita duplicada: ese doctor ya tiene una cita en esa fecha y hora");

        citas.push_back(make_shared<Cita>(contadorCitas++, p, d, fecha, hora, motivo));
        cout << "Cita agendada exitosamente (ID: " << contadorCitas - 1 << ")" << endl;
    }

    // --------------------------------------------------------
    // [MÉTODO 19] Cancelar cita por ID
    // [REQ-5] EntidadNoEncontrada si no existe la cita
    // --------------------------------------------------------
    void cancelarCita() {
        int id;
        cout << "ID de cita a cancelar: "; cin >> id;

        for (auto& c : citas) {
            if (c->id == id) {
                c->cancelar(); // lanza runtime_error si ya estaba cancelada
                cout << "Cita #" << id << " cancelada." << endl;
                return;
            }
        }
        throw EntidadNoEncontrada("Cita con ID " + to_string(id) + " no encontrada");
    }

    // --------------------------------------------------------
    // [MÉTODO 20] Listar citas de un paciente por DNI
    // --------------------------------------------------------
    void listarCitasPorPaciente() {
        string dni;
        cout << "DNI paciente: "; cin >> dni;
        Paciente* p = buscarPaciente(dni);

        cout << "\n=== Citas de " << p->getNombre() << " ===" << endl;
        bool encontrado = false;
        for (const auto& c : citas) {
            if (c->paciente == p) {
                c->mostrar();
                encontrado = true;
            }
        }
        if (!encontrado)
            cout << "No tiene citas registradas." << endl;
    }

    // --------------------------------------------------------
    // [MÉTODO 21] Listar citas de un doctor por índice
    // --------------------------------------------------------
    void listarCitasPorDoctor() {
        int idx;
        cout << "Doctores disponibles:" << endl;
        for (int i = 0; i < (int)doctores.size(); i++) {
            cout << "  [" << i << "] ";
            doctores[i]->mostrar();
        }
        cout << "Indice doctor: "; cin >> idx;
        Doctor* d = buscarDoctor(idx);

        cout << "\n=== Citas del Dr. " << d->getNombre() << " ===" << endl;
        bool encontrado = false;
        for (const auto& c : citas) {
            if (c->doctor == d) {
                c->mostrar();
                encontrado = true;
            }
        }
        if (!encontrado)
            cout << "No tiene citas registradas." << endl;
    }

    // --------------------------------------------------------
    // [MÉTODO 22] Reporte por especialidad (delega a clase Reporte)
    // --------------------------------------------------------
    void reportePorEspecialidad() {
        Reporte::reportePorEspecialidad(citas);
    }

    // --------------------------------------------------------
    // [MÉTODO 23] Demostración explícita de polimorfismo
    // Itera vector<unique_ptr<Persona>> y llama mostrar() virtual
    // --------------------------------------------------------
    void listarPersonas() {
        cout << "\n=== TODAS LAS PERSONAS (polimorfismo) ===" << endl;
        for (const auto& per : personas)
            per->mostrar(); // despacho dinámico: Paciente::mostrar o Doctor::mostrar
    }
};

// ============================================================
// [REQ-3] MENÚ PRINCIPAL — no se cae ante errores
// ============================================================
int main() {

    Clinica clinica;
    int op;

    while (true) {
        try {
            cout << "\n========== CLINICA MEDICA ==========\n";
            cout << "1) Registrar paciente\n";
            cout << "2) Registrar doctor\n";
            cout << "3) Agendar cita\n";
            cout << "4) Cancelar cita\n";
            cout << "5) Listar citas por paciente\n";
            cout << "6) Listar citas por doctor\n";
            cout << "7) Reporte por especialidad\n";
            cout << "8) Salir\n";
            cout << "Opcion: ";
            cin >> op;

            // [REQ-5] out_of_range para opción fuera de rango
            if (op < 1 || op > 8)
                throw out_of_range("Opcion invalida. Ingrese entre 1 y 8");

            if      (op == 1) clinica.registrarPaciente();
            else if (op == 2) clinica.registrarDoctor();
            else if (op == 3) clinica.agendarCita();
            else if (op == 4) clinica.cancelarCita();
            else if (op == 5) clinica.listarCitasPorPaciente();
            else if (op == 6) clinica.listarCitasPorDoctor();
            else if (op == 7) clinica.reportePorEspecialidad();
            else if (op == 8) {
                cout << "Saliendo del sistema..." << endl;
                break;
            }

        }
        // [REQ-3] Captura todas las excepciones → el menú NO se cae
        catch (const EntidadNoEncontrada& e) {
            cout << "[ERROR - No encontrado] " << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cout << "[ERROR - Dato invalido] " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << "[ERROR - Fuera de rango] " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "[ERROR - Operacion invalida] " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "[ERROR] " << e.what() << endl;
        }
    }

    return 0;
}