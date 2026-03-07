#include <iostream>
using namespace std;

bool esPar(int num){
    return num % 2 == 0;
}

int main(){
    if(esPar(4)){
        cout<<"Par";
    }else{
        cout<<"Impar";
    }
}
