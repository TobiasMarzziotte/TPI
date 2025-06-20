
#include <iostream>
#include "FUNCION_MENU.h"
using namespace std;

//ARCHIVO .CPP PARA EL DESARROLLO DE LA FUNCION PREVIAMENTE DECLARADA
int menuPrincipal(){

int opc;

     cout << "-------Menu principal-------" <<  endl;
     cout <<  endl;
     cout << "1) Cargar lote de marcas" <<  endl;
     cout << "2) Cargar lote de productos" <<  endl;
     cout << "3) Cargar lote de formas de pago" <<  endl;
     cout << "4) Cargar lote de ventas" <<  endl;
     cout << "5) Mostrar reportes" <<  endl;
     cout << "0) Salir del Programa" <<  endl;
     cout <<  endl;
     cout << "Opcion: ";
     cin >> opc;

    system("cls");
    return opc;
}
