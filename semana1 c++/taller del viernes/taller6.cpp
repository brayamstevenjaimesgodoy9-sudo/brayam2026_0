//ejercicios de triangulo inscrito
#include <stdio.h>
#include <math.h>
int main(){
    //area
   int lado1=9;
   int lado2=8;
   int lado3=7;
   int radio=6;
   float area;
   area=(lado1 * lado2 * lado3) / (4*6);
   printf("\n el area del triangulo inscrito es: %.f", area);
   
   return 0;
}