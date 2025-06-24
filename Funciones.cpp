#include <iostream>
#include <string>
#include "Funciones.h"
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()


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

void reportePunto3(VentaMarcaForma acumulador[], int cantidadAcumulada, FormaPago formasPago[], marca marcas[]) {
    cout << "------ VENTAS POR MARCA Y FORMA DE PAGO ------" << endl;
    string nombreMarca;
    string nombreForma;
    for (int i = 0; i < cantidadAcumulada; i++) {


        // Buscar nombre de marca
        for (int x = 0; x < 10; x++) {
            if (marcas[x].codigoMarca == acumulador[i].codigoMarca) {
                nombreMarca = marcas[x].nombreMarca;
            }
        }

        // Buscar nombre de forma de pago
        for (int j = 0; j < 5; j++) {
            if (formasPago[j].codigo == acumulador[i].codigoFormaPago) {
                nombreForma = formasPago[j].nombre;
            }
        }

        cout << "Marca: " << nombreMarca << " - Forma de Pago: " << nombreForma
             << " - Cantidad Vendida: " << acumulador[i].cantidadVendida << endl;
    }
}

void reportePunto2(int contadorVentasPorForma[], int totalVentas, FormaPago formasPago[]) {




    cout << "----- PORCENTAJE DE VENTAS POR FORMA DE PAGO -----" << endl;

    if (totalVentas == 0) {
        cout << "No se registraron ventas." << endl;
        return;
    }

    for (int i = 0; i < 5; i++) {
        float porcentaje = (contadorVentasPorForma[i] * 100.0f) / totalVentas;
        cout << formasPago[i].nombre << ": " << porcentaje << "%" << endl;
    }


}


