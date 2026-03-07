#include <iostream>
using namespace std;

int* funcionBuena() {
    int* x = new int(50); // memoria dinámica
    return x;
}

int main() {
    int* ptr = funcionBuena();

    cout << *ptr << endl;

    delete ptr; // liberar memoria
    return 0;
}
