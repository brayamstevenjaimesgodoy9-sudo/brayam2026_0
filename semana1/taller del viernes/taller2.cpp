//ejercicio del rectangulo
#include <stdio.h>
#include <math.h>
int main(){
    //area del rectangulo
    int base = 8;
    int altura =6;
    int area;
    int perimetro;
    float diagonal;
    area = base * altura;
    printf("\n el area del rectangulo es: %d", area);
    
    //perimetro del rectandulo
    perimetro = 2 * (base + altura);
    printf("\n el perimetro del rectangulo es: %d", perimetro);
    //diagonal
    diagonal = sqrt(base * base + (altura * altura));
    printf ("\n la diagonal es: %.f", diagonal);
    
    
    
    
    return 0 ;
}