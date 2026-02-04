//ejercicios del triangulo
#include <stdio.h>
#include <math.h>
int main(){
    //area
   int lado1=9;
   int lado2=6;
   int base =8;
   int altura=6;
   float area;
   float perimetro;
   area=(base*altura) / 2;
   printf("\n el area del triangulo es: %.f", area);
   //perimetro
   perimetro = lado1 + base + lado2;
   printf("\n el perimetro es: %.f", perimetro);
   return 0;
}