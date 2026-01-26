//triangulo de formula de heron
#include <stdio.h>
#include <math.h>
int main(){
    //semiperimetro
   int lado1=3;
   int lado2=7;
   int lado3=5;
   float area;
   float semiperimetro;
   semiperimetro=(lado1 + lado2 + lado3) / 2.0;
   printf("\n el semiperimetro del triangulo circunscrito es: %.1f", semiperimetro);
   //area
   area = sqrt(semiperimetro*(semiperimetro-lado1)*(semiperimetro - lado2)*(semiperimetro - lado3));
   printf("\n el area de Triangulo circunscrito: %.9f", area); 
   return 0;
}