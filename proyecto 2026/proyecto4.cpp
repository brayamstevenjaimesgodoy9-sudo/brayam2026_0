#include <iostream>// Permite usar entrada y salida de datos (cout, cin)
#include <string>// Permite usar texto (string)
using namespace std;// Evita escribir std:: antes de cada cosa
int main(){// Inicio del programa
   cout <<"multiservicios namekusei";

    string nombres[100];// Guarda nombres
    float precios[100];// Guarda precios
    int cantidades[100];// Guarda cantidades
    int totalproductos = 0;// No hay productos al inicio
    
    int opcion;// Guarda la opción del menú
    do{// Repite hasta salir
        mostrarmenu();// Muestra el menú
        cin >> opcion;// Lee la opción

        switch (opcion)// Decide qué hacer
        {
        case 1:
            agregarproducto(nombres, precios, cantidades, totalproductos);
            break;
        case 2:
            mostrarproductos(nombres, precios, cantidades, totalproductos);
            break;
        case 3:
            venderproductos(nombres, precios, cantidades, totalproductos);
            break;
        case 4:
            cout << "hasta pronto cliente: ";
            break;
        default:
            cout <<"ingrese la opcion corecta.\n";
        }
    } while (opcion !=4);// Se repite hasta salir

    return 0;// Fin correcto del programa
    
}
void mostrarmenu(){// Función que solo muestra el menú
    cout <<"\n --- menu --- \n";// Muestra el título del menú
    cout <<"agregar producto\n";// Opción 1
    cout <<"mostrar productos\n"; // Opción 2
    cout <<"vender productos\n"; // Opción 3
    cout <<"salir\n"; // Opción 4
    cout <<"seleccione una opcion";// Pide al usuario elegir
}
void agregarproducto(string nombre[], float precios[],int cantidades[], int totalproductos){// Arreglo de nombres
    // Arreglo de precios    // Arreglo de cantidades
    cout << "nombre del producto";// Pide el nombre
    cin>> nombre[totalproductos];// Guarda el nombre

    cout <<"precio: ";// Pide el precio
    cin >> precios[totalproductos];// Guarda el precio
    cout <<"cantidad: ";// Pide la cantidad
    cin >> cantidades[totalproductos];// Guarda la cantidad
    totalproductos++;// Aumenta el total de productos
    cout <<"producto agrgado exitoso:\n";// Confirma al usuario
}


void mostrarproductos(string nombre[], float precios[], int cantidades[], int totalproductos){
    // Arreglo de nombres  // Arreglo de precios // Arreglo de cantidades   // Cantidad total de productos
    if(totalproductos == 0){ // Si no hay productos
        cout <<"no hay productos en el almacen:\n";// Mensaje
        return;// Sale de la función
    }
    for (int i=0; i< totalproductos;i++){// Recorre todos los productos
        cout << i + 1 <<". ";// Muestra número del producto
        cout << nombre[i]<<"precio: ";// Muestra nombre
        cout << precios[i]<< "cantidad: ";// Muestra precio
        cout << cantidades[i] << endl;// Muestra cantidad
        }
}

void venderproductos(string nombres[], float precios[], int cantidades[], int totalproductos){
    // Arreglo de nombres  // Arreglo de precios  // Arreglo de cantidades   // Total de productos 
    int opcion, cantidadvendidas;// Producto elegido  // Cantidad a vender
    mostrarproductos(nombres, precios, cantidades, totalproductos);// Muestra productos
    cout <<"seleccione el producto a vender: "; // Pide el producto
    cin >> opcion;// Lee la opción
    opcion--;//ajustar el indice
    if(opcion < 0 || opcion >= totalproductos){// Valida la opción
        cout <<"productos invalido. \n";// Mensaje de error
        return;// Sale de la función
    }
    cout <<"cantidad a vender:";// Pide cantidad
    cin >> cantidadvendidas;// Lee cantidad
    if(cantidadvendidas > cantidades[opcion]){// Verifica stock
        cout << "no hay suficiente productos.\n";// Error
        return;// Sale
    }
    cantidades[opcion] -= cantidadvendidas;// Resta del inventario
    float total=cantidadvendidas * precios[opcion];// Calcula total a pagar
    cout << "total a pagar: "<<total << endl;// Muestra el total
}
