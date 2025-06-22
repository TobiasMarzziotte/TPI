#include <iostream>
#include <cctype>
#include "funciones.h"
using namespace std;

// DEFINICION DE FUNCIONES



void cargarMarcas(marca marcas[], int cantidad) {

    for (int x = 0; x < cantidad; x++) {
        while (true) {
            cout << "CODIGO DE MARCA (1 a 10): ";
            cin >> marcas[x].codigoMarca;
            system("cls");


            if (marcas[x].codigoMarca < 1 || marcas[x].codigoMarca > 10) {
                cout << "CODIGO INVALIDO, vuelva a empezar" << endl;
                system("pause");
                system("cls");

                continue;
            }

            cout << "NOMBRE DE LA MARCA: " << endl;
            cin.ignore();
            getline(cin, marcas[x].nombreMarca);
            system("cls");


            if (marcas[x].nombreMarca.empty()) {
                cout << "El nombre no puede estar vacio. Vuelva a empezar." << endl;
                continue;
            }

            break;
        }

    }
    cout << "Marcas cargadas con exito" << endl;
}

void mayusculas(string &str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void CargarFormasPago(FormaPago formasPago[]) {
    cout << "---- CARGA DE FORMAS DE PAGO ----" << endl;

    for (int i = 0; i < 5; i++) {
        cout << endl << "Forma de pago " << i+1 << " de 5" << endl;

        bool datosValidos = false;
        while (!datosValidos) {
            // Ingreso del código de la forma de pago
            cout << "Ingrese codigo (EF,MP,TR,TC,CT): " << endl;
            string codigoActual;
            cin >> codigoActual;

            // Convertir a mayúsculas
            mayusculas(codigoActual);

            // Validar si el codigo es valido
            if (!(codigoActual == "EF" || codigoActual == "MP" || codigoActual == "TR" || codigoActual == "TC" || codigoActual == "CT")) {
                cout << "Error: Codigo no valido. Use EF, MP, TR, TC o CT" << endl;
                continue;
            }

            // Verificar que el código no se repite
            bool repetido = false;
            for (int x = 0; x < i; x++) {
                if (formasPago[x].codigo == codigoActual) {
                    repetido = true;
                }
            }

            if (repetido) {
                cout << "Error: Este codigo ya fue usado" << endl;
                continue;
            }

            // Guardar el codigo validado
            formasPago[i].codigo = codigoActual;

            cout << "Ingrese nombre: ";
            cin.ignore();
            getline(cin, formasPago[i].nombre);

            //verificar que el nombre no esté vacío
            if (formasPago[i].nombre.empty()) {
                cout << "Error: Nombre no puede estar vacio" << endl;
                continue;
            }

            // Ingresar porcentaje
            cout << "Ingrese el porcentaje (negativo para descuento, positivo para interes): ";
            cin >> formasPago[i].porcentaje;

            datosValidos = true;
            cout << "Forma de pago cargada correctamente" << endl;

        }

    }
    cout << endl << "Carga de formas de pago completada" << endl;

}



void reportePunto2(int contadorVentasPorForma[], int totalVentas, FormaPago formasPago[]) {


    cout << "----- PORCENTAJE DE VENTAS POR FORMA DE PAGO -----" << endl;

    if (totalVentas == 0) {
        cout << "No se registraron ventas." << endl;
        return;
    }

    cout << "---- Porcentaje de ventas por forma de pago ----" << endl;
    for (int i = 0; i < 5; i++) {
        float porcentaje = (contadorVentasPorForma[i] * 100.0f) / totalVentas;
        cout << formasPago[i].nombre << ": " << porcentaje << "%" << endl;
    }


}


void cargarVentas(int contadorVentasPorForma[], int& totalVentas, FormaPago formasPago[]){



    // PEDIDO DE DATOS INICIAL

    venta ventas;
    totalVentas = 0;

    cout << "Ingrese numero de compra (0 para finalizar): ";
    cin >> ventas.numeroCompra;

    while (ventas.numeroCompra != 0) {

        cout << "Ingrese codigo de producto: ";
        cin >> ventas.codigoProducto;

        cout << "Ingrese forma de pago (EF,MP,TR,TC,CT): ";
        cin >> ventas.formaPago;
        mayusculas(ventas.formaPago);

        cout << "Ingrese cantidad vendida: ";
        cin >> ventas.cantidadVendida;

        cout << "Ingrese codigo de cliente (1 a 50): ";
        cin >> ventas.codigoCliente;

        cout << "Ingrese dia de la venta (1 a 30): ";
        cin >> ventas.diaVenta;

        // Actualizar contadores de forma de pago
        for (int i = 0; i < 5; i++) {
            if (formasPago[i].codigo == ventas.formaPago) {
                contadorVentasPorForma[i]++;
                break;
            }
        }

        totalVentas++;

        cout << "----------------------------------------" << endl;

        cout << "Ingrese numero de compra (0 para finalizar): ";
        cin >> ventas.numeroCompra;


    }
}


int menuPrincipal(){


int opc;

     while (true){

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
     }
    system("pause");
    system("cls");
    return opc;
}





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

