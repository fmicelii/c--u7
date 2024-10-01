#include <iostream>
#include <vector>
using namespace std;
// • Realizar un programa donde el usuario ingrese todos los libros de
// su biblioteca y posteriormente se deberá imprimir por pantalla, la
// cantidad de libros que posee y sus datos. 

struct Libro{
    string nombre;
    string autor;
    int paginas;
};

void mostrar_datos(vector <Libro> biblioteca){
    for (long unsigned int i = 0; i < biblioteca.size(); i++){
        cout<< biblioteca[i].nombre<<endl;
        cout<< biblioteca[i].autor<<endl;
        cout<< biblioteca[i].paginas<<endl;
    }
}

int main(){
    bool seguir = true;
    string respuesta;
    vector <Libro> biblioteca;

    while (seguir){
        Libro libro;
        cout<<"ingrese nombre del libro:";
        cin>>libro.nombre;
        cout<<"ingrese autor del libro:"<<endl;
        cin>>libro.autor;
        cout<<"ingrese cantidad de paginas:"<<endl;
        cin>>libro.paginas;
        biblioteca.push_back(libro);

        cout<<"quiere agregar un libro mas?"<<endl;
        cin>>respuesta;
        if(respuesta == "no" || respuesta == "NO"){
            seguir = false;
        }
    }
    mostrar_datos(biblioteca);
}

