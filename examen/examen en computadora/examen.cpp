#include <iostream>
using namespace std;

int main() {

    int opcion;
    int units, unitPrice, transactionCode;
    int diaCerrado = 0;

    int ventasValidas = 0;
    int devoluciones = 0;
    int transInvalidas = 0;

    int ingreso;
    int ingresoNeto = 0;

    int mayorIng = 0;
    int menorIng = 0;
    int primerIngreso = 1;

    int sumaVentas = 0;

    int codigo;
    int temp;
    int sumaDigitos;
    int digitos;

    while (true) {

        cout << "\n1) Registrar transaccion\n";
        cout << "2) Reporte de ventas del dia\n";
        cout << "3) Reporte por transaccion\n";
        cout << "4) Cerrar dia\n";
        cout << "5) Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {

            if (diaCerrado == 1) {
                cout << "NO SE PUEDEN REGISTRAR MAS TRANSACCIONES. DIA CERRADO.\n";
            } else {
                cin >> units >> unitPrice >> transactionCode;

                if (units != 0 && unitPrice > 0) {

                    ingreso = units * unitPrice;
                    ingresoNeto = ingresoNeto + ingreso;

                    if (primerIngreso == 1) {
                        mayorIng = ingreso;
                        menorIng = ingreso;
                        primerIngreso = 0;
                    } else {
                        if (ingreso > mayorIng) mayorIng = ingreso;
                        if (ingreso < menorIng) menorIng = ingreso;
                    }

                    if (units > 0) {
                        ventasValidas++;
                        sumaVentas = sumaVentas + ingreso;
                    } else {
                        devoluciones++;
                    }

                } else {
                    transInvalidas++;
                }
            }

        } else if (opcion == 2) {

            cout << "INGRESO_NETO=" << ingresoNeto << endl;
            cout << "VENTAS_VALIDAS=" << ventasValidas << endl;
            cout << "DEVOLUCIONES=" << devoluciones << endl;
            cout << "TRANS_INVALIDAS=" << transInvalidas << endl;
            cout << "MAYOR_ING=" << mayorIng << endl;
            cout << "MENOR_ING=" << menorIng << endl;

            if (ventasValidas > 0) {
                cout << "PROM_VENTA=" << (sumaVentas / ventasValidas) << endl;
            } else {
                cout << "PROM_VENTA=NO EXISTE\n";
            }

        } else if (opcion == 3) {

            cin >> codigo;

            if (codigo < 0) codigo = -codigo;

            sumaDigitos = 0;
            digitos = 0;
            temp = codigo;

            if (temp == 0) {
                digitos = 1;
            }

            while (temp > 0) {
                sumaDigitos = sumaDigitos + (temp % 10);
                temp = temp / 10;
                digitos++;
            }

            if (sumaDigitos % 2 == 0 && codigo % 4 == 0) {
                cout << "A\n";
            } else if (sumaDigitos % 2 == 1 && codigo % 6 == 0) {
                cout << "B\n";
            } else if (digitos == 3) {
                cout << "C\n";
            } else {
                cout << "D\n";
            }

        } else if (opcion == 4) {

            diaCerrado = 1;
            cout << "DIA CERRADO\n";

        } else if (opcion == 5) {
            break;
        }
    }

    return 0;
}
