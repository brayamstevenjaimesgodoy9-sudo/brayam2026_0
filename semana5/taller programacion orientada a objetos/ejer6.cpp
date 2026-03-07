#include <iostream>

using namespace std;
class Persona {
public:
    virtual void rol() {
        cout << "Soy una persona" << endl;
    }
};

class Estudiante : public Persona {
public:
    void rol() override {
        cout << "Soy estudiante" << endl;
    }
};

class Profesor : public Persona {
public:
    void rol() override {
        cout << "Soy profesor" << endl;
    }
};

int main() {
    Persona* personas[2];
    personas[0] = new Estudiante();
    personas[1] = new Profesor();

    for (int i = 0; i < 2; i++) {
        personas[i]->rol();
    }
}
