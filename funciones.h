#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


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



// DECLARACION DE FUNCIONES

void mayusculas(string &str);

void CargarFormasPago(FormaPago formasPago[]);

void cargarMarcas(marca marcas[], int cantidad);

void cargarVentas(venta ventas);

#endif // FUNCIONES_H_INCLUDED