void cargarVentas(int contadorVentasPorForma[], int& totalVentas, FormaPago formasPago[], VentaMarcaForma acumulador[], int &cantAcumuladas, Producto productos[], int ventasPorProducto[], float recaudadoPorProducto[], int comprasPorCliente[]) {

    venta ventas;
    totalVentas = 0;
    cantAcumuladas = 0;

    cout << "Ingrese numero de compra (0 para finalizar): ";
    cin >> ventas.numeroCompra;

    while (ventas.numeroCompra != 0) {
        cout << "Ingrese codigo de producto: ";
        cin >> ventas.codigoProducto;


        //bucle para guardar las ventas por cada producto y guardar lo recaudado por cada producto (para reporte 1 y 4)
        for (int i = 0; i < 20; i++) {
            if (productos[i].codProducto == ventas.codigoProducto){
            ventasPorProducto[i] += ventas.cantidadVendida;
            recaudadoPorProducto[i] += ventas.cantidadVendida * productos[i].precioVenta;
            break;
            }
        }

        cout << "Ingrese forma de pago (EF,MP,TR,TC,CT): ";
        cin >> ventas.formaPago;
        mayusculas(ventas.formaPago);

        cout << "Ingrese cantidad vendida: ";
        cin >> ventas.cantidadVendida;

        cout << "Ingrese codigo de cliente (1 a 50): ";
        cin >> ventas.codigoCliente;

        cout << "Ingrese dia de la venta (1 a 30): ";
        cin >> ventas.diaVenta;

        // Actualizar contador de forma de pago (para punto 2)
        for (int i = 0; i < 5; i++) {
            if (formasPago[i].codigo == ventas.formaPago) {
                contadorVentasPorForma[i]++;
            }
        }

        // Buscar la marca del producto
        int codMarca = -1;
        for (int i = 0; i < 20; i++) {
            if (productos[i].codProducto == ventas.codigoProducto) {
                codMarca = productos[i].codMarca;
            }
        }

        // Acumular ventas por marca y forma de pago (para punto 3)
        if (codMarca != -1) {
            bool encontrada = false;
            for (int i = 0; i < cantAcumuladas; i++) {
                if (acumulador[i].codigoMarca == codMarca && acumulador[i].codigoFormaPago == ventas.formaPago) {
                    acumulador[i].cantidadVendida += ventas.cantidadVendida;
                    encontrada = true;
                }
            }
            if (!encontrada) {
                acumulador[cantAcumuladas].codigoMarca = codMarca;
                acumulador[cantAcumuladas].codigoFormaPago = ventas.formaPago;
                acumulador[cantAcumuladas].cantidadVendida = ventas.cantidadVendida;
                cantAcumuladas++;
            }


            // buscar ventar por cliente para (para punto 5)
            if (ventas.codigoCliente >= 1 && ventas.codigoCliente <= 50){
                comprasPorCliente[ventas.codigoCliente]++;
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

int menuReportes(){
                system("cls");
                int opcReporte;
                cout << "=== MENU DE REPORTES ===" << endl << endl;
                cout << "1) Recaudacion por producto" << endl;
                cout << "2) Porcentaje de ventas por forma de pago" << endl;
                cout << "3) Ventas por marca y forma de pago" << endl;
                cout << "4) Productos sin ventas" << endl;
                cout << "5) Top 10 clientes + sorteo de cupones" << endl;
                cout << "0) Volver al menu principal" << endl;
                cout << "Opcion: ";
                cin >> opcReporte;

        return opcReporte;
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

void reporteSinVentas(Producto productos[], int ventasPorProducto[]) {
    cout << "--- PRODUCTOS SIN VENTAS ---" << endl;
    bool sinVentas = false;

    for (int i = 0; i < 20; i++) {
        if (ventasPorProducto[i] == 0) {
            cout << "Código: " << productos[i].codProducto << " -- Nombre: " << productos[i].nombreProducto << endl;
            sinVentas = true;
        }
    }

    if (!sinVentas) {
        cout << "Todos los productos registraron ventas." << endl;
    }
}

void reportePunto1(Producto productos[], int ventasPorProducto[], float recaudacionPorProducto[], int totalVentas) {

    cout << "---- RECAUDACION POR PRODUCTO ----" << endl << endl;

    if (totalVentas == 0) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    // Ordenamiento burbuja
    for (int i = 0; i < 19; i++) {
        for (int x = i + 1; x < 20; x++) {
            if (ventasPorProducto[i] < ventasPorProducto[x]) {

                // intercambio para la cantidad de ventas por producto
                int auxVentas = ventasPorProducto[i];
                ventasPorProducto[i] = ventasPorProducto[x];
                ventasPorProducto[x] = auxVentas;

                // intercambio para la recaudación por producto
                float auxRecaudacion = recaudacionPorProducto[i];
                recaudacionPorProducto[i] = recaudacionPorProducto[x];
                recaudacionPorProducto[x] = auxRecaudacion;

                //intercambio para el vector productos(que contiene los demás datos)
                Producto auxProducto = productos[i];
                productos[i] = productos[x];
                productos[x] = auxProducto;
            }
        }
    }

    cout << endl << "LISTADO DE RECAUDACION POR PRODUCTO:" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < 20; i++) {
        cout << "Codigo: " << productos[i].codProducto << endl;
        cout << "Nombre: " << productos[i].nombreProducto << endl;
        cout << "Vendido: " << ventasPorProducto[i] << endl;
        cout << "Recaudado: $" << recaudacionPorProducto[i] << endl;
        cout << "Stock remanente: " << (productos[i].stockDisponible - ventasPorProducto[i]) << endl;
    cout << "----------------------------------------------" << endl << endl;
    }
}





void reportePunto5(int comprasPorCliente[]) {
    cout << "---- TOP 10 CLIENTES + SORTEO DE CUPONES ---" << endl;

    ClienteRanking ranking[50];
    int totalClientes = 0;

    // Llenar el ranking con clientes que tengan al menos 1 compra
    for (int i = 1; i <= 50; i++) {
        if (comprasPorCliente[i] > 0) {
            ranking[totalClientes].codigo = i;
            ranking[totalClientes].compras = comprasPorCliente[i];
            if (totalClientes == 10) {
                break;
            }
            else {
                totalClientes++;
            }

        }
    }

    // Ordenar de mayor a menor
    for (int i = 0; i < totalClientes - 1; i++) {
        for (int x = i + 1; x < totalClientes; x++) {
            if (ranking[i].compras < ranking[x].compras) {
                ClienteRanking auxRanking = ranking[i];
                ranking[i] = ranking[x];
                ranking[x] = auxRanking;
            }
        }
    }

    // Mostrar Top 10
    cout << "---- TOP 10 CLIENTES ----" << endl << endl;
    for (int i = 0; i < totalClientes; i++) {
        cout << "Cliente " << ranking[i].codigo << ": " << ranking[i].compras << " compras" << endl;
    }

    //Sorteo de 3 ganadores, solo si hay al menos 3 en el top 10
    if (totalClientes >= 3) {
        cout << "--- GANADORES DEL SORTEO ---" << endl;
        srand(time(NULL));

        int ganadores[3];
        for (int i = 0; i < 3; i++) {
            int indice;
            do {
                indice = rand() % totalClientes; // Número aleatorio entre 0 y limite-1
            } while (i > 0 && (indice == ganadores[0] || indice == ganadores[1])); // para evitar repetidos

            ganadores[i] = indice;
            cout << "Cliente " << ranking[indice].codigo << " (" << ranking[indice].compras << " compras) GANO UN CUPON!!!" << endl;
        }
    } else {
        cout << endl << "No hay suficientes clientes para el sorteo." << endl;
    }
}

