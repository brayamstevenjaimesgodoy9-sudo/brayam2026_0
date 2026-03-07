#include <iostream>
using namespace std;

bool validar(int op,int min,int max){
    return op>=min && op<=max;
}

int main(){
    if(validar(2,1,5)){
        cout<<"Valida";
    }else{
        cout<<"No valida";
    }
}
