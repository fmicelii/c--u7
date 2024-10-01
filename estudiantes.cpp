#include <iostream>
#include <vector>
using namespace std;
// Realizar el sistema de promedios de calificaciones con
// estructuras. Se deberá cargar un vector de Estudiantes (Se le tiene
// que permitir cargar su nombre, su apellido, sus calificaciones, la
// nota mas alta, la mas baja y su promedio) y mostrar por pantalla
// todos sus datos y se quiere saber quien fue el mejor estudiante a
// través de los promedios.

struct Estudiante{
    string nombre,apellido;
    vector <float> calificaciones;
    float nota_baja;
    float nota_alta;    
    float promedio;
};

void ordenar_calificaciones(vector <float> &calificaciones , int tamanio){
    for (int i = 0; i < tamanio-1; i++){
        for (int j = 0; j < tamanio-i-1; j++){
            if (calificaciones[j] > calificaciones[j+1]){
                int t = calificaciones[j];
                calificaciones[j] = calificaciones[j+1];
                calificaciones[j+1] = t;
            }
        }
    }
}

void ingresar_calificaciones(vector <float> &calificaciones){
    bool keep=true;
    string ans;
    float nota;
    for (int i = 0; keep ; i++){
        cout<<"ingrese una calificacion: ";
        cin>>nota;
        calificaciones.push_back(nota);
        cout<<"queres ingresar otra calificacion?"<<endl;
        cin>>ans;
        if (ans == "no"){
            keep = false;
        }
    }
    ordenar_calificaciones(calificaciones,calificaciones.size());
}

float calcular_promedio(vector <float> calificaciones){
    float suma = 0;
    float promedio;
    for(long unsigned int i = 0 ;i < calificaciones.size(); i++){
        suma += calificaciones[i];
    }
    promedio = suma/calificaciones.size();
    return promedio;
}

void mostrar_datos(const vector <Estudiante> &clase) {
    for (int i = 0; i < clase.size(); ++i){
        const Estudiante &estudiante = clase[i];
        cout << estudiante.nombre << endl;
        cout << estudiante.apellido << endl;
        for (int j = 0; j < estudiante.calificaciones.size(); ++j){
            cout << estudiante.calificaciones[j] << endl;
        }
        cout << "la nota mas baja es: " << estudiante.nota_baja << endl;
        cout << "la nota mas alta es: " << estudiante.nota_alta << endl;
        cout << "la nota promedio es: " << estudiante.promedio << endl;
    }
}


int main() {
    bool seguir = true;
    string respuesta;
    vector<Estudiante> clase;

    while (seguir) {
        Estudiante estudiante_dato;
        cout << "Ingrese nombre: ";
        cin >> estudiante_dato.nombre;
        cout << "Ingrese apellido: ";
        cin >> estudiante_dato.apellido;
        ingresar_calificaciones(estudiante_dato.calificaciones);

        if (!estudiante_dato.calificaciones.empty()) {  // Verificar que el vector no esté vacío
            estudiante_dato.nota_baja = estudiante_dato.calificaciones.at(0);  // tambien se puede usar la funcion estudiante_dato.calificaciones.front() que muestra el primer elemento del vector
            estudiante_dato.nota_alta = estudiante_dato.calificaciones.at(estudiante_dato.calificaciones.size()-1);   // tambien se puede usar la funcion estudiante_dato.calificaciones.back() que muestra el extremo del vector
        } else {
            estudiante_dato.nota_baja = estudiante_dato.nota_alta = 0;  // Valores predeterminados si no hay calificaciones
        }
        estudiante_dato.promedio = calcular_promedio(estudiante_dato.calificaciones);
        clase.push_back(estudiante_dato);
        cout << "¿Quiere agregar un alumno más? (sí/no) ";
        cin >> respuesta;
        if (respuesta == "no") {
            seguir = false;
            mostrar_datos(clase);
        }
    }
    return 0;
}
