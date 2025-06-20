
#include <iostream>
#include "FUNCION_CARGA_PRODUCTOS.h"
#include <string>
using namespace std;


//ARCHIVO .CPP PARA EL DESARROLLO DE LA FUNCION PREVIAMENTE DECLARADA

bool cargaProductos(Producto productos[20]){

    bool cargaExitosa = true; //VARIABLE BOOLEANA PARA QUE DEVUELVA LA CONFIRMACION DE LA CARGA EXITOSA AL MAIN
    int codActual=0; //VARIABLE PARA INICIALIZAR codActual QUE DESPUES ALMACENA EL CODIGO INGRESADO POR EL USUARIO

    for (int i=0; i<20; i++){

            cout << "Ingrese el codigo del producto(3 DIGITOS NO CONSECUTIVOS):"<< endl;
            cin >> productos[i].codProducto;
            if (productos[i].codProducto< 100 || productos[i].codProducto > 999){ //PRIMER CONDICION, NUMERO DE 3 DIGITOS
                cargaExitosa = false; //SI NO ES DE 3 DIGITOS EL BOOL DA FALSE PARA QUE RETORNE AL MAIN

                cin.ignore(); //PARA EVITAR QUE QUEDE ALMACENADO UN REGISTRO Y NO CONTENGA "BASURA"

                cout << "ERROR: El código ingresado no cumple con los requisitos."<< endl;
                break; //PARA QUE CORTE EL CICLO FOR Y PUEDA CONTINUAR EL CODIGO EN EL MAIN
            }

            if (i > 0 && productos[i].codProducto - codActual == 1 || codActual - productos[i].codProducto == 1){
                //SEGUNDA CONDICION QUE NO SEA CONSECUTIVOS. GUARDAMOS EL ULTIMO CODIGO INGRESADO POR EL USUARIO EN codActual
                //Y RESTAMOS EL SIGUIENTE CODIGO INGRESADO PARA EVALUAR SI SON CONSECUTIVOS
                cargaExitosa = false;
                cout << "ERROR: El código ingresado no cumple con los requisitos."<< endl;
                cin.ignore();
                break;

            }

            codActual = productos[i].codProducto; //ALMACENAMOS EN codActual EL ULTIMO CODIGO INGRESADO POR EL USUARIO

            cin.ignore();


            cout << "Ingrese el nombre del producto: ";
            getline(cin, productos[i].nombreProducto);
            if (productos[i].nombreProducto == ""){
                cargaExitosa = false;
                cout << "ERROR: El nombre ingresado no cumple con los requisitos."<< endl;
                cin.ignore();
                break;
            }

            cout << "Ingrese el precio de venta del producto: ";
            cin >> productos[i].precioVenta;
            if (productos[i].precioVenta == 0){
                cargaExitosa = false;
                cout << "ERROR: El precio de venta ingresado no cumple con los requisitos."<< endl;
                cin.ignore();
                break;
            }

            cout << "Ingrese el precio de compra del producto: ";
            cin >> productos[i].precioCompra;
            if (productos[i].precioCompra == 0){
                cargaExitosa = false;
                cout << "ERROR: El precio de compra ingresado no cumple con los requisitos."<< endl;
                cin.ignore();
                break;
            }

            cout << "Ingrese la cantidad de stock disponible del producto: ";
            cin >> productos[i].stockDisponible;
            if (productos[i].stockDisponible == 0){
                cargaExitosa = false;
                cout << "ERROR: El número de stock ingresado no cumple con los requisitos."<< endl;
                cin.ignore();
                break;
            }

            cout << "Ingrese el codigo de marca del producto: ";
            cin >> productos[i].codMarca;
            if (productos[i].codMarca < 1 && productos[i].codMarca > 10){
                cargaExitosa = false;
                cout << "ERROR: El código de marca ingresado no cumple con los requisitos."<< endl;
                cin.ignore();
                break;
            }

            cout << "----------------------------------------------" << endl;


    }



return cargaExitosa;
}
