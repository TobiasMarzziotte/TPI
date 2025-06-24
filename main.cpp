#include <iostream>
#include <string>
using namespace std;

#include "FuncionesTPI.h"


int main() {

    // DECLARACION DE VARIABLES

    int opc;
    int opcReporte;
    int totalVentas = 0;

    // DECLARACION DE VECTORES STRUCT

    marca marcas[10];
    FormaPago formasPago[5];
    Producto productos[20];
    VentaMarcaForma acumulador[100];

    // DECLARACION DE VECTORES

    int contadorVentasPorForma[5] = {0};
    int cantidadAcumulada = 0;
    int ventasPorProducto[20] = {0};


    // MENU

    bool iniciarMenu = false; //INICIAMOS UN BOOL PARA QUE EL WHILE SIGA REPITIENDO MIENTRAS SIGA EN FALSE

    while(iniciarMenu == false){
    opc = menuPrincipal(); //RECIBIMOS POR REFERENCIA LA FUNCION DEL MENU Y LA ALMACENAMOS EN LA VARIABLE opc
                           //SE INICIA EL MENU

    switch (opc){
    case 1:
    system("cls");

    cargarMarcas(marcas, 10);

    system("pause");
    system("cls");

    break;

    case 2:
        system("cls");
        cout << "Ingrese el listado de 20 productos: ";
        cout << endl;

            if (cargaProductos(productos))
            {
                cout << "Se cargaron los 20 productos de manera correcta." << endl;
            }
            else
            {
                cout << "La carga tuvo un error. Inicie nuevamente." << endl;
            }
        system("pause");
        system("cls");
        break;

    case 3:
        system("cls");
        CargarFormasPago(formasPago);
        system("pause");
        system("cls");
        break;

    case 4:
        system("cls");
        cargarVentas(contadorVentasPorForma, totalVentas, formasPago, acumulador,cantidadAcumulada, productos ,ventasPorProducto);
        system("pause");  // cargarVentas(contadorVentasPorForma, totalVentas, formasPago, productos, ventasPorProducto);
        system("cls");


        break;

    case 5:
                system("cls");
                do {
                opcReporte = menuReportes();


                switch (opcReporte) {
                case 1:
                    system("cls");

                    system("pause");
                    break;

                case 2:
                    system("cls");
                    reportePunto2(contadorVentasPorForma, totalVentas, formasPago);
                    system("pause");
                    break;

                case 3:
                    system("cls");
                    reportePunto3(acumulador,cantidadAcumulada,formasPago,marcas);
                    system("pause");
                    break;

                case 4:
                    system("cls");

                    reporteSinVentas(productos, ventasPorProducto);

                    system("pause");
                    break;

                case 5:
                    system("cls");

                    system("pause");
                    break;

                case 0:
                    system("cls");
                    continue;
                    system("pause");
                    break;

                default:
                    system("cls");
                    cout<< "Opcion invalida" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
                } while (opcReporte != 0);
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
