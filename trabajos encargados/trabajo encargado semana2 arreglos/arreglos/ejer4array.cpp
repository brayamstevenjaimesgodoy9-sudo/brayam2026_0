#include <iostream>
using namespace std;

int main() {

    int datos[8] = {-5, 10, 12, -3, 4, 6, 8, -2};

    int rachaActual = 0;
    int mayorRacha = 0;

    for(int i = 0; i < 8; i++){

        if(datos[i] > 0){
            rachaActual++;

            if(rachaActual > mayorRacha){
                mayorRacha = rachaActual;
            }
        }else{
            rachaActual = 0;
        }
    }

    cout << "Mayor racha positiva: " << mayorRacha << " dias" << endl;

    return 0;
}
