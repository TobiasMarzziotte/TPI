#include <iostream>
#include "Funciones.h"

using namespace std;

int main()
{
// DECLARACION DE VARIABLES

    int opc;
    int opcReporte;

    int totalVentas = 0;

    int ventasPorProducto[20] = {0};

    venta ventas;

// DECLARACION DE VECTORES

    marca marcas[10];
    Producto productos[20]; //DECLARAMOS EL VECTOR QUE VAMOS A UTILIZAR PARA LOS PRODUCTOS
    FormaPago formasPago[5];
    int contadorVentasPorForma[5]={0};

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
        break;

    case 3:
        system("cls");
        CargarFormasPago(formasPago);
        system("pause");
        break;

    case 4:
        system("cls");
        cargarVentas(contadorVentasPorForma, totalVentas, formasPago, productos, ventasPorProducto);
        system("pause");
        break;

    case 5:
                system("cls");
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
