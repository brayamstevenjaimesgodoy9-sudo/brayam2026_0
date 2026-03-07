#include <iostream>
using namespace std;

double promedio(int arr[], int tam){
    int suma=0;
    for(int i=0;i<tam;i++){
        suma+=arr[i];
    }
    return (double)suma/tam;
}

int main(){
    int notas[]={80,90,70};
    cout<<promedio(notas,3);
}
