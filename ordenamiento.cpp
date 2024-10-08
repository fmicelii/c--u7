#include <iostream>
using namespace std;

void ordenar(int pito[]){
    for (int i = 0; i < 5-1; i++){
        for (int j = 0; j < 5-i-1; j++){
            if (pito[j]>pito[j+1]){
                int aux = pito[j];
                pito[j]=pito[j+1];
                pito[j+1]=aux;
            }
        }
    }
}

int main(){
    int arreglo[5];

    cout<<"ingrese 5 numeros en un arreglo: ";
    for (int i = 0; i < 5; i++){
        cin>>arreglo[i];
    }

    ordenar(arreglo);

    for(int j=0;j<5;j++){
        cout<<arreglo[j]<<", ";
    }
}
