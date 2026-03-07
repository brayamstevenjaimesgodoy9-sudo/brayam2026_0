#include <iostream>
using namespace std;

int maximo(int arr[], int tam){
    int max=arr[0];
    for(int i=1;i<tam;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int main(){
    int nums[]={3,7,2,9};
    cout<<maximo(nums,4);
}
