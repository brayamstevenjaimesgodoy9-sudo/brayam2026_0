#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

struct productos{
    string codigo;
    string descripcion;
    string unidad;
    int cantidad;
    double preciounitario;
};
struct factura{
    string numerofactura;
    string ruccliente;
    string nombrecliente;
    string direccioncliente;
    string fecha;
    productos* productos;
    int cantidadproductos;
};
struct usuario{
    string username;
    string passwordhash;
};
