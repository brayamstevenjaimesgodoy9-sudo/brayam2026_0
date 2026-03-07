#include <iostream>
using namespace std;

int suma(int arr[], int tam){
    int total = 0;
    for(int i=0;i<tam;i++){
        total += arr[i];
    }
    return total;
}

int main(){
    int numeros[]={1,2,3,4};
    cout<<suma(numeros,4);
}
