#include <iostream>
using namespace std;

int mayor(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int main(){
    cout << mayor(5,9);
    return 0;
}
