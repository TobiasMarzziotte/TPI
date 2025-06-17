#include <iostream>
#include "funciones.h"
using namespace std;
// DECLARACION DE STRUCT

    struct marca{
    int codigoMarca;
    string nombreMarca;
    };

int main()
{
// DECLARACION DE VARIABLES

    int opc;


// DECLARACION DE VECTORES

    marca marcas[10];
    FormaPago formasPago[5];

    // MENU

    while(true){

    system("cls");

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

    for(int x = 0; x < 10; x++)
        {
    cout << "CODIGO DE MARCA: " << endl;
    cin >> marcas[x].codigoMarca;
    if (marcas[x].codigoMarca >= 1 && marcas[x].codigoMarca <= 10) {
        marcas[x].codigoMarca = marcas[x].codigoMarca;
    } else {
    cout << "CODIGO INVALIDO, SE TERMINA EL PROGRAMA";

    return 0;
    }
    cout << "NOMBRE DE MARCA: " << endl;
    cin >> marcas[x].nombreMarca;
    system("cls");
    }

    system("pause");

    break;

    case 2:
        system("cls");
        system("pause");
        break;

    case 3:
        system("cls");
        CargarFormasPago(formasPago);
        system("pause");
        break;

    case 4:
        system("cls");
        system("pause");
        break;

    case 5:
        system("cls");
        system("pause");
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
    }
                }



    return 0;
}
