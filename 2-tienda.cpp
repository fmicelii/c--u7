#include <iostream>
#include <vector>
using namespace std;

//  Realizar un sistema para el control de ventas en un local. Cada
// producto tiene los siguientes datos: Código, nombre, cantidad y
// precio (agregar los datos que necesiten). Se deberá poder
// registrar una venta, pidiendo el código del producto y la cantidad
// (tener en cuenta el stock del mismo), mostrar el total de ventas
// realizadas en el día (Utilizar una estructura de fecha con el día,
// mes y año como strings), mostrar los productos mas vendidos y
// una función para buscar un producto por su código. 
struct Producto{
    int codigo;
    string nombre;
    int stock;
    int precio;
};
struct Fecha{
    int dia;
    int mes;
    int anio;
};
struct Venta{
    Fecha fecha_venta;
    int venta_codigo,venta_cantidad;
};

void mostrar_menu(){
    cout<<endl;
    cout<<"=======Que quiere hacer?======="<<endl;
    cout<<"1. Hacer compra"<<endl;
    cout<<"2. Mostrar total ventas del dia"<<endl;
    cout<<"3. Mostrar productos mas vendidos"<<endl;
    cout<<"4. Buscar producto (por codigo)"<<endl;
    cout<<"5. Salir"<<endl;
}

void registrar_venta(vector <Producto> catalogo,vector <Venta> &total_ventas){
    Venta venta1;
    int vcodigo;
    int vcantidad;
    cout << "Ingrese la fecha de hoy: " << endl;
    cout << "Día (1-30): ";
    cin >> venta1.fecha_venta.dia;
    while (venta1.fecha_venta.dia < 1 || venta1.fecha_venta.dia >= 30) {
        cout << "Día inválido. Debe estar entre 1 y 30. Intente nuevamente: ";
        cin >> venta1.fecha_venta.dia;
    }
    cout << "Mes (1-12): ";
    cin >> venta1.fecha_venta.mes;
    while (venta1.fecha_venta.mes < 1 || venta1.fecha_venta.mes > 12) {
        cout << "Mes inválido. Debe estar entre 1 y 12. Intente nuevamente: ";
        cin >> venta1.fecha_venta.mes;
    }
    venta1.fecha_venta.anio = 2024;
    cout<<"========="<<endl;
    cout<<"ingrese primero el codigo del producto que quiere y luego la cantidad de este,\nsi no esta en stock se le avisará\n";
    cout<<"codigo: ";
    cin>>vcodigo;
    for (int i = 0; i < catalogo.size(); i++){
        if(catalogo[i].codigo == vcodigo){
            venta1.venta_codigo = vcodigo;
            cout<<"stock actual: "<<catalogo[i].stock<<endl;
            cout<<"cantidad: ";
            cin>>vcantidad;
            while (true){
                if (vcantidad > catalogo[i].stock){
                    cout<<"la cantidad es mayor que la del stock, porfavor ingrese una menor o igual a "<<catalogo[i].stock<<endl;
                    cin>>vcantidad;
                }
                else{
                    venta1.venta_cantidad = vcantidad;
                    total_ventas.push_back(venta1);
                    cout<<"venta completada!"<<endl;
                    break;
                }
            }
            break;
        }
    }
}

void venta_por_dia(vector <Venta> total_ventas){
    int ddia,dmes;
    cout<<"ingrese dia y mes que quiera ver el total de sus ventas: ";
    cout<<"dia: ";
    cin>>ddia;
    cout<<"mes: ";
    cin>>dmes;
    for (int i = 0; i <= total_ventas.size(); i++)
    {
        if (ddia == total_ventas[i].fecha_venta.dia && dmes == total_ventas[i].fecha_venta.mes){
            cout<<"el total de ventas del dia "<<ddia<<"/"<<dmes<<" es: "<<total_ventas[i].venta_cantidad<<endl;
        }
        else{
            cout<<"no hay ventas ese dia"<<endl;
        }
    }
}

void producto_mas_vendido(vector <Venta> total_ventas){
    cout<<"en proceso...";
}

void buscar_producto(vector <Producto> catalogo){
    int bcodigo;
    cout<<"ingrese el codigo del producto deseado: ";
    cin>>bcodigo;
    for (int i = 0; i < catalogo.size(); i++){
        if (catalogo[i].codigo == bcodigo){
            cout<<"el codigo "<<bcodigo<<" representa al producto: "<<catalogo[i].nombre<<"."<<endl;
            return; //termina la funcion y en este caso vuelve el main
        }
    }
    cout<<"el codigo que ingresó no se ha podido encontrar en el catalogo :("<<endl;
}

int main(){
    int opcion;
    vector <Producto> catalogo;
    vector <Venta> total_ventas;
    Producto p1,p2,p3;
    p1.codigo = 1;
    p1.nombre = "fideos";
    p1.precio = 2500;
    p1.stock = 30;

    p2.codigo = 2;
    p2.nombre = "manteca";
    p2.precio = 2100;
    p2.stock = 4;

    p3.codigo = 3;
    p3.nombre = "crema";
    p3.precio = 8000;
    p3.stock = 0;

    catalogo.push_back(p1);
    catalogo.push_back(p2);
    catalogo.push_back(p3);
    
    while (true){
        mostrar_menu();
        cout<<"Ingrese opcion: ";
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            registrar_venta(catalogo,total_ventas);
            break;

        case 2:
            venta_por_dia(total_ventas);
            break;

        case 3:
            producto_mas_vendido(total_ventas);
            break;

        case 4:
            buscar_producto(catalogo);
            break;

        case 5:
            cout<<"SALIENDO..."<<endl;
            return 0;

        default:
            cout<<"OPCION INVALIDA"<<endl;
            cout<<"SALIENDO..."<<endl;
            return 0;
        }
    }
}