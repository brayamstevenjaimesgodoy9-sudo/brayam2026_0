//Triangulo circunscrito
#include <stdio.h>
#include <math.h>
int main(){
    //semiperimetro
   int lado1=9;
   int lado2=12;
   int lado3=15;
   int radio=6;
   float area;
   float semiperimetro;
   semiperimetro=(lado1 + lado2 + lado3) / 2;
   printf("\n el semiperimetro del triangulo circunscrito es: %.f", semiperimetro);
   //area
   area = radio * semiperimetro;
   printf("\n el area de Triangulo circunscrito: %.f", area); 
   return 0;
}