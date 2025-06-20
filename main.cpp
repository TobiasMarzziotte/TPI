#include <iostream>
#include <string>

//INCLUIMOS LAS FUNCIONES QUE CONSTRUIMOS

#include "FUNCION_MENU.h"
#include "FUNCION_CARGA_PRODUCTOS.h"

using namespace std;

int main()
{
    int opc; //VARIABLE QUE ALMACENARA LO QUE DEVUELVE LA FUNCION DEL MENU PRINCIPAL
    Producto productos[20]; //DECLARAMOS EL VECTOR QUE VAMOS A UTILIZAR PARA LOS PRODUCTOS
    bool iniciarMenu = false; //INICIAMOS UN BOOL PARA QUE EL WHILE SIGA REPITIENDO MIENTRAS SIGA EN FALSE

 while(iniciarMenu == false){
    opc = menuPrincipal(); //RECIBIMOS POR REFERENCIA LA FUNCION DEL MENU Y LA ALMACENAMOS EN LA VARIABLE opc
                           //SE INICIA EL MENU

    switch (opc){
    case 1:
        system("cls");
        system("pause");
        break;

    case 2:
        system("cls");

        cout << "Ingrese el listado de 20 productos: ";
        cout << "" << endl;

        if (cargaProductos(productos)){

            cout << "Se cargaron los 20 productos de manera correcta." << endl;
        } else{
            cout << "La carga tuvo un error. Inicie nuevamente." << endl;
        }

        system("pause");
        system("cls");
        break;

    case 3:
        system("cls");
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
