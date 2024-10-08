#include <iostream>
#include <vector>
using namespace std;

// Realizar un sistema para la reserva de butacas en un cine. El cine tiene varias salas, y cada sala tiene un número de asientos organizados en filas y columnas (se deberá usar una matriz para representar los asientos del cine). Las funcionalidades del sistema deberán permitir reservar asientos libres, mostrar todos los asientos (Con su estado, ocupados o libres), cancelar una reserva de asiento y calcular el total de entradas vendidas.

const int FILAS = 5;   // Número de filas por sala
const int COLUMNAS = 6; // Número de columnas por sala

struct Sala {
    int numero_sala;
    char asientos[FILAS][COLUMNAS]; // Matriz para representar los asientos (O=ocupado, L=libre)
    int entradas_vendidas = 0;
};

void inicializar_sala(Sala &sala) {
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            sala.asientos[i][j] = 'L'; // Inicialmente, todos los asientos están libres
        }
    }
}

void mostrar_asientos(Sala &sala) {
    cout << "Asientos de la sala " << sala.numero_sala << ":" <<endl;
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << sala.asientos[i][j] << " ";
        }
        cout << endl;
    }
}

void reservar_asiento(Sala &sala) {
    int fila, columna;
    cout << "Ingrese la fila (1-" << FILAS << "): ";
    cin >> fila;
    cout << "Ingrese la columna (1-" << COLUMNAS << "): ";
    cin >> columna;

    // Verificar si las coordenadas son válidas
    if (fila < 1 || fila > FILAS || columna < 1 || columna > COLUMNAS) {
        cout << "Coordenadas inválidas. Intente nuevamente." << endl;
        return;
    }

    // Verificar si el asiento está libre
    if (sala.asientos[fila - 1][columna - 1] == 'L') {
        sala.asientos[fila - 1][columna - 1] = 'O';
        sala.entradas_vendidas++;
        cout << "Asiento reservado exitosamente!" << endl;
    } else {
        cout << "El asiento ya está ocupado." << endl;
    }
}

void cancelar_reserva(Sala &sala) {
    int fila, columna;
    cout << "Ingrese la fila (1-" << FILAS << "): ";
    cin >> fila;
    cout << "Ingrese la columna (1-" << COLUMNAS << "): ";
    cin >> columna;

    // Verificar si las coordenadas son válidas
    if (fila < 1 || fila > FILAS || columna < 1 || columna > COLUMNAS) {
        cout << "Coordenadas inválidas. Intente nuevamente." << endl;
        return;
    }

    // Verificar si el asiento está ocupado
    if (sala.asientos[fila - 1][columna - 1] == 'O') {
        sala.asientos[fila - 1][columna - 1] = 'L';
        sala.entradas_vendidas--;
        cout << "Reserva cancelada exitosamente!" << endl;
    } else {
        cout << "El asiento ya está libre." << endl;
    }
}

void mostrar_total_entradas(Sala &sala) {
    cout << "Total de entradas vendidas en la sala " << sala.numero_sala << ": " << sala.entradas_vendidas << endl;
}

void agregar_sala(vector<Sala> &salas) {
    Sala nueva_sala;
    cout << "Ingrese el número de la sala: ";
    cin >> nueva_sala.numero_sala;
    inicializar_sala(nueva_sala);
    salas.push_back(nueva_sala);
    cout << "Sala agregada exitosamente!" << endl;
}

int main() {
    int opcion = 0;
    int indice;
    vector<Sala> salas;

    while (opcion != 6) {
        cout << "Sistema de Reserva de Butacas en el Cine" << endl;
        cout << "1. Agregar nueva sala" << endl;
        cout << "2. Reservar asiento" << endl;
        cout << "3. Cancelar reserva de asiento" << endl;
        cout << "4. Mostrar asientos de una sala" << endl;
        cout << "5. Mostrar total de entradas vendidas" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;

        int numero_sala;

        if (opcion >= 2 && opcion <= 5) {
            cout << "Ingrese el número de la sala: ";
            cin >> numero_sala;

            // Buscar la sala seleccionada
            for (int i = 0; i < salas.size(); i++){
                if (salas[i].numero_sala == numero_sala) {
                    indice = i;
                    cout << "Sala encontrada." << endl;
                    break;
                }
            }

            if (salas[indice].numero_sala != numero_sala) {
                cout << "Sala no encontrada." << endl;
                continue;
            }
        }

        switch (opcion) {
            case 1:
                agregar_sala(salas);
                break;
            case 2:
                reservar_asiento(salas[indice]);
                break;
            case 3:
                cancelar_reserva(salas[indice]);
                break;
            case 4:
                mostrar_asientos(salas[indice]);
                break;
            case 5:
                mostrar_total_entradas(salas[indice]);
                break;
            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
    }
}
