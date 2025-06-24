#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>

using namespace std;



// DECLARACION DE STRUCT

struct marca{
    int codigoMarca;
    string nombreMarca;
};

struct FormaPago {
    string codigo;  // EF, MP, TR, TC, CT
    string nombre;
    int porcentaje;
};

struct Producto{
    int codProducto;
    string nombreProducto;
    float precioVenta;
    float precioCompra;
    int stockDisponible;
    int codMarca;
};

struct venta{
    int numeroCompra;
    int codigoProducto;
    string formaPago;
    int cantidadVendida;
    int codigoCliente;
    int diaVenta;
};

struct VentaMarcaForma {
    int codigoMarca;
    string codigoFormaPago;
    int cantidadVendida;
};

//para reporte 5
struct ClienteRanking {
        int codigo;
        int compras;
    };

// DECLARACION DE FUNCIONES
void reportePunto1(Producto productos[], int ventasPorProducto[], float recaudacionPorProducto[], int totalVentas);

void reportePunto2(int contadorVentasPorForma[], int totalVentas, FormaPago formasPago[]);

void reportePunto3(VentaMarcaForma acumulador[], int cantidadAcumulada, FormaPago formasPago[], marca marcas[]);

void reportePunto5(int comprasPorCliente[]);

int menuPrincipal();

int menuReportes(); //declaración para el menú de reportes

void mayusculas(string &str);

void CargarFormasPago(FormaPago formasPago[]);

void cargarMarcas(marca marcas[], int cantidad);
                                                                                                                                                                    //para reporte 1 y 4        //para reporte 1            //para reporte 5
void cargarVentas(int contadorVentasPorForma[], int& totalVentas, FormaPago formasPago[], VentaMarcaForma acumulador[], int &cantAcumuladas, Producto productos[], int ventasPorProducto[], float recaudadoPorProducto[], int comprasPorCliente[]);

bool cargaProductos(Producto productos[]); //contadorVentasPorForma, totalVentas, formasPago, acumulador,cantidadAcumulada, productos ,ventasPorProducto

void reporteSinVentas(Producto productos[], int ventasPorProducto[]);




#endif // FUNCIONES_H_INCLUDED
