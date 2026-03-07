/*******************************************************
==================== BITÁCORA IA ====================

Herramienta IA usada: ChatGPT

Objetivo del uso:
Utilicé la IA como apoyo para diseñar un sistema de biblioteca
en C++ aplicando memoria dinámica, punteros, referencias,
structs y persistencia en archivos de texto, asegurando que
el programa compile correctamente en C++17.

---

Preguntas que hice a la IA (resumen):

1. ¿Cómo implementar arreglos dinámicos sin usar vector y
   permitir que crezcan cuando se llenen?

2. ¿Cuál es la forma correcta de retornar un puntero desde
   una función de búsqueda sin provocar errores de memoria?

3. ¿Cómo guardar y cargar información de structs en un
   archivo .txt de forma simple y segura?

4. ¿Cómo evitar fugas de memoria cuando uso new[]?

5. ¿Qué validaciones mínimas debe tener un sistema de
   préstamos para que sea robusto?

---

Qué sugerencias acepté y por qué:

✔ Usar duplicación de capacidad (cap *= 2) al redimensionar
los arreglos porque mejora el rendimiento y evita
redimensionamientos constantes.

✔ Retornar nullptr cuando un elemento no existe para
prevenir desreferenciación de memoria inválida.

✔ Separar el programa en funciones con responsabilidad
única para mejorar la legibilidad y el mantenimiento.

✔ Guardar los datos en archivos de texto usando el
carácter '|' como delimitador porque facilita la lectura
y reconstrucción de los objetos.

✔ Liberar toda la memoria con delete[] antes de finalizar
el programa para evitar memory leaks.

---

Qué sugerencias rechacé y por qué:

✘ Usar vector o librerías STL para almacenamiento dinámico,
ya que el examen exige implementar memoria dinámica manual.

✘ Guardar datos en formato binario porque el requisito
indica persistencia simple en archivo de texto.

✘ Crear un sistema demasiado complejo con clases,
herencia o plantillas avanzadas, porque el nivel del
examen es universitario inicial.

---

Test manual diseñado por mí:

Entrada (pasos/comandos):

1. Iniciar el programa.

2. Agregar libro:
   ID: 1
   Título: Cien años de soledad
   Autor: Gabriel García Márquez
   Año: 1967

3. Agregar usuario:
   ID: 10
   Nombre: Juan Pérez
   Carrera: Ingeniería

4. Prestar el libro ID 1 al usuario ID 10.

5. Intentar prestar nuevamente el mismo libro.

6. Mostrar préstamos.

7. Devolver el libro.

8. Cerrar el programa y volver a abrirlo para verificar
   la carga desde archivos.

Salida esperada:

✔ El libro se presta correctamente.
✔ El segundo préstamo es rechazado porque el libro no
está disponible.
✔ El préstamo activo se muestra en pantalla.
✔ Tras la devolución, el libro vuelve a estar disponible.
✔ Al reiniciar el programa, los datos se cargan desde
los archivos .txt.

---

Nota de autoría:

Declaro que entiendo completamente el código entregado,
puedo explicar el uso de punteros, memoria dinámica,
referencias, structs y la lógica de cada función.
El programa fue desarrollado con apoyo de IA,
pero fue revisado, comprendido y validado por mí.

Autor: [BRAYAM STEVEN JAIMES GODOY]
Fecha: [13/02/2026]

====================================================
*******************************************************/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*************** STRUCTS ****************/

struct Libro{
    int id;
    string titulo;
    string autor;
    int anio;
    bool disponible;
};

struct Usuario{
    int id;
    string nombre;
    string carrera;
};

struct Prestamo{
    int idLibro;
    int idUsuario;
};

/*************** REDIMENSIONAR ****************/

void redimensionarLibros(Libro*& arr, int& cap){
    cap*=2;
    Libro* nuevo=new Libro[cap];

    for(int i=0;i<cap/2;i++)
        nuevo[i]=arr[i];

    delete[] arr;
    arr=nuevo;
}

void redimensionarUsuarios(Usuario*& arr, int& cap){
    cap*=2;
    Usuario* nuevo=new Usuario[cap];

    for(int i=0;i<cap/2;i++)
        nuevo[i]=arr[i];

    delete[] arr;
    arr=nuevo;
}

void redimensionarPrestamos(Prestamo*& arr, int& cap){
    cap*=2;
    Prestamo* nuevo=new Prestamo[cap];

    for(int i=0;i<cap/2;i++)
        nuevo[i]=arr[i];

    delete[] arr;
    arr=nuevo;
}

/*************** BUSQUEDAS (PUNTEROS) ****************/

