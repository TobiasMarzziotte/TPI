#include <iostream>
#include <cctype>
#include <string>
#include "funciones.h"

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

void cargarVentas(venta ventas){
    while(ventas.numeroCompra != 0){
    cout << "Ingrese numero de compra: " << endl;
    cin >> ventas.numeroCompra;

    cout << "Ingrese codigo de producto: " << endl;
    cin >> ventas.codigoProducto;

    cout << "Ingrese forma de pago (EF,MP,TR,TC,CT): " << endl;
    cin >> ventas.formaPago;

    cout << "Ingrese cantidad vendida: " << endl;
    cin >> ventas.cantidadVendida;

    cout << "Ingrese codigo de cliente (1 a 50): " << endl;
    cin >> ventas.codigoCliente;

    cout << "Ingrese dia de la venta (1 a 30): " << endl;
    cin >> ventas.diaVenta;
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;
    }
}


