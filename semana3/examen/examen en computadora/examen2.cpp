#include <iostream>
using namespace std;

int main() {

    int opcion;
    int units;
    int unitPrice;
    int transactionCode;

    int ventasValidas = 0;
    int devoluciones = 0;
    int transInvalidas = 0;

    int mayorIng = 0;
    int menorIng = 0;
    int ingreso;
    int ingresoNeto = 0;

    int sumaVentas = 0;

    int diaCerrado = 0;

    long long codigosValidos = 0;
    long long auxCodigos;
    int codigoActual;

    do {
        cout << "1) Registrar transaccion\n";
        cout << "2) Reporte de ventas del dia\n";
        cout << "3) Reporte por transaccion (A / B / C / D)\n";
        cout << "4) Cerrar dia\n";
        cout << "5) Salir\n";
        cin >> opcion;

        // OPCION 1
        if (opcion == 1) {

            if (diaCerrado == 1) {
                cout << "NO SE PUEDEN REGISTRAR MAS TRANSACCIONES. DIA CERRADO.\n";
            } else {
                cin >> units >> unitPrice >> transactionCode;

                if (units != 0 && unitPrice > 0) {
                    ingreso = units * unitPrice;
                    ingresoNeto = ingresoNeto + ingreso;

                    codigosValidos = codigosValidos * 10000 + transactionCode * 10;

                    if (ventasValidas + devoluciones == 0) {
                        mayorIng = ingreso;
                        menorIng = ingreso;
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
        }

        // OPCION 2
        if (opcion == 2) {
            cout << "INGRESO_NETO=" << ingresoNeto << "\n";
            cout << "VENTAS_VALIDAS=" << ventasValidas << "\n";
            cout << "DEVOLUCIONES=" << devoluciones << "\n";
            cout << "TRANS_INVALIDAS=" << transInvalidas << "\n";
            cout << "MAYOR_ING=" << mayorIng << "\n";
            cout << "MENOR_ING=" << menorIng << "\n";

            if (ventasValidas > 0) {
                cout << "PROM_VENTA=" << (sumaVentas / ventasValidas) << "\n";
            } else {
                cout << "PROM_VENTA=NO EXISTE\n";
            }
        }

        // OPCION 3
        if (opcion == 3) {

            auxCodigos = codigosValidos;

            while (auxCodigos > 0) {

                codigoActual = (auxCodigos % 10000) / 10;
                auxCodigos = auxCodigos / 10000;

                int temp = codigoActual;
                if (temp < 0) temp = -temp;

                int sumaDig = 0;
                int digitos = 0;

                while (temp > 0) {
                    sumaDig = sumaDig + (temp % 10);
                    temp = temp / 10;
                    digitos++;
                }

                if (sumaDig % 2 == 0 && sumaDig % 4 == 0) {
                    cout << "A\n";
                } else if (sumaDig % 2 != 0 && sumaDig % 6 == 0) {
                    cout << "B\n";
                } else if (digitos == 3) {
                    cout << "C\n";
                } else {
                    cout << "D\n";
                }
            }
        }

        // OPCION 4
        if (opcion == 4) {
            diaCerrado = 1;
        }

    } while (opcion != 5);

    return 0;
}
