#include <iostream>   
using namespace std;  

int main() {

    int N;                
    cin >> N;             

    int num;              
    int maximo, minimo;   

    int contarPrimos = 0; 

    int sumaParesPos = 0;  
    int contarParesPos = 0;

    int mayorEspecial;     
    bool existeEspecial = false; 

    Repetir N veces
    for (int i = 1; i <= N; i++) {

        cin >> num;  

        Si es el primer número, se toma como máximo y mínimo
        if (i == 1) {
            maximo = num;
            minimo = num;
        } else {
            Comparar para máximo
            if (num > maximo) {
                maximo = num;
            }

            Comparar para mínimo
            if (num < minimo) {
                minimo = num;
            }
        }

        -------- VER SI ES PRIMO --------
        if (num > 1) {           
            bool esPrimo = true; 

            Probar divisiones
            for (int d = 2; d < num; d++) {
                if (num % d == 0) { 
                    esPrimo = false;
                    break;          
                }
            }

            if (esPrimo) {
                contarPrimos++; 
            }
        }

        -------- PARES POSITIVOS --------
        if (num > 0 && num % 2 == 0) { 
            sumaParesPos += num;       
            contarParesPos++;          
        }

        -------- CONTAR DÍGITOS --------
        int copia = num;        
        if (copia < 0) {
            copia = -copia;     
        }

        int pares = 0;          
        int impares = 0;        

        Revisar dígito por dígito
        while (copia > 0) {
            int dig = copia % 10; 

            if (dig % 2 == 0) {
                pares++;          
            } else {
                impares++;        
            }

            copia = copia / 10;   
        }

        Si tiene más impares que pares
        if (impares > pares) {
            if (!existeEspecial || num > mayorEspecial) {
                mayorEspecial = num;   
                existeEspecial = true; 
            }
        }
    }

    -------- MOSTRAR RESULTADOS --------

    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;

    if (contarPrimos > 0) {
        cout << "Cantidad de primos: " << contarPrimos << endl;
    } else {
        cout << "Cantidad de primos: NO EXISTE" << endl;
    }

    if (contarParesPos > 0) {
        float promedio = (float)sumaParesPos / contarParesPos;
        cout << "Promedio de pares positivos: " << promedio << endl;
    } else {
        cout << "Promedio de pares positivos: NO EXISTE" << endl;
    }

    if (existeEspecial) {
        cout << "Mayor con mas digitos impares que pares: "
             << mayorEspecial << endl;
    } else {
        cout << "Mayor con mas digitos impares que pares: NO EXISTE" << endl;
    }

    return 0;
}