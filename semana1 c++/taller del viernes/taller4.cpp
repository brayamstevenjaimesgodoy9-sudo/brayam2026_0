//ejercicios del trapecio
#include <stdio.h>
#include <math.h>
int main(){
    //area
    int basemayor = 10;
    int basemenor = 6;
    int altura = 5;
    float area;
    area = ((basemayor + basemenor) * altura) / 2;
    printf("\n el area del tapecio es: %.f", area);
    return 0;
}