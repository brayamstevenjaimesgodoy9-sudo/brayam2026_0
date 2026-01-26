//ejericios del rombo
#include <stdio.h>
#include <math.h>
int main(){
int diagonalmayor= 8;
int diagonalmenor= 6;
int exponente = 2;
int area;
float lado;
float perimetro;
//area
area= (diagonalmayor * diagonalmenor) / 2;
printf("\n el area del rombo es: %d", area);
//lado
lado= sqrt (
    pow(diagonalmayor /2, exponente) + 
    pow(diagonalmenor / 2, exponente));
printf("\n el lado del rombo es: %.f", lado);
//perimetro
perimetro = lado * 4;
printf("\n el lado del rombo es: %.f", perimetro);
return 0;
}