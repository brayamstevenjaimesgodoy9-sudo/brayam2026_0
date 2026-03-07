#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>

using namespace std;

/* ===============================
   EXCEPCIÓN PERSONALIZADA
=================================*/
class CuentaNoEncontrada : public runtime_error {
public:
    CuentaNoEncontrada() : runtime_error("Cuenta no encontrada.") {}
};

/* ===============================
   CLASE CUENTA BANCARIA
=================================*/
class CuentaBancaria {
private:
    int numeroCuenta;
    string titular;
    double saldo;

public:
    CuentaBancaria(int numero, string nombre, double saldoInicial)
        : numeroCuenta(numero), titular(nombre), saldo(saldoInicial) {}

    void depositar(double monto) {
        if (monto <= 0)
            throw invalid_argument("El monto a depositar no puede ser negativo o cero.");
        saldo += monto;
    }

    void retirar(double monto) {
        if (monto <= 0)
            throw invalid_argument("El monto a retirar no puede ser negativo o cero.");
        if (monto > saldo)
            throw runtime_error("Fondos insuficientes.");
        saldo -= monto;
    }

    void consultarSaldo() const {
        cout << "Saldo actual: " << saldo << endl;
    }

    int getNumeroCuenta() const {
        return numeroCuenta;
    }

    void mostrarInformacion() const {
        cout << "Numero de cuenta: " << numeroCuenta << endl;
        cout << "Titular: " << titular << endl;
        cout << "Saldo: " << saldo << endl;
        cout << "------------------------" << endl;
    }
};

/* ===============================
   CLASE BANCO
=================================*/
class Banco {
private:
    vector<CuentaBancaria> cuentas;

public:
    void agregarCuenta(const CuentaBancaria& cuenta) {
        cuentas.push_back(cuenta);
    }

    CuentaBancaria& buscarCuenta(int numero) {
        for (auto& cuenta : cuentas) {
            if (cuenta.getNumeroCuenta() == numero)
                return cuenta;
        }
        throw CuentaNoEncontrada();
    }

    void mostrarCuentas() const {
        for (const auto& cuenta : cuentas)
            cuenta.mostrarInformacion();
    }
};

/* ===============================
   FUNCIÓN PRINCIPAL
=================================*/
int main() {
    Banco banco;
    int opcion;

    do {
        cout << "\n1. Crear cuenta\n";
        cout << "2. Depositar dinero\n";
        cout << "3. Retirar dinero\n";
        cout << "4. Consultar saldo\n";
        cout << "5. Mostrar todas las cuentas\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Debe ingresar un numero.\n";
            continue;
        }

        try {
            if (opcion < 1 || opcion > 6)
                throw out_of_range("Opcion invalida.");

            switch (opcion) {

            case 1: {
                int numero;
                string nombre;
                double saldo;

                cout << "Numero de cuenta: ";
                cin >> numero;

                cout << "Titular: ";
                cin >> nombre;

                cout << "Saldo inicial: ";
                cin >> saldo;

                banco.agregarCuenta(CuentaBancaria(numero, nombre, saldo));
                cout << "Cuenta creada correctamente.\n";
                break;
            }

            case 2: {
                int numero;
                double monto;

                cout << "Numero de cuenta: ";
                cin >> numero;

                cout << "Monto a depositar: ";
                cin >> monto;

                banco.buscarCuenta(numero).depositar(monto);
                cout << "Deposito realizado.\n";
                break;
            }

            case 3: {
                int numero;
                double monto;

                cout << "Numero de cuenta: ";
                cin >> numero;

                cout << "Monto a retirar: ";
                cin >> monto;

                banco.buscarCuenta(numero).retirar(monto);
                cout << "Retiro realizado.\n";
                break;
            }

            case 4: {
                int numero;
                cout << "Numero de cuenta: ";
                cin >> numero;

                banco.buscarCuenta(numero).consultarSaldo();
                break;
            }

            case 5:
                banco.mostrarCuentas();
                break;

            case 6:
                cout << "Saliendo del sistema...\n";
                break;
            }

        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const CuentaNoEncontrada& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (opcion != 6);

    return 0;
}
