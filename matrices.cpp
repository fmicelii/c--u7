#include <iostream>
using namespace std;

void ingresar_matriz(int (&matriz)[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << "Ingrese valor para fila " << i + 1 << " y columna " << j + 1 << ": ";
            cin >> matriz[i][j];
        }
    }
}

void suma(int matriz[2][2],int matrizdos[2][2],int nuevamatriz[2][2]){
    cout<<"==suma de matrices ingresaadas=="<<endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            nuevamatriz[i][j] = matriz[i][j] + matrizdos[i][j];
            cout<<nuevamatriz[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"=================================";
}

void resta(int matriz[2][2],int matrizdos[2][2],int nuevamatriz[2][2]){
    cout<<"==resta de matrices ingresaadas=="<<endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            nuevamatriz[i][j] = matriz[i][j] - matrizdos[i][j];
            cout<<nuevamatriz[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"=================================";
}

void escalar(int matriz[2][2],int matrizdos[2][2]){
    int num_escalar;
    cout<<"==escalar de matrices ingresaadas=="<<endl;
    cout<<"ingrese un escalar: ";
    cin>>num_escalar;
    cout<<"matriz 1: "<<endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            matriz[i][j] *= num_escalar;
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"================================="<<endl;
    cout<<"matriz 2: "<<endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            matrizdos[i][j] *= num_escalar;
            cout<<matrizdos[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"================================="<<endl;
}

void mostrar_matrices(int matriz[2][2],int matrizdos[2][2]){
    cout << "Matriz 1 ingresada:" << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << matriz[i][j] << " "; 
        }
        cout << endl;
    }

    cout << "Matriz 2 ingresada:" << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << matrizdos[i][j] << " "; 
        }
        cout << endl;
    }

}

void mostrar_menu(){
    cout<<"=======Que quiere hacer?======="<<endl;
    cout<<"1. mostrar matrices"<<endl;
    cout<<"2. sumar matrices"<<endl;
    cout<<"3. restar matrices"<<endl;
    cout<<"4. producto escalar"<<endl;
    cout<<"5. Salir"<<endl;
}

int main(){
    int op;
    cout << "Creando primera matriz..." << endl;
    int matriz1[2][2]; 
    ingresar_matriz(matriz1); 

    cout << "Creando segunda matriz..." << endl;
    int matriz2[2][2]; 
    ingresar_matriz(matriz2);
    
    while (true){
        mostrar_menu();
        cin>>op;

        switch (op){
        case 1:
            mostrar_matrices(matriz1,matriz2);
            break;

        case 2:
            int suma_matriz[2][2];
            suma(matriz1,matriz2,suma_matriz);
            break;

        case 3:
            int resta_matriz[2][2];
            resta(matriz1,matriz2,resta_matriz);
            break;

        case 4:
            escalar(matriz1,matriz2);
            break;

        default:
            return 0;
        }
    }
}
