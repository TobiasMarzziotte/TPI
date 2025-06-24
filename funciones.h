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

// DECLARACION DE FUNCIONES

void reportePunto2(int contadorVentasPorForma[], int totalVentas, FormaPago formasPago[]);

void reportePunto3(VentaMarcaForma acumulador[], int cantidadAcumulada, FormaPago formasPago[], marca marcas[]);

int menuPrincipal();

int menuReportes(); //declaración para el menú de reportes

void mayusculas(string &str);

void CargarFormasPago(FormaPago formasPago[]);

void cargarMarcas(marca marcas[], int cantidad);

void cargarVentas(int contadorVentasPorForma[], int& totalVentas, FormaPago formasPago[], VentaMarcaForma acumulador[], int &cantAcumuladas, Producto productos[], int ventasPorProducto[]);

bool cargaProductos(Producto productos[]); //contadorVentasPorForma, totalVentas, formasPago, acumulador,cantidadAcumulada, productos ,ventasPorProducto

void reporteSinVentas(Producto productos[], int ventasPorProducto[]);




#endif // FUNCIONES_H_INCLUDED
