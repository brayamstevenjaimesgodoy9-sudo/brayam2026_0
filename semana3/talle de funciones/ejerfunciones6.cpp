#include <iostream>
using namespace std;

int minimo(int arr[], int tam){
    int min=arr[0];
    for(int i=1;i<tam;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}

int main(){
    int nums[]={3,7,2,9};
    cout<<minimo(nums,4);
}
