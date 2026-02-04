#include <iostream>
using namespace std;

int main() {

    int temp[7] = {28, 31, 29, 35, 33, 30, 27};

    int max = temp[0];
    int min = temp[0];
    int diaMax = 1;
    int diaMin = 1;
    int mayores30 = 0;

    for(int i = 0; i < 7; i++){

        if(temp[i] > max){
            max = temp[i];
            diaMax = i + 1;
        }

        if(temp[i] < min){
            min = temp[i];
            diaMin = i + 1;
        }

        if(temp[i] > 30){
            mayores30++;
        }
    }

    cout << "Maxima: " << max << " (dia " << diaMax << ")" << endl;
    cout << "Minima: " << min << " (dia " << diaMin << ")" << endl;
    cout << "Dias mayores a 30: " << mayores30 << endl;

    return 0;
}
