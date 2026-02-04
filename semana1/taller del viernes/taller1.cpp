//ejercicios 1 : cuadrado lado, ara, perietro, diagonal
#include <stdio.h>
#include <math.h>
int main(){
    //area
    int lado = 6 ;
    int area;
    int exponente = 2;
    int perimetro;
    float diagonal;
    area = pow(lado, exponente);
    //cout <<"el resultado es: " << endl << area;
    printf("el resultado es: %d", area);

    // perimetro
    perimetro=lado * 4;
    printf("\n el perimetro es: %d", perimetro);
    
    //diagonal
    diagonal =lado * sqrt(2);
    printf("\n la diagonal: %.4f",diagonal);
    return 0 ;
}