Libro* buscarLibro(Libro* libros,int total,int id){
    for(int i=0;i<total;i++)
        if(libros[i].id==id)
            return &libros[i];

    return nullptr;
}

Usuario* buscarUsuario(Usuario* usuarios,int total,int id){
    for(int i=0;i<total;i++)
        if(usuarios[i].id==id)
            return &usuarios[i];

    return nullptr;
}

/*************** GUARDAR DATOS ****************/

void guardarLibros(Libro* libros,int total){
    ofstream f("libros.txt");

    for(int i=0;i<total;i++){
        f<<libros[i].id<<"|"
         <<libros[i].titulo<<"|"
         <<libros[i].autor<<"|"
         <<libros[i].anio<<"|"
         <<libros[i].disponible<<"\n";
    }
}

void guardarUsuarios(Usuario* usuarios,int total){
    ofstream f("usuarios.txt");

    for(int i=0;i<total;i++){
        f<<usuarios[i].id<<"|"
         <<usuarios[i].nombre<<"|"
         <<usuarios[i].carrera<<"\n";
    }
}

void guardarPrestamos(Prestamo* prestamos,int total){
    ofstream f("prestamos.txt");

    for(int i=0;i<total;i++){
        f<<prestamos[i].idLibro<<"|"
         <<prestamos[i].idUsuario<<"\n";
    }
}

/*************** CARGAR DATOS ****************/

void cargarLibros(Libro*& libros,int& total,int& cap){
    ifstream f("libros.txt");
    if(!f) return;

    string linea;

    while(getline(f,linea)){
        if(total==cap)
            redimensionarLibros(libros,cap);

        string datos[5];
        int pos=0;

        for(int i=0;i<4;i++){
            pos=linea.find('|');
            datos[i]=linea.substr(0,pos);
            linea.erase(0,pos+1);
        }
        datos[4]=linea;

        libros[total].id=stoi(datos[0]);
        libros[total].titulo=datos[1];
        libros[total].autor=datos[2];
        libros[total].anio=stoi(datos[3]);
        libros[total].disponible=stoi(datos[4]);

        total++;
    }
}

void cargarUsuarios(Usuario*& usuarios,int& total,int& cap){
    ifstream f("usuarios.txt");
    if(!f) return;

    string linea;

    while(getline(f,linea)){
        if(total==cap)
            redimensionarUsuarios(usuarios,cap);

        int pos=linea.find('|');
        string id=linea.substr(0,pos);
        linea.erase(0,pos+1);

        pos=linea.find('|');
        string nombre=linea.substr(0,pos);
        linea.erase(0,pos+1);

        string carrera=linea;

        usuarios[total].id=stoi(id);
        usuarios[total].nombre=nombre;
        usuarios[total].carrera=carrera;

        total++;
    }
}

void cargarPrestamos(Prestamo*& prestamos,int& total,int& cap){
    ifstream f("prestamos.txt");
    if(!f) return;

    string linea;

    while(getline(f,linea)){
        if(total==cap)
            redimensionarPrestamos(prestamos,cap);

        int pos=linea.find('|');

        prestamos[total].idLibro=stoi(linea.substr(0,pos));
        prestamos[total].idUsuario=stoi(linea.substr(pos+1));

        total++;
    }
}

/*************** FUNCIONES PRINCIPALES ****************/

void agregarLibro(Libro*& libros,int& total,int& cap){
    if(total==cap)
        redimensionarLibros(libros,cap);

    int id;
    cout<<"ID libro: ";
    cin>>id;

    if(buscarLibro(libros,total,id)){
        cout<<"ID repetido\n";
        return;
    }

    cin.ignore();

    libros[total].id=id;

    cout<<"Titulo: ";
    getline(cin,libros[total].titulo);

    cout<<"Autor: ";
    getline(cin,libros[total].autor);

    cout<<"Anio: ";
    cin>>libros[total].anio;

    libros[total].disponible=true;

    total++;
}

void listarLibros(Libro* libros,int total){
    for(int i=0;i<total;i++){
        cout<<"\nID:"<<libros[i].id
            <<"\nTitulo:"<<libros[i].titulo
            <<"\nAutor:"<<libros[i].autor
            <<"\nDisponible:"<<(libros[i].disponible?"Si":"No")
            <<"\n----------------";
    }
}

