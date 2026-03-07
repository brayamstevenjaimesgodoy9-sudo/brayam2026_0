
#include <iostream>
using namespace std;

bool buscar(int arr[],int tam,int valor){
    for(int i=0;i<tam;i++){
        if(arr[i]==valor){
            return true;
        }
    }
    return false;
}

int main(){
    int nums[]={1,5,9};
    if(buscar(nums,3,5)){
        cout<<"Existe";
    }else{
        cout<<"No existe";
    }
}
