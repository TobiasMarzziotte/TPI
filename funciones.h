#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
using namespace std;

//struct para lote 1
struct marca{
    int codigoMarca;
    string nombreMarca;
    };


//Struct del lote 2
struct Producto{
    int codProducto;
    string nombreProducto;
    float precioVenta;
    float precioCompra;
    int stockDisponible;
    int codMarca;
};

//struct para el lote 3
struct FormaPago {
    string codigo;  // EF, MP, TR, TC, CT
    string nombre;
    int porcentaje;
};


//struct para lote 4
struct venta{
    int numeroCompra;
    int codigoProducto;
    string formaPago;
    int cantidadVendida;
    int codigoCliente;
    int diaVenta;

};

void cargarMarcas(marca marcas[], int cantidad);

void CargarFormasPago(FormaPago formasPago[]);

void mayusculas(string &str);

void cargarVentas(int contadorVentasPorForma[], int& totalVentas, FormaPago formasPago[], Producto productos[], int ventasPorProducto[]);

bool cargaProductos(Producto productos[]);

int menuPrincipal(); //DECLARACION DE FUNCION PARA LLAMAR AL MENU PRINCIPAL

int menuReportes(); //declaración para el menú de reportes

void reportePunto2(int contadorVentasPorForma[], int totalVentas, FormaPago formasPago[]);

void reporteSinVentas(Producto productos[], int ventasPorProducto[]);

#endif // FUNCIONES_H_INCLUDED