void agregarUsuario(Usuario*& usuarios,int& total,int& cap){
    if(total==cap)
        redimensionarUsuarios(usuarios,cap);

    int id;
    cout<<"ID usuario: ";
    cin>>id;

    if(buscarUsuario(usuarios,total,id)){
        cout<<"ID repetido\n";
        return;
    }

    cin.ignore();

    usuarios[total].id=id;

    cout<<"Nombre: ";
    getline(cin,usuarios[total].nombre);

    cout<<"Carrera: ";
    getline(cin,usuarios[total].carrera);

    total++;
}

void prestarLibro(Libro* libros,int totalLibros,
                  Usuario* usuarios,int totalUsuarios,
                  Prestamo*& prestamos,int& totalPrestamos,int& capPrestamos){

    int idLibro,idUsuario;

    cout<<"ID libro: ";
    cin>>idLibro;

    Libro* libro=buscarLibro(libros,totalLibros,idLibro);

    if(!libro){
        cout<<"Libro no existe\n";
        return;
    }

    if(!libro->disponible){
        cout<<"Libro no disponible\n";
        return;
    }

    cout<<"ID usuario: ";
    cin>>idUsuario;

    if(!buscarUsuario(usuarios,totalUsuarios,idUsuario)){
        cout<<"Usuario no existe\n";
        return;
    }

    if(totalPrestamos==capPrestamos)
        redimensionarPrestamos(prestamos,capPrestamos);

    prestamos[totalPrestamos++]={idLibro,idUsuario};

    libro->disponible=false;
}

void devolverLibro(Libro* libros,int totalLibros,
                   Prestamo* prestamos,int& totalPrestamos){

    int id;
    cout<<"ID libro a devolver: ";
    cin>>id;

    Libro* libro=buscarLibro(libros,totalLibros,id);

    if(!libro){
        cout<<"No existe\n";
        return;
    }

    for(int i=0;i<totalPrestamos;i++){
        if(prestamos[i].idLibro==id){
            prestamos[i]=prestamos[--totalPrestamos];
            libro->disponible=true;
            cout<<"Devuelto!\n";
            return;
        }
    }

    cout<<"No tenia prestamo\n";
}

void mostrarPrestamos(Prestamo* prestamos,int total,
                      Libro* libros,int totalLibros,
                      Usuario* usuarios,int totalUsuarios){

    if(total==0){
        cout<<"Sin prestamos\n";
        return;
    }

    for(int i=0;i<total;i++){
        Libro* l=buscarLibro(libros,totalLibros,prestamos[i].idLibro);
        Usuario* u=buscarUsuario(usuarios,totalUsuarios,prestamos[i].idUsuario);

        cout<<u->nombre<<" tiene \""<<l->titulo<<"\"\n";
    }
}

/*************** MAIN ****************/

int main(){

    int capLibros=5,totalLibros=0;
    int capUsuarios=3,totalUsuarios=0;
    int capPrestamos=5,totalPrestamos=0;

    Libro* libros=new Libro[capLibros];
    Usuario* usuarios=new Usuario[capUsuarios];
    Prestamo* prestamos=new Prestamo[capPrestamos];

    // Cargar datos
    cargarLibros(libros,totalLibros,capLibros);
    cargarUsuarios(usuarios,totalUsuarios,capUsuarios);
    cargarPrestamos(prestamos,totalPrestamos,capPrestamos);

    int op;

    do{
        cout<<"\n=== BIBLIOTECA ===\n";
        cout<<"1.Agregar libro\n";
        cout<<"2.Listar libros\n";
        cout<<"3.Agregar usuario\n";
        cout<<"4.Prestar libro\n";
        cout<<"5.Devolver libro\n";
        cout<<"6.Mostrar prestamos\n";
        cout<<"0.Salir\n";
        cin>>op;

        switch(op){
            case 1: agregarLibro(libros,totalLibros,capLibros); break;
            case 2: listarLibros(libros,totalLibros); break;
            case 3: agregarUsuario(usuarios,totalUsuarios,capUsuarios); break;
            case 4: prestarLibro(libros,totalLibros,usuarios,totalUsuarios,prestamos,totalPrestamos,capPrestamos); break;
            case 5: devolverLibro(libros,totalLibros,prestamos,totalPrestamos); break;
            case 6: mostrarPrestamos(prestamos,totalPrestamos,libros,totalLibros,usuarios,totalUsuarios); break;
        }

    }while(op!=0);

    // Guardar datos antes de salir
    guardarLibros(libros,totalLibros);
    guardarUsuarios(usuarios,totalUsuarios);
    guardarPrestamos(prestamos,totalPrestamos);

    // Liberar memoria
    delete[] libros;
    delete[] usuarios;
    delete[] prestamos;

    cout<<"Datos guardados. Memoria liberada.\n";
}
