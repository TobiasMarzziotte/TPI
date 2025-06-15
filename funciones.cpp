#include <iostream>
#include <cctype>
#include "funciones.h"
using namespace std;

//funcion para convertir a mayusculas
void mayusculas(string &str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}
// función para cargar el tercer lote 
void CargarFormasPago(FormaPago formasPago[]) {
    cout << "---- CARGA DE FORMAS DE PAGO ----" << endl;

    for (int i = 0; i < 5; i++) {
        cout << endl << "Forma de pago " << i+1 << " de 5" << endl;

        bool datosValidos = false;
        while (!datosValidos) {
            // Ingreso del código de la forma de pago
            cout << "Ingrese codigo (EF,MP,TR,TC,CT): ";
            string codigoActual;
            cin >> codigoActual;

            // Convertir a mayúsculas
            Mayusculas(codigoActual);

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




int suma(int n1, int n2)
{
 int r = n1 + n2;
 return r;
}


