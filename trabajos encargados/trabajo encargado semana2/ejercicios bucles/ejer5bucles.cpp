//Serie Fibonacci (primeros 20 números)
#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 1, c;

    cout << "Serie Fibonacci:\n";
    for (int i = 1; i <= 20; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}
