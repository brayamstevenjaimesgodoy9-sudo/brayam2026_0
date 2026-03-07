#include <iostream>
using namespace std;

int main() {

    int asistencia[3][5] = {
        {1,1,1,1,1},
        {1,0,1,1,1},
        {1,1,0,1,0}
    };

    int totalAula = 0;

    for(int i = 0; i < 3; i++){
        int totalEstudiante = 0;

        for(int j = 0; j < 5; j++){
            totalEstudiante += asistencia[i][j];
            totalAula += asistencia[i][j];
        }

        cout << "Asistencia del estudiante " << i+1 << ": " << totalEstudiante << endl;

        if(totalEstudiante == 5){
            cout << "Estudiante " << i+1 << " tiene asistencia perfecta." << endl;
        }
    }

    cout << "Total de asistencias del aula: " << totalAula << endl;

    return 0;
}
