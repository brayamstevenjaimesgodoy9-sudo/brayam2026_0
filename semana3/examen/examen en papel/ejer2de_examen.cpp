#include <iostream>
using namespace std;

int main() {

    int M;
    cin >> M;  

    int x;

    for (int i = 1; i <= M; i++) {

        cin >> x;   

        
        int copia = x;

        if (copia < 0)
            copia = -copia;   

        int suma = 0;

        while (copia > 0) {
            int dig = copia % 10; 
            suma += dig;          
            copia /= 10;         
        }

        
        int absX = x;
        if (absX < 0)
            absX = -absX;

        bool tiene3 = (absX >= 100 && absX <= 999);

        

        
        if (suma % 2 == 0 && x % 4 == 0) {
            cout << "A" << endl;
        }

        
        else if (suma % 2 != 0 && x % 6 == 0) {
            cout << "B" << endl;
        }

        
        else if (tiene3) {
            cout << "C" << endl;
        }

        
        else {
            cout << "D" << endl;
        }
    }

    return 0;
}
