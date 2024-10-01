#include <iostream>
#include <vector>
using namespace std;
// Realizar un sistema para hacer reservas de habitación en un hotel.
// Cada reserva va a tener los siguientes datos: Nombre del huésped,
// fecha de llegada, número de noches y número habitación. Se
// deberá poder agregar nuevas reservas, cancelarlas con el nombre
// del huésped, mostrar todas las reservas y mostrar disponibilidad
// de habitaciones (sabiendo que hay un total de 20). 

struct Reserva{
    string nombre_huesped;
    string apellido_huesped;
    string fecha;
    int cant_noches;
    int num_habitacion;
};

void cancelar_reserva(string nombre, string apellido){

}

void mostrar_reservas(vector <Reserva> total_reservas){
    if (total_reservas.empty()){
        cout<<"no hay reservas."<<endl;
    }
    else{
        for(Reserva reserva : total_reservas){
            cout<<"== Mostrando reservas..."<<endl;
            cout<<"Nombre: "<< reserva.nombre_huesped<<endl;
            cout<<"Apellido: "<< reserva.apellido_huesped<<endl;
            cout<<"Fecha: "<< reserva.fecha<<endl;
            cout<<"Cantidad de Noches: "<< reserva.cant_noches<<endl;
            cout<<"Numero de Habitacion: "<< reserva.num_habitacion<<endl;
            
        }
    }
}

void mostrar_menu(){
    cout<<"=======================Que quiere hacer hoy?======================="<<endl;
    cout<<"== 1. Agregar reserva."<<endl;
    cout<<"== 2. Cancelar reserva."<<endl;
    cout<<"== 3. Mostrar reservas."<<endl;
    cout<<"== 4. Mostrar disponibilidad (habitaciones)."<<endl;
    cout<<"==================================================================="<<endl;
}

int main(){
    int opcion;

    mostrar_menu();
    cin>>opcion;
    vector <Reserva> total_reservas;
    string nombre,apellido;
    const int total_habitaciones = 20;

    Reserva reserva_dato;

    switch (opcion){
    case 1:
        cout<<"== Ingresando datos de reserva..."<<endl;
        cout<<"Ingrese su nombre: (Juan)"<<endl;
        cin>>reserva_dato.nombre_huesped;
        cout<<"Ingrese su apellido: (Perez)"<<endl;
        cin>>reserva_dato.apellido_huesped;
        cout<<"Ingrese la fecha de la reserva: (´2024-09-25´)"<<endl;
        cin>>reserva_dato.fecha;
        cout<<"Ingrese la cantidad de noches: (´9´)"<<endl;
        cin>>reserva_dato.cant_noches;
        cout<<"Ingrese numero de habitacion: (´12´)"<<endl;
        cin>>reserva_dato.num_habitacion;
        total_reservas.push_back(reserva_dato);

    case 2:
        cout<<"== Cancelando reserva..."<<endl;
        cout<<"Ingrese su nombre y apellido para cancelar la reserva: "<<endl;
        cin>>nombre;
        cin>>apellido;
        cancelar_reserva(nombre,apellido);
        break;

    case 3:
        mostrar_reservas(total_reservas);
        break;
    default:
        break;
    }
}