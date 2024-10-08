#include <iostream>
#include <vector>
using namespace std;

// Realizar un sistema para la reserva de butacas en un cine. El cine
// tiene varias salas, y cada sala tiene un número de asientos
// organizados en filas y columnas (se deberá usar una matriz para
// representar los asientos del cine). Las funcionalidades del sistema
// deberán permitir reservar asientos libres, mostrar todos los
// asientos (Con su estado: Ocupados o libres), cancelar una reserva
// de asiento y calcular el total de entradas vendidas.

struct Sala{
    char asientos[5][5];//  libre = l   ,   ocupado = o
    int asientos_vendidos;
};


void mostrar_menu(){
    cout<<"--------------MENU--------------"<<endl;
    cout<<"--1. reservar asientos libres"<<endl;
    cout<<"--2. mostrar todos los asientos"<<endl;
    cout<<"--3. cancelar reserva"<<endl;
    cout<<"--4. calcular entradas vendidas"<<endl;
    cout<<"--5. salir"<<endl;
}



int main(){
    int opcion;


    while (true){
        mostrar_menu();
        cout<<"ingrese su opcion: ";
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            
            break;
        
        default:
            return 0;
        }
    }
    
}