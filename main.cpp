#include <iostream>
#include "funciones.h"
using namespace std;

venta ventas;
int main()
{
// DECLARACION DE VARIABLES

    int opc;
    int totalVentas = 0;

    venta ventas;

// DECLARACION DE VECTORES

    marca marcas[10];
    FormaPago formasPago[5];
    int contadorVentasPorForma[5]={0};




    // MENU
   while(true){
    cout << "-------Menu principal-------" << endl;
    cout << endl;
    cout << "1) Cargar lote de marcas" << endl;
    cout << "2) Cargar lote de productos" << endl;
    cout << "3) Cargar lote de formas de pago" << endl;
    cout << "4) Cargar lote de ventas" << endl;
    cout << "5) Mostrar reportes" << endl;
    cout << "0) Salir del Programa" << endl;
    cout << endl;
    cout << "Opcion: ";

    cin >> opc;

    switch (opc){

    case 1:

    system("cls");

    cargarMarcas(marcas, 10);

    system("pause");
    system("cls");


    break;

    case 2:
        system("cls");
        system("pause");
        break;

    case 3:
        system("cls");

        CargarFormasPago(formasPago);

        system("pause");
        system("cls");
        break;

    case 4:
        system("cls");

        cargarVentas(contadorVentasPorForma, totalVentas, formasPago);
        system("pause");
        system("cls");

        break;

    case 5:
        system("cls");
        reportePunto2(contadorVentasPorForma, totalVentas, formasPago);
        system("pause");
        system("cls");
        break;

    case 0:
        system ("cls");
        cout << "FIN DEL PROGRAMA, PRESIONE CUALQUIER TECLA PARA TERMINAR";
        return 0;
        break;

    default:
        system("cls");
        cout<< "Opcion invalida" << endl;
        cout << endl;
        system("pause");
        system ("cls");
    }
}



    return 0;
}
