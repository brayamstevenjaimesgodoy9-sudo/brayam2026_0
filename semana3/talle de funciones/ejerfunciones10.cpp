#include <iostream>
using namespace std;

bool ordenado(int arr[],int tam){
    for(int i=0;i<tam-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    int nums[]={1,2,3,4};
    if(ordenado(nums,4)){
        cout<<"Ordenado";
    }else{
        cout<<"No ordenado";
    }
}
